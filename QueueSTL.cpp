#include <iostream>
#include <list>

using namespace std;

template<typename T>
class QueueSTL{
private:
    std::list<T> queue;
public:
    QueueSTL(){
    }
    bool push(T element){
        queue.push_back(element);
        return true;
    }
    T pop(){
        T popped = *(queue.begin());
        queue.pop_front();
        return popped;
    }
    void printQueue(){
        std::list<int>::iterator ptr;
        for(ptr = queue.begin(); ptr != queue.end(); ++ptr)
            cout<<"|"<<*ptr<<endl;
    }
    int getSize(){
        return queue.size();
    }
};