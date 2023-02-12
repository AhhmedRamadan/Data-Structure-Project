#include <bits/stdc++.h>
#include <conio.h>  /* 70 = UP / 80 = DOWN / 75 = LEFT / 77 = RIGHT  */
#include <windows.h>
#include <ctime>
//#include "arrayQueueType.h"
#include "arrayListType.h"
#include "arrayStackType.h"
#include "linkedListType.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
#include "stackLinked.h"
#include "doublyLinkedList.h"

int color(int numColor=7)
{
    return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),numColor);
}

///////////////////<<<<<<<<<<<<<<<app calculations>>>>>>>>>>>>>>>>>////////////////

struct operation{
	int id ;
	static int counter ;
	string scope , data_structure , jop ;
	float time ;
};

int operation::counter=1 ;
arrayListType<operation> operations_list(1000) ;
operation jop ;
void show_app_calc()
{
	if(operation::counter==1)
	{
		cout<<"No Operations Done."<<endl;
		return ;
	}
	cout<< " ID  Scope     Data structure        Operation      Time taken" <<endl ;

	operation jop ;
	for(int i=0 ; i<operation::counter-1 ; i++)
	{
		operations_list.retrieveAt(i,jop) ;
		cout<<jop.id<<" "<<jop.scope<<" "<<jop.data_structure<<" "<<jop.jop<<" "<<jop.time<<endl;
	}
}
///////////////////////////////////////////////////////////////////<<Lists playground>>/////////////////////////////////////////////////////////

const int size = 100000 ;
arrayListType<int> arr(size) ;
unorderedLinkedList<int> unordered_linked ;
orderedLinkedList<int> ordered_Linked ;
map<int,int> arr_frequency ;
map<int,int> ordered_frequency ;
map<int,int> unordered_frequency ;

calc_time(double arr_time_taken ,double ordered_linked_time_taken ,double unordered_linked_time_taken )
{
	color(10);
	cout<<endl<<"Operation Succeeded."<<endl;
	color(11);
	cout<<"Array based list time: "<<fixed<< arr_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Linked-list time: "<<fixed<< unordered_linked_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Sorted Linked-list time: "<<fixed<< ordered_linked_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Total Time Taken: "<<ordered_linked_time_taken+unordered_linked_time_taken+arr_time_taken<<" sec "<<endl<<endl;

}
bool check()
{
	if(arr.isFull())
	{
		color(12);
		cout<<"Lists are Full , so can not insert any more."<<endl
			<<"Try to delete some elements ."<<endl<<endl ;
		return 1 ;
	}
	return 0 ;
}

void Append_random_elements()
{
	jop.jop="Append some random elements" ;

	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<<Appending random elements>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	if(check()) 	return ;

	int max_append_size=arr.maxListSize()-arr.listSize() ;
	cout<<"Please specificity the number of elements needed [1:"<<max_append_size<<"] :  ";
	int size;
	cin>>size;
	if(size>max_append_size)
	{
		cout<<"Sorry ... You can append only "<<arr.maxListSize()-arr.listSize()<<" element MAX."<<endl;
		size=arr.maxListSize()-arr.listSize() ;
	}

	cout<<"Please specify range:"<<endl;
	int st , en;
	cout<<"start = ";
	cin>>st;
	cout<<"End = ";
	cin>>en;

	clock_t start, end;

	start = clock();
	for(int i=0 ;i<size; i++)
	{
		int element= st+rand()%(en-st+1) ;
		arr.insertEnd(element);
		arr_frequency[element]++ ;
	}
	end = clock();

	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	jop.data_structure="Array based list" ;
	jop.id=operation::counter++;
	jop.time=arr_time_taken ;
	operations_list.insertEnd(jop) ;

	start = clock();

	for(int i=0 ;i<size; i++)
	{
		int element= st+rand()%(en-st+1) ;
		unordered_linked.insertLast(element) ;
		unordered_frequency[element]++ ;
	}
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	jop.data_structure="unordered linked" ;
	jop.id=operation::counter++;
	jop.time=unordered_linked_time_taken ;

	operations_list.insertEnd(jop) ;
	start = clock();
	for(int i=0 ;i<size; i++)
	{
		int element= st+rand()%(en-st+1) ;
		ordered_Linked.insert(element) ;
		ordered_frequency[element]++ ;
	}
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	jop.data_structure="ordered linked" ;
	jop.id=operation::counter++;
	jop.time=ordered_linked_time_taken ;
	operations_list.insertEnd(jop) ;
	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	color();
	cout<<"Press any key to go to the list menu " <<endl<<endl ;
	getch() ;
}

void Append_an_element()
{
	jop.jop="Append an element" ;
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Append an element >>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	if(check()) 	return ;

	int element ;
	cout<<"Enter an element to be appended to lists : " ;
	cin>>element ;
	ordered_frequency[element]++ ;
	unordered_frequency[element]++ ;
	arr_frequency[element]++ ;

	clock_t start, end;

	start = clock();
	arr.insertEnd(element);
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	unordered_linked.insertLast(element) ;
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	ordered_Linked.insert(element) ;
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);


	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	color();
	cout<<"Press any key to go to the list menu " <<endl<<endl ;
	getch() ;
}

void Insert_element_at()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<<Insert an element at a specific place>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	if(check())	return ;

	int element , position;
	cout<<"Enter an element to be appended to lists : " ;
	cin>>element ;
	cout<<"Enter position to be inserted at : ";
	cin>>position ;
	position--;

	clock_t start, end;

	start = clock();
	arr.insertAt(position , element);
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	unordered_linked.insertAt(position , element);
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	ordered_Linked.insert(element) ;
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);


	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;

}

void Delete_element_from()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Delete an element from a specific place >>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	cout<<"Enter Position to delete element at : " ;
	int position;
	cin>>position;
	position--;
	bool ok=1 ;

	clock_t start, end;

	start = clock();
	ok &= arr.removeAt(position);
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if(ok)
	{
		start = clock();
		ordered_Linked.removeAt(position) ;
		end = clock();
		double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

		start = clock();
		unordered_linked.removeAt(position) ;
		end = clock();
		double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	}
	else
	{
		color(4);
		cout<<"Operation Failed"<<endl ;
	}
	color();
	cout<<"Press any key to go to the list menu " <<endl<<endl ;
	getch() ;

};

void Edit_element_at()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Edit an element at a specific place >>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	if(arr.isEmpty())
	{
		cout<<"Lists are empty , there are no elements to be edited "<<endl ;
		color(4);
		cout<<"Operation Failed"<<endl<<endl ;
		return ;
	}
	cout<<"Enter element to replace with : ";
	int element;
	cin>>element;
	cout<<"Enter Position to Replace at : " ;
	int position;
	cin>>position;
	position-- ;
	clock_t start, end;

	start = clock();
	bool ok = arr.replaceAt(position, element);
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	ordered_Linked.removeAt(position) ;
	ordered_Linked.insert(element) ;
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	unordered_linked.updateAt(position+1,element) ;
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if(ok)
		calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	else
	{
		color(4);
		cout<<"Operation Failed"<<endl<<endl ;
	}

	color();
	cout<<"Press any key to go to the list menu " <<endl<<endl ;
	getch() ;
};

void Find_element()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Find an element >>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	if(arr.isEmpty())
	{
		cout<<"Lists are empty "<<endl<<endl ;
		return ;
	}

	int element ;
	clock_t start, end;
	double total_arr_time = 0 , totlal_ordered_time = 0 , totlal_unordered_time = 0 ;

	do{
		cout<<"-1) return to last menu."<<endl
			<<"Enter element to search for : ";
		cin>>element;
		if(element>=0)
		{
			start = clock();
			cout<<"Element is "<<( arr.seqSearch(element) ? "found " : "not found " )<<"in the Array Based List"<<endl ;
			end = clock();
			double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			total_arr_time+=arr_time_taken ;

			start = clock();
			cout<<"Element is "<<( ordered_Linked.search(element) ? "found " : "not found " )<<"in the Ordered Linked List"<<endl ;
			end = clock();
			double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			totlal_ordered_time+=ordered_linked_time_taken;

			start = clock();
			cout<<"Element is "<<( unordered_linked.search(element) ? "found " : "not found " )<<"in the Unordered Linked List"<<endl<<endl ;
			end = clock();
			double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			totlal_unordered_time+=unordered_linked_time_taken ;

			calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
		}

	}while(element>=0) ;

	cout<<endl<<"Total taken time over all search times is :"<<endl;
	calc_time(total_arr_time , totlal_ordered_time , totlal_unordered_time) ;
	cout<<endl<<endl;
};

void Count_occurrence_of()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Count the occurrence of an element >>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	if(arr.isEmpty())
	{
		cout<<"Lists are empty , occurrence of all elements is : 0 "<<endl<<endl ;
		return ;
	}
	int element ;

	cout<<"Enter element to count occurrence : ";
	cin>>element;
	clock_t start, end;

	cout<<"The element "<<element<<" occurred : "<<endl ;
	start = clock();
	cout<<arr_frequency[element]<<" at the Array based list "<<endl;
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	cout<<ordered_frequency[element]<<" at the ordered linked list"<<endl ;
	cout<<unordered_frequency[element]<<" at the unordered linked list"<<endl<<endl  ;

	calc_time(arr_time_taken , arr_time_taken , arr_time_taken) ;
	cout<<endl;
}

void Display_lists()
{

	if(arr.isEmpty())
	{
		cout<<"Lists are empty , there are no elements to display "<<endl ;
		color(4);
		cout<<"Operation Failed"<<endl<<endl ;
		return ;
	}

	clock_t start, end;
	cout<<"Array Based List :  " ;

	start = clock();
	arr.print();
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	cout<<"ordered Linked List :  " ;
	start = clock();
	ordered_Linked.print() ;
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	cout<<"unordered Linked List :  " ;
	start = clock();
	unordered_linked.print() ;
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	color();
	cout<<endl;

};

void Merge_Sort(){

	clock_t start, end;
	start = clock();
	arr.mergeSort() ;
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	cout<<"Array Based List hass been sorted ."<<endl ;
	cout<<"Total Time Taken = "<<arr_time_taken<<" sec"<<endl<<endl;

};


bool Lists_playground()
{
	jop.scope="Lists" ;
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Lists playground >>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	static bool creation_flage=0 ;
	if(!creation_flage++)
	{
		color(5);
		cout<<"An integer Array based list, a linked list, and a sorted linked list have been created."<<endl<<endl ;
		color();
	}

	char choice ;
	do{
		color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		color();

		cout<<"A. Append some random elements."<<endl
		<<"B. Append an element."<<endl
		<<"C. Insert an element at a specific place."<<endl
		<<"D. Delete an element from a specific place."<<endl
		//<<"E. Delete a batch of elements."<<endl
		<<"F. Edit an element at a specific place."<<endl
		<<"G. Find an element."<<endl
		<<"H. Count the occurrence of an element."<<endl
		<<"I. Display lists"<<endl
		<<"J. Sort Array Based List by Merge Sort"<<endl
		<<"1. Main Menu"<<endl
		<<"0. Exit application."<<endl<<endl
		<<"Please make a selection: " ;
		cin>>choice ;

		if(choice>='a')	choice-=('a'-'A') ;
		switch(choice)
		{
			case 'A' : Append_random_elements() ;
			break ;

			case 'B' : Append_an_element() ;
			break ;

			case 'C' : 	Insert_element_at() ;
			break ;

			case 'D' : Delete_element_from();
			break ;

			//case 'E' : Delete_batch_of_elements();
			//break ;

			case 'F' : Edit_element_at();
			break ;

			case 'G' : Find_element();
			break ;

			case 'H' : Count_occurrence_of();
			break ;

			case 'I' : Display_lists();
			break ;

			case 'J' : Merge_Sort();
			break ;
		}

	}while(choice!='1' && choice!='0') ;

	return choice-'0' ;
}


//////////////////////////////////////////////////////////////////////////

//////////////////////////////////<<Phone Directory Application>>///////////////////////////////

struct contact{
	int id;
	string name;
	string number;
	static int counter ;
};
int contact::counter=1 ;
doublyLinkedList<contact> phone_directory ;

void Insert_contact()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Insert new contact >>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	contact new_contact ;
	cout<<"Enter Name : ";
	string name ;
	cin.ignore();
	getline(cin,name) ;
	cout<<"Enter phone number : ";
	string phone ;
	cin>>phone ;
	new_contact.id= contact::counter++ ;
	new_contact.name=name ;
	new_contact.number=phone ;

	phone_directory.insert(new_contact) ;

}

void Find_contact()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Find a contact >>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	string name;
	cout<<"Enter Name of contact to search for : ";
	cin.ignore();
	getline(cin,name) ;
	phone_directory.search(name);
}

void print_current()
{

	if(phone_directory.get_current()!=NULL)
	{
		cout<<"////////////////////////////////////////////////////////////"<<endl<<endl;
		contact current = (phone_directory.get_current()->info);
		cout<<"Contact Id : "<<current.id<<endl
		<<"Name : "<<current.name<<endl
		<<"Phone Number : "<<current.number<<endl<<endl;
		cout<<"////////////////////////////////////////////////////////////"<<endl<<endl;
	}
	else
	{
		cout<<"NO Contact Data Found"<<endl<<endl;
		color() ;
	}

}
void Next()
{
	phone_directory.Next() ;
	print_current() ;
}
void Previous()
{
	phone_directory.Previous() ;
	print_current() ;
}
bool Phone_Directory_Application()
{
	char choice ;
	do{
		color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		color();
		cout<<"A. Insert new contact"<<endl
			<<"B. Find a contact "<<endl
			<<"C. Print the currently selected contact."
			<<">. Next"<<endl<<"<. Previous"<<endl
			<<"1. Main Menu"<<endl
			<<"0. Exit application."<<endl<<endl
			<<"Please make a selection: " ;

		cin>>choice ;
		if(choice>='a')	choice-=('a'-'A') ;

		switch(choice)
		{
			case 'A' : Insert_contact();
			break ;

			case 'B' : Find_contact();
			break ;

			case 'C' : print_current();
			break ;
			case '>' : Next();
			break ;

			case '<' : Previous();
			break ;
		}
	}while(choice!='1' && choice!='0') ;

	return choice-'0' ;
}



/////////////////////////////////////////////////////////////////Hashes_playground///////////////////////////////////////

map<int , int > mp;
bool Hashes_playground()
{
    color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Hashes playground >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();


    char choice ;
    do
    {
        color();
         cout << "What are the operations that you need to do?" << endl
 	<<endl << "A. Add some random elements." << endl
        <<"B. Add an element."<< endl
        << "C. Delete an element."<< endl
        << "D. Delete the first N elements."<< endl
        << "E. Find an element."<< endl
        << "F. Display hash" << endl
        << "G. Use the current hash to get unique numbers from the previous list. (Bonus)"<< endl
        << "1. Main Menu"<< endl
        << "0. Exit application."<< endl
<< endl << "Please make a selection: " ;

        cin >> choice ;
        if(choice>='a')	choice-=('a'-'A') ;
		switch(choice)
		{
			case 'A' :
            {
             clock_t start, end ;
             cout<<endl<<"Enter Number of elements : ";
             int s;
             cin>>s;
             cout<<"Please specify ranges of elements:"<<endl;
	         int e_st , e_en;
	         cout<<"start = ";
             cin>>e_st;
	         cout<<"End = ";
	         cin>>e_en;
	         cout<<"Please specify ranges of values:"<<endl;
	         int v_st , v_en;
	         cout<<"start = ";
             cin>>v_st;
	         cout<<"End = ";
	         cin>>v_en;

             start = clock();
             for(int i=0 ; i<s; i++)
             {
                 int element = e_st+rand()%(e_en-e_st+1);
                 int value = v_st+rand()%(v_en-v_st+1);
                 mp.insert( {element , value } );
             }
             end = clock();
             double hash_time = double(end - start) / double(CLOCKS_PER_SEC);

             color(10);
             cout<<endl<<"Operation Succeeded."<<endl;
             color(11);
            cout<<"list hash time: "<<fixed<< hash_time<< setprecision(5)<<" sec " << endl;

			break ;
            }

			case 'B' :
                {

                    clock_t start, end ;
			    int element , value ;
			    cout <<endl<< "enter the number element : " ;
			    cin >> element ;
			    cout << "enter the number of value : ";
			    cin >> value ;
			    start = clock();
                mp.insert( { element , value } );
			    end = clock();
                double hash_time = double(end - start) / double(CLOCKS_PER_SEC);
                color(10);
                cout<<endl<<"Operation Succeeded."<<endl;
                color(11);
                cout<<"list hash time: "<<fixed<< hash_time<< setprecision(5)<<" sec " << endl;

			break ;
                }
			case 'C' :
                {
                    if(mp.empty())
                    {
                        color(4);
                        cout<<endl<<"Map is Empty , There is no elements to be deleted"<<endl<<endl;
                        color();
                        continue ;
                    }
                clock_t start, end ;
			    int element  ;
			    cout <<endl<< "enter the number element : " ;
			    cin >> element ;
                auto it1 = mp.find(element);
                start = clock();
                mp.erase(it1);
                end = clock();
                double hash_time = double(end - start) / double(CLOCKS_PER_SEC);
                color(10);
                cout<<endl<<"Operation Succeeded."<<endl;
                color(11);
                cout<<"list hash time: "<<fixed<< hash_time<< setprecision(5)<<" sec " << endl;

			break ;
                }


			case 'D' :
                {

                cout<<"Enter number of elements to be deleted : " ;
                int n ;
                cin>>n;
                if(mp.size()<=n)
                {
                    cout<<endl;
                    cout<<"Map size ( "<<mp.size()<<"elements ) is "<<(mp.size()==n ? "Equal" : "Less")<<" than "<<n<<" !"<<endl ;
                    cout<<"Map will be cleared ."<<endl ;
                    mp.clear() ;
                    continue ;
                }
                clock_t start, end ;
                start = clock();
			    for(int i=0 ; i<n; i++)
                    mp.erase(mp.begin()) ;


			    end = clock();
                double hash_time = double(end - start) / double(CLOCKS_PER_SEC);
                color(10);
                cout<<endl<<end<<"Operation Succeeded."<<endl;
                color(11);
                cout<<"list hash time: "<<fixed<< hash_time<< setprecision(5)<<" sec " << endl;

			break ;
                }
			case 'E' :
                {

			    clock_t start, end ;
			    int element ;
			    cout <<endl<< "enter the number element : " << endl ;
                cin >> element ;

			    start = clock();
			    auto it1 = mp.find(element) ;
			    end = clock();
                if ( it1 == mp.end() )
                {
                    color(4);
                    cout<<endl<<"Element Not Found in the map"<<endl<<endl;
                    color();
                    continue ;
                }
			    cout << "the value is " << it1->second << endl ;
                double hash_time = double(end - start) / double(CLOCKS_PER_SEC);
                color(10);
                cout<<endl<<"Operation Succeeded."<<endl;
                color(11);
                cout<<"list hash time: "<<fixed<< hash_time<< setprecision(5)<<" sec " << endl;
			break ;

                }
			case 'F' :
			    {

			    clock_t start, end ;
			    cout <<endl<< "element  value" << endl << endl ;
			    start = clock();
			    for (auto it1 : mp)
                    cout << it1.first << "         " << it1.second << endl;
                end = clock();
                double hash_time = double(end - start) / double(CLOCKS_PER_SEC);
                color(10);
                cout<<endl<<"Operation Succeeded."<<endl;
                color(11);
                cout<<"list hash time: "<<fixed<< hash_time<< setprecision(5)<<" sec " << endl;
			break ;
			    }



			case 'G' :
                {

                cout<<endl<<"unique numbers from the previous list : "<<endl<<"[  ";
                for(auto it :arr_frequency )
                    cout<<it.first<<" ";
                cout<<"]"<<endl;

            break ;
                }
		}

	}while(choice!='1' && choice!='0') ;
       return choice-'0' ;
}


/////////////////////////////////////<<<<<<<<<< stack >>>>>>>>>////////////////////////////////////////////

linkedStackType<int> linkedstack;
stackType<int> arrstack;

calc_stack_time(double array_stack_time_taken ,double linked_stack_time_taken)
{
	color(10);
	cout<<endl<<"Operation Succeeded."<<endl;
	color(11);
	cout<<"Array Stack time: "<<fixed<< array_stack_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Linked Stack time: "<<fixed<< linked_stack_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Total Time Taken: "<<array_stack_time_taken+linked_stack_time_taken<<" sec "<<endl<<endl;
}

void pushRandomArrayLinked()
{
    int st,en,size;
	clock_t start, end;
    cout << "Enter the size you want: " ;
    cin >> size;
    cout << "Choose the range of the numbers: ";
    cin >> st >> en;

	start = clock();
    for (int i = 0 ; i< size ; i++)
	{
        int element= st+rand()%(en-st+1);
        linkedstack.push(element);
	}
	end = clock();
	double linked_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	for (int i = 0 ; i< size ; i++)
	{
		int element= st+rand()%(en-st+1) ;
        arrstack.push(element);
    }
	end = clock();
	double array_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	calc_stack_time(array_stack_time_taken, linked_stack_time_taken) ;

}

void pushArrayLinked()
{
    int element;
    cout <<"Enter element to be pushed: " << endl;
    cin >> element;
	clock_t start, end;
	start = clock();
    linkedstack.push(element);
	end = clock();
	double linked_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
    arrstack.push(element);
	end = clock();
	double array_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	calc_stack_time(array_stack_time_taken, linked_stack_time_taken) ;

}

void popArrayLinked()
{
	clock_t start, end;
	start = clock();
    linkedstack.pop();
	end = clock();
	double linked_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
    arrstack.pop();
	end = clock();
	double array_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	calc_stack_time(array_stack_time_taken, linked_stack_time_taken) ;

}

void popElementArrayLinked()
{
    int element;
    cout << "Enter the number of elements to delete: " << endl;
    cin >> element;
	clock_t start, end;
	start = clock();
    linkedstack.popElments(element);
	end = clock();
	double linked_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
    arrstack.popElements(element);
	end = clock();
	double array_stack_time_taken = double(end - start) ;

	calc_stack_time(array_stack_time_taken, linked_stack_time_taken) ;

}

void clearArrayLinked()
{
	clock_t start, end;
	start = clock();
    linkedstack.initializeStack();
	end = clock();
	double linked_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
    arrstack.initializeStack();
	end = clock();
	double array_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	calc_stack_time(array_stack_time_taken, linked_stack_time_taken) ;

}

void displayArrayLinked()
{
	clock_t start, end;
	start = clock();
    cout << "Linked Stack: ";
	linkedstack.print();
	cout << endl;
	end = clock();
	double linked_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	start = clock();
	cout << "Array Stack: ";
    arrstack.print();
	cout << endl;
	end = clock();
	double array_stack_time_taken = double(end - start) / double(CLOCKS_PER_SEC);

	calc_stack_time(array_stack_time_taken, linked_stack_time_taken) ;

}

void sorted()
{
	arrstack.is_sorted() ;
	linkedstack.is_sorted();
	cout<<endl;
}

bool Stack_Playground()
{

	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Stacks playground >>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();

	 static bool creation_flage=0 ;
	if(!creation_flage++)
	{
		color(5);
		cout<<"An integer Array based stack and a linked based stack have been created."<<endl<<endl ;
		color() ;
	}

	char choice ;
	do{
		 color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		 color();

		cout<<"A. Push some random elements."<<endl
		    <<"B. Push an element."<<endl
    		<<"C. Pop an element."<<endl
	    	<<"D. Pop some elements."<<endl
		    <<"E. Clear stack."<<endl
    		<<"F. Display stacks"<<endl
	    	<<"G. Is Stack sorted"<<endl
		    <<"1. Main Menu"<<endl
		    <<"0. Exit application."<<endl<<endl
		    <<"Please make a selection: " ;

		cin>>choice ;

		if(choice>='a')	choice-=('a'-'A') ;
		switch(choice)
		{
			case 'A' : pushRandomArrayLinked() ;
			break ;

			case 'B' : pushArrayLinked() ;
			break ;

			case 'C' : 	popArrayLinked() ;
			break ;

            case 'D' : 	popElementArrayLinked() ;
			break ;

            case 'E' : 	clearArrayLinked() ;
			break ;

            case 'F' : 	displayArrayLinked() ;
			break ;

            case 'G' : 	sorted() ;
			break ;
		}

	}while(choice!='1' && choice!='0') ;

		return choice-'0' ;
}

int main(){

    	srand(time(0));

    char choice ;
	do{
		 color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		 color();

		cout<<"A. Lists playground. "<<endl
		    <<"B. Stacks playground. "<<endl
    		<<"C. Queues playground. "<<endl
	    	<<"D. Hashes playground. "<<endl
		    <<"E. Phone directory application. "<<endl
    		<<"F. Show app calculations. "<<endl
		    <<"0. Exit application."<<endl<<endl
		    <<"Please make a selection: " ;

		cin>>choice ;
		bool ok= 1 ;
		if(choice>='a')	choice-=('a'-'A') ;
		switch(choice)
		{
			case 'A' :ok= Lists_playground() ;
			break ;

			case 'B' : ok=Stack_Playground() ;
			break ;

			case 'C' : 	//ok=Queue_playground() ;
			break ;

            //case 'D' : 	ok=Hashes_playground() ;
			//break ;

            case 'E' : 	ok=Phone_Directory_Application() ;
			break ;

            case 'F' : 	show_app_calc() ;
			break ;

		}
		if(!ok)	return 0 ;

	}while(choice!='1' && choice!='0') ;

	return 0 ;
}
