//
// Created by Owner on 24.02.2020.
//

#ifndef UNTITLED1_OCHERED_H
#define UNTITLED1_OCHERED_H
template <typename T>
class Queue
{
private:
    T *Buf;
    int size;
public:
    explicit Queue() {
        size = 0;
        Buf = new T[0];
    };
    ~Queue();
    void display();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    int count();//возврат количества элементов в структуре;
    void reverse();
    friend void swap(Queue<T> &m1,Queue<T> &m2)
    {
        T b = 0;
        if (m1.size==m2.size)
            for (int i = 0;i < m1.size;i++){
                b = m1.Buf[i];
                m1.Buf[i] = m2.Buf[i];
                m2.Buf[i] = b;
            }
        if (m1.size > m2.size){
            T *l;
            l = new T[m1.size];
            for (int i = 0;i < m1.size;i++)
                l[i] = m1.Buf[i];
            delete[] m1.Buf;
            for (int i = 0;i < m1.size;i++)
                m1.Buf[i] = m2.Buf[i];
            delete[] m2.Buf;
            m2.Buf = l;
        }
        if (m1.size < m2.size){
            T *l;
            l = new T[m2.size];
            for (int i = 0;i < m2.size;i++)
                l[i] = m2.Buf[i];
            delete[] m2.Buf;
            for (int i = 0;i < m2.size;i++)
                m2.Buf[i] = m1.Buf[i];
            delete[] m1.Buf;
            m1.Buf = l;
        }
        int a = m1.size;
        m1.size = m2.size;
        m2.size = a;
    };
    friend bool operator ==(const Queue<T> &m1, const Queue<T> &m2) {
        if (m1.size == m2.size)
        {
            for (int i = 0; i < m1.size; i++) {
                if (m1.Buf[i] != m2.Buf[i])
                    return false;
            }
            return true;
        };
        return false;
    };
    friend bool operator !=(const Queue<T> &m1,const Queue<T> &m2) {
        return !(m1 == m2);
    };
    friend bool operator > (const Queue<T> &m1, const Queue<T> &m2) {
        int i=0;
        if (m1.size>=m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return false;
                else if (m1.Buf[i] > m2.Buf[i]) return true;
                i++;
            }while ((m1.Buf[i] == m2.Buf[i])&&(i < m2.size));
            if (m1.size > m2.size) return true;
        }
        i = 0;
        if (m1.size < m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return false;
                else if (m1.Buf[i] > m2.Buf[i]) return true;
                i++;
            }while ((m1.Buf[i] == m2.Buf[i])&&(i < m1.size));
        }
        return false;
    };
    friend bool operator < (const Queue<T> &m1,const Queue<T> &m2) {
        int i = 0;
        if (m1.size > m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return true;
                else if (m1.Buf[i] > m2.Buf[i]) return false;
                i++;
            }while ((m1.Buf[i] == m2.Buf[i])&&(i < m2.size));
        }
        i = 0;
        if (m1.size <= m2.size) {
            do {
                if (m1.Buf[i] < m2.Buf[i]) return true;
                else if (m1.Buf[i] > m2.Buf[i]) return false;
                i++;
            }while ((m1.Buf[i] == m2.Buf[i])&&(i < m2.size));
            if (m1.size < m2.size) return true;
        }
        return false;
    };
    friend bool operator <= (const Queue<T> &m1, const Queue<T> &m2) {
        return !(m1 > m2);
    };
    friend bool operator >= (const Queue<T> &m1,const Queue<T> &m2) {
        return !(m1 < m2);
    };
};
template <typename T>
Queue<T>::~Queue()
{
    delete[] Buf;
};
template <typename T>
void Queue<T>::display()
{
    cout << "\nVyvod elements otcheredi:\n";
    for (int i = 0; i < size; i++) cout << Buf[i] <<"  ";
};
template <typename T>
void Queue<T>::push(T b)
{
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
void Queue<T>::pop()
{
    if (size > 0) {
        T *t;
        t = new T[size - 1];
        for (int i = 1; i < size; i++)
            t[i - 1] = Buf[i];
        delete[] Buf;
        size--;
        Buf = t;
    }
    cout << "\nerror\n";
};
template <typename T>
T Queue<T>::peek()
{
    if (size > 0) {
        return Buf[0];
    }
    cout << "\nerror\n";
    return 0;
};
template <typename T>
int Queue<T>::count()
{
    return size;
};
template <typename T>
void Queue<T>::reverse()
{
    if (size > 0) {
        for (int i = 0; i < size / 2; i++) {
            T x = Buf[i];
            Buf[i] = Buf[size - 1 - i];
            Buf[size - 1 - i] = x;
        }
    }
    cout << "\nerror\n";
};
#endif //UNTITLED1_OCHERED_H
