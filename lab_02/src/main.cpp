#include <iostream>
#include "onelist.h"
#include "twolist.h"
#include "ring_buffer.h"
using namespace std;

int main()
{
    RingBuffer <int> buf1(10),buf2(10), buf(10);
    buf.push_back(0);
    buf.push_back(1);
    buf.push_back(2);
    buf.push_back(3);
    buf.push_back(4);
    buf.push_back(5);
    buf.push_back(6);
    buf.push_back(7);
    buf.push_back(8);
    buf.push_back(9);
    buf.display();
    buf.razbienie(5,buf1, buf2);
    buf1.display();
    buf2.display();
    return 0;
}