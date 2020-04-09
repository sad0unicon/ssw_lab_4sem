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
        explicit Element (T value = T(), Element *next = nullptr) : data { value }, Next { next } {}
    };
    Element *head { nullptr };
    Element *tail { nullptr };
    int Size { 0 };
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
    void slijanie(RingBuffer<T> &List1, RingBuffer<T> &List2);
    void razbienie(T k, RingBuffer<T> &rezult1, RingBuffer<T> &rezult2);

    bool operator ==(const RingBuffer<T> &m) {
        if ((this->Size == 0)&&(m.Size == 0)) throw std::out_of_range("RingBuffers are empty");
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
        if ((this->Size == 0)&&(m.Size == 0)) throw std::out_of_range("RingBuffers are empty");
        Element *current1 = this->head;
        Element *current2 = m.head;
        T value1 = current1->data;
        T value2 = current2->data;
        while ((current1->Next != this->tail)&&(current2->Next != m.tail)){
            if (value1 < value2) return false;
            if (value1 > value2) return true;
            current1 = current1->Next;
            current2 = current2->Next;
            value1 = current1->data;
            value2 = current2->data;
        }
        if (value1 < value2) return false;
        if (value1 >  value2) return true;
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
    for (int i = 1; i < maxSize; i++){
        current->Next = new Element(0);
        current = current->Next;
    }
    current->Next = head;
    tail = head;
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
    while (maxSize > 0){
        del = current;
        current = current->Next;
        delete del;
        maxSize--;
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
void RingBuffer<T>::slijanie(RingBuffer<T> &List1, RingBuffer<T> &List2) {
    Element *current1 = List1.head;
    Element *current2 = List2.head;
    int k1 = 0;
    int k2 = 0;
    while ((k1 != List1.Size)&&(k2 != List2.Size)) {
        if (current1->data <= current2->data) {
            this->push_back(current1->data);
            k1++;
            if (k1 != List1.Size) current1 = current1->Next;
        }
        if (current2->data < current1->data) {
            this->push_back(current2->data);
            k2++;
            if (k2 != List2.Size) current2 = current2->Next;
        }
    }

    if ((k1 == List1.Size)&&(k2 != List2.Size)) {
        while (k2 != List2.Size) {
            this->push_back(current2->data);
            k2++;
            if (k2 != List2.Size) current2 = current2->Next;
        }
    }

    if ((k2 == List2.Size)&&(k1 != List1.Size)) {
        while (k1 != List1.Size) {
            this->push_back(current1->data);
            k1++;
            if (k1 != List1.Size) current1 = current1->Next;
        }
    }
}

template<typename T>
void RingBuffer<T>::razbienie(T k, RingBuffer<T> &rezult1, RingBuffer<T> &rezult2) {
    Element *current = this->head;
    int l = 0;
    while (l != this->Size) {
        if (current->data < k) rezult1.push_back(current->data);
        else rezult2.push_back(current->data);
        current = current->Next;
        l++;
    }
}
#endif //LABA2_1_RING_BUFFER_H