

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

// A struct to keep items
struct node
{
	int index;
	int data;
	node *next;
	node(int i,int x, node* t) { // constructor	
		index=i; data = x; next = t;
	}
};

typedef  node* link;


class LinkedList
{
public:
	LinkedList();							// Construction
	link getHead();
	void setHead(link h);
	link add(link head,int index,int data);			// Adds a new index and number
	void printList(LinkedList l);					// List all items of Bag.
	unsigned short getSize();		// How many items  the Bag has
	int product(LinkedList a,LinkedList b); // find the dot product of two vectors
private:
	node* head;						// A pointer to show the first node
	unsigned short size;			// how many items Bag has
};
LinkedList::LinkedList() // Initialize an instance of the class
{
	size = 0;
	head = NULL; // At the beginning both, head and last are null    
	//	cout << "A new bag with  " << getCapacity() << " was created...!" << endl;
}

link LinkedList::getHead()
{
	return head;
}

void LinkedList::setHead(link h)
{
	head = h;
}

link LinkedList::add(link head,int index,int data)
{
	link e = new node(index,data,NULL);			//  dynamically create a new struct/item
	if(head==0)
	{
		head=e;
		size++;
	}			
	else
	{
		e->next = head;
		head = e;
		size++;
	}
return head;	// Yeah, added.
}


void LinkedList::printList(LinkedList l)	// List, print out, all items in the arrays, // make 5 coloumns
{
	
	link it = l.head;   // it means iterator, visit all items one by one.
	while (it != NULL) {
	cout << it->index << "   "<< it->data<<endl;
		it = it->next;
	}
	cout << endl;
}
// How many items the Bag has
unsigned short LinkedList::getSize()
{
	return size;
}


int LinkedList::product(LinkedList A,LinkedList B)
{
	int prod=0;
	link itA = A.getHead();   
	link itB = B.getHead();

	while(itA!=0 && itB!=0)
	{
		if(itA->index == itB->index)
		{
		prod = prod + (itA->data*itB->data);
		itA = itA->next;
		itB = itB->next;	
		}
		else if(itA->index < itB->index)
		itA = itA->next;
		else
		itB = itB->next;
	}

	return prod;
}
	

int main(int argc, const char * argv[]) 
{
	LinkedList a;
	LinkedList b;

	int a_d,b_d,a_i,b_i;
	cout<<"Enter nonzero elements in A"<<endl;
	cout<<"Index val"<<endl;
	while(a_i!=-1 && a_d!=-1)
	{
		cin>>a_i>>a_d;
		link tempa = a.add(a.getHead(),a_i,a_d);
		a.setHead(tempa);

	}
	
	a.printList(a);
	
	cout<<"Enter nonzero elements in B"<<endl;
	cout<<"Index val"<<endl;
	while(b_i!=-1 && b_d!=-1)
	{
		
		cin>>b_i>>b_d;
		link tempb = b.add(b.getHead(),b_i,b_d);
		b.setHead(tempb);
		
	}
	
	b.printList(b);
	
	//finding the dot product of A and B
	
	cout<<"The dot product of A and B is "+ a.product(a,b);
	
	
}


