#ifndef LABA2_1_RING_BUFFER_H
#define LABA2_1_RING_BUFFER_H
#include <iostream>
using namespace std;
template <typename T>
class RingBuffer {
public:
    explicit RingBuffer(int nSize);
    ~RingBuffer();
    void display();
    void push_back(T data);//добавление элемента в конец списка
    void pop_front();//удаление первого элемента в списке
    void insert(T data, int index);//добавление элемента в список по указанному индексу
    void erase(int index);//удаление элемента в списке по указанному индексу
    T* begin();
    T* end();
    int count() { return Size; }// получить количество елементов в списке
    void slijanie(RingBuffer<T> &m, RingBuffer<T> &m1);
    void razbienie(T k, RingBuffer<T> &m1, RingBuffer<T> &m2);

    void clear();
    bool operator ==(const RingBuffer<T> &m) {
        if (this->Size == m.Size) {
            Element<T> *current1 = this->head;
            Element<T> *current2 = m.head;
            while (current1->Next != nullptr) {
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
        Element<T> *current1 = this->head;
        Element<T> *current2 = m.head;
        while ((current1->Next != nullptr)&&(current2->Next != nullptr)){
            if (current1->data < current2->data) return false;
            else if (current1->data > current2->data) return true;
            current1 = current1->Next;
            current2 = current2->Next;
        }
        if (current1->data < current2->data) return false;
        else if (current1->data > current2->data) return true;
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
private:
    template <typename T>
    class Element {
    public:
        T data;
        Element *Next;
        Element (T data = T(), Element *Next = nullptr) {
            this->data = data;
            this->Next = Next;
        }
    };
    Element <T> *head;
    int Size;
    int maxSize;
};

template<typename T>
RingBuffer<T>::RingBuffer(int nSize) {
    head = nullptr;
    maxSize = nSize;
    Size = 0;
}

template<typename T>
RingBuffer<T>::~RingBuffer() {
    while (Size)
        pop_front();
}

template <typename T>
void RingBuffer<T>::clear() {
    while (Size)
        pop_front();
}

template<typename T>
void RingBuffer<T>::push_back(T data) {
    if (head == nullptr) head = new Element<T>(data);
    else {
        if (Size < maxSize) {
            Element<T> *current = this->head;
            while (current->Next != nullptr)
                current = current->Next;
            current->Next = new Element<T>(data);
        }
        else {
            erase (Size - 1);
            head = new Element<T>(data, head);
        }
    }
    Size++;
}

template<typename T>
void RingBuffer<T>::pop_front() {
    if (head == nullptr) throw std::out_of_range("list is empty");
    Element<T> *t = head;
    head = head->Next;
    delete t;
    Size--;
}

template<typename T>
void RingBuffer<T>::insert(T data, int index) {
    if ((index < 0)||(index > Size)) throw std::out_of_range("index is more then size of list");
    if (index == 0) {
        head = new Element<T>(data, head);
        Size++;
    }
    else {
        Element<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->Next;
        Element<T> *newElement = new Element<T>(data, previous->Next);
        previous->Next = newElement;
        Size++;
        if (Size >= maxSize) {
            Element<T> *current = this->head;
            while (current->Next != nullptr)
                current = current->Next;
            T a = current->data;
            erase (Size - 1);
            erase (Size - 1);
            head = new Element<T>(a, head);
            Size++;
        }
    }
}

template<typename T>
void RingBuffer<T>::erase (int index) {
    if ((index < 0)||(index >= Size)) throw std::out_of_range("index is more then size of list");
    if (index == 0) pop_front();
    else {
        Element<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->Next;
        Element<T> *delElement= previous->Next;
        previous->Next = delElement->Next;
        delete delElement;
        Size--;
    }
}

template<typename T>
void RingBuffer<T>::display() {
    Element<T> *current = this->head;
    cout << endl;
    while (current->Next != nullptr) {
        cout << current->data << " ";
        current = current->Next;
    }
    cout << current->data << " ";
}

template<typename T>
T *RingBuffer<T>::begin() {
    return &head->data;
}

template<typename T>
T *RingBuffer<T>::end() {
    Element<T> *current = this->head;
    while (current->Next != nullptr)
        current = current->Next;
    return &current->data;
}

template<typename T>
void RingBuffer<T>::slijanie(RingBuffer<T> &m, RingBuffer<T> &m1) {
    Element<T> *current1 = this->head;
    Element<T> *current2 = m.head;
    while ((current1->Next != nullptr)&&(current2->Next != nullptr)) {
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
    if ((current1->Next == nullptr)&&(current2->Next != nullptr)) {
        do {
            current2 = current2->Next;
            m1.push_back(current2->data);
            m1.display();
        } while (current2->Next != nullptr);
    }

    if ((current2->Next == nullptr)&&(current1->Next != nullptr)) {
        do{
            current1 = current1->Next;
            m1.push_back(current1->data);
            m1.display();
        } while (current1->Next != nullptr);
    }
    this->clear();
    m.clear();
}

template<typename T>
void RingBuffer<T>::razbienie(T k, RingBuffer<T> &m1, RingBuffer<T> &m2) {
    Element<T> *current = this->head;
    while (current->Next != nullptr) {
        if (current->data < k) m1.push_back(current->data);
        else m2.push_back(current->data);
        current = current->Next;
    }
    if (current->data < k) m1.push_back(current->data);
    else m2.push_back(current->data);
}

#endif //LABA2_1_RING_BUFFER_H