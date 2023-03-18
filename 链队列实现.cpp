#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class queue
{
private:
	Node<T>* _front;
	Node<T>* _rear;
	size_t _size;
public:
	queue();
	~queue();
	void push(T elem);
	void pop();
	bool empty();
	size_t size();
	T front();
	T back();
	void clear();

};

template<class T>
queue<T>::queue()
{
	_size = 0;
	_front = _rear = NULL;
}

template<class T>
queue<T>::~queue()
{
	Node<T>* tmp;
	while (_size)
	{
		tmp = _front;
		_front = _front->next;
		delete tmp;
		--_size;
	}
}

template<class T>
void queue<T>::push(T elem)
{
	try
	{
		Node<T>* s = new Node<T>;
		s->data = elem;
		s->next = NULL;
		if (_rear) _rear->next = s;		//前尾节点next指向当前节点
		else _front = s;
		_rear = s;
		++_size;
	}
	catch (...)
	{
		abort();
	}
}

template<class T>
void queue<T>::pop()
{
	if (!_size) abort();
	Node<T>* tmp = _front;
	_front = _front->next;
	delete tmp;
	--_size;
}

template<class T>
bool queue<T>::empty()
{
	return _size == 0;
}

template<class T>
size_t queue<T>::size()
{
	return _size;
}

template<class T>
T queue<T>::front()
{
	if (_front)
		return _front->data;
	else abort();
}

template<class T>
T queue<T>::back()
{
	if (_rear)
		return _rear->data;
	else abort();
}

template<class T>
void queue<T>::clear()
{
	Node* tmp;
	while (_size)
	{
		tmp = _front;
		_front = _front->next;
		delete tmp;
		--_size;
	}
	_rear = _front = NULL;
}

int main()
{
	//测试代码
	queue<double> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.pop();
	a.push(9);
	//a.clear();
	cout << a.empty() << '\n';
	a.push(11);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	cout << a.front() << '\n';
	cout << a.back() << '\n';
	cout << a.size() << '\n';
	cout << a.empty() << '\n';
	return 0;

}