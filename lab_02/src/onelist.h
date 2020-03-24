#ifndef LABA2_1_ONELIST_H
#define LABA2_1_ONELIST_H
#include <iostream>
using namespace std;
template<typename T>
class oneList{
public:
    oneList();
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
    void slijanie(oneList<T> &m, oneList<T> &m1);
    void razbienie(T k, oneList<T> &m1, oneList<T> &m2);
    bool operator ==(const oneList<T> &m) {
        if (this->Size == m.Size) {
            Element<T> *current1 = this->head;
            Element<T> *current2 = m.head;
            while (current1->next != nullptr) {
                if (current1->data != current2->data) return false;
                current1 = current1->next;
                current2 = current2->next;
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
        Element<T> *current1 = this->head;
        Element<T> *current2 = m.head;
        while ((current1->next != nullptr)&&(current2->next != nullptr)){
            if (current1->data < current2->data) return false;
            else if (current1->data > current2->data) return true;
            current1 = current1->next;
            current2 = current2->next;
        }
        if (current1->data < current2->data) return false;
        else if (current1->data > current2->data) return true;
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

    void clear();// очистить список
private:
    template<typename T>
    class Element {
    public:
        Element * next;
        T data;
        Element(T data = T(), Element *next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    int Size;
    Element<T> *head;
};

template<typename T>
oneList<T>::oneList() {
    Size = 0;
    head = nullptr;
}

template<typename T>
oneList<T>::~oneList() {
    clear();
}

template<typename T>
void oneList<T>::push_front(T data) {
    head = new Element<T>(data, head);
    Size++;
}

template<typename T>
void oneList<T>::push_back(T data) {
    if (head == nullptr) head = new Element<T>(data);
    else {
        Element<T> *current = this->head;
        while (current->next != nullptr)
            current = current->next;
        current->next = new Element<T>(data);
    }
    Size++;
}

template<typename T>
void oneList<T>::pop_front() {
    if (head == nullptr) throw std::out_of_range("list is empty");
    Element<T> *t = head;
    head = head->next;
    delete t;
    Size--;
}

template<typename T>
void oneList<T>::pop_back() {
    if (head == nullptr) throw std::out_of_range("list is empty");
    erase (Size - 1);
}

template<typename T>
void oneList<T>::insert(T data, int index) {
    if ((index < 0)||(index >= Size)) throw std::out_of_range("index is more then size of list");
    if (index == 0) push_front(data);
    else {
        Element<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->next;
        Element<T> *newElement = new Element<T>(data, previous->next);
        previous->next = newElement;
        Size++;
    }
}

template<typename T>
void oneList<T>::erase (int index) {
    if ((index < 0)||(index >= Size)) throw std::out_of_range("index is more then size of list");
    if (index == 0) pop_front();
    else {
        Element<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->next;
        Element<T> *delElement= previous->next;
        previous->next = delElement->next;
        delete delElement;
        Size--;
    }
}

template<typename T>
void oneList<T>::clear() {
    while (Size)
        pop_front();
}

template<typename T>
T * oneList<T>::begin() {
    return &head->data;
}
template<typename T>
T * oneList<T>::end() {
    Element<T> *current = this->head;
    while (current->next != nullptr)
        current = current->next;
    return &current->data;
}

template<typename T>
void oneList<T>::display() {
    Element<T> *current = this->head;
    cout << endl;
    while (current->next != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << " ";
}

template<typename T>
void oneList<T>::slijanie(oneList<T> &m,oneList<T> &m1) {
    Element<T> *current1 = this->head;
    Element<T> *current2 = m.head;
    while ((current1->next != nullptr)&&(current2->next != nullptr)) {
        if (current1->data <= current2->data) {
            m1.push_back(current1->data);
            current1 = current1->next;
        }
        if (current2->data < current1->data) {
            m1.push_back(current2->data);
            current2 = current2->next;
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

    if ((current1->next == nullptr)&&(current2->next != nullptr)) {
        do {
            current2 = current2->next;
            m1.push_back(current2->data);
        } while (current2->next != nullptr);
    }

    if ((current2->next == nullptr)&&(current1->next != nullptr)) {
        do{
            current1 = current1->next;
            m1.push_back(current1->data);
        } while (current1->next != nullptr);
    }
    this->clear();
    m.clear();
}

template<typename T>
void oneList<T>::razbienie(T k, oneList<T> &m1, oneList<T> &m2) {
    Element<T> *current = this->head;
    while (current->next != nullptr) {
        if (current->data < k) m1.push_back(current->data);
        else m2.push_back(current->data);
        current = current->next;
    }
    if (current->data < k) m1.push_back(current->data);
    else m2.push_back(current->data);
}
#endif //LABA2_1_ONELIST_H