#ifndef LABA2_1_RING_BUFFER_H
#define LABA2_1_RING_BUFFER_H
#include <iostream>
using namespace std;
template <typename T>
class RingBuffer {
private:
    class Element {
    public:
        T data { 0 };
        Element *Next { nullptr };
        Element (T data = T(), Element *Next = nullptr) {
            this->data = data;
            this->Next = Next;
        }
    };
    Element *head;
    Element *tail;
    int Size;
    int maxSize;
public:
    explicit RingBuffer(int nSize);
    RingBuffer(const std::initializer_list<T> &m);
    ~RingBuffer();
    void display();
    void push_back(T data);//добавление элемента в конец списка
    void pop_front();//удаление первого элемента в списке
    void insert(T data, int index);//добавление элемента в список по указанному индексу
    T* begin();
    T* end();
    int count() { return Size; }// получить количество елементов в списке
    void slijanie(RingBuffer<T> &m, RingBuffer<T> &m1);
    void razbienie(T k, RingBuffer<T> &m1, RingBuffer<T> &m2);

    void clear();
    bool operator ==(const RingBuffer<T> &m) {
        if (this->Size == m.Size) {
            Element *current1 = this->head;
            Element *current2 = m.head;
            while ((current1->Next != this->tail)&&(current2->Next != m.tail)) {
                if (current1->data != current2->data) return false;
                current1 = current1->Next;
                current2 = current2->Next;
            }
            if (current1->data != current2->data) return false;
            return true;
        }
        return false;
    };

    bool operator !=(const RingBuffer<T> &m) {
        return !(*this == m);
    };

    bool operator > (const RingBuffer<T> &m) {
        Element *current1 = this->head;
        Element *current2 = m.head;
        while ((current1->Next != this->tail)&&(current2->Next != m.tail)){
            if (current1->data < current2->data) return false;
            if (current1->data > current2->data) return true;
            current1 = current1->Next;
            current2 = current2->Next;
        }
        if (current1->data < current2->data) return false;
        if (current1->data > current2->data) return true;
        return (this->Size > m.Size);
    };

    bool operator <= (const RingBuffer<T> &m) {
        return !(*this > m);
    };

    bool operator >= (const RingBuffer<T> &m) {
        return ((*this > m)||(*this == m));
    };

    bool operator < (const RingBuffer<T> &m) {
        return !(*this >= m);
    };

    friend std::ostream& operator<< (std::ostream &out, const RingBuffer<T> &m){
        if (m.Size == 0) throw std::out_of_range("RingBuffer is empty");
        Element *current = m.head;
        int count = m.Size;
        out<<"( ";
        for (int i = 1; i < m.Size;i++){
            out<<current->data<<", ";
            current = current->Next;
            count--;
        }
        out<<current->data<<")";
        return out;
    }
};

template<typename T>
RingBuffer<T>::RingBuffer(int nSize) {
    if (nSize <= 0) throw std::out_of_range("size will be positive number");
    maxSize = nSize;
    head = new Element (0);
    Element *current = head;
    for (int i = 1; i<maxSize; i++){
        current->Next = new Element(0);
        current = current->Next;
    }
    current->Next = head;
    tail = head;
    Size = 0;
}

template<class T>
RingBuffer<T>::RingBuffer( const std::initializer_list<T> &m) {
    if (m.size() == 0) throw std::out_of_range("initializer list is empty");
    this->maxSize = m.size();
    this->Size = this->maxSize;
    head = new Element (m.begin()[0]);
    Element *current = head;
    for (int i = 1; i < maxSize; i++){
    current->Next = new Element(m.begin()[i]);
    current = current->Next;
    }
    tail = current;
    current->Next = head;
}
template<typename T>
RingBuffer<T>::~RingBuffer() {
    Element *current = head;
    Element *del = nullptr;
    while (Size > 0){
        del = current;
        current = current->Next;
        delete del;
        Size--;
    }
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void RingBuffer<T>::push_back(T data) {
    if (Size == 0) tail->data = data;
    else {
        if (tail->Next == head) head = head->Next;
        tail = tail->Next;
        tail->data = data;
    }
    if (Size < maxSize) Size++;
}

template<typename T>
void RingBuffer<T>::pop_front() {
    if (head == nullptr) throw std::out_of_range("list is empty");
    head = head->Next;
    Size--;
}

template<typename T>
void RingBuffer<T>::insert(T data, int index) {
    if ((index < 0)||(index >= Size)) throw std::out_of_range("index is more then size of list or will be positive number");
    Element *current = head;
    for (int i = 0; i < index ; i++){
        current = current->Next;
    }
    current->data = data;
}

template<typename T>
void RingBuffer<T>::display() {
    Element *current = this->head;
    cout << endl;
    for (int i=0;i<Size;i++){
        cout << current->data << " ";
        current = current->Next;
    }
}

template<typename T>
T *RingBuffer<T>::begin() {
    return &head->data;
}

template<typename T>
T *RingBuffer<T>::end() {
    return &tail->data;
}

template<typename T>
void RingBuffer<T>::slijanie(RingBuffer<T> &m, RingBuffer<T> &m1) {
    Element *current1 = this->head;
    Element *current2 = m.head;
    while ((current1->Next != this->tail)&&(current2->Next != m.tail)) {
        if (current1->data <= current2->data) {
            m1.push_back(current1->data);
            current1 = current1->Next;
        }
        if (current2->data < current1->data) {
            m1.push_back(current2->data);
            current2 = current2->Next;
        }
    }
    if (current1->data <= current2->data) {
        m1.push_back(current1->data);
        m1.push_back(current2->data);
    }
    else {
        m1.push_back(current2->data);
        m1.push_back(current1->data);
    }
    if ((current1->Next == this->tail)&&(current2->Next != m.tail)) {
        do {
            current2 = current2->Next;
            m1.push_back(current2->data);
            m1.display();
        } while (current2->Next != m.tail);
    }

    if ((current2->Next == this->tail)&&(current1->Next != m.tail)) {
        do{
            current1 = current1->Next;
            m1.push_back(current1->data);
            m1.display();
        } while (current1->Next != this->tail);
    }
}

template<typename T>
void RingBuffer<T>::razbienie(T k, RingBuffer<T> &m1, RingBuffer<T> &m2) {
    Element *current = this->head;
    while (current->Next != this->tail) {
        if (current->data < k) m1.push_back(current->data);
        else m2.push_back(current->data);
        current = current->Next;
    }
    if (current->data < k) m1.push_back(current->data);
    else m2.push_back(current->data);
}

#endif //LABA2_1_RING_BUFFER_H