//singly circular linked list
#include <iostream>
using namespace std;

class Node 
{
	public:
	 int value;
	 Node* next;
  
	//Constructor creating a node
	 Node(int data)
	 {
	   value = data;
	   next = nullptr;
 	 }
};

class CLL
{
  private:
  //pointer to the last node
  Node* last;
  
  public:
  //constructor
  CLL()
  {
    last = nullptr;
  }
  
  //Methods
  //1// Insert
  //1.1//At Head
  void insert_at_head(int data)
  {
    Node* new_node = new Node(data); 
    
    //if empty
    if(last == nullptr)
    {
      last = new_node;
      //it points back to itself since there are no other elements
      new_node->next = new_node;
    }
    //if its not empty				
    else
    {
      //new node's next pointer stores the first node since last->next loops back to the head 
      //this way new node becomes the head and its next pointer stores ret of the list
      new_node->next = last->next;
      //update the last node to new_node for access
      last->next = new_node;
    }
  }
  
  //1.2//At Tail
  void insert_at_tail(int data)
  {
  	Node* new_node = new Node(data);
  	//if empty
  	if(last == nullptr)
  	{
  		last = new_node;
  		new_node->next = new_node;
  	}
  	
  	//if not empty
  	else
  	{
  	//new node's next will point back to head
  	new_node->next = last -> next; 
  	
  	 last->next = new_node;

  	//update last pointer to point to new last pointer
  	 last = new_node;
  	 }
  }
  
  //2// Delete
  void deleteNode(int key)
  {
  	//if empty
  	if(last == nullptr)
  	{
  		cout<<"Empty list"<<endl;
  		return;
  	}	
  	//if only one node exists and matches the key
  	if(last->next == last && last->value == key)
  	{
  		delete last;	 //free memory
  		last = nullptr; //no elements so set list to empty
  	return;
  	}
  	
  	//if list last multiple nodes
  	Node* current = last->next; //current element 
  	Node* previous = last;	     //previous element
  	
  	//search for the key
  	do
  	{
  		//if its found
  		if(current->value == key)
  		{
  			//if its last node
  			if(current == last)
  			{
  				//set it to previous element
  				last = previous;
  			}
  			//set next of previous to the head
  			previous->next = current->next;
  			//free the memory
  			delete current;
  			return;
  		}
  		//if its not found
  		//go to the next element
  		previous = current;
  		current = current->next;
  		
  	} while(current != last->next); //while we reach the end of the list
  	//if we didn't find the value	
  	cout<<"The value was not found !"<<endl;
  }
  
  //3// Search
  int search(int data)
  {
  	//if empty
  	if(last == nullptr)
  	{
  		return -1;
  	}
  	
  	Node* current = last->next; //first element
  	int position = 0;
  	
  	//traverse
  	do
  	{
  		//if found
  		if(current->value == data)
  		{
  			return position;
  		}
  		
  		current = current->next;
  		position ++;
  	} while(current != last->next);

  return -1; //not found
  }
  
  //4// Print
  void print()
  {
  	//if the list is empty
  	if(last == nullptr)
  	{
  	  cout<<"Empty"<<endl;
  	  return;
  	}
  	//if its not empty
  	Node* temp = last->next;
        do{
  		cout<<temp->value<<"\t"<<endl;
  		temp = temp->next;
  	  } while(temp != last->next);
  }
  
  //find size
  int FindSize()
  {
  	int size = 0;
  	Node* temp = last->next;
  	
  	while(temp->next != last->next)
  	{
  		temp = temp->next;
  		size++;
  	}
  	
  	return size;
  }
};


