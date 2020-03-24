#ifndef LABA2_1_TWOLIST_H
#define LABA2_1_TWOLIST_H
#include <iostream>
using namespace std;
template <typename T>
class twoList {
public:
    twoList();
    ~twoList();
    void display();
    void push_front(T data);//добавление элемента в начало списка
    void push_back(T data);//добавление элемента в конец списка
    void pop_front();//удаление первого элемента в списке
    void pop_back();//удаление последнего элемента в списке
    void insert(T data, int index);//добавление элемента в список по указанному индексу
    void erase(int index);//удаление элемента в списке по указанному индексу
    T* begin();
    T* end();
    int count() { return Size; }// получить количество елементов в списке
    void slijanie(twoList<T> &m, twoList<T> &m1);
    void razbienie(T k, twoList<T> &m1, twoList<T> &m2);
    bool operator ==(const twoList<T> &m) {
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

    bool operator !=(const twoList<T> &m) {
        return !(*this == m);
    };

    bool operator > (const twoList<T> &m) {
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

    bool operator <= (const twoList<T> &m) {
        return !(*this > m);
    };

    bool operator >= (const twoList<T> &m) {
        return ((*this > m)||(*this == m));
    };

    bool operator < (const twoList<T> &m) {
        return !(*this >= m);
    };
    void clear();
private:
    template <typename T>
    class Element {
    public:
        T data;
        Element *Next;
        Element *Prev;
        Element (T data = T(), Element *Next = nullptr, Element *Prev = nullptr) {
            this->data = data;
            this->Next = Next;
            this->Prev = Prev;
        }
    };
    Element <T> *head;
    Element <T> *tail;
    int Size;
};

template <typename T>
twoList <T>::twoList() {
    head = nullptr;
    tail = nullptr;
    Size = 0;
}

template <typename T>
twoList<T>::~twoList() {
    while (Size)
        pop_front();
}

template <typename T>
void twoList<T>::clear() {
    while (Size)
        pop_front();
}

template<typename T>
void twoList<T>::display() {
    Element <T> *print = head;
    while (print->Next != nullptr) {
        cout << print->data << " ";
        print = print->Next;
    }
    cout << print->data << " ";
}

template <typename T>
void twoList <T>::push_front(T data) {
    if (Size > 0) {
        Element <T> *temp = head;
        head = new Element <T>(data, head);
        temp->Prev = head;
    }
    else head = tail = new Element <T>(data, head, tail);
    Size++;
}

template <typename T>
void twoList <T>::push_back(T data) {
    if (Size > 0) {
        Element <T> *temp = tail;
        tail = new Element <T>(data, nullptr, tail);
        temp->Next = tail;
    }
    else head = tail = new Element <T>(data, head, tail);
    Size++;
}

template <typename T>
void twoList <T>::pop_front() {
    Element <T> *temp = head;
    head = head->Next;
    delete temp;
    Size--;
}

template <typename T>
void twoList <T>::pop_back() {
    Element <T> *temp = tail;
    tail = tail->Prev;
    tail->Next = nullptr;
    delete temp;
    Size--;
}

template <typename T>
void twoList <T>::insert(T data, int index) {
    if (index == 0) push_front(data);
    else if (index == Size) push_back(data);
    if (index <= Size / 2) {
        Element<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->Next;
        Element<T> *newElement = new Element<T>(data, previous->Next, previous);
        previous->Next = newElement;
        Element<T> *next = newElement->Next;
        next->Prev = newElement;
        Size++;
    }
    if (index > Size / 2) {
        Element<T> *next = this->tail;
        for (int i = Size - 1; index < i; i--)
            next = next->Prev;
        Element<T> *newElement = new Element<T>(data, next, next->Prev);
        next->Prev = newElement;
        Element<T> *previous = newElement->Prev;
        previous->Next = newElement;
        Size++;
    }
}

template <typename T>
void twoList <T>::erase(int index) {
    if (index == 0) pop_front();
    else if (index == Size - 1) pop_back();
    if (index <= Size / 2) {
        Element<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->Next;
        Element<T> *delElement = previous->Next;
        previous->Next = delElement->Next;
        Element<T> *next = delElement->Next;
        delete delElement;
        next->Prev = previous;
        Size--;
    }
    if (index > Size / 2) {
        Element<T> *next = this->tail;
        for (int i = Size - 1; index + 1 < i; i--)
            next = next->Prev;
        Element<T> *delElement = next->Prev;
        next->Prev = delElement->Prev;
        Element<T> *previous = delElement->Prev;
        delete delElement;
        previous->Next = next;
        Size--;
    }
}

template<typename T>
T *twoList<T>::begin() {
    return &head->data;
}

template<typename T>
T *twoList<T>::end() {
    return &tail->data;
}

template<typename T>
void twoList<T>::slijanie(twoList<T> &m, twoList<T> &m1) {
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
        } while (current2->Next != nullptr);
    }
    if ((current2->Next == nullptr)&&(current1->Next != nullptr)) {
        do{
            current1 = current1->Next;
            m1.push_back(current1->data);
        } while (current1->Next != nullptr);
    }
    this->clear();
    m.clear();
}

template<typename T>
void twoList<T>::razbienie(T k, twoList<T> &m1, twoList<T> &m2) {
    Element<T> *current = this->head;
    while (current->Next != nullptr) {
        if (current->data < k) m1.push_back(current->data);
        else m2.push_back(current->data);
        current = current->Next;
    }
    if (current->data < k) m1.push_back(current->data);
    else m2.push_back(current->data);
}
#endif //LABA2_1_TWOLIST_H