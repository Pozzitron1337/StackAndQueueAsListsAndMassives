#include <iostream>
#include "list.h"
template<typename T>
class QueueAsList{
private:
    list<T>* head;
    list<T>* tail;
public:
    QueueAsList(){
        head=NULL;
        tail=NULL;
    }

    ~QueueAsList(){
        list<T>* temp;
        while(head){
            temp=head->next;
            delete head;
            head=temp;
        }
    }
    bool add(const T element){
        if(tail==NULL){
            head=(list<T>*)malloc(sizeof(list<T>));
            tail=head;
            tail->prev=NULL;
            tail->next=NULL;
            tail->element=element;
            return true;
        }else{
            list<T> *temp = (list<T>*)malloc(sizeof(list<T>));
            temp->prev=tail;
            temp->next=NULL;
            temp->element=element;
            tail->next=temp;
            tail=temp;
            return true;
        }
    }

    bool pop(){
        if(head==NULL)
            return false;
        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
            return true;
        }
        else{
            head=head->next;
            delete head->prev;
            head->prev=NULL;
            return true;
        }

    }
    void printQueue() {
        if (head == NULL){
            std::cout << "Queue is empty";
            return;
        }
        list<T>* temp=head;
        do{
            std::cout<<temp->element<<" ";
            temp=temp->next;
        }while(temp!=NULL);
    }
};
