# include <iostream>
template <typename T>
class Queue
{
private:
	T*Buffer;
	int Size;
	int n{ 0 };
public:
	Queue(int nSize);
	~Queue();
	void  display();
	void push(T);//вставка элемента в структуру;
	void pop();//выталкивание элемента из структуры;
	T peek();//возврат вершины структуры (верхнего элемента);
	int count();//возврат количества элементов в структуре;
	void reverse();//смены порядка элементов в структуре на обратный (reverse);
	friend void swap(Queue<T> &m1, Queue<T> &m2)//обмена (swap) данными между структурами;
	{
		T a;
		for (int i = 0; i < m1.Size; i++)
		{
			a = m1.Buffer[i];
			m1.Buffer[i] = m2.Buffer[i];;
			m2.Buffer[i] = a;
		}
	};
	/////////////////////////////
	friend bool operator == (Queue<T> &m1, Queue<T> &m2)
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
	friend bool operator != (Queue<T> &m1, Queue<T> &m2)
	{
		return !(m1 == m2);
	};
	friend bool operator > (Queue<T> &m1, Queue<T>&m2)
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
	friend bool operator >= (Queue<T> &m1, Queue<T> &m2)
	{
		return !(m1 < m2);
	};
	friend bool operator < (Queue<T> &m1, Queue<T> &m2)
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

	friend bool operator <= (Queue<T> &m1, Queue<T> &m2)
	{
		return !(m1 > m2);
	};
};
template <typename T>
Queue<T>::Queue(int nSize)
{
	Size = nSize;
	Buffer = new T[Size];
};
template <typename T>
Queue<T>::~Queue()
{
	delete[] Buffer;
};
template <typename T>
void Queue<T>::display()
{
	cout << "\nVyvod elem Queue\n";
	for (int i = 0; i < Size; i++)
		cout << Buffer[i] << " ";
};
template <typename T>
void  Queue<T>::push(T a)
{
	T * k;
	k = new T[Size + 1];
	for (int i = 0; i < Size; i++)
		k[i] = Buffer[i];
	k[Size] = a;
	delete[] Buffer;
	Size++;
	Buffer = k;
};
template <typename T>
void Queue<T>::pop()
{
	T * k;
	k = new T[Size - 1];
	for (int i = 1; i < Size; i++)
		k[i - 1] = Buffer[i];
	delete[] Buffer;
	Size--;
	Buffer = k;
};
template <typename T>
T Queue<T>::peek()
{
	return Buffer[0];
};
template <typename T>
int Queue<T>::count()
{
	cout << endl << Size;
	return Size;
};
template <typename T>
void Queue<T>::reverse()
{
	for (int i = 0; i < Size / 2; i++)
	{
		T x = Buffer[i];
		Buffer[i] = Buffer[Size - 1 - i];
		Buffer[Size - 1 - i] = x;
	}
};