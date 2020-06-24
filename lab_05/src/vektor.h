#ifndef UNTITLED1_VEKTOR_H
#define UNTITLED1_VEKTOR_H
#include <iostream>
using namespace std;
template <typename T>
class Vektor {
private:
    T *Buf;
    int size;
public:
    Vektor() {
        size = 0;
        Buf = new T[0];
    };
    ~Vektor();
    void push_back(T); //вставка элемента в структуру;
    void pop_back();  //выталкивание элемента из структуры;
    T& at(int);//метод произвольного доступа к элементу
};
template <typename T>
Vektor<T>::~Vektor() {
    delete[] Buf;
};

template <typename T>
void Vektor<T>::push_back(T b) {
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
void Vektor<T>::pop_back() {
    if (size > 0) {
        T *t;
        t = new T[size - 1];
        for (int i = 0; i < size - 1; i++)
            t[i] = Buf[i];
        delete[] Buf;
        Buf = t;
        size--;
    }
    else throw std::out_of_range("vector is empty");;
};

template <typename T>
T& Vektor<T>::at(int i) {
    if ((i>=0)&&(i<size)) return Buf[i];
    else throw std::out_of_range("out of range in vector");
};
#endif //UNTITLED1_VEKTOR_H