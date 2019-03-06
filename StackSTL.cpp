#include <iostream>
#include <list>

using namespace std;

template<typename T>
class StackSTL{
private:
    std::list<T> stack;
public:
    StackSTL(){
    }
    bool push(T element){
            stack.push_back(element);
        return true;
    }
    bool pop(){
        stack.pop_back();
        return true;
    }
    void printStack(){
        std::list<int>::iterator ptr;
        for(ptr = stack.begin(); ptr != stack.end(); ++ptr)
        cout<<"|"<<*ptr<<endl;
    }
};