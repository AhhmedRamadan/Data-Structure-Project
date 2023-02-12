//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered doubly linked list.
//***********************************************************
//Definition of the node
#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
struct nodeTyp
{
	Type info;
	nodeTyp<Type> *next;
	nodeTyp<Type> *back;
};

template <class Type>
class doublyLinkedList
{
public:
const doublyLinkedList<Type>& operator=
(const doublyLinkedList<Type> &);
//Overload the assignment operator.
void initializeList();
//Function to initialize the list to an empty state.
//Postcondition: first = NULL; last = NULL; count = 0;
bool isEmptyList() const;
//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
// otherwise returns false.
void destroy();
//Function to delete all the nodes from the list.
//Postcondition: first = NULL; last = NULL; count = 0;
void print() const;
//Function to output the info contained in each node.
void reversePrint() const;
//Function to output the info contained in each node
//in reverse order.

int length() const;
//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.
Type front() const;
//Function to return the first element of the list.
//Precondition: The list must exist and must not be empty.
//Postcondition: If the list is empty, the program terminates;
// otherwise, the first element of the list is returned.
Type back() const;
//Function to return the last element of the list.
//Precondition: The list must exist and must not be empty.
//Postcondition: If the list is empty, the program terminates;
// otherwise, the last element of the list is returned.
void search(string searchItem) const;
//Function to determine whether searchItem is in the list.
//Postcondition: Returns true if searchItem is found in the
// list, otherwise returns false.
void insert( Type& insertItem);
//Function to insert insertItem in the list.
//Precondition: If the list is nonempty, it must be in order.
//Postcondition: insertItem is inserted at the proper place
// in the list, first points to the first node, last points
// to the last node of the new list, and count is
// incremented by 1.
void deleteNode(const Type& deleteItem);
//Function to delete deleteItem from the list.
//Postcondition: If found, the node containing deleteItem is
// deleted from the list; first points to the first node of
// the new list, last points to the last node of the new
// list, and count is decremented by 1; otherwise an
// appropriate message is printed.
doublyLinkedList();
//default constructor
//Initializes the list to an empty state.
//Postcondition: first = NULL; last = NULL; count = 0;
doublyLinkedList(const doublyLinkedList<Type>& otherList);
//copy constructor
//~doublyLinkedList();
void Next() ;
void Previous() ;
nodeTyp<Type>* get_current() ;
//destructor
//Postcondition: The list object is destroyed.
protected:
int count;
nodeTyp<Type> *first; //pointer to the first node
nodeTyp<Type> *last; //pointer to the last node
nodeTyp<Type> *current_node;
private:
void copyList(const doublyLinkedList<Type>& otherList);
//Function to make a copy of otherList.
//Postcondition: A copy of otherList is created and assigned
// to this list.
};

template <class Type>
nodeTyp<Type>* doublyLinkedList<Type>::
get_current()
{
	if(!cout) current_node=NULL ;
	return current_node ;
} 

template <class Type>
void doublyLinkedList<Type>::Next()
{
	if(count) current_node=current_node->next ;
	else current_node=NULL ; 
} 
template <class Type>
void doublyLinkedList<Type>::Previous()
{
	if(count) current_node=current_node->back ;
	else current_node=NULL ;
} 

template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
	first= NULL;
	last = NULL;
	count = 0;
}

template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
	return (first == NULL);
}

template <class Type>
void doublyLinkedList<Type>::destroy()
{
	nodeTyp<Type> *temp; //pointer to delete the node
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
	last = NULL;
	count = 0;
}

template <class Type>
void doublyLinkedList<Type>::initializeList()
{
	destroy();
}

template <class Type>
int doublyLinkedList<Type>::length() const
{
	return count;
}

template <class Type>
void doublyLinkedList<Type>::print() const
{
	nodeTyp<Type> *current; //pointer to traverse the list
	current = first; //set current to point to the first node
	while (current != NULL)
	{
	cout << current->info << " "; //output info
	current = current->next;
	}//end while
}//end print

template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
nodeTyp<Type> *current; //pointer to traverse the list
current = last; //set current to point to the last node
while (current != NULL)
{
cout << current->info << " ";
current = current->back;
}//end while
}//end reversePrint

template <class Type>
void doublyLinkedList<Type>::search(string searchItem) const
{
	if(!count)
	{
		cout<<"List is empty , try to insert some contact data"<<endl<<endl;
		return ;
	}
	
	nodeTyp<Type> *current; //pointer to traverse the list
	current = first;
	for(int i=0 ; i<count ; i++)
	{
		if (current->info.name == searchItem)
		{
			cout<<"Contact Found : "<<endl;
			cout<<"ID : "<<current->info.id<<
			endl<<"Name : "<<current->info.name<<
			endl<<"Phone Number : "<<current->info.number<<endl<<endl;
			return ;
		}
		current=current->next;
	}
	
	cout<<searchItem<<" Not found "<<endl<<endl ;

}//end search

template <class Type>
Type doublyLinkedList<Type>::front() const
{
assert(first != NULL);
return first->info;
}
template <class Type>
Type doublyLinkedList<Type>::back() const
{
assert(last != NULL);
return last->info;
}

template <class Type>
void doublyLinkedList<Type>::insert( Type& insertItem)
{
	nodeTyp<Type> *current; //pointer to traverse the list
	nodeTyp<Type> *trailCurrent; //pointer just before current
	nodeTyp<Type> *newNode; //pointer to create a node
	newNode = new nodeTyp<Type>; //create the node
	newNode->info = insertItem; //store the new item in the node
	newNode->next = NULL;
	newNode->back = NULL;
	if (first == NULL) //if list is empty, newNode is the only node
	{
		first = newNode;
		last = newNode;
		first->next=first->back =last ;
		last->next=last->back = first ;
		count++;
	}
	else
	{
		current = first;
		first->back = newNode;
		newNode->next = first;
		first = newNode;
		count++;
	}
		current_node = first ;
		first->back = last ;
		last->next = first ;
}//end insert

template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& deleteItem)
{
nodeTyp<Type> *current; //pointer to traverse the list
nodeTyp<Type> *trailCurrent; //pointer just before current

bool found;
if (first == NULL)
cout << "Cannot delete from an empty list." << endl;
else if (first->info == deleteItem) //node to be deleted is
//the first node
{
	current = first;
	first = first->next;
	if (first != NULL)
	first->back = NULL;
	else
	last = NULL;
	count--;
	delete current;
}
else
{
found = false;
current = first;
while (current != NULL && !found) //search the list
if (current->info >= deleteItem)
found = true;
else
current = current->next;
if (current == NULL)
cout << "The item to be deleted is not in "
<< "the list." << endl;
else if (current->info == deleteItem) //check for equality
{
	trailCurrent = current->back;
	trailCurrent->next = current->next;
	if (current->next != NULL)
	current->next->back = trailCurrent;
	if (current == last)
	last = trailCurrent;
	count--;
	delete current;
}
else
cout << "The item to be deleted is not in list."<<endl;
}//end else
}//end deleteNode


