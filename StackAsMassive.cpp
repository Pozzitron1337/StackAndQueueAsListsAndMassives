#include <iostream>
template<typename T>
class StackAsMassive {
private:
    T *stack;           // massive
    unsigned int size;  // stack size
    int top;            // stack top
public:
    StackAsMassive(int s=10)// by default
    {
        size = s > 0 ? s: 10;
        stack = new T[size];
        top = -1;// stack is empty
    }
    ~StackAsMassive()
    {
        delete[] stack;
    }
    bool push(const T element) //adding element to stack
    {
        if (top == size - 1) {
            std::cout<<"Stack is overflow."<<std::endl;
            return false; //Stack is overflow
        }else{
        top++;
        stack[top] = element;
        return true;//success
        }
    }
    bool pop() //delete element from stack
    {
        if (top == - 1)
            return false; //stack is empty
        top--;
        return true;    //success
    }
    void printStack(){//output to console
        if(top==-1) {
            std::cout<<"Stack is empty."<<std::endl;
            return;
        }
        for (int i = top; i>= 0; i--)
            std::cout << "|"  << stack[i] << std::endl;
    }
};