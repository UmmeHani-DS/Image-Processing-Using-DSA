#include <iostream>
using namespace std;

template <class T>
class SNode
{

private:
	SNode<T>* next;
	T data;
public:

	SNode()
	{
		next = nullptr;
		data = 0;

	}

	SNode(T d)
	{
		data = d;
		next = nullptr;

	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(SNode<T>* n)
	{
		next = n;
	}

	SNode<T>* getNext()
	{
		return next;
	}

	T getData()
	{
		return data;
	}

};
