#ifndef LABA3_1_GENERAL_TREE_H
#define LABA3_1_GENERAL_TREE_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Tree {
private:
    class Element{
    public:
        vector<Element*> Subtrees;
        T data { 0 };
        explicit Element (T value){
            data = value;
            Subtrees.clear();
        }
        ~Element() = default;
    };
    Element* root { nullptr };
    vector<T> elements_tree;
    vector<int> it;
    int Size { 0 };
    vector<Element*> Elem;
    vector<int> visota;

    void DeleteElements (Element* elm) {
        if (elm != nullptr ){
            for (int i = 0; i < elm->Subtrees.size(); i++)
                DeleteElements(elm->Subtrees.begin()[i]);
            elm->Subtrees.clear();
            delete elm;
        }
    }

    void DeleteListok(Element* elm, Element* poisk) {
        for (int i = 0; i < elm->Subtrees.size();i++){
            if (elm->Subtrees.begin()[i] == poisk) {
                for (int i = 0; i < elements_tree.size(); i++)
                    if (poisk->data == elements_tree[i]) {
                        elements_tree.erase(elements_tree.begin()+i);
                        break;
                    }
                elm->Subtrees.erase(elm->Subtrees.begin() + i);
                Size--;
                break;
            }
            DeleteListok(elm->Subtrees.begin()[i], poisk);
        }
    }

    void FindElement(Element* elm, T d) {
        if (elm == nullptr) return;
        if (elm->data == d) Elem.push_back(elm);
        for (int i = 0; i < elm->Subtrees.size(); i++)
            FindElement(elm->Subtrees.begin()[i], d);
    }

    int heightElement(Element* elm){
        if (elm == nullptr) return 0;
        int maxHeight = 0;
        for (int i = 0; i < elm->Subtrees.size(); i++){
            int height = heightElement(elm->Subtrees.begin()[i]);
            if (height > maxHeight) maxHeight = height;
        }
        return maxHeight + 1;
    }

    int PathElement(const Element* elm, T d) {
        int height = 0;
        for (int i = 0; i < elm->Subtrees.size(); i++)
            height = PathElement(elm->Subtrees.begin()[i], d);
        height++;
        if (elm->data == d) visota.push_back(height + 1);
        return height;
    }

    void display (Element* elm) {
        cout << "(" << elm->data << ")";
        for (int i = 0; i < elm->Subtrees.size(); i++)
            display(elm->Subtrees.begin()[i]);
        if (elm != root)
            cout << ".";
        if (elm->Subtrees.size() == 0)
            return;
    }

    void DeleteElement(Element* node, Element* poisk) {
        if (poisk == root) {
            DeleteRoot(poisk);
            return;
        }
        else if (poisk->Subtrees.size() == 0){
            DeleteListok(node, poisk);
            return;
        }
        else if (poisk->Subtrees.size() != 0) {
            DeleteUzel(node, poisk);
            return;
        }
    }

    void DeleteRoot(Element* poisk) {
        Element* new_root = root->Subtrees.begin()[0];
        Element* old_root = root;
        for (int i = 1; i < old_root->Subtrees.size(); i++)
            new_root->Subtrees.push_back(old_root->Subtrees.begin()[i]);
        root = new_root;
        delete old_root;
        Size--;
    }

    void DeleteUzel (Element* node, Element* poisk) {
        for (int i = 0; i < node->Subtrees.size(); i++) {
            if (node->Subtrees.begin()[i] == poisk) {
                Element* new_poisk = poisk->Subtrees.begin()[0];
                Element* old_poisk = poisk;
                for (int i = 1; i < old_poisk->Subtrees.size(); i++)
                    new_poisk->Subtrees.push_back(old_poisk->Subtrees.begin()[i]);
                node->Subtrees.erase(node->Subtrees.begin() + i);
                node->Subtrees.push_back(new_poisk);
                delete old_poisk;
                Size--;
                break;
            }
            DeleteUzel(node->Subtrees.begin()[i], poisk);
        }
    }

    bool Ravno(Element* b1,Element* b2){
        if (b1->Subtrees.size() != b2->Subtrees.size())
            return false;
        bool ravn = true;
        ravn = (b1->data == b2->data);
        if (ravn)
            for (int i = 0; i < b1->Subtrees.size(); i++) {
                ravn = Ravno(b1->Subtrees.begin()[i], b2->Subtrees.begin()[i]);
                if (!ravn) return false;
            }
        else return false;
        return ravn;
    }

    bool Bolshe(Element* b1,Element* b2) {
        bool bol = true;
        if (b1->data > b2->data) return true;
        cout << "sdffa";
        if (b1->data < b2->data) return false;
        bol = (b1->data == b2->data);
        if (bol)
            for (int i = 0; i < b1->Subtrees.size(); i++) {
                bol = Bolshe(b1->Subtrees.begin()[i], b2->Subtrees.begin()[i]);
                if (!bol) return false;
            }
        else return false;
        return bol;
    }
public:
    Tree() = default;

    Tree(const std::initializer_list<T> &tree) {
        for (int i = 0; i < tree.size(); i++){
            push(root, tree.begin()[i]);
        }
    }

    ~Tree(){
        DeleteElements(root);
    }

    void push(Element* p, T data) {
        elements_tree.push_back(data);
        if (root == nullptr) root = new Element (data);
        else p->Subtrees.push_back(new Element(data));
        Size++;
    }

    void pop(Element* elm) {
        if (Size == 0) throw std::out_of_range("tree is empty");
        if (elm->Subtrees.size() != 0) throw std::out_of_range("this element is not list");
        DeleteListok(root, elm);
    }

    vector<Element*> find (T d){
        if (Size == 0) throw std::out_of_range("tree is empty");
        Elem.clear();
        FindElement(root, d);
        if (Elem.empty()) throw std::out_of_range(" tree is haven't this element");
        return Elem;
    }

    int count(){
        return Size;
    }

    int height(){
        if (Size == 0) throw std::out_of_range("tree is empty");
        if (Size == 1) return 0;
        return heightElement(root);
    }

    vector<int> path(T d) {
        if (Size == 0) throw std::out_of_range("tree is empty");
        visota.clear();
        PathElement(root, d);
        if (visota.size() == 0) throw std::out_of_range("tree is haven't this element");
        return visota;
    }

    void print() {
        if (Size == 0) throw std::out_of_range("tree is empty");
        cout << endl;
        display(root);
        cout << endl;
    }

    void double_pop(){
        if (Size == 0) throw std::out_of_range("tree is empty");
        vector<T> k;
        for (int i = 0; i < elements_tree.size(); i++)
            k.push_back(elements_tree[i]);
        elements_tree.clear();
        for (int i = 0; i < k.size(); i++) {
            for (int j = i; j < k.size(); j++)
                if (i != j && k[i] == k[j])
                    it.push_back(i);
        }
        for (int i = it.size() - 1; i >= 0; i--) {
            auto ptr = find(k[it[i]]);
            for (auto& node: ptr)
                DeleteElement(root, node);
        }
        for (int i = 0; i < k.size(); i++){
            for (int j = it.size() - 1; j >= 0; j--)
                if (k[i] != k[it[j]])
                    elements_tree.push_back(k[i]);
        }
        k.clear();
        it.clear();
    }

    void erase(Element* elm) {
        if (Size == 0) throw std::out_of_range("tree is empty");
        DeleteElement(root, elm);
        for (int i = 0; i < elements_tree.size(); i++)
            if (elm->data == elements_tree[i]) {
                elements_tree.erase(elements_tree.begin()+i);
                break;
            }
    }

    bool operator == (Tree<T> const &m) {
        if (this->Size == 0 || m.Size == 0) throw std::out_of_range ("tree is empty");
        return Ravno(this->root, m.root);
    }

    bool operator != (Tree<T> const &m){
        return !(this->operator==(m));
    };

    bool operator > (Tree<T> const &m) {
        if ( this->Size == 0 || m.Size == 0 ) throw std::out_of_range ("tree is empty");
        if (!Ravno(this->root, m.root))
        return Bolshe(this->root, m.root);
        else return false;
    }

    bool operator < (Tree<T> const &m){
        return !(this->operator>=(m));
    };

    bool operator >= (Tree<T> const &m){
        return (this->operator>(m) || this->operator==(m));
    };

    bool operator <= (Tree<T> const &m){
        return !(this->operator>(m));
    };
};
#endif //LABA3_1_GENERAL_TREE_H