#include <iostream>
template<typename T>
class StackX2InMassive {
private:
    T *stack;
    int size;
    int topleft;
    int topright;
public:
    StackX2InMassive(int s=10)// по умолчанию размер стека равен 10 элементам
    {
        size = s > 0 ? s: 10;
        stack = new T[size];
        topleft = -1;  //leftstack is empty
        topright=size; //righth queue is empty
    }
    ~StackX2InMassive() // деструктор
    {
        delete[] stack;
    }
    bool pushleft(const T element){
        topleft++;
         if(topleft!=topright) {
             stack[topleft]=element;
             return true;
         }else{
             topleft--;
             std::cout<<"Overflow left queue."<<"Cannot add element: "<<element<<std::endl;
             return false;
         }

    }
    bool pushright(const T element){
        topright--;
        if(topright!=topleft){
            stack[topright]=element;
            return true;
        }else{
            topright++;
            std::cout<<"Overflow left queue."<<"Cannot add element: "<<element<<std::endl;
            return false;
        }

    }
    bool popleft() {
        if(topleft==-1)
            return false;
        else{
            stack[topleft]='\0';
            topleft--;
            return true;
        }
    }
    bool popright(){
        if(topright==size)
            return false;
        else{
            stack[topright]='\0';
            topright++;
            return true;
        }
    }
    void printLeftStack(){
        if(topleft==-1) {
            std::cout<<"Left queue is empty."<<std::endl;
            return;
        }
        for (int i = topleft; i>= 0; i--)
            std::cout << "|"  << stack[i] << std::endl;
    }
    void printRightStack(){
        if(topright==size) {
            std::cout<<"Right queue is empty."<<std::endl;
            return;
        }
        for (int i = topright; i<size ; i++)
            std::cout << "|"  << stack[i] << std::endl;
    }
};
