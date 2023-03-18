#include<iostream>
using namespace std;


class stack
{
private:
	size_t _size;
	int** ptrlist;
	int _top;
	size_t _capacity;
public:
	stack()
	{
		_size = 0;
		_top =-1;
		try
		{
			ptrlist = new int* [10];
		}
		catch (const std::exception&)
		{
			abort();
		}
		_capacity = 10;
	}
	~stack()
	{
		while (_top!=-1)
		{
			delete ptrlist[_top];
			--_top;
		}
		delete[] ptrlist;
	}
	int top()
	{
		if (_size) return *ptrlist[_top];
		else abort();
	}
	void push(int elem)
	{
		if (_capacity - _size < 3)
		{
			
			int** temp = new int* [(int)(_capacity*1.5)];
			memmove(temp, ptrlist, _capacity * sizeof(int*));
			delete[] ptrlist;
			ptrlist = temp;
			_capacity *= 1.5;
		}
		++_top;
		try
		{
			ptrlist[_top] = new int(elem);
		}
		catch (const std::exception&)
		{
			abort();
		}
		++_size;
	}
	void pop()
	{
		if (_size > 0)
		{
			delete ptrlist[_top];
			--_top ;
			--_size ;
		}
		else abort();
		if ((double)_size / _capacity < 0.5 && _capacity > 40)
		{
			int** temp = new int* [(int)(_capacity * 0.75)];
			memmove(temp, ptrlist, _size*sizeof(int*));		
			delete[] ptrlist;
			ptrlist = temp;
			_capacity *= 0.75;
		}
	}
	bool empty()
	{
		return (_size == 0 ? true : false);
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
		while (_top!=-1)
		{
			delete ptrlist[_top];
			--_top;
		}
		try
		{
			ptrlist = new int* [10];
		}
		catch (const std::exception&)
		{
			abort();
		}
		_capacity = 10;
		_size = 0;
	}
};


int main()
{
	stack a;
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

	cout<<a.top()<<'\n';
//	cout << a.empty()<<'\n';
	cout << a.capacity() << '\n';
	cout << a.size();
	return 0;
}
