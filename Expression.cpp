#include "StackAsList.cpp"
#include "QueueSTL.cpp"
#include "StackSTL.cpp"

#include <string>
using namespace std;
class Expression{
public:

};

class InfixExpression:public Expression{
private:
    string infixExpression;
public:
    InfixExpression(){
        infixExpression="";
    }
    InfixExpression(string ie){
        infixExpression=ie;
    }
    friend ostream& operator<<(ostream &os, const InfixExpression& ie) {
        return os << ie.infixExpression;
    }

    string getInfixExpression() {
        return infixExpression;
    }
};


class PostfixExpression:public Expression{
private:
    string postfixEpression;
    QueueSTL<string> variables;
public:
    PostfixExpression(){
        postfixEpression="";

    }
    ~PostfixExpression(){

    }
    PostfixExpression(string pe) {
        postfixEpression=pe;
    }
    PostfixExpression(InfixExpression ie){
        string infixExp=ie.getInfixExpression();
        string value_buffer="";
        StackAsList<char> operators;
        int size=infixExp.size();
        for(int i=0;i<size;i++){
            if(infixExp[i]=='('){
                operators.push(infixExp[i]);
                continue;
            }
            if(infixExp[i]=='+'||infixExp[i]=='-'||infixExp[i]=='*'||infixExp[i]=='/') {
                if(value_buffer.compare("")){
                    variables.push(value_buffer);
                    value_buffer="";
                }
                while((infixExp[i]!=42||infixExp[i]!=47)&&  //42=='*',47=='/'
                      (operators.getTopElement()==42||operators.getTopElement()==47)&&
                      operators.getTopElement()!='(')
                {
                    postfixEpression+=operators.getTopElement();
                    operators.pop();
                }
                operators.push(infixExp[i]);
                continue;
            }
            if(infixExp[i]==')'){
                variables.push(value_buffer.c_str());
                value_buffer="";
                while(operators.getTopElement()!='('){
                    postfixEpression+=operators.getTopElement();
                    operators.pop();
                }
                operators.pop();
            }else{
                value_buffer+=infixExp[i];
                postfixEpression+=infixExp[i];
            }
        }
        if(value_buffer.compare("")){
            variables.push(value_buffer);
            value_buffer="";
        }
        while(operators.getTopElement()!='('&&!operators.isEmpty()){
            postfixEpression+=operators.pop();
        }
    }
    template <typename T>
    T count(QueueSTL<T> q){
        if(q.getSize()!=variables.getSize())
            return 0;
        string pe=postfixEpression;
        StackSTL<int> stack;
        T size=pe.size();
        T rightoperand;
        T leftoperand;
        for(int i=0;i<size;i++){
            switch(pe[i]){
                case '+':{
                    rightoperand=stack.pop();
                    leftoperand=stack.pop();
                    leftoperand=leftoperand+rightoperand;
                    stack.push(leftoperand);
                    break;
                }
                case '-':{
                    rightoperand=stack.pop();
                    leftoperand=stack.pop();
                    leftoperand=leftoperand-rightoperand;
                    stack.push(leftoperand);
                    break;
                }
                case '*':{
                    rightoperand=stack.pop();
                    leftoperand=stack.pop();
                    leftoperand=leftoperand*rightoperand;
                    stack.push(leftoperand);
                    break;
                }case '/':{
                    rightoperand=stack.pop();
                    leftoperand=stack.pop();
                    leftoperand=leftoperand/rightoperand;
                    stack.push(leftoperand);
                    break;
                }
                default:{
                    stack.push(q.pop());
                }
            }
        }
        return stack.pop();
    }


    friend ostream& operator<<(ostream &os, const PostfixExpression& pe) {
        return os << pe.postfixEpression;
    }
};

