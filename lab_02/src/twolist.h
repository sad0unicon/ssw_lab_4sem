#ifndef LABA2_1_TWOLIST_H
#define LABA2_1_TWOLIST_H
#include <iostream>
using namespace std;
template <typename T>
class twoList {
private:
    class Element {
    public:
        T data = 0;
        Element *Next = nullptr;
        Element *Prev = nullptr;
        Element (T data = T(), Element *Next = nullptr, Element *Prev = nullptr) {
            this->data = data;
            this->Next = Next;
            this->Prev = Prev;
        }
    };
    Element *head = nullptr;
    Element *tail = nullptr;
    int Size = 0;
public:
    twoList() = default;
    twoList(const std::initializer_list<T> &m);
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
        if ((this->Size == 0)&&(m.Size == 0)) throw std::out_of_range("twoLists are empty");
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

    bool operator !=(const twoList<T> &m) {
        return !(*this == m);
    };

    bool operator > (const twoList<T> &m) {
        if ((this->Size == 0)&&(m.Size == 0)) throw std::out_of_range("twoLists are empty");
        Element *current1 = this->head;
        Element *current2 = m.head;
        while ((current1->Next != nullptr)&&(current2->Next != nullptr)){
            if (current1->data < current2->data) return false;
            if (current1->data > current2->data) return true;
            current1 = current1->Next;
            current2 = current2->Next;
        }
        if (current1->data < current2->data) return false;
        if (current1->data > current2->data) return true;
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

    friend std::ostream& operator<< (std::ostream &out, const twoList<T> &m){
        if ( m.head == nullptr ) throw std::out_of_range("twoList is empty");
        Element *current = m.head;

        out << "(";
        while(current->Next != nullptr){
            out << current->data << ", ";
            current = current->Next;
        }
        out << current->data << ")";
        return out;
    };
    void clear();
};

template<class T>
twoList<T>::twoList(const std::initializer_list<T> &m) {
    for (int i = 0; i < m.size();i++){
        push_back(m.begin()[i]);
    }
}

template <typename T>
twoList<T>::~twoList() {
    clear();
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void twoList<T>::clear() {
    while (Size)
        pop_front();
}

template<typename T>
void twoList<T>::display() {
    cout << endl;
    Element *print = head;
    while (print->Next != nullptr) {
        cout << print->data << " ";
        print = print->Next;
    }
    cout << print->data << " ";
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
        tail->Next = nullptr;
        delete temp;
        Size--;
    }
}

template <typename T>
void twoList <T>::insert(T data, int index) {
    if ((index < 0)||(index > Size)) throw std::out_of_range("index is more then size of two list or will be positive number");
    if (index == 0) push_front(data);
    if (index == Size) push_back(data);
    if ((index != 0)&&(index != Size)) {
        if (index <= Size / 2) {
            Element *previous = this->head;
            for (int i = 0; i < index - 1; i++)
                previous = previous->Next;
            Element *newElement = new Element(data, previous->Next, previous);
            previous->Next = newElement;
            Element *next = newElement->Next;
            next->Prev = newElement;
            Size++;
        }
        if (index > Size / 2) {
            Element *next = this->tail;
            for (int i = Size - 1; index < i; i--)
                next = next->Prev;
            Element *newElement = new Element(data, next, next->Prev);
            next->Prev = newElement;
            Element *previous = newElement->Prev;
            previous->Next = newElement;
            Size++;
        }
    }
}

template <typename T>
void twoList <T>::erase(int index) {
    if ((index < 0)||(index >= Size)) throw std::out_of_range("index is more then size of two list or will be positive number");
    if (index == 0) pop_front();
    if (index == Size - 1) pop_back();
    if ((index != 0)&&(index != Size - 1)) {
        if (index <= Size / 2) {
            Element *previous = this->head;
            for (int i = 0; i < index - 1; i++)
                previous = previous->Next;
            Element *delElement = previous->Next;
            previous->Next = delElement->Next;
            Element *next = delElement->Next;
            delete delElement;
            next->Prev = previous;
        }
        else if (index > Size / 2) {
            Element *next = this->tail;
            for (int i = Size - 1; index + 1 < i; i--)
                next = next->Prev;
            Element *delElement = next->Prev;
            next->Prev = delElement->Prev;
            Element *previous = delElement->Prev;
            delete delElement;
            previous->Next = next;
        }
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
    Element *current1 = m.head;
    Element *current2 = m1.head;
    while ((current1->Next != nullptr)||(current2->Next != nullptr)) {
        if (current1->data <= current2->data) {
            this->push_back(current1->data);
            if (current1->Next != nullptr)
                current1 = current1->Next;
            else break;
        }
        if (current2->data < current1->data) {
            this->push_back(current2->data);
            if (current2->Next != nullptr)
                current2 = current2->Next;
            else break;
        }
    }

    if (current1->data <= current2->data) {
        this->push_back(current1->data);
        this->push_back(current2->data);
    }
    else {
        this->push_back(current2->data);
        this->push_back(current1->data);
    }

    if ((current1->Next == nullptr)&&(current2->Next != nullptr)) {
        do {
            current2 = current2->Next;
            this->push_back(current2->data);
        } while (current2->Next != nullptr);
    }

    if ((current2->Next == nullptr)&&(current1->Next != nullptr)) {
        do{
            current1 = current1->Next;
            this->push_back(current1->data);
        } while (current1->Next != nullptr);
    }
    m.clear();
    m1.clear();
}

template<typename T>
void twoList<T>::razbienie(T k, twoList<T> &m1, twoList<T> &m2) {
    Element *current = this->head;
    while (current->Next != nullptr) {
        if (current->data < k) m1.push_back(current->data);
        else m2.push_back(current->data);
        current = current->Next;
    }
    if (current->data < k) m1.push_back(current->data);
    else m2.push_back(current->data);
}
#endif //LABA2_1_TWOLIST_H