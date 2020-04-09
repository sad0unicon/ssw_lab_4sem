#include <iostream>
#include "onelist.h"
#include "twolist.h"
#include "ring_buffer.h"
using namespace std;

int main()
{
    RingBuffer <int> buf1(5), buf2(5), buf(10);
    buf1.push_back(0);
    buf1.push_back(1);
    buf1.push_back(2);
    buf1.display();

    buf2.push_back(4);
    buf2.push_back(5);
    buf2.push_back(30);
    buf2.display();

    buf.slijanie(buf1, buf2);
    buf.display();
    return 0;
}