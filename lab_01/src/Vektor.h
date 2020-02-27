# include <iostream>
template <typename T>
class Vektor
{
private:
	T*Buffer;
	int Size;
public:
	Vektor(int nSize);
	~Vektor();
	/*stack functions*/
	void  display();
	void push(T);//вставка элемента в структуру;
	void pop();//выталкивание элемента из структуры;
	T at(int);//метод произвольного доступа к элементу, реализуется только для структуры вектор;
	T peek();//возврат вершины структуры (верхнего элемента);
	int count();//возврат количества элементов в структуре;
	void reverse();//смены порядка элементов в структуре на обратный (reverse);
	friend void swap(Vektor<T> &m1, Vektor<T> &m2)//обмена (swap) данными между структурами;
	{
		T a;
		for (int i = 0; i < m1.Size; i++)
		{
			a = m1.Buffer[i];
			m1.Buffer[i] = m2.Buffer[i];;
			m2.Buffer[i] = a;
		}
	};

	friend bool operator == (Vektor<T> &m1, Vektor<T> &m2)
	{
		if (m1.Size != m2.Size) {
			return false;
		}
		else
		{
			int i = 0;
			do {
				if (m1.Buffer[i] != m2.Buffer[i]) return false;
				i++;
			} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < m1.Size));
			return  true;
		}
	};
	friend bool operator != (Vektor<T> &m1, Vektor<T> &m2)
	{
		return !(m1 == m2);
	};
	friend bool operator > (Vektor<T> &m1, Vektor<T>&m2)
	{
		int minimum = 0;
		if (m1.Size < m2.Size) minimum = m1.Size;
		else minimum = m2.Size;
		int i = 0;
		do {
			if (m1.Buffer[i] < m2.Buffer[i]) return false;
			if (m1.Buffer[i] > m2.Buffer[i]) return true;
			i++;
		} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < minimum));

		if (m1.Size > m2.Size)
		{
			return true;
		}
		return false;

	};
	friend bool operator < (Vektor<T> &m1, Vektor<T> &m2)
	{
		int minimum = 0;
		if (m1.Size < m2.Size) minimum = m1.Size;
		else minimum = m2.Size;
		int i = 0;
		do {
			if (m1.Buffer[i] > m2.Buffer[i]) return false;
			if (m1.Buffer[i] < m2.Buffer[i]) return true;
			i++;
		} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < minimum));

		if (m1.Size < m2.Size)
		{
			return true;
		}
		return false;
	};
	friend bool operator >= (Vektor<T> &m1, Vektor<T> &m2)
	{
		return !(m1 < m2);
	};
	friend bool operator <= (Vektor<T> &m1, Vektor<T> &m2) {
		return !(m1 > m2);
	};
};
template <typename T>
Vektor<T>::Vektor(int nSize)
{
	Size = nSize;
	Buffer = new T[Size];
};
template <typename T>
Vektor<T>::~Vektor()
{
	delete[] Buffer;
};
template <typename T>
void Vektor<T>::display()
{
	cout << "\nVyvod elem Vektora\n";
	for (int i = 0; i < Size; i++)
		cout << Buffer[i] << " ";
};
template <typename T>
void  Vektor<T>::push(T a)
{
	T * k;
	k = new T[Size + 1];
	for (int i = 0; i < Size; i++)
		k[i] = Buffer[i];
	k[Size] = a;
	delete Buffer;
	Size++;
	Buffer = k;
};
template <typename T>
void Vektor<T>::pop()
{
	T * k;
	k = new T[Size - 1];
	for (int i = 0; i < Size - 1; i++)
		k[i] = Buffer[i];
	delete Buffer;
	Size--;
	Buffer = k;
};
template <typename T>
T  Vektor<T>::at(int i)
{
	if ((i < 0) || (i >= Size))
	{
		return  0;
	}
	else return Buffer[i];
};
template <typename T>
T Vektor<T>::peek()
{
	cout << endl << "Vershina vektora:";
	cout << endl << Buffer[0] << endl;
	return Buffer[0];
};
template <typename T>

int Vektor<T>::count()
{
	cout << endl << Size;
	return Size;
};
template <typename T>
void Vektor<T>::reverse()
{
	for (int i = 0; i < Size / 2; i++)
	{
		T x = Buffer[i];
		Buffer[i] = Buffer[Size - 1 - i];
		Buffer[Size - 1 - i] = x;
	}
};
