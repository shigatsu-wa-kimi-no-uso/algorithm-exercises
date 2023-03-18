#include <iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	node<T>* next;
};

template<class T>
class stack
{
private:
	node<T>* _top;
	int _size;
public:
	stack();
	~stack();
	bool empty();
	T top();
	void push(T elem);
	void pop();
	void clear();
};

template<class T>
stack<T>::stack()
{
	_size = 0;
	_top = NULL;
}

template<class T>
bool stack<T>::empty()
{
	return (_size == 0);
}

template<class T>
T stack<T>::top()
{
	if (_size) return _top->data;
	else abort();
}

template<class T>
void stack<T>::push(T elem)
{
	try
	{
		node<T>* s = new node<T>;
		s->data = elem;
		s->next = _top;
		_top = s;
		++_size;
	}
	catch (const exception&)
	{
		abort();
	}

}

template<class T>
void stack<T>::pop()
{
	if (_size)
	{
		node<T>* s = _top;
		_top = _top->next;
		delete s;
		--_size;
	}
	else abort();
}

template<class T>
void stack<T>::clear()
{
	while (_size)
	{
		node<T>* s = _top;
		_top = _top->next;
		delete s;
		--_size;
	}
}

template<class T>
stack<T>::~stack()
{
	while (_size)
	{
		node<T>* s = _top;
		_top = _top->next;
		delete s;
		--_size;
	}
}

int main()
{
	stack<double> a;
	a.push(1);
	a.clear();
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(9);
	a.push(10);
	a.push(11);
	a.pop();


	cout << a.top() << '\n';
	//	cout << a.empty()<<'\n';
	return 0;
}
