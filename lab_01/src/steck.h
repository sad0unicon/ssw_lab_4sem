//
// Created by Owner on 24.02.2020.
//

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
    void display();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    int count();//возврат количества элементов в структуре;
    void reverse();
    friend void swap(Stack<T> &m1,Stack<T> &m2) {
        T b = 0;
        if (m1.size==m2.size)
            for (int i = 0;i < m1.size;i++) {
                b = m1.Buf[i];
                m1.Buf[i] = m2.Buf[i];
                m2.Buf[i] = b;
            }
        if (m1.size > m2.size) {
            T *l;
            l = new T[m1.size];
            for (int i = 0;i < m1.size;i++)
                l[i] = m1.Buf[i];
            delete[] m1.Buf;
            m1.Buf = new T[m2.size];
            for (int i = 0;i < m2.size;i++)
                m1.Buf[i] = m2.Buf[i];
            delete[] m2.Buf;
            m2.Buf = new T[m1.size];
            m2.Buf = l;
        }
        if (m1.size < m2.size) {
            T *l;
            l = new T[m2.size];
            for (int i = 0;i < m2.size;i++)
                l[i] = m2.Buf[i];
            delete[] m2.Buf;
            m2.Buf = new T[m1.size];
            for (int i = 0;i < m1.size;i++)
                m2.Buf[i] = m1.Buf[i];
            delete[] m1.Buf;
            m1.Buf = new T[m2.size];
            m1.Buf = l;
        }
        int a = m1.size;
        m1.size = m2.size;
        m2.size = a;
    };

    friend bool operator ==(const Stack<T> &m1, const Stack<T> &m2) {
        if (m1.size == m2.size) {
            int i=0;
            do {
                if (m1.Buf[i] != m2.Buf[i]) return false;
                i++;
            }while ((m1.Buf[i] == m2.Buf[i])&&(i < m1.size));
            return true;
        };
        return false;
    };

    friend bool operator !=(const Stack<T> &m1,const Stack<T> &m2) {
        return !(m1 == m2);
    };

    friend bool operator > (const Stack<T> &m1, const Stack<T> &m2) {
        int i=0;
        if (m1.size>=m2.size) {
             do {
                if (m1.Buf[i] < m2.Buf[i]) return false;
                else if (m1.Buf[i] > m2.Buf[i]) return true;
                i++;
            } while ((m1.Buf[i] == m2.Buf[i])&&(i < m2.size));
            if (m1.size > m2.size) return true;
        }
        i = 0;
        if (m1.size < m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return false;
                else if (m1.Buf[i] > m2.Buf[i]) return true;
                i++;
            } while ((m1.Buf[i] == m2.Buf[i])&&(i < m1.size));
        }
        return false;
    };

    friend bool operator < (const Stack<T> &m1,const Stack<T> &m2) {
        int i = 0;
        if (m1.size > m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return true;
                else if (m1.Buf[i] > m2.Buf[i]) return false;
                i++;
            } while ((m1.Buf[i] == m2.Buf[i])&&(i < m2.size));
        }
        i = 0;
        if (m1.size <= m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return true;
                else if (m1.Buf[i] > m2.Buf[i]) return false;
                i++;
            } while ((m1.Buf[i] == m2.Buf[i])&&(i < m2.size));
            if (m1.size < m2.size) return true;
        }
        return false;
    };

    friend bool operator <= (const Stack<T> &m1, const Stack<T> &m2) {
        return !(m1 > m2);
    };

    friend bool operator >= (const Stack<T> &m1,const Stack<T> &m2) {
        return !(m1 < m2);
    };
};
template <typename T>
Stack<T>::~Stack() {
    delete[] Buf;
};

template <typename T>
void Stack<T>::display() {
    cout << "\nVyvod elements stack:\n";
    for (int i = size-1; i >= 0; i--) cout << endl << Buf[i];
};

template <typename T>
void Stack<T>::push(T b) {
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
void Stack<T>::pop() {
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
    if (size > 0) {
        return Buf[size-1];
    }
    else throw std::out_of_range("vector is empty");
    return 0;
};

template <typename T>
int Stack<T>::count() {
    return size;
};

template <typename T>
void Stack<T>::reverse() {
    if (size > 0) {
        for (int i = 0; i < size / 2; i++) {
            T x = Buf[i];
            Buf[i] = Buf[size - 1 - i];
            Buf[size - 1 - i] = x;
        }
    }
    else throw std::out_of_range("vector is empty");
};
#endif //UNTITLED1_STECK_H