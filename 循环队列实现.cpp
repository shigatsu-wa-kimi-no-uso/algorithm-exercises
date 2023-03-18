#include<iostream>
using namespace std;

template<class T>
class cqueue
{
private:
	T* _front;
	T* _rear;
	T* _write;
	T* _base;
	size_t _size;
	size_t _capacity;
public:
	cqueue(const size_t capacity);
	~cqueue();
	T front();
	T back();
	bool empty();
	bool full();
	void push(T elem);
	void pop();
	size_t capacity();
	size_t size();
	void clear();
};

template<class T>
cqueue<T>::cqueue(const size_t capacity)
{
	_capacity = capacity;
	_size = 0;
	_front = _rear = _write = _base = new T[_capacity];
}

template<class T>
cqueue<T>::~cqueue()
{
	delete[] _base;
}

template<class T>
T cqueue<T>::front()
{
	if (_size) return *_front;
	else abort();
}

template<class T>
T cqueue<T>::back()
{
	if (_size) return *_rear;
	else abort();
}

template<class T>
bool cqueue<T>::empty()
{
	return _size==0;
}

template<class T>
bool cqueue<T>::full()
{
	return _size == _capacity;
}

template<class T>
void cqueue<T>::push(const T elem)
{
	if (_size == _capacity) abort();
	*_write = elem;
	_rear = _write;
	if (_write - _base == _capacity - 1) _write = _base;
	else ++_write;
	++_size;
}

template<class T>
size_t cqueue<T>::size()
{
	return _size;
}

template<class T>
size_t cqueue<T>::capacity()
{
	return _capacity;
}

template<class T>
void cqueue<T>::pop()
{
	if (!_size) abort();
	else if (_front - _base == _capacity -1 ) _front = _base;
	else ++_front;
	--_size;
}

template<class T>
void cqueue<T>::clear()
{
	_rear = _front=_write;
	_size = 0;
}


int main()
{
	cqueue<double> q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	q.push(5);
	cout << q.front()<<'\n';
	q.push(5);
	q.pop();
	cout << q.back() << '\n';
	q.push(6);
	q.pop();
	q.pop();
	q.pop();
	q.push(7);
	cout << q.front() << '\n';
	q.push(8);
	q.clear();
	q.push(7);
	q.push(8);


	return 0;
}