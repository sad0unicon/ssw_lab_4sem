#include <iostream>
#include "test.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    vector<int> Elements1000;

    cout << "\nOpen file";
    fstream fin;
    fin.open(R"(D:\ssw_lab_4sem\lab_05\src\nums.txt)");

    string str;
    if (fin){
        int i = 0;
        cout <<"\nRead Elements1000";
        while(!fin.eof() && i < 1000){

            getline(fin,str);
            Elements1000.push_back(atoi(str.c_str()));
            i++;
        }
        fin.close();
    }
    else cout << endl << "error!" << endl;

    cout << "\nvector with 1000 elements was create";
    vector<int> Elements10k;
    cout << "\ncreating vector with 10k elements";
    for ( int i =0; i < 10; i++)
        for (int j = 0; j < 1000; j++)
            Elements10k.push_back(Elements1000[j]);
    test(Elements10k);
    vector<int> Elements100k;
    cout << "\ncreating vector with 100k elements";
    for ( int i =0; i < 100; i++)
        for (int j = 0; j < 1000; j++)
        Elements100k.push_back(Elements1000[j]);
    test(Elements100k);
    vector<int> Elements1m;
    cout << "\ncreating vector with 1 million elements";
    for ( int i =0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            Elements1m.push_back(Elements1000[j]);
    test(Elements1m);
    return 0;
}
