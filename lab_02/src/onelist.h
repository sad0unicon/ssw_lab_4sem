#ifndef LABA2_1_ONELIST_H
#define LABA2_1_ONELIST_H
#include <iostream>
using namespace std;
template<typename T>
class oneList{
private:
    class Element {
    public:
        Element * Next { nullptr };
        T data { 0 };
        explicit Element(T value = T(), Element *next = nullptr) : data { value }, Next { next } {}
    };
    int Size { 0 };
    Element *head { nullptr };
public:
    oneList() = default;
    oneList(const std::initializer_list<T> &m);
    ~oneList();
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
    void slijanie(oneList<T> &List1, oneList<T> &List2);
    void razbienie(T k, oneList<T> &rezult1, oneList<T> &rezult2);

    bool operator ==(const oneList<T> &m) {
        if ((this->Size == 0)&&(m.Size == 0)) throw std::out_of_range("Lists are empty");
        if (this->Size == m.Size) {
            Element *current1 = this->head;
            Element *current2 = m.head;
            while ((current1->Next != nullptr)&&(current2->Next != nullptr)) {
                if (current1->data != current2->data) return false;
                current1 = current1->Next;
                current2 = current2->Next;
            }
            if (current1->data != current2->data) return false;
            return true;
        }
        return false;
    };

    bool operator !=(const oneList<T> &m) {
        return !(*this == m);
    };

    bool operator > (const oneList<T> &m) {
        if ((this->Size == 0)&&(m.Size == 0)) throw std::out_of_range("Lists are empty");
        Element *current1 = this->head;
        Element *current2 = m.head;
        T value1 = current1->data;
        T value2 = current2->data;
        while ((current1->Next != nullptr)&&(current2->Next != nullptr)){
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

    bool operator <= (const oneList<T> &m) {
        return !(*this > m);
    };

    bool operator >= (const oneList<T> &m) {
        return ((*this > m)||(*this == m));
    };

    bool operator < (const oneList<T> &m) {
        return !(*this >= m);
    };

    friend std::ostream& operator<< (std::ostream &out, const oneList<T> &m){
        if ( m.head == nullptr ) throw std::out_of_range("List is empty");
        Element *current = m.head;
        out<<"( ";
        while(current->next != nullptr){
            out << current->data << ", ";
            current = current->Next;
        }
        out << current->data<<" )";
        return out;
    };
    T& operator[] (int index);
    void clear();// очистить список
};

template<typename T>
oneList<T>::oneList(const std::initializer_list<T> &m) {
    for (int i = 0; i < m.size();i++){
        push_back(m.begin()[i]);
    }
}

template<typename T>
oneList<T>::~oneList() {
    clear();
}

template<typename T>
void oneList<T>::push_front(T data) {
    head = new Element(data, head);
    Size++;
}

template<typename T>
void oneList<T>::push_back(T data) {
    if (head == nullptr) head = new Element(data);
    else {
        Element *current = this->head;
        while (current->Next != nullptr)
            current = current->Next;
        current->Next = new Element(data);
    }
    Size++;
}

template<typename T>
void oneList<T>::pop_front() {
    if (Size==0) throw std::out_of_range("list is empty");
    Element *t = head;
    head = head->Next;
    delete t;
    Size--;
}

template<typename T>
void oneList<T>::pop_back() {
    if (Size==0) throw std::out_of_range("list is empty");
    erase (Size - 1);
}

template<typename T>
void oneList<T>::insert(T data, int index) {
    if ((index < 0)||(index > Size)) throw std::out_of_range("index is more then size of list or will be positive number");
    if (index == 0) push_front(data);
    else {
        Element *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->Next;
        Element *newElement = new Element(data, previous->Next);
        previous->Next = newElement;
        Size++;
    }
}

template<typename T>
void oneList<T>::erase (int index) {
    if ((index < 0)||(index >= Size)) throw std::out_of_range("index is more then size of list or will be positive number");
    if (index == 0) pop_front();
    else {
        Element *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->Next;
        Element *delElement= previous->Next;
        previous->Next = delElement->Next;
        delete delElement;
        Size--;
    }
}

template<typename T>
void oneList<T>::clear() {
    while (Size)
        pop_front();
    head = nullptr;
}

template<class T>
T &oneList<T>::operator[](int index) {
    if ((index >= Size) || (index < 0)) throw std::out_of_range("index is more then size of list or will be positive number");
    int count = 0;
    Element *current = head;
    while (current != nullptr){
        if (count == index){
            return current->data;
        }
        current = current->Next;
        count++;
    }
    throw std::out_of_range("out of range");
}

template<typename T>
T * oneList<T>::begin() {
    return &head->data;
}
template<typename T>
T * oneList<T>::end() {
    Element *current = this->head;
    while (current->Next != nullptr)
        current = current->Next;
    return &current->data;
}

template<typename T>
void oneList<T>::display() {
    Element *current = this->head;
    cout << endl;
    while (current->Next != nullptr) {
        cout << current->data << " ";
        current = current->Next;
    }
    cout << current->data << " ";
}

template<typename T>
void oneList<T>::slijanie(oneList<T> &List1,oneList<T> &List2) {
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
void oneList<T>::razbienie(T k, oneList<T> &rezult1, oneList<T> &rezult2) {
    Element *current = this->head;
    while (current->Next != nullptr) {
        if (current->data < k) rezult1.push_back(current->data);
        else rezult2.push_back(current->data);
        current = current->Next;
    }
    if (current->data < k) rezult1.push_back(current->data);
    else rezult2.push_back(current->data);
}
#endif //LABA2_1_ONELIST_H