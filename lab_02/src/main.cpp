#include "onelist.h"
#include "twolist.h"
#include "ring_buffer.h"
using namespace std;

int main()
{
    RingBuffer <int> buf1(5),buf2(5);
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
    buf2.push_back(6);
    buf2.display();

    if (buf1.operator!=(buf2)) cout << "\nda\n";
    else cout << "\nnet\n";
    return 0;
}