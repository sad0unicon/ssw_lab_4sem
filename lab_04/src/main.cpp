#include "hash_table.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    HashTable<string> hash, hash1, hash2;
    hash1.emplace("1234");
    hash1.emplace("1235");
    hash1.emplace("1236");
    hash1.emplace("12367");
    hash1.emplace("123689");
    hash1.emplace("1236924");
    hash1.emplace("123");
    hash1.display();
    hash2.emplace("abcd");
    hash2.emplace("abce");
    hash2.emplace("abcf");
    hash2.emplace("abcfg");
    hash2.emplace("abcfgh");
    hash2.emplace("sgsgsgr");
    hash2.emplace("abc");
    hash2.display();

    if (hash1 == hash2) cout << "\nda";
    else cout << "\nnet";
    hash.sliajnie(hash1, hash2);
    hash.display();
    hash.print_reverse();

    fstream fin;
    fin.open(R"(D:\ssw_lab_4sem\lab_04\src\cities.txt)");
    HashTable<string> cities;
    int i = 0;
    string str;

    if (fin){
        while(!fin.eof()){
            getline(fin,str);
            cities.emplace(str);
            i++;
        }
        fin.close();
    }
    else cout << endl << "error!" << endl;
    return 0;
}
