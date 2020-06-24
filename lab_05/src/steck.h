#ifndef UNTITLED1_STECK_H
#define UNTITLED1_STECK_H
#include <iostream>
using namespace std;
template <typename T>
class Stack {
private:
    T *Buf;
    int size;
public:
    Stack() {
        size = 0;
        Buf = new T[0];
    };
    ~Stack();
    void push_back(T); //вставка элемента в структуру;
    void pop_back();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
};
template <typename T>
Stack<T>::~Stack() {
    delete[] Buf;
};

template <typename T>
void Stack<T>::push_back(T b) {
    T *l;
    l = new T[size + 1];
    for (int i = 0; i < size; i++)
        l[i] = Buf[i];
    l[size] = b;
    delete[] Buf;
    size++;
    Buf = l;
};

template <typename T>
void Stack<T>::pop_back() {
    if (size > 0) {
        T *t;
        t = new T[size - 1];
        for (int i = 0; i < size - 1; i++)
            t[i] = Buf[i];
        delete[] Buf;
        Buf = t;
        size--;
    }
    else throw std::out_of_range("stack is empty");
};

template <typename T>
T Stack<T>::peek() {
    if (size > 0) return Buf[size-1];
    else throw std::out_of_range("stack is empty");
    return 0;
};
#endif //UNTITLED1_STECK_H