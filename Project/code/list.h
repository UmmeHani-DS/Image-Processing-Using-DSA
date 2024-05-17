#include <iostream>
using namespace std;

template <typename T>
class node
{

private:
	node<T>* next;
	T data;
public:

	node()
	{
		next = nullptr;
		data = 0;

	}

	node(T d)
	{
		data = d;
		next = nullptr;

	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(node<T>* n)
	{
		next = n;
	}

	node<T>* getNext()
	{
		return next;
	}

	T getData()
	{
		return data;
	}

};

template <typename T>

class List
{
private:

	node<T>* head;
	node<T>* current;


public:

	List()
	{
		head = nullptr;
		current = nullptr;
	}

	void insertData(T val)
	{
		node<T>* newNode = new node<T>(val);
		newNode->setData(val);

		if (head == nullptr)
		{
			head = newNode;
			current = head;
			newNode->setNext(nullptr);

		}

		else
		{
			current->setNext(newNode);
			current = newNode;
			newNode->setNext(nullptr);
		}

	}

	T removeData()
	{
		node<T>* temp = head;
		if (temp == nullptr)
		{
			return -1;
		}

		int m = temp->getData();
		head = head->getNext();
		return m;
		delete temp;
	}

	bool search(T val)
	{
		node<T>* temp = head;
		while (temp->getNext() != nullptr)
		{
			if (temp->getData() == val)
			{
				return true;
			}
			else
			{
				temp = temp->getNext();
			}
		}
		delete temp;
		return false;
	}

	bool isEmpty()
	{
		bool flag;
		if (head == nullptr)
		{
			flag = true;
		}

		else
		{
			flag = false;
		}

		return flag;
	}


	void display()
	{
		node<T>* temp = head;

		while (temp != nullptr)
		{
			cout << "|" << temp->getData() << "|";
			temp = temp->getNext();
			if (temp != nullptr)
			{
				cout << "->";
			}
		}

	}


};