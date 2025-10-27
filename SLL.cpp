//Singly Linked List 

#include<iostream>
using namespace std;

//Linked List Node
class Node 
{
	public: 
	int value;
	Node* next;
	
	//Constructor that creates a node and assigns a value to it	
	Node(int data)
	{
	  value = data;
	  next = nullptr;
	}
};
        
class SLL
{
	private:
	Node* list;
        
        public:
        //constructor
        SLL()
        {
        	list = nullptr;
        }
        
        //methods
        
	//1//Printing 
	void print()
	{
	  //check if the list is empty
	  if(list == nullptr)
	  	cout<<"The list is empty"<<endl;
	  //if the list is not empty
	  else
	  {
		//Temporary node
		Node* temp = list;
		//iterate till we reach the end of list
		while(temp != nullptr)
		{
			//print the value of current node
			cout<<temp->value<<"\t";
			//move on to the next node
			temp = temp->next;
		}
	   }
	}
	
	//2// Inserting
	//2.1//Inserting at head
	void insert_at_head(int data)
	{
	  try {
		//create node
		Node* new_node = new Node(data);
		//check for empty list
		if(list == nullptr)
			list = new_node;
		
		//if the list is not empty
		else
		{
			new_node->next = list;	//new node's next points to rest of the list
			list = new_node;	//the list takes the new values
		}
	      }  catch(bad_alloc& e) {cerr<<"Error: Out of memory :"<< e.what();}
	}
	//2.2// Inserting at tail
	void insert_at_tail(int data)
	{
	  try {
		//create node
		Node* new_node = new Node(data);
		//check if list is empty
		if(list == nullptr)
			list = new_node;

		else
		{
		//temporary node
		Node* temporary = list;
		
		//traverse to the end of list
		while(temporary->next != nullptr)
			temporary = temporary->next;
			
		temporary->next = new_node;
		}
	      }catch(bad_alloc& e) {cerr<<"Error: Out of memory :"<< e.what();}	      
	}
	
	//3//Delete
	void deleteNode(int key)
	{
		//if list is empty
		if(list == nullptr)
			cout<<"empty list"<<endl;

		//if there is only one element and it matches the key
		else if(list->next == nullptr && list->value == key)
		{
			delete list;
			list = nullptr;
		}
		//else search for the element
		else
		{
			Node* current  = list;
			Node* previous = nullptr;
			
			while(current->next != nullptr)
			{
				//if its head
				if(current->value == key && previous == nullptr)
				{
					current = current->next;
					return;
				}
				
				if(current->value == key && previous != nullptr)
				{
					previous->next = current->next;
					delete current;
					return;
				}
				
				previous = current;
				current  = current->next;
			}
		}
	}
	
	///4// Searching for an element
	int search(int key)
	{
	 Node* temp = list;
	 int index = 0;
	
	while(temp != nullptr)
	{
	  if(temp->value == key)
	     return index;
		 	 
	  index++;
	  temp = temp->next;
	}
	
	return -1;
	}

};
