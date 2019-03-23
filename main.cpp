

#include "StackAsMassive.cpp"
//#include "StackAsList.cpp"
#include "QueueAsMassive.cpp"
#include "QueueAsList.cpp"
#include "StackX2InMassive.cpp"
#include "expression.cpp"


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
    stack2.clear();
    stack2.getTopElement();
    cout << endl;
    stack2.printStack();
    stack2.push(0);
    stack2.push(5);
    stack2.printStack();
    cout << endl;
    stack2.pop();
    stack2.printStack();

    QueueAsMassive<int> queue1(3);
     queue1.add(7);
     queue1.add(8);
     queue1.add(11);
    queue1.add(12);
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
        queue2.add(5);
        queue2.add(9);
        cout<<endl;
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

    QueueSTL<int> variebles;
    variebles.push(10);
    variebles.push(3);
    variebles.push(3);
    variebles.push(4);
    variebles.push(98);
    variebles.push(2);

   InfixExpression infixExpression1("((A-B)-C)/D-E*F");
   cout << infixExpression1 << endl;

   PostfixExpression postfixExpression1(infixExpression1);
   cout << postfixExpression1 << endl;
   cout<<postfixExpression1.count(variebles)<<endl;

   InfixExpression infixExpression2("(A+B)*C-(D+E)/F");
   cout << infixExpression2 << endl;
   PostfixExpression postfixExpression2(infixExpression2);
   cout << postfixExpression2 << endl;
    cout<<postfixExpression2.count(variebles)<<endl;

   InfixExpression infixExpression3("(A/(B-C)+D*(E-F)");
   cout << infixExpression3 << endl;
   PostfixExpression postfixExpression3(infixExpression3);
   cout << postfixExpression3 << endl;


   InfixExpression infixExpression4("(A*B+C)/D-F/E");
   cout << infixExpression4 << endl;

   PostfixExpression postfixExpression4(infixExpression4);
   cout << postfixExpression4 << endl;

    InfixExpression ie("35+91*(9213+8)");
    cout<<ie<<endl;
    PostfixExpression pe(ie);
    cout<<pe<<endl;

    cout<<endl;
   StackSTL<int> s1;
   s1.push(3);
   s1.push(7);
   s1.push(5);
   s1.push(9);
   s1.printStack();
    cout<<endl;

    QueueSTL<int> q1;
    q1.push(4);
    q1.push(8);
    q1.push(1);
    q1.printQueue();
    int wqe=q1.pop();
    cout<<endl;
    q1.printQueue();
}