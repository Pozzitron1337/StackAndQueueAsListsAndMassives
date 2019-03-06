#include <iostream>
template<typename T>
class StackAsMassive {
private:
    T *stack; // указатель на стек
    int size; // размер стека
    int top; // вершина стека
public:
    StackAsMassive(int s=10)// по умолчанию размер стека равен 10 элементам
    {
        size = s > 0 ? s: 10;   // инициализировать размер стека
        stack = new T[size]; // выделить память под стек
        top = -1; // значение -1 говорит о том, что стек пуст
    }
    ~StackAsMassive() // деструктор
    {
        delete[] stack;//
    }
    bool push(const T element) // поместить элемент в стек
    {
        if (top == size - 1) {
            std::cout<<"Stack is overflow."<<std::endl;
            return false; // стек полон
        }else{
        top++;                //увеличиваем индекс вершины
        stack[top] = element; // помещаем элемент в стек
        return true;          //элемент добавлен
        }
    }
    bool pop() // удалить из стека элемент
    {
        if (top == - 1)
            return false; // стек пуст

        stack[top] = 0; // удаляем элемент из стека
        top--;          // уменьшаем индекс вершины
        return true;    // элемент удалён
    }
    void printStack(){//вывести стек в консоль
        if(top==-1) {
            std::cout<<"Stack is empty."<<std::endl;
            return;
        }
        for (int i = top; i>= 0; i--)
            std::cout << "|"  << stack[i] << std::endl;
    }
};