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
        top=stack;
        stack->next=NULL;
        stack->prev=NULL;
        stack->element='\0';
    }
    StackAsList(T element){
        stack = (list<T>*)malloc(sizeof(list<T>));
        top=stack;
        stack->next=NULL;
        stack->prev=NULL;
        stack->element=element;
    }
    ~StackAsList(){
        delete stack;
    }
    bool push(const T element){
        if(top->element=='\0') {
            top->element=element;
            return true;
        }
        list<T>* temp=(list<T>*)malloc(sizeof(list<T>));
        temp->prev=top;
        temp->next=NULL;
        top->next=temp;
        top=temp;
        temp->element=element;
        return true;
    }
    T getTopElement(){
        return top->element;
    }

    bool pop(){
        if(top!=stack){
            top=top->prev;
            free(top->next);
            top->next=NULL;
            return true;
        }
        else{
            top->element='\0';
            return false;
        }
    }
    bool isEmpty(){
        if(stack->element=='\0')
            return true;
        else return false;
    };
    bool clear(){
        while(top!=stack)
            pop();
        pop();
        return true;
    }
    void printStack(){
        list<T>* iterator=top;
        if(iterator->element=='\0')
        {
            std::cout<<"Stack is empty."<<std::endl;
            return;
        }
        while (iterator!=NULL){
            std::cout<<"|"<<iterator->element<<std::endl;
            iterator=iterator->prev;
        }
    }
};
