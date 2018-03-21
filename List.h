#pragma once
template <typename T>
class List;

template <typename T>
class node
{
	friend class List<T>;
public:
	//default constructor with no initial vale
	node() :next(NULL)
	{}
	//constructor with initial value and next
	node(const T& item, node<T>* nextNode = NULL) : nodeValue(item), next(nextNode)
	{}
private:
	T nodeValue;  //data held by node
	node<T>* next;
};

template <typename T>
class List
{
public:
	// constructors and destructor:
	List();
	List(const List<T>& obj);  // copy constructor for List 
	~List();  //destructor

			  // list operations:
	void insertFront(const T& newItem);  //insert a new node at the front
	void insertBack(const T& newItem);  //insert a new node at the back
	T&  removeFront();//remove a node from the front and return node value 
	void printList();  //print linked list

					   //operator overload   : assignment operator
	List<T>& operator=(const List<T>& List);

private:
	bool isEmpty() const;   //is list empty
	int size;       // number of items in list
	node<T> *head; // pointer to linked list of items

}; // end class
   //implementation starts here
template <typename T>
List<T>::List() //creates list with start and end as NULL
{
	head = NULL;
	size = 0;
}
template <typename T>
List<T>::List(const List<T>& obj)
{
	size = obj.size;
	if (obj.head == NULL)
		head = NULL; // original list is empty
	else
	{
		head = new node<T>;
		head->nodeValue = obj.head->nodeValue;
		node<T> *newPtr = head; // new list pointer
		for (node<T> *origPtr = obj.head->next; origPtr != NULL; origPtr = origPtr->next)
		{
			newPtr->next = new node<T>;
			newPtr = newPtr->next;
			newPt->nodeValue = origPtr->nodeValue;
		} // end for
		newPtr->next = NULL;
	} // end if

}
template <typename T>
List<T>::~List()
{
	node<T>* currentNode;
	while (head)
	{
		currentNode = head;
		head = head->next;
		delete currentNode;
	}
}

template <typename T>
void List<T>::insertFront(const T& newItem)
{
	node<T>* newNode = new node<T>(newItem);
	newNode->nodeValue = newItem;
	newNode->next = head;
	head = newNode;
	size += 1;
}

template <typename T>
void List<T>::insertBack(const T& newItem)
{
	node<T>* newNode = new node<T>(newItem);
	newNode->nodeValue = newItem;
	node<T>* currentNode = head;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	size += 1;
}

template <typename T>
T& List<T>::removeFront()
{
	node<T>* currentNode = head;
	head = head->next;
	delete currentNode;
	size -= 1;

	return head->nodeValue;
}

template <typename T>
void List<T>::printList()
{
	node<T>* currentNode = head;
	while (currentNode)
	{
		cout << currentNode->nodeValue << " ===> ";
		currentNode = currentNode->next;
	}


}

template <typename T>
bool List<T>::isEmpty() const
{
	if (head == NULL)
		return true;
	else
		return false;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& aList)  // = operator overloading
{
	if (this != &aList)  //self?
	{

		size = aList.size;
		if (aList.head == NULL)
			head = NULL; // original list is empty

		else
		{
			head = new node<T>;
			head->nodeValue = aList.head->nodeValue;

			node<T> *newPtr = head;
			for (node<T> *origPtr = aList.head->next;
			origPtr != NULL;          origPtr = origPtr->next) {
				newPtr->next = new node<T>;
				newPtr = newPtr->next;
				newPtr->nodeValue = origPtr->nodeValue;
			} // end for
			newPtr->next = NULL;
		} // end if
	}

	return *this;
}

