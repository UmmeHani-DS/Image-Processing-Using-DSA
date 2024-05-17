#include "snode.h"

template <class T, class SNode>
class stack
{
	SNode* top;

public:

	stack()
	{
		top = nullptr;
	}

	void push(T data)
	{
		SNode* newNode = new SNode(data);
		newNode->setNext(top);
		top = newNode;
	}

	T pop()
	{
		SNode* temp = top;
		int dataBackup = temp->getData();
		top = top->getNext();
		delete temp;
		return dataBackup;
	}

	T getTop()
	{
		return top->getData();
	}

	bool isEmpty()
	{
		bool flag;

		if (top == nullptr)
		{
			flag = true;
		}

		else
		{
			flag = false;
		}

		return flag;

	}

	void print()
	{
		SNode* iterator = top;

		while (iterator != nullptr)
		{
			cout << "|" << iterator->getData() << "|";
			iterator = iterator->getNext();
			if (iterator != nullptr)
				cout << " -> ";
		}
		cout << endl;
	}


};