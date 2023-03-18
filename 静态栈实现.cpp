#include<iostream>
using namespace std;
class stack
{
private:
	int* data;
	size_t _size;
	int _top;
	size_t _capacity;
public:
	stack(size_t capacity)
	{
		_size = 0;
		_top = -1;
		try
		{
			data = new int[capacity];
		}
		catch (const std::exception&)
		{
			abort();
		}
		_capacity = capacity;
	}
	~stack()
	{
		delete[] data;
	}
	int top()
	{
		if (_size) return data[_top];
		else abort();
	}
	void push(int elem)
	{
		if (_size < _capacity)
		{
			data[_top + 1] = elem;
			++_size;
			++_top;
		}
		else abort();
	}
	void pop()
	{
		if (_size > 0)
		{
			--_top;
			--_size;
		}
		else abort();
	}
	bool empty()
	{
		return (_size == 0 ? true : false);
	}
	bool full()
	{
		return (_size == _capacity ? true : false);
	}
	size_t size()
	{
		return _size;
	}
	size_t capacity()
	{
		return _capacity;
	}
	void clear()
	{
		_top = -1;
		_size = 0;
	}
};




int main()
{
	stack a(5);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(1);
	a.push(1);
	a.pop();

	//a.clear();
	cout << a.top() << '\n';
	cout << a.capacity() << '\n';
	cout << a.full() << '\n';
	cout << a.empty() << '\n';
	cout << a.size();
	return 0;
}
