#ifndef LABA4_1_HASH_TABLE_H
#define LABA4_1_HASH_TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

template <class T>
class HashTable {
private:
    class Element {
    public:
        Element *Next {nullptr};
        T data {0};

        explicit Element(T value = T(), Element *next = nullptr) : data{value}, Next{next} {}

        ~Element() = default;
    };
    int Size { 0 };
    vector<Element*> Keys_ptr;
    vector<T> Elem;

public:
    HashTable() {
        for (int i = 0;i < 100; i++)
            Keys_ptr.push_back(nullptr);

    }

    ~HashTable() = default;

    void display() {
        Element *k;
        for (int i = 0; i < 100; i++) {
            k = Keys_ptr[i];
            if (k != nullptr)
                cout << "\n\n[" << i << "] ";
            while (k != nullptr) {
                for (auto el: k->data)
                    cout << el;
                cout << "->";
                k = k->Next;
            }
        }
    }

    int HashFunction(const T str) {
        int hash = 0;
        for (auto el: str)
            hash++;
        return hash % 100;
    }

    void emplace(T d) {// вставка элемента в структуру;
        int index = HashFunction(d);
        if (Keys_ptr[index] == nullptr) {
            Keys_ptr[index] = new Element(d);
            Elem.push_back(d);
            Size++;
            return;
        }
        Element* p = Keys_ptr[index];
        while (p != nullptr) {
            if (p->data == d) {
                p->data = d;
                break;
            }
            if (p->Next == nullptr) {
                p->Next = new Element(d);
                Elem.push_back(d);
                Size++;
                break;
            }
            p = p->Next;
        }
    }

    void erase(T d) {// удаление элемента из структуры;
        if (Size == 0) throw std::out_of_range ("hash-table is empty");
        for (int i = 0; i < Elem.size(); i++)
            if (d == Elem[i]) {
                Elem.erase(Elem.begin()+i);
                break;
            }
        int index = HashFunction(d);
        if (Keys_ptr[index] == nullptr) throw std::out_of_range("hash-table haven't element with this value");
        Element* previous = Keys_ptr[index];
        if (previous->data == d) {
            Element *k = Keys_ptr[index];
            Keys_ptr[index] = k->Next;
            delete k;
            Size--;
            return;
        }
        Element* delElement = previous;
        while (delElement->data != d && delElement->Next != nullptr) {
            previous = delElement;
            delElement = delElement->Next;
        }
        if (delElement->data != d) throw std::out_of_range("hash-table haven't element with this value");
        previous->Next = delElement->Next;
        delete delElement;
        Size--;
    }

    Element* find(T d) {// поиск элемента в структуре;
        if (Size == 0) throw std::out_of_range ("tree is empty");
        int index = HashFunction(d);
        if (Keys_ptr[index] == nullptr) throw std::out_of_range("hash-table haven't element with this value");
        Element* current = Keys_ptr[index];
        while (current->data != d && current->Next != nullptr)
            current = current->Next;
        if (current->data != d) throw std::out_of_range("hash-table haven't element with this value");
        else return current;
    }

    int count() {// возврат количества элементов в структуре;
        return Size;
    }

    void sliajnie(HashTable<T> m1, HashTable<T> m2) {// реализация слияния хеш-таблиц;
        vector<T> k = m1.Elem;
        for (int i = 0; i < k.size(); i++)
            this->emplace(k[i]);
        for (int i = 0; i < k.size(); i++)
            m1.erase(k[i]);
        k.clear();
        k = m2.Elem;
        for (int i = 0; i < k.size(); i++)
            this->emplace(k[i]);
        for (int i = 0; i < k.size(); i++)
            m2.erase(k[i]);
    }

    void print_reverse() {// реализация вывода городов в обратном алфавитном порядке;
        list<T> m;
        for (int i = 0; i < Elem.size(); i++)
            m.push_back(Elem[i]);
        m.sort();
        Elem.clear();
        for (T n : m)
            Elem.push_back(n);
        m.clear();
        for (int i = Elem.size() - 1; i > -1; i--){
            cout << endl;
            for (auto el: Elem[i])
                cout << el;
        }
    }

    bool operator == (const HashTable<T> &m) {
        if (this->Size == 0 || m.Size == 0) throw std::out_of_range ("HashTable is empty");
        vector<Element*> hashkeys1 = this->Keys_ptr;
        vector<Element*> hashkeys2 = m.Keys_ptr;
        Element* hash1 = hashkeys1[0];
        Element* hash2 = hashkeys2[0];
        for (int i = 0;i < 100; i++) {
            hash1 = hashkeys1[i];
            hash2 = hashkeys2[i];
            while (hash1 != nullptr || hash2 != nullptr) {
                if (hash1 != nullptr && hash2 == nullptr) return false;
                if (hash1 == nullptr && hash2 != nullptr) return false;
                if (hash1->data != hash2->data) return false;
                hash1 = hash1->Next;
                hash2 = hash2->Next;
            }
        }
        return true;
    }

    bool operator != (HashTable<T> const &m){
        return !(this->operator==(m));
    };

    bool operator > (HashTable<T> const &m) {
        if (this->Size == 0 || m.Size == 0) throw std::out_of_range ("HashTable is empty");
        vector<Element*> hashkeys1 = this->Keys_ptr;
        vector<Element*> hashkeys2 = m.Keys_ptr;
        Element* hash1 = hashkeys1[0];
        Element* hash2 = hashkeys2[0];
        for (int i = 0;i < 100; i++) {
            hash1 = hashkeys1[i];
            hash2 = hashkeys2[i];
            while (hash1 != nullptr || hash2 != nullptr) {
                if (hash1 != nullptr && hash2 == nullptr) return false;
                if (hash1 == nullptr && hash2 != nullptr) return true;
                if (hash1->data > hash2->data) return true;
                if (hash1->data < hash2->data) return false;
                hash1 = hash1->Next;
                hash2 = hash2->Next;
            }
        }
        return false;
    }

    bool operator < (HashTable<T> const &m){
        return !(this->operator>=(m));
    };

    bool operator >= (HashTable<T> const &m){
        return (this->operator>(m) || this->operator==(m));
    };

    bool operator <= (HashTable<T> const &m){
        return !(this->operator>(m));
    };
};

#endif //LABA4_1_HASH_TABLE_H
