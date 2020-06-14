#ifndef LABA3_1_BINARY_TREE_H
#define LABA3_1_BINARY_TREE_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Bin_Tree {
private:
    class Element{
    public:
        Element* Left { nullptr };
        Element* Right { nullptr };
        T data { 0 };
        explicit Element(T value = T(), Element *lLeft = nullptr, Element *lRight = nullptr) : data { value }, Left { lLeft }, Right { lRight }{}
        ~Element() = default;
    };
    Element* root { nullptr };
    vector<T> elements_tree;
    vector<int> visota;
    int Size { 0 };

    void DeleteElements (Element* elm) {
        if (elm != nullptr ){
            DeleteElements(elm->Left);
            DeleteElements(elm->Right);
            delete elm;
            elm = nullptr;
        }
        else return;
    }

    Element* pushElement(Element* elm, T d) {
        if (elm == nullptr) {
            elements_tree.push_back(d);
            elm = new Element(d);
            return elm;
        }
        if (d < elm->data) {
            elm->Left = pushElement(elm->Left, d);
            elm = BalanceTree (elm);
        }
        else {
            elm->Right = pushElement(elm->Right, d);
            elm = BalanceTree (elm);
        }
        return elm;
    }

    Element* DeleteListok(Element* node, T d) {
        if (node == nullptr) return node;
        if (d == node->data && node->Right == nullptr && node->Left == nullptr) {
            delete node;
            for (int i = 0; i < elements_tree.size(); i++)
                if (d == elements_tree[i]) {
                    elements_tree.erase(elements_tree.begin()+i);
                    break;
                }
            return nullptr;
        }
        else if(d < node->data) node->Left  = DeleteListok(node->Left, d);
        else node->Right = DeleteListok(node->Right, d);
        return node;
    }

    int heightElement(Element* elm){
        if (elm == nullptr) return 0;
        return max(heightElement(elm->Right),heightElement(elm->Left))+1;
    }

    void display (Element* elm) {
        if (elm == nullptr){
            cout << ".";
            return;
        }
        cout << "(" << elm->data << ")";
        display(elm->Left);
        display(elm->Right);
    }

    int FBalance (Element* elm) {
        return heightElement(elm->Right)-heightElement(elm->Left);
    }

    Element* BalanceTree (Element* p){
        if (FBalance(p) == 2)
        {
            if (FBalance(p->Right) < 0)
                p->Right = right_rotate(p->Right);
            p = left_rotate(p);
        }
        if (FBalance(p) == -2)
        {
            if(FBalance(p->Left) > 0)
                p->Left = left_rotate(p->Left);
            p = right_rotate(p);
        }
        return p;
    }

    Element* BalanceEntireTree(Element* elm){
        if (elm == nullptr) return elm;
        elm->Left = BalanceEntireTree(elm->Left);
        elm->Right = BalanceEntireTree(elm->Right);
        elm = BalanceTree(elm);
    }

    Element* right_rotate(Element* elm) {
        Element* left = elm->Left;
        elm->Left = left->Right;
        left->Right = elm;
        return left;
    }

    Element* left_rotate(Element* elm) {
        Element* right = elm->Right;
        elm->Right = right->Left;
        right->Left = elm;
        return right;
    }

    Element* DeleteElement(Element* node, T d) {
        if (node == nullptr)
            return node;
        if (d == node->data){
            if(node->Right== nullptr && node->Left == nullptr) {
                delete node;
                return nullptr;
            }
            Element* tmp;
            if (node->Right == nullptr)
                tmp = node->Left;
            else {
                Element* ptr = node->Right;
                if (ptr->Left == nullptr) {
                    ptr->Left = node->Left;
                    tmp = ptr;
                }
                else {
                    Element* pmin = ptr->Left;
                    while(pmin->Left != nullptr){
                        ptr  = pmin;
                        pmin = ptr->Left;
                    }
                    ptr->Left   = pmin->Right;
                    pmin->Left  = node->Left;
                    pmin->Right = node->Right;
                    tmp = pmin;
                }
            }
            delete node;
            return tmp;
        }
        else if(d < node->data) node->Left  = DeleteElement(node->Left, d);
        else node->Right = DeleteElement(node->Right, d);
        return node;
    }

    bool Ravno(Element* b1,Element* b2){
        if (b1 == nullptr && b2 == nullptr)
            return true;
        if (b1 == nullptr || b2 == nullptr)
            return false;
        bool ravn = true;
        ravn = (b1->data == b2->data);
        if (ravn)
            ravn = Ravno(b1->Left, b2->Left);
        else return false;
        if (ravn)
            ravn = Ravno(b1->Right, b2->Right);
        else return false;
        return ravn;
    }

    bool Bolshe(Element* b1,Element* b2) {
        if (b1 != nullptr && b2 == nullptr)
            return true;
        if (b1 == nullptr && b2 != nullptr)
            return false;
        if (b1 == nullptr && b2 == nullptr)
            return false;
        bool bol = true;
        if (b1->data > b2->data) return true;
        if (b1->data < b2->data) return false;
        bol = (b1->data == b2->data);
        if (bol)
            bol = Bolshe(b1->Left, b2->Left);
        else return false;
        if (bol)
            bol = Bolshe(b1->Right, b2->Right);
        else return false;
        return bol;
    }
public:
    Bin_Tree() = default;

    Bin_Tree(const std::initializer_list<T> &tree) {
        for (int i = 0; i < tree.size(); i++){
            push(tree.begin()[i]);
        }
    }

    ~Bin_Tree(){
        DeleteElements(root);
    }

    void push(T data) {
        if (root == nullptr) root = new Element (data);
        else root = pushElement(root, data);
        Size++;
    }

    void pop(T data) {
        if (Size == 0) throw std::out_of_range ("tree is empty");
        root = DeleteListok(root, data);
        root = BalanceEntireTree(root);
    }

    Element* find(T data){
        if (Size == 0) throw std::out_of_range ("tree is empty");
        Element* now = root;
        while (now != nullptr){
            if (now->data == data) return now;
            if (data < now->data) now = now->Left;
            else now = now->Right;
        }
        throw std::out_of_range("tree haven't element with this value");
    }

    int count(){
        return Size;
    }

    int height(){
        if (Size == 0) throw std::out_of_range("tree is empty");
        if (Size == 1) return 0;
        return heightElement(root);
    }

    vector<int> path (T d){
        if (Size == 0) throw std::out_of_range ("tree is empty");
        visota.clear();
        int i = 0;
        Element* elm = root;
        while (elm != nullptr){
            if (d < elm->data)
                elm = elm->Left;
            else if (d > elm->data)
                elm = elm->Right;
            else {
                visota.push_back(i);
                elm = elm->Right;
            }
            i++;
        }
        if visota.empty() throw std::out_of_range("tree is haven't this element");
        return visota;
    }

    void print() {
        if (Size == 0) throw std::out_of_range("tree is empty");
        cout << endl;
        display(root);
        cout << endl;
    }

    void double_pop(){
        if (Size == 0) throw std::out_of_range ("tree is empty");
        vector<int> it;
        for (int i = 0; i < elements_tree.size(); i++)
            for (int j = i; j < elements_tree.size(); j++)
                if (i != j && elements_tree[i] == elements_tree[j]) {
                    root = DeleteElement(root, elements_tree[i]);
                    root = BalanceEntireTree(root);
                    root = DeleteElement(root, elements_tree[i]);
                    root = BalanceEntireTree(root);
                    it.push_back(i);
                }
        for (int i = it.size() - 1; i >= 0; i--)
            elements_tree.erase(elements_tree.begin()+it[i]);
        it.clear();

    }

    void erase(T data){
        if (Size == 0) throw std::out_of_range ("tree is empty");
        root = DeleteElement(root, data);
        root = BalanceEntireTree(root);
        for (int i = 0; i < elements_tree.size(); i++)
            if (data == elements_tree[i]) {
                elements_tree.erase(elements_tree.begin()+i);
                break;
            }
    }

    bool operator == (Bin_Tree<T> const &m) {
        if ( this->Size == 0 || m.Size == 0 ) throw std::out_of_range ("tree is empty");
        return Ravno(this->root, m.root);
    }

    bool operator != (Bin_Tree<T> const &m){
        return !(this->operator==(m));
    };

    bool operator > (Bin_Tree<T> const &m) {
        if ( this->Size == 0 || m.Size == 0 ) throw std::out_of_range ("tree is empty");
        return Bolshe(this->root, m.root);
    }

    bool operator < (Bin_Tree<T> const &m){
        return !(this->operator>=(m));
    };

    bool operator >= (Bin_Tree<T> const &m){
        return (this->operator>(m) || this->operator==(m));
    };

    bool operator <= (Bin_Tree<T> const &m){
        return !(this->operator>(m));
    };
};
#endif //LABA3_1_BINARY_TREE_H