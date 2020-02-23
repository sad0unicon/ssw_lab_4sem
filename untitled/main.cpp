# include <algorithm>
# include <iostream>
# include <string>
# include <vector>//для генератора чисел
# include <type_traits>
# include <random>
# include <exception>
# include <cassert>
using namespace std;

template <typename T>
class Vektor
{
private:
    T *Buf;
    int size;
public:
    explicit Vektor(int nSize) : size(nSize) {
        Buf = new T[nSize];
    };
    ~Vektor();
    void display();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    T count();//возврат количества элементов в структуре;
    T at(int);//метод произвольного доступа к элементу
    void reverse();
    friend void swap(Vektor<T> &m1,Vektor<T> &m2) {
        float a;
        for (int i=0;i<m1.size;i++){
            a = m1.Buf[i];
            m1.Buf[i] = m2.Buf[i];
            m2.Buf[i] = a;
        }
    };
    friend bool operator ==(const Vektor<T> &m1, const Vektor<T> &m2) {
        bool s1 = true;
        if (m1.size==m2.size)
        {
            for (int i = 0; i < m1.size; i++)
                if (m1.Buf[i] != m2.Buf[i]) s1=false;
            return s1;
        };
        return false;
    };
    friend bool operator !=(const Vektor<T> &m1,const Vektor<T> &m2) {
        return !(m1 == m2);
    };
    friend bool operator > (const Vektor<T> &m1, const Vektor<T> &m2) {
        int i=0;
        if (m1.size>=m2.size) {
            while ((m1.Buf[i] >= m2.Buf[i])&&(i < m2.size)) {
                if (m1.Buf[i] > m2.Buf[i])
                    return true;
                i++;
            }
            if (m1.size > m2.size) return true;
        }
        i = 0;
        if (m1.size < m2.size) {
            while ((m1.Buf[i] >= m2.Buf[i])&&(i < m1.size)) {
                if (m1.Buf[i] > m2.Buf[i])
                    return true;
                i++;
            }
        }
        return false;
    };
    friend bool operator < (const Vektor<T> &m1,const Vektor<T> &m2) {
        int i = 0;
        if (m1.size > m2.size) {
            while ((m1.Buf[i] <= m2.Buf[i])&&(i < m2.size)) {
                if (m1.Buf[i] < m2.Buf[i])
                    return true;
                i++;
            }
        }
        i = 0;
        if (m1.size <= m2.size) {
            while ((m1.Buf[i] <= m2.Buf[i])&&(i < m1.size)) {
                if (m1.Buf[i] < m2.Buf[i])
                    return true;
                i++;
            }
            if (m1.size < m2.size) return true;
        }
        return false;
    };
    friend bool operator <= (const Vektor<T> &m1, const Vektor<T> &m2) {
        return !(m1 > m2);
    };
    friend bool operator >= (const Vektor<T> &m1,const Vektor<T> &m2) {
        return !(m1 < m2);
    };
};
template <typename T>
Vektor<T>::~Vektor() {
    delete[] Buf;
};
template <typename T>
void Vektor<T>::display() {
    cout << "\nVyvod elements vecktor:\n";
    for (int i = 0; i < size; i++) cout << Buf[i] << "  ";
};
template <typename T>
void Vektor<T>::push(T b) {
    T *l;
    l = new T[size + 1];
    for (int i = 0; i < size; i++)
        l[i] = Buf[i];
    l[size] = b;
    delete[] Buf;
    size++;
    Buf = l;
};
template <typename T>
void Vektor<T>::pop() {
    T *t;
    t = new T[size - 1];
    for (int i = 0; i < size - 1; i++)
        t[i] = Buf[i];
    delete[] Buf;
    Buf = t;
    size--;
};
template <typename T>
T Vektor<T>::peek() {
    cout << endl;
    cout << Buf[0] << endl;
    return Buf[0];
};
template <typename T>
T Vektor<T>::count() {
    cout << endl;
    cout << size << endl;
    return size;
};
template <typename T>
T Vektor<T>::at(int i) {

    return Buf[i-1];
};
template <typename T>
void Vektor<T>::reverse() {
    for (int i = 0; i < size / 2; i++)
    {
        T x = Buf[i];
        Buf[i] = Buf[size - 1 - i];
        Buf[size - 1 - i] = x;
    }
};


//

template <typename T>
class Stack
{
private:
    T *Buf1;
    int size1;
public:
    explicit Stack(int nSize) : size1(nSize) {
        Buf1 = new T[nSize];
    };
    ~Stack();
    void display();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    T count();//возврат количества элементов в структуре;
    void reverse();
    friend void swap(Stack<T> &m1,Stack<T> &m2)
    {
        float a;
        for (int i=0;i<m1.size1;i++){
            a = m1.Buf1[i];
            m1.Buf1[i] = m2.Buf1[i];
            m2.Buf1[i] = a;
        }
    };
    friend bool operator ==(const Stack<T> &m1, const Stack<T> &m2) {
        bool s1 = true;
        if (m1.size1==m2.size1)
        {
            for (int i = 0; i < m1.size1; i++)
                if (m1.Buf1[i] != m2.Buf1[i]) s1=false;
            return s1;
        };
        return false;
    };
    friend bool operator !=(const Stack<T> &m1,const Stack<T> &m2) {
        return !(m1 == m2);
    };
    friend bool operator > (const Stack<T> &m1, const Stack<T> &m2) {
        int i=0;
        if (m1.size1>=m2.size1) {
            while ((m1.Buf1[i] >= m2.Buf1[i])&&(i < m2.size1)) {
                if (m1.Buf1[i] > m2.Buf1[i])
                    return true;
                i++;
            }
            if (m1.size1 > m2.size1) return true;
        }
        i = 0;
        if (m1.size1 < m2.size1) {
            while ((m1.Buf1[i] >= m2.Buf1[i])&&(i < m1.size1)) {
                if (m1.Buf1[i] > m2.Buf1[i])
                    return true;
                i++;
            }
        }
        return false;
    };
    friend bool operator < (const Stack<T> &m1,const Stack<T> &m2) {
        int i = 0;
        if (m1.size1 > m2.size1) {
            while ((m1.Buf1[i] <= m2.Buf1[i])&&(i < m2.size1)) {
                if (m1.Buf1[i] < m2.Buf1[i])
                    return true;
                i++;
            }
        }
        i = 0;
        if (m1.size1 <= m2.size1) {
            while ((m1.Buf1[i] <= m2.Buf1[i])&&(i < m1.size1)) {
                if (m1.Buf1[i] < m2.Buf1[i])
                    return true;
                i++;
            }
            if (m1.size1 < m2.size1) return true;
        }
        return false;
    };
    friend bool operator <= (const Stack<T> &m1, const Stack<T> &m2) {
        return !(m1 > m2);
    };
    friend bool operator >= (const Stack<T> &m1,const Stack<T> &m2) {
        return !(m1 < m2);
    };
};
template <typename T>
Stack<T>::~Stack()
{
    delete[] Buf1;
};
template <typename T>
void Stack<T>::display()
{
    cout << "\nVyvod elements stack:\n";
    for (int i = size1-1; i >= 0; i--) cout << endl << Buf1[i];
};
template <typename T>
void Stack<T>::push(T b)
{
    T *l;
    l = new T[size1 + 1];
    for (int i = 0; i < size1; i++)
        l[i] = Buf1[i];
    l[size1] = b;
    delete[] Buf1;
    size1++;
    Buf1 = l;
};
template <typename T>
void Stack<T>::pop()
{
    T *t;
    t = new T[size1 - 1];
    for (int i = 0; i < size1 - 1; i++)
        t[i] = Buf1[i];
    delete[] Buf1;
    Buf1 = t;
    size1--;
};
template <typename T>
T Stack<T>::peek()
{
    cout << endl;
    cout << Buf1[size1-1] << endl;
    return Buf1[size1-1];
};
template <typename T>
T Stack<T>::count()
{
    cout << endl;
    cout << size1 << endl;
    return size1;
};
template <typename T>
void Stack<T>::reverse()
{
    for (int i = 0; i < size1 / 2; i++)
    {
        T x = Buf1[i];
        Buf1[i] = Buf1[size1 - 1 - i];
        Buf1[size1 - 1 - i] = x;
    }
};

//

template <typename T>
class Queue
{
private:
    T *Buf2;
    int size2;
public:
    explicit Queue(int nSize) : size2(nSize) {
        Buf2 = new T[nSize];
    };
    ~Queue();
    void display();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    T count();//возврат количества элементов в структуре;
    void reverse();
    friend void swap(Queue<T> &m1,Queue<T> &m2)
    {
        float a;
        for (int i=0;i<m1.size2;i++){
            a = m1.Buf2[i];
            m1.Buf2[i] = m2.Buf2[i];
            m2.Buf2[i] = a;
        }
    };
    friend bool operator ==(const Queue<T> &m1, const Queue<T> &m2) {
        bool s1 = true;
        if (m1.size2==m2.size2)
        {
            for (int i = 0; i < m1.size2; i++)
                if (m1.Buf2[i] != m2.Buf2[i]) s1=false;
            return s1;
        };
        return false;
    };
    friend bool operator !=(const Queue<T> &m1,const Queue<T> &m2) {
        return !(m1 == m2);
    };
    friend bool operator > (const Queue<T> &m1, const Queue<T> &m2) {
        int i=0;
        if (m1.size2>=m2.size2) {
            while ((m1.Buf2[i] >= m2.Buf2[i])&&(i < m2.size2)) {
                if (m1.Buf2[i] > m2.Buf2[i])
                    return true;
                i++;
            }
            if (m1.size2 > m2.size2) return true;
        }
        i = 0;
        if (m1.size2 < m2.size2) {
            while ((m1.Buf2[i] >= m2.Buf2[i])&&(i < m2.size2)) {
                if (m1.Buf2[i] > m2.Buf2[i])
                    return true;
                i++;
            }
        }
        return false;
    };
    friend bool operator < (const Queue<T> &m1,const Queue<T> &m2) {
        int i = 0;
        if (m1.size2 > m2.size2) {
            while ((m1.Buf2[i] <= m2.Buf2[i])&&(i < m2.size2)) {
                if (m1.Buf2[i] < m2.Buf2[i])
                    return true;
                i++;
            }
        }
        i = 0;
        if (m1.size2 <= m2.size2) {
            while ((m1.Buf2[i] <= m2.Buf2[i])&&(i < m1.size2)) {
                if (m1.Buf2[i] < m2.Buf2[i])
                    return true;
                i++;
            }
            if (m1.size2 < m2.size2) return true;
        }
        return false;
    };
    friend bool operator <= (const Queue<T> &m1, const Queue<T> &m2) {
        return !(m1 > m2);
    };
    friend bool operator >= (const Queue<T> &m1,const Queue<T> &m2) {
        return !(m1 < m2);
    };
};
template <typename T>
Queue<T>::~Queue()
{
    delete[] Buf2;
};
template <typename T>
void Queue<T>::display()
{
    cout << "\nVyvod elements otcheredi:\n";
    for (int i = 0; i < size2; i++) cout << Buf2[i] <<"  ";
};
template <typename T>
void Queue<T>::push(T b)
{
    T *l;
    l = new T[size2 + 1];
    l[size2] = b;
    for (int i = 0; i < size2; i++)
        l[i] = Buf2[i];
    delete[] Buf2;
    size2++;
    Buf2 = l;
};
template <typename T>
void Queue<T>::pop()
{
    T *t;
    t = new T[size2 - 1];
    for (int i = 1; i < size2; i++)
        t[i-1] = Buf2[i];
    delete[] Buf2;
    size2--;
    Buf2 = t;
};
template <typename T>
T Queue<T>::peek()
{
    cout << endl;
    cout << Buf2[0] << endl;
    return Buf2[0];
};
template <typename T>
T Queue<T>::count()
{
    cout << endl;
    cout << size2 << endl;
    return size2;
};
template <typename T>
void Queue<T>::reverse()
{
    for (int i = 0; i < size2 / 2; i++)
    {
        T x = Buf2[i];
        Buf2[i] = Buf2[size2 - 1 - i];
        Buf2[size2 - 1 - i] = x;
    }
};

void comands() {
    cout << "\nVyberi dejstvie:\n";
    cout << "1.Push element\n";
    cout << "2.Pop element\n";
    cout << "3.Znatchenie vershiny struct\n";
    cout << "4.Kolitchestvo elements struct\n";
    cout << "5.Smena porjadka elements v struct na reverse\n";
    cout << "6.End\n";
}

template < class T>
constexpr auto generate(const size_t N) {
    static_assert(!std::is_void<T>::value, " <E> Can't generate array of void");
    std::vector<T> res;

    assert(N != 0);
    assert(N < res.max_size());

    res.reserve(N);
    std::random_device rd;
    std::mt19937 mt(rd());

    if constexpr (std::is_arithmetic<T>::value) {
        auto gen = [&]() {
            if constexpr (std::is_floating_point<T>::value) {
                std::uniform_real_distribution<T> dist(1, 100); // rand from 1 to 100
                for (size_t i = 0; i < N; i++) {
                    res.emplace_back(dist(mt));
                }
            } else {
                std::uniform_int_distribution<T> dist(1, 100);
                for (size_t i = 0; i < N; i++) {
                    res.emplace_back(dist(mt));
                }
            }
        };

        gen(); // lambda (non name) function

    } else {
        std::throw_with_nested(std::runtime_error("<E> Can't work with unknown types"));
    }

    return res;
}


template<>
auto generate<std::string> (const size_t N) { // template specialization for std::string
    std::vector<std::string> res;

    assert(N != 0);
    assert(N < res.max_size());
    res.reserve(N);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (size_t i = 0; i < N; i++) {
        res.emplace_back(std::to_string(dist(mt)));
    }

    return res;
}

int main(int charc, char** argv)
{
    //setlocale(LC_ALL, "Russian");
    int m,n,k1,k2,k3;
    float a, b, c;
    int VSZ[2] = { 0,0 };
    Vektor <float> vek(0), vek1(0);
    Stack <float> steck(0), steck1(0);
    Queue <float> otshered(0), otshered1(0);
    cout << "Vyberi kakoj type struct create:\n";
    cout << "1.Vector\n2.Stack\n3.Queue\n";
    cin >> k1;
    switch(k1)
    {
        case 1:
        {
            cout << "Vyberi type vector:\n1.Int\n2.Float\n";
            cin >> k3;
            if (k3 == 1) Vektor <int> vek(0);
            cout << "\n1 VEKTOR\n";
            comands();
            cout << "7.Proizvolnij dostup k element\n";
            cin >> k2;
            while (k2 != 6)
            {
                if (k2 == 1) {
                    if (k3 == 1) {auto t1 = generate<int>(1);vek.push(t1[0]);} // t1 is std::vector
                    else {auto t1 = generate<float>(1);vek.push(t1[0]);}

                    VSZ[0]++;
                    vek.display();
                }
                if ((k2 == 2) & (VSZ[0] != 0)) {
                    vek.pop();
                    VSZ[0]--;
                    vek.display();
                }
                if ((k2 == 3) & (VSZ[0] != 0)) m = vek.peek();
                if (k2 == 4) n = vek.count();
                if ((k2 == 5)& (VSZ[0] != 0)) {
                    vek.reverse();
                    vek.display();
                }
                if ((k2 == 7)& (VSZ[0] != 0)) {
                    int i = rand() % VSZ[0] + 1; // диапазон равен от 1 до vsz включительно
                    cout << endl;
                    cout << "Buf[" << i << "]=" << vek.at(i) << endl;
                }
                comands();
                cout << "7.Proizvolnij dostup k element\n";
                cin >> k2;
            }
            cout << "\n2 VEKTOR\n";
            comands();
            cout << "7.Proizvolnij dostup k element\n";
            cin >> k2;
            while (k2 != 6)
            {
                if (k2 == 1) {
                    if (k3 == 1) {auto t1 = generate<int>(1);vek1.push(t1[0]);} // t1 is std::vector
                    else {auto t1 = generate<float>(1);vek1.push(t1[0]);}
                    VSZ[1]++;
                    vek1.display();
                }
                if ((k2 == 2) & (VSZ[1] != 0)) {
                    vek1.pop();
                    VSZ[1]--;
                    vek1.display();
                }
                if ((k2 == 3) & (VSZ[1] != 0)) m = vek1.peek();
                if (k2 == 4) n = vek1.count();
                if ((k2 == 5)& (VSZ[1] != 0)) {
                    vek1.reverse();
                    vek1.display();
                }
                if ((k2 == 7)& (VSZ[1] != 0)) {
                    int i = rand() % VSZ[1] + 1; // диапазон равен от 1 до vsz включительно
                    cout << endl;
                    cout << "Buf[" << i << "]=" << vek1.at(i) << endl;
                }
                comands();
                cout << "7.Proizvolnij dostup k element\n";
                cin >> k2;
            }
            cout << "\n\n1 VEKTOR\n";
            vek.display();
            cout << "\n\n2 VEKTOR\n";
            vek1.display();
            cout << "\n==\n";
            if (vek==vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n!=\n";
            if (vek!=vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>\n";
            if (vek>vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<=\n";
            if (vek<=vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<\n";
            if (vek<vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>=\n";
            if (vek>=vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n\n1 VEKTOR\n";
            vek.display();
            cout << "\n\n2 VEKTOR\n";
            vek1.display();

            if (VSZ[0]==VSZ[1]) {
                cout << "\nObmen date";
                swap(vek,vek1);
                cout << "\n\n1 VEKTOR\n";
                vek.display();
                cout << "\n\n2 VEKTOR\n";
                vek1.display();
            }
            break;
        }
        case 2:
        {
            cout << "Vyberi type stack:\n1.Int\n2.Float\n";
            cin >> k3;
            if (k3 == 1) Stack <int> vek(0);
            cout << "\n1 STECK\n";
            comands();
            cin >> k2;
            while (k2 != 6)
            {
                if (k2 == 1) {
                    if (k3 == 1) {auto t1 = generate<int>(1);steck.push(t1[0]);} // t1 is std::vector
                    else {auto t1 = generate<float>(1);steck.push(t1[0]);}
                    VSZ[0]++;
                    steck.display();
                }
                if ((k2 == 2) & (VSZ[0] != 0)) {
                    steck.pop();
                    VSZ[0]--;
                    steck.display();
                }
                if ((k2 == 3) & (VSZ[0] != 0)) m = steck.peek();
                if (k2 == 4) n = steck.count();
                if ((k2 == 5)& (VSZ[0] != 0)) {
                    steck.reverse();
                    steck.display();
                }
                comands();
                cin >> k2;
            }
            cout << "\n2 STECK\n";
            comands();
            cin >> k2;
            while (k2 != 6)
            {
                if (k2 == 1) {
                    if (k3 == 1) {auto t1 = generate<int>(1);steck1.push(t1[0]);} // t1 is std::vector
                    else {auto t1 = generate<float>(1);steck1.push(t1[0]);}
                    VSZ[1]++;
                    steck1.display();
                }
                if ((k2 == 2) & (VSZ[1] != 0)) {
                    steck1.pop();
                    VSZ[1]--;
                    steck1.display();
                }
                if ((k2 == 3) & (VSZ[1] != 0)) m = steck1.peek();
                if (k2 == 4) n = steck1.count();
                if ((k2 == 5)& (VSZ[1] != 0)) {
                    steck1.reverse();
                    steck1.display();
                }
                comands();
                cin >> k2;
            }
            cout << "\n\n1 STECK\n";
            steck.display();
            cout << "\n\n2 STECK\n";
            steck1.display();
            cout << "\n==\n";
            if (steck==steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n!=\n";
            if (steck!=steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>\n";
            if (steck>steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<=\n";
            if (steck<=steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<\n";
            if (steck<steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>=\n";
            if (steck>=steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n\n1 STECK\n";
            steck.display();
            cout << "\n\n2 STECK\n";
            steck1.display();
            if (VSZ[0] == VSZ[1]) {
                cout << "\nObmen date";
                swap(steck,steck1);
                cout << "\n\n1 STECK\n";
                steck.display();
                cout << "\n\n2 STECK\n";
                steck1.display();
            }
            break;
        }
        case 3:
        {
            cout << "Vyberi type otcheredi:\n1.Int\n2.Float\n";
            cin >> k3;
            if (k3 == 1) Queue <int> otshered(0);
            cout << "\n1 otshered\n";
            comands();
            cin >> k2;
            while (k2 != 6)
            {
                if (k2 == 1) {
                    if (k3 == 1) {auto t1 = generate<int>(1);otshered.push(t1[0]);} // t1 is std::vector
                    else {auto t1 = generate<float>(1);otshered.push(t1[0]);}
                    VSZ[0]++;
                    otshered.display();
                }
                if ((k2 == 2) & (VSZ[0] != 0)) {
                    otshered.pop();
                    VSZ[0]--;
                    otshered.display();
                }
                if ((k2 == 3) & (VSZ[0] != 0)) m = otshered.peek();
                if (k2 == 4) n = otshered.count();
                if ((k2 == 5)& (VSZ[0] != 0)) {
                    otshered.reverse();
                    otshered.display();
                }
                comands();
                cin >> k2;
            }
            cout << "\n2 otshered\n";
            comands();
            cin >> k2;
            while (k2 != 6)
            {
                if (k2 == 1) {
                    if (k3 == 1) {auto t1 = generate<int>(1);otshered1.push(t1[0]);} // t1 is std::vector
                    else {auto t1 = generate<float>(1);otshered1.push(t1[0]);}
                    VSZ[1]++;
                    otshered1.display();
                }
                if ((k2 == 2) & (VSZ[1] != 0)) {
                    otshered1.pop();
                    VSZ[1]--;
                    otshered1.display();
                }
                if ((k2 == 3) & (VSZ[1] != 0)) m = otshered1.peek();
                if (k2 == 4) n = otshered1.count();
                if ((k2 == 5)& (VSZ[1] != 0)) {
                    otshered1.reverse();
                    otshered1.display();
                }
                comands();
                cin >> k2;
            }
            cout << "\n\n1 otshered\n";
            otshered.display();
            cout << "\n\n2 otshered\n";
            otshered1.display();
            cout << "\n==\n";
            if (otshered==otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n!=\n";
            if (otshered!=otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>\n";
            if (otshered>otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<=\n";
            if (otshered<=otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<\n";
            if (otshered<otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>=\n";
            if (otshered>=otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n\n1 otshered\n";
            otshered.display();
            cout << "\n\n2 otshered\n";
            otshered1.display();
            if (VSZ[0] == VSZ[1]) {
                cout << "\nObmen date";
                swap(otshered,otshered1);
                cout << "\n\n1 otshered\n";
                otshered.display();
                cout << "\n\n2 otshered\n";
                otshered1.display();
            }
            break;
        }
    }
    getchar();
    return 0;
}