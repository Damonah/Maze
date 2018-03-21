#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> myList, otherList; //list objects to test List implementation
	int choice;    //user choice
	int value;     //value to add or value in the deleted node


				   // ask user to choose operations on list  
	do
	{
		//display options
		cout << "\n"
			<< " 1: add a new node at the front of myList \n"
			<< " 2: add a new node at the end of myList \n"
			<< " 3: delete the first node  of myList \n"
			<< " 4: display otherList \n"
			<< " 5: display myList \n"
			<< " 6: list assignment  otherList = myList\n"
			<< " 7: quit \n\n";
		cout << "choose your option from the above: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			//add a new node at the front of myList
			cout << "item value? ";
			cin >> value;
			myList.insertFront(value);
			break;
		case 2:
			//add a new node at the end of myList
			cout << "item value? ";
			cin >> value;
			myList.insertBack(value);
			break;
		case 3:
			//delete the first node  of myList
			value = myList.removeFront();
			cout << value << " is removed from myList\n";
			break;
		case 4:
			//display otherList
			otherList.printList();  //print otherList 
			break;
		case 5:
			//display myList
			myList.printList();  //print myList
			break;
		case 6:
			//List assignment 

			otherList = myList;  //print linked list back to front   list   5 -> 10
			break;
		case 7:
			break;

		} //end of switch


	} while (choice <7);


	return 0;
}  // end main
