#ifndef LABA2_1_TWOLIST_H
#define LABA2_1_TWOLIST_H
#include <iostream>
using namespace std;
template <typename T>
class twoList {
private:
    class Element {
    public:
        T data { 0 };
        Element *Next { nullptr };
        Element *Prev { nullptr };
        explicit Element (T value = T(), Element *next = nullptr, Element *prev = nullptr) : data { value },Next { next }, Prev { prev } {}
    };
    Element *head { nullptr };
    Element *tail { nullptr };
    int Size { 0 };
public:
    twoList() = default;
    ~twoList();
    void push_front(T);//добавление элемента в начало списка
    void push_back(T);//добавление элемента в конец списка
    void pop_front();//удаление первого элемента в списке
    void pop_back();//удаление последнего элемента в списке
    T* find(T);
    void clear();
};

template <typename T>
twoList<T>::~twoList() {
    clear();
}
template<typename T>
void twoList<T>::clear() {
    while (Size)
        pop_front();
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void twoList <T>::push_front(T data) {
    if (Size > 0) {
        Element *temp = head;
        head = new Element (data, head);
        temp->Prev = head;
    }
    else {
        head = new Element(data, head, tail);
        tail = head;
    }
    Size++;
}

template <typename T>
void twoList <T>::push_back(T data) {
    if (Size > 0) {
        Element *temp = tail;
        tail = new Element (data, nullptr, tail);
        temp->Next = tail;
    }
    else {
        head = new Element(data, head, tail);
        tail = head;
    }
    Size++;
}

template <typename T>
void twoList <T>::pop_front() {
    if (Size == 0) throw std::out_of_range("two list is empty");
    Element *temp = head;
    head = head->Next;
    delete temp;
    Size--;
}

template <typename T>
void twoList <T>::pop_back() {
    if (Size == 0) throw std::out_of_range("two list is empty");
    if (Size == 1){
        pop_front();
    }
    else {
        Element *temp = tail;
        tail = tail->Prev;
        delete temp;
        Size--;
    }
}

template<class T>
T *twoList<T>::find(T data) {
    Element* current = head;
    while (current->Next != nullptr){
        if(current->data == data)
            return &current->data;
        current = current->Next;
    }
    if (current->data == data) return &current->data;
    else throw std::out_of_range("list haven't el-t with this value");
}
#endif //LABA2_1_TWOLIST_H