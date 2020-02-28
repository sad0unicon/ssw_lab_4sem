//
// Created by Owner on 24.02.2020.
//

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
    void display();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    int count();//возврат количества элементов в структуре;
    T& at(int);//метод произвольного доступа к элементу
    void reverse();
    friend void swap(Vektor<T> &m1,Vektor<T> &m2) {
        T b = 0;
        if (m1.size==m2.size)
            for (int i = 0;i < m1.size;i++){
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

    friend bool operator ==(const Vektor<T> &m1, const Vektor<T> &m2) {
        if (m1.size == m2.size) {
            int i=0;
            do {
                if (m1.Buf[i] != m2.Buf[i]) return false;
                i++;
            } while ((m1.Buf[i] == m2.Buf[i])&&(i < m1.size));
            return true;
        };
        return false;
    };

    friend bool operator !=(const Vektor<T> &m1,const Vektor<T> &m2) {
        return !(m1 == m2);
    };

    friend bool operator > (const Vektor<T> &m1, const Vektor<T> &m2) {
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

    friend bool operator < (const Vektor<T> &m1,const Vektor<T> &m2) {
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

    friend bool operator <= (const Vektor<T> &m1, const Vektor<T> &m2) {
        return !(m1 > m2);
    };

    friend bool operator >= (const Vektor<T> &m1,const Vektor<T> &m2) {
        return !(m1 < m2);
    };
};
template <typename T>
Vektor<T>::~Vektor() {
    delete[] Buf;
};

template <typename T>
void Vektor<T>::display() {
    cout << "\nVyvod elements vecktor:\n";
    for (int i = 0; i < size; i++) cout << Buf[i] << "  ";
};

template <typename T>
void Vektor<T>::push(T b) {
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
void Vektor<T>::pop() {
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
T Vektor<T>::peek() {
    if (size > 0) {
        return Buf[0];
    }
    else throw std::out_of_range("vector is empty");
    return 0;
};

template <typename T>
int Vektor<T>::count() {
    return size;
};

template <typename T>
T& Vektor<T>::at(int i) {
    if ((i>=0)&&(i<size))
        return Buf[i];
    else throw std::out_of_range("out of range in vector");
};

template <typename T>
void Vektor<T>::reverse() {
    if (size > 0) {
        for (int i = 0; i < size / 2; i++) {
            T x = Buf[i];
            Buf[i] = Buf[size - 1 - i];
            Buf[size - 1 - i] = x;
        }
    }
    else throw std::out_of_range("vector is empty");
};
#endif //UNTITLED1_VEKTOR_H