#include <iostream>
#include "general_tree.h"
#include "binary_tree.h"
using namespace std;

int main() {
    Bin_Tree<int> tree1{1,2,3,4,2,6,7,2,9}, tree2{1,2,3,4,2,6,7,2,9};
    tree1.print();
    auto res1 = tree1.path(2);
    for (auto& node: res1)
        cout << node << " ";

    tree1.pop(9);
    tree1.print();
    tree1.double_pop();
    tree1.print();
    tree1.erase(6);
    tree1.print();
    tree2.print();
    if (tree1 == tree2)
        cout << "\nda";
    else cout << "\nnet";


    Tree<int> tree3 {11,22,33,22}, tree4{11,22,33,22};
    tree3.print();
    auto r = tree3.find(22);

    tree3.push(r.at(0),5);
    tree3.push(r.at(1),5);

    tree3.double_pop();
    tree3.print();
    r = tree3.find(33);
    tree3.push(r.at(0),5);
    tree3.print();
    tree4.print();
    if (tree3 > tree4)
        cout << "\nda";
    else cout << "\nnet";
    return 0;
}