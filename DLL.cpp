#include <iostream>
using namespace std;

class Node 
{
public:

int data; 
Node *prev;
Node *next;

//Creating a node
Node(int value)
{
  data = value;
  prev = nullptr;
  next = nullptr;
}

};

class DLL
{
private:
Node *list;

public:
DLL()
{
    list = nullptr;
}
	
//Printing
void Print_DLL()
{
 	 if(list == nullptr)
  	 	cout<<"Empty list!\n";
  
 	 else
 	 {
		Node* temporary = list;
		while(temporary != nullptr)
		{
  			cout<<temporary->data<<"\t";
  			temporary = temporary->next;
		}
	  //new line
	  cout<<endl;
 	}
}
  
//Insert at beginning
void insert_at_head(int data)
{
	try
	{
		Node* newnode = new Node(data);
		if(list == nullptr)
			list = newnode;
		
		else
		{
			newnode->next = list;
			newnode->next->prev = newnode;
			list = newnode;
		}		
	} catch(bad_alloc& e) {cerr<<"Error: Out of memory : "<<e.what();}
}


//Insert at end
void insertNode_Tail(int value)
{
	try {
		//create node
		Node* newnode = new Node(value);
		
		if(list == nullptr)
			list = newnode;
		
		else
		{
		//temporary node
		Node* temporary = list;
		while(temporary->next != nullptr)     
			temporary = temporary->next;
		
		temporary->next = newnode;
		temporary->next->prev = temporary;
		}
	} catch(bad_alloc& e) {cerr<<"Error: Out of memory: "<<e.what();}
}


//Insert after a position
void insertNode_AfterIndex(int value,int index)
{
	Node* newnode = new Node(value);
	
	int size = FindSize();
	
	if(list == nullptr)
		list = newnode;
	
	
	//Check if its last element or bigger
	else if(index == size)
		insertNode_Tail(value);
	
	else
	{
	int size = FindSize();
	if(index > size || index < 0)
	{
		throw std::out_of_range("The specified index is out of list range.");
	}
	
	  Node* temporary = list;
	
	//Traverse to index:
	int count = 0;
	while(count != index)
	{
		temporary = temporary->next;
		count++;
	}
	//Node to save next nodes
	Node* AfterIndex = temporary->next;
	
	//Insert newnode after index
	temporary->next = newnode;
	//Insert previous element of newnode
	temporary->next->prev = temporary;
	
	//Insert rest of the list back
	temporary->next->next = AfterIndex;
	//Insert previous element
	temporary->next->next->prev = temporary->next;
	}
}

//Insert before a position
void insertNode_BeforeIndex(int value,int index)
{
	Node* newnode = new Node(value);
	Node* temporary = list;
	
	if(list == nullptr)
		list = newnode;
	
	//check if index is head
	else if(index == 0)
		insert_at_head(value);
	
	else
	{
	
	int size = FindSize();
	if(index > size-1 || index < 0)
	{
		throw std::out_of_range("The specified index is out of list range.");
	}



	//Traverse to index:
	int count = 0;
	while(count+1 != index)
	{
		temporary = temporary->next;
		count++;
	}
	//Node to save next nodes
	Node* AfterIndex = temporary->next;
	//Insert newnode before index
	temporary->next = newnode;
	temporary->next->prev = temporary;
	
	//Insert rest of the list back
	temporary->next->next = AfterIndex;
	temporary->next->next->prev = temporary->next;
	}
}

//Remove element
//Remove at Head
void Remove_Head()
{
	if(list == nullptr)
		cout<<"The list is empty";
	
	else
	{
		Node* temp = list;
	
		list = list->next;
		list->prev = nullptr;

		temp = nullptr;	
		delete temp;
	}
}

//Remove at Tail
void Remove_Tail()
{
	Node* temporary = list;
	
	if(list == nullptr)
		cout<<"The list is empty";
	
	else if(temporary->next == nullptr)
	{
		list = nullptr;
		delete temporary;
	}
	
	else
	{
	while(temporary->next->next != nullptr)
	{
		temporary = temporary->next;	
	}
	
	temporary->next = nullptr;
	delete temporary->next;
	}
}

//Remove at index
void Remove_Pos(int index)
{
	int size = FindSize();
	//if index is at head
	if(index == 0) 
		Remove_Head();

	//if index is at tail
	else if(index == size)
		Remove_Tail();
	
	//if index is out of range
	else if(index > size-1 || index < 0)
	{
		throw std::out_of_range("The specified index is out of list range.");
	}
	
	//if not find position of index
	else
	{
	Node* temporary = list;
	
	Node* prev = nullptr;
	for(int i = 0 ; i < index; i++)
	{
		prev = temporary;
		temporary = temporary->next;
	}
	prev->next = temporary->next;
	prev->next->prev = prev;
	delete temporary;
	}
}

//Linear Search
int Linear_Search(int element)
{
  Node* temporary = list;
  
  for(int index = 0; temporary->next != NULL; index++)
  {
  	if(temporary->data == element)
  	{
  		return index;
  	}
  	temporary = temporary->next;
  }
   return -1;
}


//Get length of list
int FindSize()
{
	int size = 0;
	Node* Temporary = list;
	
	while(Temporary != NULL)
	{
	Temporary = Temporary->next;
	size++;
	}
	
	return size;
}
};
