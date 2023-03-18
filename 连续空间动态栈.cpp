、#include<iostream>
using namespace std;

template<class T>		//类型模版
class stack
{
private:
	size_t _size;	//现有元素个数
	T* data;
	int _top;		//栈顶元素下标
	size_t _capacity;	//容量
public:
	stack();
	~stack();
	T top();
	void push(T elem);
	void pop();
	bool empty();
	size_t size();
	size_t capacity();
	void clear();
};

template<class T>
stack<T>::stack()
{
	_size = 0;
	_top = -1;
	try
	{
		data = new T[10];
	}
	catch (const exception&)
	{
		abort();
	}
	_capacity = 10;
}

template<class T>
stack<T>::~stack()
{
	delete[] data;
}

template<class T>
T stack<T>::top()
{
	if (_size) return data[_top];
	else abort();
}

template<class T>
void stack<T>::push(T elem)
{
	if (_capacity - _size < 3)			//扩容机制
	{
		T* temp = new T[(int)(_capacity * 1.5)];
		memmove(temp, data, _capacity * sizeof(T));
		delete[] data;
		data = temp;
		_capacity *= 1.5;
	}
	++_top;
	try
	{
		data[_top] = elem;
	}
	catch (const exception&)
	{
		abort();
	}
	++_size;
}

template<class T>
void stack<T>::pop()
{
	if (_size > 0)
	{
		--_top;
		--_size;
	}
	else abort();
	if ((double)_size / _capacity < 0.5 && _capacity > 40)		//缩容机制
	{
		T* temp = new T[(int)(_capacity * 0.75)];
		memmove(temp, data, _size * sizeof(T));
		delete[] data;
		data = temp;
		_capacity *= 0.75;
	}
}

template<class T>
bool stack<T>::empty()
{
	return (_size == 0);
}

template<class T>
size_t stack<T>::size()
{
	return _size;
}

template<class T>
size_t stack<T>::capacity()
{
	return _capacity;
}

template<class T>
void stack<T>::clear()
{
	delete[] data;
	try
	{
		data = new T[10];
	}
	catch (const exception&)
	{
		abort();
	}
	_size = 0;
	_top = -1;
	_capacity = 10;
}

int main()
{
	//测试代码
	stack<int> a;
	a.push(1);
	a.clear();
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(11);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(8);
	a.push(9);
	a.push(9);
	//a.clear();
	a.push(10);
	a.push(11);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();

	cout << a.top() << '\n';
	//	cout << a.empty()<<'\n';
	cout << a.capacity() << '\n';
	cout << a.size();
	return 0;
}