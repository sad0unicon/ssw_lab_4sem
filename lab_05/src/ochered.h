#ifndef UNTITLED1_OCHERED_H
#define UNTITLED1_OCHERED_H
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
    T *Buf;
    int size;
public:
    explicit Queue() {
        size = 0;
        Buf = new T[0];
    };
    ~Queue();
    void push_back(T); //вставка элемента в структуру;
    void pop_front();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
};
template <typename T>
Queue<T>::~Queue() {
    delete[] Buf;
};

template <typename T>
void Queue<T>::push_back(T b) {
    T *l;
    l = new T[size + 1];
    l[size] = b;
    for (int i = 0; i < size; i++)
        l[i] = Buf[i];
    delete[] Buf;
    size++;
    Buf = l;
};

template <typename T>
void Queue<T>::pop_front() {
    if (size > 0) {
        T *t;
        t = new T[size - 1];
        for (int i = 1; i < size; i++)
            t[i - 1] = Buf[i];
        delete[] Buf;
        size--;
        Buf = t;
    }
    else throw std::out_of_range("Queue is empty");
};

template <typename T>
T Queue<T>::peek() {
    if (size > 0) return Buf[0];
    else throw std::out_of_range("Queue is empty");
};
#endif //UNTITLED1_OCHERED_H