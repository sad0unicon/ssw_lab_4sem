#include <iostream>
#include "general_tree.h"
#include "binary_tree.h"
using namespace std;

int main() {
    Bin_Tree<int> tree1{1,2,3,4,2,6,7,2,9};
    tree1.print();

    tree1.pop(9);
    tree1.print();
    tree1.double_pop();
    tree1.print();
    tree1.erase(6);
    tree1.print();
    if (tree1.operator==(tree1))
        cout << "\nravno";
    else cout << "\nneravno";


    Tree<int> tr3 {11,22,33,22};
    tr3.print();
    auto r = tr3.find(22);

    tr3.push(r.at(0),5);
    tr3.push(r.at(1),5);

    tr3.double_pop();
    tr3.print();
    r = tr3.find(33);
    tr3.push(r.at(0),5);
    tr3.print();
    if (tr3.operator==(tr3))
        cout << "\nravno";
    else cout << "\nneravno";
    return 0;
}