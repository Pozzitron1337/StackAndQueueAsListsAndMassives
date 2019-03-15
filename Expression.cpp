#include "StackAsList.cpp"
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
        StackAsList<char> operators;
        int size=infixExp.size();
        for(int i=0;i<size;i++){
            if(infixExp[i]=='('){
                operators.push(infixExp[i]);
                continue;
            }
            if(infixExp[i]=='+'||infixExp[i]=='-'||infixExp[i]=='*'||infixExp[i]=='/') {
                while((infixExp[i]!=42||infixExp[i]!=47)&&(operators.getTopElement()==42||operators.getTopElement()==47)&&operators.getTopElement()!='('){
                    postfixEpression+=operators.getTopElement();
                    operators.pop();
                }
                operators.push(infixExp[i]);
                continue;
            }
            if(infixExp[i]==')'){
                while(operators.getTopElement()!='('){
                    postfixEpression+=operators.getTopElement();
                    operators.pop();
                }
                operators.pop();
            }else{
                postfixEpression+=infixExp[i];
            }
        }
        while(operators.getTopElement()!='('&&!operators.isEmpty()){
            postfixEpression+=operators.getTopElement();
            operators.pop();
        }

    }

    friend ostream& operator<<(ostream &os, const PostfixExpression& pe) {
        return os << pe.postfixEpression;
    }
};

