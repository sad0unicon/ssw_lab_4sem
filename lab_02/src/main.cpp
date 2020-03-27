#include <iostream>
#include "onelist.h"
#include "twolist.h"
#include "ring_buffer.h"
using namespace std;

int main()
{
    twoList <int> buf1,buf2;
    buf1.push_back(1);
    buf1.push_back(2);
    buf1.push_back(3);
    buf1.push_back(4);
    buf1.push_back(5);
    buf1.display();

    buf2.push_back(1);
    buf2.push_back(2);
    buf2.push_back(3);
    buf2.push_back(4);
    buf2.push_back(5);
    buf2.display();

    if (buf1.operator==(buf2)) cout << "\nda\n";
    else cout << "\nnet\n";
    return 0;
}