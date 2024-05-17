#include <iostream>
using namespace std;

template <class T>
class Node
{

private:
	Node<T>* next;
	T data;
public:

	Node()
	{
		next = nullptr;
		data = 0;

	}

	Node(T d)
	{
		data = d;
		next = nullptr;

	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(Node<T>* n)
	{
		next = n;
	}

	Node<T>* getNext()
	{
		return next;
	}

	T getData()
	{
		return data;
	}

};