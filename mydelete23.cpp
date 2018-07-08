#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next;
	
	node(int d, node* n)
	{
		data=d;
		next=n;
	}
};

typedef node* link;

void printLL(link head)
{
	link temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ,";
		temp=temp->next;
	}
}

link myDelete(link h)
{
	link temp = h;
	link t;
		
	if(h->data==2 )
	{
		if(h->next->data==3)
		{
			temp =h->next;
			h->next=temp->next;
			delete temp;
		}
		
	}
	else
	{
		while(temp!=NULL)
		{
	 	if(temp->data==3)
		{
			if(t->data==2)
			{
				t->next=temp->next;
				delete temp;		
			}
		}
		t=temp;
		temp=temp->next;
		
	}
	}
	
	return h;
}

link insertAtEnd(link head, int d)
{
	if(head==NULL)
	{
		head = new node(d,NULL);
	}
	else
	{
		link temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		
		link n = new node(d,NULL);
		temp->next=n;
	}
return head;
}

int main()
{
cout<<"Inserting at end"<<endl;
	link A = NULL;
A = insertAtEnd(A,1);
A = insertAtEnd(A,2);
A = insertAtEnd(A,3);
A = insertAtEnd(A,4);
A = insertAtEnd(A,5);
A = insertAtEnd(A,6);
A = insertAtEnd(A,2);

	printLL(A);
	cout<<endl;
A = myDelete(A);
	printLL(A);
	cout<<endl;
}
