#include <iostream>
template<typename T>
class QueueAsMassive {
private:
    T *queue;           //massive
    unsigned int size;  //size of massive
    int head;           //pointer on head of queue
    int tail;           //pointer on tail of queue
public:
    QueueAsMassive(int s=10)
    {
        size = s > 0 ? s: 10;
        queue = new T[size];
        head=-1;//queue is empty
        tail=0;
    }
    ~QueueAsMassive()
    {
        delete[] queue;
    }
    bool add(const T element)
    {
        if(tail==-1) //if queue is full
            return false;
        if(head==-1){
            queue[tail]=element;
            head=tail;
            tail=(tail+1)%size;
            return true;
        }else{
            queue[tail]=element;
            tail=(tail+1)%size;
            if(tail==head)
                tail=-1;
            return true;
        }

    }
    T pop()
    {
        if(head==-1)
            return (T)'\0';//queue empty

        if(tail==-1){
            T x=queue[head];
            tail=head;
            head=(head+1)%size;
            return x;
        }
        else{
            T x=queue[head];
            head=(head+1)%size;
            if(head==tail)
                head=-1;
            return x;
        }
    }
    void clear()
    {
        head=-1;
        tail=0;

    }
    bool isEmpty()
    {
        return head==-1?true:false;
    }
    void printQueue()
    {
        if(head==-1) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        unsigned int temp=(tail==-1)?temp=(head+size)%size: temp=tail;
        unsigned int it=head;
        do{
            std::cout<<queue[it]<<" ";
            it=(it+1)%size;
        }while(it!=temp);
    }
};
