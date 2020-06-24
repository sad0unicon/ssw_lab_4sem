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

    Element* DeleteListok(Element* node) {
        if (node == nullptr) return node;
        if (node->Right == nullptr && node->Left == nullptr) {
            delete node;
            Size--;
            return nullptr;
        }
        if (node->Left == nullptr) node->Right = DeleteListok(node->Right);
        else node->Left = DeleteListok(node->Left);
        return node;
    }

    int heightElement(Element* elm){
        if (elm == nullptr) return 0;
        return max(heightElement(elm->Right),heightElement(elm->Left))+1;
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
        return elm;
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
public:
    Bin_Tree() = default;

    ~Bin_Tree(){
        DeleteElements(root);
    }

    void push(T data) {
        if (root == nullptr) root = new Element (data);
        else root = pushElement(root, data);
        Size++;
    }

    void pop() {
        if (Size == 0) throw std::out_of_range ("tree is empty");
        root = DeleteListok(root);
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
};
#endif //LABA3_1_BINARY_TREE_H