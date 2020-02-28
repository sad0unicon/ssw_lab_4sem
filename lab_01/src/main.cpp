#include <iostream>
#include "vektor.h"
#include "steck.h"
#include "ochered.h"
#include <vector>
#include <stack>
#include <queue>
#include <chrono>
using ms = std::chrono::milliseconds;
using namespace std;

int main(int charc, char** argv)
{
    Vektor <int> vek, vek1;
    vector<int> v;
    Stack <int> steck, steck1;
    stack <int> s;
    Queue <int> otshered, otshered1;
    queue <int> q;

    vek.push(11);
    vek.push(12);
    vek.push(13);
    vek.push(14);
    vek.push(15);

    vek1.push(21);
    vek1.push(22);
    vek1.push(23);
    vek1.push(24);
    vek1.push(25);
    vek1.push(26);

    cout << "\n1 vektor\n";
    vek.display();
    cout << "\n2 vektor\n";
    vek1.display();

    swap(vek,vek1);

    cout << "\n1 vektor\n";
    vek.display();
    cout << "\n2 vektor\n";
    vek1.display();

    cout << "\nSravnenie vektor\nVstavka element\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 10000;i++)
    vek.push(11);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 10000;i++)
    v.push_back(11);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout <<"Vektor=" <<res_time<<endl;
    cout <<"std vector="<<res_time1<<endl;

    cout << "Kolitchestvo elements\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 1000000;i++)
        vek.count();
     end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 1000000;i++)
        v.size();
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout <<"Vektor=" <<res_time<<endl;
    cout <<"std vector="<<res_time1<<endl;

    cout << "\nSravnenie stack\nVstavka element\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 10000;i++)
        steck.push(11);
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 10000;i++)
        s.push(11);
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout <<"Stack=" <<res_time<<endl;
    cout <<"std stack="<<res_time1<<endl;

    cout << "Vershina stack\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 1000000;i++)
        steck.peek();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 1000000;i++)
        s.top();
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout <<"Stack="<<res_time<<endl;
    cout <<"std stack="<<res_time1<<endl;

    cout << "\nSravnenie otchered\nVstavka element\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 10000;i++)
        otshered.push(11);
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 10000;i++)
        q.push(11);
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout <<"Queue="<<res_time<<endl;
    cout <<"std queue="<<res_time1<<endl;

    cout << "Vershina otchered\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 1000000;i++)
        otshered.peek();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < 1000000;i++)
        q.front();
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout <<"Queue="<<res_time<<endl;
    cout <<"std queue="<<res_time1<<endl;
    getchar();
    return 0;
}