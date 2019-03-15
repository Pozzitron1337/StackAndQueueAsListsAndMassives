#include <iostream>

#include "list.h"

template<typename T>
class StackAsList{
private:
    list<T>* stack;
    list<T>* top;
public:
    StackAsList(){
        stack = (list<T>*)malloc(sizeof(list<T>));
        stack->next=NULL;
        stack->prev=NULL;
        top=NULL;
    }
    ~StackAsList(){
        list<T>* temp;
        while(stack){
            temp=stack->next;
            delete stack;
            stack=temp;
        }
        delete top;
    }
    bool push(const T element){
        if(top==NULL) {
            top=stack;
            top->element=element;
            return true;
        }else {
            list<T> *temp = (list<T>*)malloc(sizeof(list<T>));
            temp->prev = top;
            temp->next = NULL;
            top->next = temp;
            top = temp;
            top->element = element;
            return true;
        }
    }
    T getTopElement(){
        if(top==NULL)
            return (T)'\0';
        else
            return top->element;
    }

    bool pop(){
        if(top==NULL){
            return false;
        }
        if(top==stack){
            top=NULL;
            return true;
        }
        else{
            list<T>* temp=top;
            top=top->prev;
            top->next=NULL;
            delete temp;
            return true;
        }
    }
    bool isEmpty(){
        return (top==NULL)?true:false;
    };
    bool clear(){
        while(top!=NULL)
            pop();
        return true;
    }
    void printStack(){
        list<T>* iterator=top;
        if(iterator==NULL) {
            std::cout<<"Stack is empty."<<std::endl;
            return;
        }
        while (iterator!=NULL){
            std::cout<<"|"<<iterator->element<<std::endl;
            iterator=iterator->prev;
        }
    }
};