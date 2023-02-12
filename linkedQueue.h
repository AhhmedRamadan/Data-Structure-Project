#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}

};

class linkedQueue
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL;
	}

	bool isEmpty()
	{
		if (front == NULL )
			return true;
		else
			return false;

	}

	void enqueue(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;

		if (isEmpty())
			front = rear = newnode;
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}
	void printQueue()
	{
		if (isEmpty())
			cout << "Queue is Empty, no items to display \n";
		else
		{
			Node* temp = front;
			cout<<"[ ";
			while (temp != NULL)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout<<" ]";
			cout << endl;
		}
	}

	int count()
	{
		int counter = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool isFound(int item)
	{
		bool found = false;
		Node* temp = front;
		while (temp != NULL)
		{
			if (temp->data == item)
				found = true;
			temp = temp->next;
		}
		return found;
	}

	int dequeue()
	{
		int delvalue = -1;
		if (isEmpty())
			cout << "The queue is empty \n";
		else if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* delptr = front;
			front = front->next;
			delvalue = delptr->data;
			delete delptr;
		}

		return delvalue;
	}



	void  clearAllElements()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}


	void dequeueSomeElements(int num)
	{

		int delvalue = -1;
		if (isEmpty())
			cout << "The queue is empty \n";
		else if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
		    for(int i=0;i<num;i++)
                {
			Node* delptr = front;
			front = front->next;
			delvalue = delptr->data;
			delete delptr;
                }
		}


	}
};

#endif // LINKEDQUEUE_H_INCLUDED





