#include "node.h"

template <class T, class Node>
class queue
{
private:
	Node* head;
	Node* current;
	Node* lastCurrent;
	T size;

public:

	queue()
	{
		head = nullptr;
		current = nullptr;
		lastCurrent = nullptr;
		size = 0;
	}

	Node* getCurrent()
	{
		return current;
	}

	void enqueue(T data)
	{
		size++;
		if (head == nullptr) {
			head = new Node(data);
			current = head;
			lastCurrent = head;
			return;
		}
		Node* iterator = head;
		while (iterator->getNext() != nullptr)
			iterator = iterator->getNext();
		iterator->setNext(new Node(data));
	}

	void push(T data)
	{
		Node* newNode = new Node(data);
		newNode->setNext(head);
		head = newNode;
		size++;
	}

	void display()
	{
		Node* iterator = head;
		while (iterator != nullptr)
		{
			cout << "|" << iterator->getData() << "|";
			iterator = iterator->getNext();
			if (iterator != nullptr)
				cout << " -> ";
		}

		cout << endl;
	}

	T headData()
	{
		return head->getData();
	}

	T dequeue()
	{
		Node* temp = head;
		T dataBackup = temp->getData();
		head = head->getNext();
		delete temp;
		size--;
		return dataBackup;
	}

	T getSize()
	{
		return size;
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
};