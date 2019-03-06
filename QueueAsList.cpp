#include <iostream>
#include "list.h"
template<typename T>
class QueueAsList{
private:
    list<T>* head;
    list<T>* tail;
public:
    QueueAsList(){
        head = (list<T>*)malloc(sizeof(list<T>));
        tail=head;
        head->next=NULL;
        head->prev=NULL;
        head->element='\0';
    }
    QueueAsList(T element){
        head = (list<T>*)malloc(sizeof(list<T>));
        head=head;
        tail=head;
        head->next=NULL;
        head->prev=NULL;
        head->element=element;
    }
    ~QueueAsList(){
        delete head;
    }
    bool add(const T element){
        if(tail->element=='\0') {
            tail->element=element;
            return true;
        } else {
            list<T> *temp = (list<T> *) malloc(sizeof(list<T>));
            temp->prev = tail;
            tail->next = temp;
            temp->next = NULL;
            temp->element = element;
            tail = temp;
            return true;
        }
    }

    bool pop(){
        if(head->next!=NULL){
            head=head->next;
            free(head->prev);
            return true;
        }else{
            head->element='\0';
            return true;
        }
    }
    void printQueue(){
        if(head->element=='\0') {
            std::cout<<"Queue is empty."<<std::endl;
            return;
        }
        else{
            list<T>* iterator=head;
            while(iterator!=NULL) {
                std::cout << "|" << iterator->element << std::endl;
                iterator=iterator->next;
            }
            return;
        }
    }
};
