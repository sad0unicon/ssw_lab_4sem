#ifndef LABA5_1_TEST_H
#define LABA5_1_TEST_H
#include "vektor.h"
#include "steck.h"
#include "ochered.h"
#include "twolist.h"
#include "binary_tree.h"
#include <chrono>
using ms = std::chrono::milliseconds;
using namespace std;

vector<int> Test_Vektor(vector<int> Elements) {
    cout << "\nstart Test Vektor";
    Vektor<int> test_v;
    vector<int> data;
    data.push_back(sizeof(test_v));

    test_v.push_back(1);
    data.push_back(sizeof(test_v));
    test_v.pop_back();

    cout << "\ntest push_back elements";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_v.push_back(Elements.begin()[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest pop_back elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_v.pop_back();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    for (int i = 0; i < Elements.size(); i++)
        test_v.push_back(Elements.begin()[i]);

    cout << "\ntest at elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Elements.size(); i++){
        test_v.at(i);
    }
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end-start).count();
    data.push_back(res_time);

    cout << "\nEnd Test Vektor";
    return data;
}

vector<int> Test_Stack(vector<int> Elements) {
    cout << "\nstart Test Stack";
    Stack<int> test_s;
    vector<int> data;
    data.push_back(sizeof(test_s));

    test_s.push_back(1);
    data.push_back(sizeof(test_s));
    test_s.pop_back();

    cout << "\ntest push_back elements";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_s.push_back(Elements.begin()[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest pop_back elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_s.pop_back();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    for (int i = 0; i < Elements.size(); i++)
        test_s.push_back(Elements.begin()[i]);

    cout << "\ntest peek elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Elements.size(); i++){
        test_s.peek();
    }
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end-start).count();
    data.push_back(res_time);

    cout << "\nEnd Test Stack";
    return data;
}

vector<int> Test_Queue(vector<int> Elements) {
    cout << "\nstart Test Queue";
    Queue<int> test_q;
    vector<int> data;
    data.push_back(sizeof(test_q));

    test_q.push_back(1);
    data.push_back(sizeof(test_q));
    test_q.pop_front();

    cout << "\ntest push_back elements";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_q.push_back(Elements.begin()[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest pop_front elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_q.pop_front();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    for (int i = 0; i < Elements.size(); i++)
        test_q.push_back(Elements.begin()[i]);

    cout << "\ntest peek elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Elements.size(); i++){
        test_q.peek();
    }
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end-start).count();
    data.push_back(res_time);

    cout << "\nEnd Test Queue";
    return data;
}

vector<int> Test_TwoList(vector<int> Elements) {
    cout << "\nstart Test TwoList";
    twoList<int> test_tl;
    vector<int> data;
    data.push_back(sizeof(test_tl));

    test_tl.push_back(1);
    data.push_back(sizeof(test_tl));
    test_tl.pop_back();

    cout << "\ntest push_front elements";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_tl.push_front(Elements.begin()[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest pop_front elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_tl.pop_front();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest push_back elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_tl.push_back(Elements.begin()[i]);
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest pop_back elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_tl.pop_back();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    for (int i = 0; i < Elements.size(); i++)
        test_tl.push_back(Elements.begin()[i]);

    cout << "\ntest find elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Elements.size(); i++)
        test_tl.find(Elements.begin()[i]);
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end-start).count();
    data.push_back(res_time);

    cout << "\nEnd Test TwoList";
    return data;
}

vector<int> Test_BinTree(vector<int> Elements) {
    cout << "\nstart Test BinTree";
    Bin_Tree<int> test_bt;
    vector<int> data;
    data.push_back(sizeof(test_bt));

    test_bt.push(1);
    data.push_back(sizeof(test_bt));
    test_bt.pop();

    cout << "\ntest push_back elements";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_bt.push(Elements.begin()[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    cout << "\ntest pop_back elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < Elements.size();i++)
        test_bt.pop();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    data.push_back(res_time);

    for (int i = 0; i < Elements.size(); i++)
        test_bt.push(Elements.begin()[i]);

    cout << "\ntest find elements";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Elements.size(); i++){
        test_bt.find(Elements.begin()[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end-start).count();
    data.push_back(res_time);

    cout << "\nEnd Test BinTree";
    return data;
}

void test(vector<int> Elements) {
    cout << "\nStart Test";
    auto test_v = Test_Vektor (Elements);//size0/size1/push_back/pop_back/at
    auto test_s = Test_Stack(Elements);//size0/size1/push_back/pop_back/peek
    auto test_q = Test_Queue(Elements);//size0/size1/push_back/pop_front/peek
    auto test_tl = Test_TwoList(Elements);//size0/size1/push_front/pop_front/push_back/pop_back/find
    auto test_bt = Test_BinTree(Elements);//size0/size1/push_back/pop_back/find

    cout << "\nEnd Test" << endl;
    cout << "struct\t\tvector\tstack\tqueue\tlist\tbin_tree\n";

    cout << "size0:\t\t" << test_v[0] <<"\t" << test_s[0] << "\t";
    cout << test_q[0] <<"\t" << test_tl[0]<<"\t" << test_bt[0] << endl;

    cout << "size1:\t\t" << test_v[1] <<"\t" << test_s[1] << "\t";
    cout << test_q[1] <<"\t" << test_tl[1]<<"\t" << test_bt[1] << endl;

    cout << "push_front\t---\t---\t---\t" << test_tl[2] << "\t---"<< endl;

    cout << "push_back\t" << test_v[2] << "\t" << test_s[2] << "\t" << test_q[2] << "\t";
    cout << test_tl[4] << "\t" << test_bt[2] << endl;

    cout << "pop_front\t---\t---\t" << test_q[3] << "\t";
    cout << test_tl[3] << "\t---\t" << endl;

    cout << "pop_back\t" << test_v[3] << "\t" << test_s[3] << "\t---\t";
    cout << test_tl[5] << "\t" << test_bt[3] << endl;

    cout << "find\t\t" << test_v[4] << "\t" << test_s[4] << "\t" << test_q[4] << "\t";
    cout << test_tl[6] << "\t" << test_bt[4] << endl;
}
#endif //LABA5_1_TEST_H