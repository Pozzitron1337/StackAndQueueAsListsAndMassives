

#include "StackAsMassive.cpp"
//#include "StackAsList.cpp"
#include "QueueAsMassive.cpp"
#include "QueueAsList.cpp"
#include "StackX2InMassive.cpp"
#include "expression.cpp"
#include "StackSTL.cpp"
using namespace std;

int main() {

    StackAsMassive<int> stack1(5);
    stack1.printStack();
    cout<<endl;
    stack1.push(5);
    stack1.push(9);
    stack1.printStack();
    cout<<endl;
    stack1.pop();
    stack1.printStack();
    cout<<endl;

    StackAsList<int> stack2;
    stack2.printStack();
    stack2.push(8);
    stack2.push(4);
    stack2.push(7);
    stack2.printStack();

    QueueAsMassive<int> queue1;
    queue1.add(7);
    queue1.add(8);
    queue1.add(11);
    queue1.printQueue();
    cout<<endl;
    queue1.pop();
    queue1.printQueue();
    cout<<endl;
    queue1.pop();
    queue1.pop();
    queue1.printQueue();
    cout<<endl;
    queue1.add(9);
    queue1.printQueue();
    cout<<endl;


    cout<<"List:"<<endl;
    QueueAsList<int> queue2;
    queue2.printQueue();
    cout<<endl;
    queue2.add(3);
    queue2.add(5);
    queue2.printQueue();
    cout<<endl;
    queue2.pop();
    queue2.printQueue();
    cout<<endl;
    queue2.pop();
    queue2.printQueue();
    cout<<endl;

    StackX2InMassive<int> s(4);
    s.pushleft(1);
    s.pushleft(2);
    s.pushright(9);
    s.pushright(8);
    s.pushleft(5);
    s.printLeftStack();
    cout<<endl;
    s.printRightStack();
    cout<<endl;
    s.popleft();
    s.printLeftStack();
    cout<<endl;
    s.popleft();
    s.printLeftStack();
    cout<<endl;
    InfixExpression infixExpression1("(A-B-C)/D-E*F");
    cout<<infixExpression1<<endl;
    PostfixExpression postfixExpression1(infixExpression1);
    cout<<postfixExpression1<<endl;

    InfixExpression infixExpression2("(A+B)*C-(D+E)/F");
    cout<<infixExpression2<<endl;
    PostfixExpression postfixExpression2(infixExpression2);
    cout<<postfixExpression2<<endl;

    InfixExpression infixExpression3("(A/(B-C)+D*(E-F)");
    cout<<infixExpression3<<endl;
    PostfixExpression postfixExpression3(infixExpression3);
    cout<<postfixExpression3<<endl;

    InfixExpression infixExpression4("(A*B+C)/D-F/E");
    cout<<infixExpression4<<endl;
    PostfixExpression postfixExpression4(infixExpression1);
    cout<<postfixExpression4<<endl;
    StackSTL<int> s1;
    s1.push(3);
    s1.push(7);
    s1.push(5);
    s1.push(9);
    s1.printStack();
}