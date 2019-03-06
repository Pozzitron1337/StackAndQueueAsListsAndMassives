#include <iostream>
template<typename T>
class QueueAsMassive {
private:
    T *queue;
    int size;
    int last;
public:
    QueueAsMassive(int s=10) {
        size = s > 0 ? s: 10;
        queue = new T[size];
        last=-1;
    }
    ~QueueAsMassive() {
        delete[] queue;
    }
    bool add(const T element){
        if(last<size) {
            last++;
            queue[last] = element;
            return true;
        } else {
            std::cout<<" Queque overflow."<<std::endl;
            return true;
        }

    }
    bool pop() {
        if(last==0) {
            queue[0] = '\0';
            last--;
            return true;
        }
        if(last>0){
        for(int i=0;i<last;i++)
            queue[i]=queue[i+1];

            last--;
            return true;
        }
    }
    void printQueue(){
        if(last==-1) {
            std::cout<<"Queue is empty."<<std::endl;
            return;
        }
        for (int i = 0; i<= last; i++)
            std::cout << "|"  << queue[i] << std::endl;
    }
};
