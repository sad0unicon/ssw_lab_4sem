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
    Vektor(int);
    ~Vektor();
    void vout();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    T count();//возврат количества элементов в структуре;
    T at(int);//метод произвольного доступа к элементу
    T Value(int);
    void zamena(int,T);
    void reverse();
    friend bool operator ==(Vektor<T> &m1,Vektor<T> &m2)
    {
        bool s1=1;
        if (m1.size==m2.size)
        {
            for (int i=0;i<=m1.size-1;i++)
                s1*=m1.Buf[i]==m2.Buf[i];
        };
        return((m1.size==m1.size)&&s1);
    };
    friend bool operator !=(Vektor<T> &m1,Vektor<T> &m2)
    {
        return !(m1==m2);
    };
    friend bool operator > (Vektor<T> &m1,Vektor<T> &m2)
    {
        bool s2=1;
        if (m1.size==m2.size)
        {
            for (int i=0;i<m1.size-1;i++)
                s2*=m1.Buf[i]>=m2.Buf[i];
            s2*=m1.Buf[m1.size-1]>m2.Buf[m2.size-1];
            return(s2);
        };
        return(m1.size>m2.size);
    };
    friend bool operator < (Vektor<T> &m1,Vektor<T> &m2)
    {
        bool s3=1;
        if (m1.size==m2.size)
        {
            for (int i=0;i<m1.size-1;i++)
                s3*=m1.Buf[i]<=m2.Buf[i];
            s3*=m1.Buf[m1.size-1]<m2.Buf[m2.size-1];
            return(s3);
        };
        return(m1.size<m2.size);
    };
};
template <typename T>
Vektor<T>::Vektor(int nSize)
{
    size = nSize;
    Buf = new T[size];
};
template <typename T>
Vektor<T>::~Vektor()
{
    delete[] Buf;
};
template <typename T>
void Vektor<T>::vout()
{
    cout << "\nVyvod elements vecktor:\n";
    for (int i = 0; i < size; i++) cout << Buf[i] << "  ";
};
template <typename T>
void Vektor<T>::push(T b)
{
    T *l;
    l = new T[size + 1];
    for (int i = 0; i < size; i++)
        l[i] = Buf[i];
    l[size] = b;
    delete Buf;
    size++;
    Buf = l;
};
template <typename T>
void Vektor<T>::pop()
{
    T *t;
    t = new T[size - 1];
    for (int i = 0; i < size - 1; i++)
        t[i] = Buf[i];
    delete Buf;
    Buf = t;
    size--;
};
template <typename T>
T Vektor<T>::peek()
{
    cout << endl << Buf[0] << endl;
    return Buf[0];
};
template <typename T>
T Vektor<T>::count()
{
    cout << endl << size << endl;
    return size;
};
template <typename T>
T Vektor<T>::at(int i)
{
    cout << endl << "Buf[" << i << "]=" << Buf[i-1] << endl;
    return Buf[i-1];
};
template <typename T>
T Vektor<T>::Value(int i)
{
    return Buf[i];
};
template <typename T>
void Vektor<T>::zamena(int i,T b)
{
    Buf[i]=b;
};
template <typename T>
void Vektor<T>::reverse()
{
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
    Stack(int);
    ~Stack();
    void sout();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    T count();//возврат количества элементов в структуре;
    T Value(int);
    void zamena(int, T);
    void reverse();
    friend bool operator ==(Stack<T> &m1,Stack<T> &m2)
    {
        bool s1=1;
        if (m1.size1==m2.size1)
        {
            for (int i=0;i<=m1.size1-1;i++)
                s1*=m1.Buf1[i]==m2.Buf1[i];
        };
        return((m1.size1==m1.size1)&&s1);
    };
    friend bool operator !=(Stack<T> &m1,Stack<T> &m2)
    {
        return !(m1==m2);
    };
    friend bool operator > (Stack<T> &m1,Stack<T> &m2)
    {
        bool s2=1;
        if (m1.size1==m2.size1)
        {
            for (int i=0;i<m1.size1-1;i++)
                s2*=m1.Buf1[i]>=m2.Buf1[i];
            s2*=m1.Buf1[m1.size1-1]>m2.Buf1[m2.size1-1];
            return(s2);
        };
        return(m1.size1>m2.size1);
    };
    friend bool operator < (Stack<T> &m1,Stack<T> &m2)
    {
        bool s3=1;
        if (m1.size1==m2.size1)
        {
            for (int i=0;i<m1.size1-1;i++)
                s3*=m1.Buf1[i]<=m2.Buf1[i];
            s3*=m1.Buf1[m1.size1-1]<m2.Buf1[m2.size1-1];
            return(s3);
        };
        return(m1.size1<m2.size1);
    };
};
template <typename T>
Stack<T>::Stack(int nSize1)
{
    size1 = nSize1;
    Buf1 = new T[size1];
};
template <typename T>
Stack<T>::~Stack()
{
    delete[] Buf1;
};
template <typename T>
void Stack<T>::sout()
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
    delete Buf1;
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
    delete Buf1;
    Buf1 = t;
    size1--;
};
template <typename T>
T Stack<T>::peek()
{
    cout << endl << Buf1[size1-1] << endl;
    return Buf1[size1-1];
};
template <typename T>
T Stack<T>::count()
{
    cout << endl << size1 << endl;
    return size1;
};
template <typename T>
T Stack<T>::Value(int i)
{
    return Buf1[i];
};
template <typename T>
void Stack<T>::zamena(int i, T b)
{
    Buf1[i] = b;
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
    Queue(int);
    ~Queue();
    void qout();
    void push(T); //вставка элемента в структуру;
    void pop();  //выталкивание элемента из структуры;
    T peek(); //возврат вершины структуры(верхнего элемента);
    T count();//возврат количества элементов в структуре;
    T Value(int);
    void zamena(int, T);
    void reverse();
    friend bool operator ==(Queue<T> &m1,Queue<T> &m2)
    {
        bool s1=1;
        if (m1.size2==m2.size2)
        {
            for (int i=0;i<=m1.size2-1;i++)
                s1*=m1.Buf2[i]==m2.Buf2[i];
        };
        return((m1.size2==m1.size2)&&s1);
    };
    friend bool operator !=(Queue<T> &m1,Queue<T> &m2)
    {
        return !(m1==m2);
    };
    friend bool operator > (Queue<T> &m1,Queue<T> &m2)
    {
        bool s2=1;
        if (m1.size2==m2.size2)
        {
            for (int i=0;i<m1.size2-1;i++)
                s2*=m1.Buf2[i]>=m2.Buf2[i];
            s2*=m1.Buf2[m1.size2-1]>m2.Buf2[m2.size2-1];
            return(s2);
        };
        return(m1.size2>m2.size2);
    };
    friend bool operator < (Queue<T> &m1,Queue<T> &m2)
    {
        bool s3=1;
        if (m1.size2==m2.size2)
        {
            for (int i=0;i<m1.size2-1;i++)
                s3*=m1.Buf2[i]<=m2.Buf2[i];
            s3*=m1.Buf2[m1.size2-1]<m2.Buf2[m2.size2-1];
            return(s3);
        };
        return(m1.size2<m2.size2);
    };
};
template <typename T>
Queue<T>::Queue(int nSize2)
{
    size2 = nSize2;
    Buf2 = new T[size2];
};
template <typename T>
Queue<T>::~Queue()
{
    delete[] Buf2;
};
template <typename T>
void Queue<T>::qout()
{
    cout << "\nVyvod elements otcheredi:\n";
    for (int i = size2 - 1; i >= 0; i--) cout << Buf2[i] <<"  ";
};
template <typename T>
void Queue<T>::push(T b)
{
    T *l;
    l = new T[size2 + 1];
    l[0] = b;
    for (int i = 0; i < size2; i++)
        l[i+1] = Buf2[i];
    delete Buf2;
    size2++;
    Buf2 = l;
};
template <typename T>
void Queue<T>::pop()
{
    T *t;
    t = new T[size2 - 1];
    for (int i = 0; i < size2 - 1; i++)
        t[i] = Buf2[i];
    delete Buf2;
    Buf2 = t;
    size2--;
};
template <typename T>
T Queue<T>::peek()
{
    cout << endl << Buf2[size2 - 1] << endl;
    return Buf2[size2 - 1];
};
template <typename T>
T Queue<T>::count()
{
    cout << endl << size2 << endl;
    return size2;
};
template <typename T>
T Queue<T>::Value(int i)
{
    return Buf2[i];
};
template <typename T>
void Queue<T>::zamena(int i, T b)
{
    Buf2[i] = b;
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
            VSZ[0] = 0;VSZ[1] = 0;
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
                    vek.vout();
                }
                if ((k2 == 2) & (VSZ[0] != 0)) {
                    vek.pop();
                    VSZ[0]--;
                    vek.vout();
                }
                if ((k2 == 3) & (VSZ[0] != 0)) m = vek.peek();
                if (k2 == 4) n = vek.count();
                if ((k2 == 5)& (VSZ[0] != 0)) {
                    vek.reverse();
                    vek.vout();
                }
                if ((k2 == 7)& (VSZ[0] != 0)) {
                    int i = rand() % VSZ[0] + 1; // диапазон равен от 1 до vsz включительно
                    m = vek.at(i);
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
                    vek1.vout();
                }
                if ((k2 == 2) & (VSZ[1] != 0)) {
                    vek1.pop();
                    VSZ[1]--;
                    vek1.vout();
                }
                if ((k2 == 3) & (VSZ[1] != 0)) m = vek1.peek();
                if (k2 == 4) n = vek1.count();
                if ((k2 == 5)& (VSZ[1] != 0)) {
                    vek1.reverse();
                    vek1.vout();
                }
                if ((k2 == 7)& (VSZ[1] != 0)) {
                    int i = rand() % VSZ[1] + 1; // диапазон равен от 1 до vsz включительно
                    m = vek1.at(i);
                }
                comands();
                cout << "7.Proizvolnij dostup k element\n";
                cin >> k2;
            }
            cout << "\n\n1 VEKTOR\n";
            vek.vout();
            cout << "\n\n2 VEKTOR\n";
            vek1.vout();
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
            if (!(vek>vek1)) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<\n";
            if (vek<vek1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>=\n";
            if (!(vek<vek1)) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n\n1 VEKTOR\n";
            vek.vout();
            cout << "\n\n2 VEKTOR\n";
            vek1.vout();

            if (VSZ[0]==VSZ[1]) {
                cout << "\nObmen date";
                for (int i = 0; i < VSZ[0]; i++) {
                    a = vek.Value(i);
                    b = vek1.Value(i);
                    c = a;
                    a = b;
                    b = c;
                    vek.zamena(i, a);
                    vek1.zamena(i, b);
                }
                cout << "\n\n1 VEKTOR\n";
                vek.vout();
                cout << "\n\n2 VEKTOR\n";
                vek1.vout();
            }
            break;
        }
        case 2:
        {
            VSZ[0] = 0;VSZ[1] = 0;
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
                    steck.sout();
                }
                if ((k2 == 2) & (VSZ[0] != 0)) {
                    steck.pop();
                    VSZ[0]--;
                    steck.sout();
                }
                if ((k2 == 3) & (VSZ[0] != 0)) m = steck.peek();
                if (k2 == 4) n = steck.count();
                if ((k2 == 5)& (VSZ[0] != 0)) {
                    steck.reverse();
                    steck.sout();
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
                    steck1.sout();
                }
                if ((k2 == 2) & (VSZ[1] != 0)) {
                    steck1.pop();
                    VSZ[1]--;
                    steck1.sout();
                }
                if ((k2 == 3) & (VSZ[1] != 0)) m = steck1.peek();
                if (k2 == 4) n = steck1.count();
                if ((k2 == 5)& (VSZ[1] != 0)) {
                    steck1.reverse();
                    steck1.sout();
                }
                comands();
                cin >> k2;
            }
            cout << "\n\n1 STECK\n";
            steck.sout();
            cout << "\n\n2 STECK\n";
            steck1.sout();
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
            if (!(steck>steck1)) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<\n";
            if (steck<steck1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>=\n";
            if (!(steck<steck1)) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n\n1 STECK\n";
            steck.sout();
            cout << "\n\n2 STECK\n";
            steck1.sout();
            if (VSZ[0] == VSZ[1]) {
                cout << "\nObmen date";
                for (int i = 0; i < VSZ[0]; i++) {
                    a = steck.Value(i);
                    b = steck1.Value(i);
                    c = a;
                    a = b;
                    b = c;
                    steck.zamena(i, a);
                    steck1.zamena(i, b);
                }
                cout << "\n\n1 STECK\n";
                steck.sout();
                cout << "\n\n2 STECK\n";
                steck1.sout();
            }
            break;
        }
        case 3:
        {
            VSZ[0] = 0;VSZ[1] = 0;
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
                    otshered.qout();
                }
                if ((k2 == 2) & (VSZ[0] != 0)) {
                    otshered.pop();
                    VSZ[0]--;
                    otshered.qout();
                }
                if ((k2 == 3) & (VSZ[0] != 0)) m = otshered.peek();
                if (k2 == 4) n = otshered.count();
                if ((k2 == 5)& (VSZ[0] != 0)) {
                    otshered.reverse();
                    otshered.qout();
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
                    otshered1.qout();
                }
                if ((k2 == 2) & (VSZ[1] != 0)) {
                    otshered1.pop();
                    VSZ[1]--;
                    otshered1.qout();
                }
                if ((k2 == 3) & (VSZ[1] != 0)) m = otshered1.peek();
                if (k2 == 4) n = otshered1.count();
                if ((k2 == 5)& (VSZ[1] != 0)) {
                    otshered1.reverse();
                    otshered1.qout();
                }
                comands();
                cin >> k2;
            }
            cout << "\n\n1 otshered\n";
            otshered.qout();
            cout << "\n\n2 otshered\n";
            otshered1.qout();
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
            if (!(otshered>otshered1)) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n<\n";
            if (otshered<otshered1) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n>=\n";
            if (!(otshered<otshered1)) {cout << "da\n";}
            else {cout << "net\n";}
            cout << "\n\n1 otshered\n";
            otshered.qout();
            cout << "\n\n2 otshered\n";
            otshered1.qout();
            if (VSZ[0] == VSZ[1]) {
                cout << "\nObmen date";
                for (int i = 0; i < VSZ[0]; i++) {
                    a = otshered.Value(i);
                    b = otshered1.Value(i);
                    c = a;
                    a = b;
                    b = c;
                    otshered.zamena(i, a);
                    otshered1.zamena(i, b);
                }
                cout << "\n\n1 otshered\n";
                otshered.qout();
                cout << "\n\n2 otshered\n";
                otshered1.qout();
            }
            break;
        }
    }
    getchar();
    return 0;
}