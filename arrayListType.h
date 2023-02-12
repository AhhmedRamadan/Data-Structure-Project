#pragma once
//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************
#include <iostream>
#include <cassert>  

using namespace std;

template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator=
		(const arrayListType<elemType>&);
	//Overloads the assignment operator

	bool isEmpty() const;
	//Function to determine whether the list is empty
	//Postcondition: Returns true if the list is empty;
	// otherwise, returns false.

	bool isFull() const;
	//Function to determine whether the list is full.
	//Postcondition: Returns true if the list is full;
	// otherwise, returns false.

	int listSize() const;
	//Function to determine the number of elements in the list
	//Postcondition: Returns the value of length.

	int maxListSize() const;
	//Function to determine the size of the list.
	//Postcondition: Returns the value of maxSize.

	void print() const;
	//Function to output the elements of the list
	//Postcondition: Elements of the list are output on the
	// standard output device.

	bool isItemAtEqual(int location, const elemType& item) const;
	//Function to determine whether the item is the same
	//as the item in the list at the position specified by
	//Postcondition: Returns true if list[location]
	// is the same as the item; otherwise,
	// returns false.

	void insertAt(int location, const elemType& insertItem);
	//Function to insert an item in the list at the
	//position specified by location. The item to be inserted
	//is passed as a parameter to the function.
	//Postcondition: Starting at location, the elements of the
	// list are shifted down, list[location] = insertItem;,
	// and length++;. If the list is full or location is
	// out of range, an appropriate message is displayed.

	void insertEnd(const elemType& insertItem);
	//Function to insert an item at the end of the list.
	//The parameter insertItem specifies the item to be inserted.
	//Postcondition: list[length] = insertItem; and length++;
	// If the list is full, an appropriate message is
	// displayed.

	bool removeAt(int location);
	//Function to remove the item from the list at the
	//position specified by location
	//Postcondition: The list element at list[location] is removed
	// and length is decremented by 1. If location is out of
	// range, an appropriate message is displayed.

	void retrieveAt(int location, elemType& retItem) const;
	//Function to retrieve the element from the list at the
	//position specified by location.
	//Postcondition: retItem = list[location]
	// If location is out of range, an appropriate message is
	// displayed.

	bool replaceAt(int location, const elemType& repItem);
	//Function to replace the elements in the list at the
	//position specified by location. The item to be replaced
	//is specified by the parameter repItem.
	//Postcondition: list[location] = repItem
	// If location is out of range, an appropriate message is
	// displayed.

	void clearList();
	//Function to remove all the elements from the list.
	//After this operation, the size of the list is zero.
	//Postcondition: length = 0;

	int seqSearch(const elemType& item) const;
	//Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.

	void merge(int l, int m, int r) ;
	void mergeSort(int left=0 , int right=-1) ;

	arrayListType(int size = 1000);
	//constructor
	//Creates an array of the size specified by the
	//parameter size. The default array size is 100.
	//Postcondition: The list points to the array, length = 0,
	// and maxSize = size

	arrayListType(const arrayListType<elemType>& otherList);
	//copy constructor

	~arrayListType();
	//destructor
	//Deallocates the memory occupied by the array.

protected:
	elemType* list; //array to hold the list elements
	int length; //to store the length of the list
	int maxSize; //to store the maximum size of the list
};


template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}
template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item) const
{
	return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem) {
	if (location < 0 || location >= maxSize)
		cout<< "The position of the item to be inserted is out of range" << endl;
	else
		if (length >= maxSize) //list is full
			cout<< "Cannot insert in a full list" << endl;
		else 
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1]; 	//move the elements down
			list[location] = insertItem; //insert the item at the specified position
			length++; //increment the length
		}
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize) //the list is full
		cout << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = insertItem; //insert the item at the end
		length++; //increment the length
	}
} //end insertEnd

template <class elemType>
bool arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
	{
		cout<< "The location of the item to be removed is out of range" << endl;
		return 0 ;
	}
		
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
	return 1 ;
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const {
	if (location < 0 || location >= length)
		cout << "The location of the item to be retrieved is out of range." << endl;
	else
		retItem = list[location];
} //end retrieveAt


template <class elemType>
bool arrayListType<elemType>::
replaceAt(int location, const elemType& repItem) 
{
	if (location < 0 || location >= length)
	{
		cout << "The location of the item to be replaced is out of range." << endl;
		return 0 ;
	}
		
	else
		list[location] = repItem;
		
	return 1 ;
} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
} //end clearList

template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
	if (size <= 0) {
		cout << "The array size must be positive. ";
		cout << "Creating an array of size 100. " << endl;
		maxSize = 1000;
	}
	else
		maxSize = size;
	length = 0;
	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize]; //create the array
	assert(list != NULL); //terminate if unable to allocate memory space

	for (int j = 0; j < length; j++) //copy otherList
		list[j] = otherList.list[j];
} //end copy constructor

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete[] list;
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList) {
	if (this != &otherList) {  //avoid self-assignment
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new elemType[maxSize]; //create the array
		assert(list != NULL); //if unable to allocate memory space, terminate the program
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	for(int i=0 ; i<length ; i++)
	{
		if(list[i]==item)
			return 1 ;
	}
	return 0;
}//end seqSearch

template <class elemType>
void arrayListType<elemType>::merge(int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;
  
    /* create temp arrays */
    int Left_arr[n1], Right_arr[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        Left_arr[i] = list[left + i];
    for (j = 0; j < n2; j++)
        Right_arr[j] = list[mid + 1+ j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = j = 0; // Initial index of first subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (Left_arr[i] <= Right_arr[j])
        {
            list[k] = Left_arr[i];
            i++;
        }
        else
        {
            list[k] = Right_arr[j];
            j++;
        }
        k++;
    }
  
    while (i < n1)
    {
        list[k] = Left_arr[i];
        i++;
        k++;
    }
  
    while (j < n2)
    {
        list[k] = Right_arr[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
template <class elemType>
void arrayListType<elemType>::mergeSort(int left, int right)
{
	if(right==-1)	right=length-1 ;
    if (left < right)
    {
        int mid = left+(right-left)/2;
  
        mergeSort( left, mid);
        mergeSort( mid+1, right);
  
        merge( left, mid, right);
    }
}


