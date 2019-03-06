#include <iostream>
#include <list>

using namespace std;

template<typename T>
class QueueSTL{
private:
    std::list<T> stack;
public:
    QueueSTL(){
    }
    bool push(T element){
        stack.push_back(element);
        return true;
    }
    bool pop(){
        stack.pop_front();
        return true;
    }
    void printQueue(){
        std::list<int>::iterator ptr;
        for(ptr = stack.begin(); ptr != stack.end(); ++ptr)
            cout<<"|"<<*ptr<<endl;
    }
};