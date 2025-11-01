//doubly circular linked list
#include <iostream>
using namespace std;

//node class
class Node
{
public:
	int value;	//stores the data of current node
	Node* next;	//stores address of next node
	Node* prev;	//stores address of previous node

//creating a new node
Node(int data)
{
	value = data;
	next = nullptr;
	prev = nullptr;
}
};

class DCLL
{
private:
	Node* last;

public:
	//Constructor	
	DCLL()
	{
		last = nullptr;
	}
//Methods
//1//Inserting
//1.1// At head
void insert_at_head(int data)
{
	//create a new node
	Node* new_node = new Node(data);
	
	//if list is empty
	if(last == nullptr)
	{
		last = new_node;
		new_node->next = new_node; 
		new_node->prev = new_node; 
	}
	//if list is not empty
	else
	{
		new_node -> next = last -> next; // new_node-> next = rest of the list
		new_node -> prev = last;	  // new_node's (head) prev points back to last element

		//The next node's previous pointer will point back to new_node (current head)
		new_node -> next -> prev = new_node;

		//updating the last node for accesibility
		last->next = new_node;
	}
}

//1.2.// At tail
void insert_at_tail(int data)
{
	Node* new_node = new Node(data);
	
	//if list is empty
	if(last == nullptr)
	{
		last = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
		
	else
	{
		new_node -> prev = last;
		new_node -> next = last->next;
		
		new_node -> next -> prev = new_node;
		
		last->next = new_node;
		last = new_node;
	}
}
//2// Deleting
void delete_node(int key)
{
	//if list is empty
	if(last == nullptr)
		printf("\nThe list is empty !\n");
	
	//if only one element is present and it matches the key
	else if(last->next == last && last->value == key)
	{
		delete last;
		last = nullptr;
	}
	
	//multiple nodes
	else
	{
		//the element we compare
		Node* current = last->next;	//initialy head
		//previous element of current
		Node* previous = last;		//initialy tail
		
		//search
		do
		{
			//if found
			if(current->value == key)
			{
				//if its last node
				if(current == last)
					last == previous;
				
				//if not last node
				previous->next = current->next;
				previous->next->prev = previous;
				
				delete current;
				return;
			}
			//if not found
			//moving forward
			previous = current;
			current =  current->next;
			
		} while(current != last->next);
	 	
	 	cout<<"Element not found !"<<endl;
	 }
}

//3// 	Print List
void print_list()
{
	if(last == nullptr)
	printf("\nList is empty !\n");
	
	else
	{
		Node* temp = last->next;
		
		do
		{
			cout<<"\n"<<temp->value<<"\t"<<endl;
			temp = temp->next;
		}
		 while(temp != last->next);
	}
}


//4// Search
int search(int key)
{
	//if list is empty
	if(last == nullptr)
	return -1; 
	
	Node* current = last->next;//head
	int index = 0;
	
	//search
	do
	{
		if(current->value == key)
			return index;
		
		current = current->next;
		index++;
	}
	  while(current != last->next);

	//if not found
	return -1;
}
};

