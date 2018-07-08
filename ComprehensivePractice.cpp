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
	while(temp!=NULL)
	{
		if(temp->data==3)
		{
			t->next=temp->next;
			delete temp;
		}
		t=temp;
		temp=temp->next;
		
	}
	
	return h;
}


link createFromArrayEnd(int a[],int n)
{
	link head= new node(a[0],NULL);
	link temp=head;
	for(int i=1;i<n;i++)
	{
		
		link nn = new node(a[i],NULL);
		temp->next = nn;
		temp=nn;
	}
	
	return head;
}



link insertAtBegin(link head, int d)
{
	if(head==NULL)
	{
		head = new node(d,NULL);
	}
	else
	{
		link n = new node(d,head);
		head = n;
	}
	return head;
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

link insertOnKthNode(link head,int k,int d)
{
	link temp = head;
	link nnode = new node(d,NULL);
	if(k==1)
	{
		nnode->next=head;
		head=nnode;
	}
	else
	{
		int count=1;
	while(temp!=NULL)
	{
		if(count==(k-1))
		{
			nnode->next=temp->next;
			temp->next=nnode;
		}
		count++;
		temp=temp->next;
	}
	
	}
	
return head;
}

link insertAfterKthNode(link head,int k,int d)
{
	link temp = head;
	link nnode = new node(d,NULL);
	if(k==1)
	{
		nnode->next=head->next;
		head->next=nnode;
	}
	else
	{
		int count=1;
	while(temp!=NULL)
	{
		if(count==(k))
		{
			nnode->next=temp->next;
			temp->next=nnode;
		}
		count++;
		temp=temp->next;
	}
	
	}
return head;
}

link insertBeforeKthNode(link head,int k,int d)
{
	link temp = head;
	link nnode = new node(d,NULL);
	if(k==1)
	{
		nnode->next=head;
		head=nnode;
	}
	else
	{
		int count=1;
	while(temp!=NULL)
	{
		if(count==(k-2))
		{
			nnode->next=temp->next;
			temp->next=nnode;
		}
		count++;
		temp=temp->next;
	}
	
	}
return head;
}

// insert 'd' before the first occurence of value 'p'

link insertBeforeP(link head, int p, int d)
{
	link nnode = new node(d,NULL);
	link temp = head;
	link t;
	
	// if head-> data is p
	if(head->data==p)
	{
		nnode->next=head;
		head=nnode;
	}
	else // traverse the rest of the list
	{
		while(temp->data!=p)
		{
			t = temp;
			temp = temp->next;
		}
		
		//temp holds the p value
		nnode->next = t->next;
		t->next = nnode;
	}
	
	return head;
	

}

// insert after p

link insertAfterP(link head, int p,int d)
{
	link nnode = new node(d,NULL);
	link temp = head;
	link t;
	
	if(head->data==p)
	{
		nnode->next=head->next;
		head->next = nnode;
	}
	else
	{
		while(temp->data!=p)
			temp=temp->next;
			
		nnode->next=temp->next;
		temp->next=nnode;
	}
return head;
}


/** DELETION **/

//delete at first

link deleteFirst(link head)
{
	if(head==NULL) //empty LL
		return NULL;
	else if(head->next==NULL)
	{ // only one element
		delete head;	
	}
	else
	{
		link temp = head;
		head = head->next;
		delete temp;
	}
return head;
}


// delete last node

link deleteLast(link head)
{
	if(head==NULL)
		return NULL;
	else if(head->next==NULL)
		delete head;
	else
	{
		link temp= head;
		link t;
		while(temp->next!=NULL)
		{
			t=temp;
			temp=temp->next;
		}
			
		t->next = NULL;
		delete temp;
		return head;
	}	
}

// delete nth node

link deleteNthNode(link head, int n)
{
	link temp = head;
	link t;
	if(n==1)
	{
		head=head->next;
		delete temp;
	}
	
	else
	{ 
		int count=1;
		while(temp!=NULL)
		{
			if(count==(n-1)) // temp has n-1 th node
			{
				t = temp->next; // t has nth node
				temp->next = t->next;
				delete t;
			}
			
			count++;
			temp = temp->next;
		}
	}
	
	return head;
}

link deleteSearch(link head, int s)
{
	link temp = head;
	link t;
	if(head->data==s)
	{
		head=head->next;
		delete temp;
	}
	
	else
	{ 
		while(temp!=NULL)
		{
			if(temp->data==s) // temp has searched value
			{
				t->next = temp->next; // t has nth node
				delete temp;
			}
			
			t = temp;
			temp = temp->next;
		}
	}
	
	return head;
}

// delete before pth node

link deleteBeforeP(link head,int p)
{
	link temp=head;
	link t;
	
	if(head->data==p)
	{
		return head;
	}
	else
	{
		while(temp->next->data!=p)
		{
			t = temp;
			temp=temp->next;
		}
		
		// temp->next has the p value
		t->next=temp->next;
		delete temp;
	}
	
	return head;
}

link deleteAfterP(link head,int p)
{
	link temp = head;
	link t;
	
	if(head->data==p)
	{
		temp=head->next;
		head->next=temp->next;
		delete temp;
	}
	else
	{
		while(temp->data!=p)
		{
			t=temp;
			temp=temp->next;
		}
		
		// temp has p
		link t1 = temp->next;
		temp->next= t1->next;
		delete t1;
	}
	return head;
}

link deleteBetweenPQ(link head,int p,int q)
{
	link temp=head;
	link t;
	
	while(temp->data!=p)
		temp=temp->next;
	// temp has value p 
	link ptemp=temp;
	
	while(temp->next->data!=q)
	{
		t=temp->next; // to delete
		temp->next=t->next;
		delete t;
	}
return head;
}


link deleteLast2Nodes(link head)
{
	link temp= head;
	link t;
	while(temp->next->next!=NULL)
	{
		t = temp;
		temp = temp->next;
	}
	
	link t1 = temp->next;
	delete temp;
	delete t1;
	t->next=NULL;
	return head;
}

link deleteOddNodes(link head)
{
	link temp=head;
	link t,t1;
	while(temp!=NULL)
	{
		if(head->data % 2==1)
		{
			// deleting head
			head= head->next;
			delete temp;
			temp=head;
		}
		else if(temp->data % 2 == 1)
		{
			t->next=temp->next;
			t1=temp->next;
			delete temp;
			temp=t1;
			
		}
		else
		{
			t=temp;
			temp=temp->next;
		}
	
	}
	return head;
}

link deleteAllExLast2(link head)
{
	
	link temp=head;
	link t,t1;
	while(temp->next->next!=NULL)
	{
		t=temp;
		temp=temp->next;
		delete t;
		head=temp;
	}
	
return head;
}

link deleteNNodesBegin(link head, int n)
{
	link temp = head;
	
	for(int i=1;i<=n;i++)
	{
			head=head->next;
			delete temp;
			temp=head;
	}
		

	return head;
}

link deleteNNodesEnd(link head, int n)
{
	link temp = head;
	link t;	
for(int i=1;i<=n;i++)
{
	temp=head;
	while(temp->next!=NULL)
	{
		t=temp;
		temp=temp->next;
	}
	//temp points to last
	delete temp;
	t->next=NULL;
}

	return head;
}


int main()
{
	cout<<"Creating LL from Array"<<endl;
	int array[5] = {1,2,3,4,5};
	printLL(createFromArrayEnd(array,5));
	cout<<endl;
	cout<<"Inserting in end"<<endl;
	link A = NULL;
A =	insertAtEnd(A,1);
A =	insertAtEnd(A,2);
A =	insertAtEnd(A,3);
A =	insertAtEnd(A,4);
A =	insertAtEnd(A,5);
A =	insertAtEnd(A,6);
A =	insertAtEnd(A,7);
A =	insertAtEnd(A,8);
A =	insertAtEnd(A,9);
A =	insertAtEnd(A,10);
	printLL(A);
//A = deleteAllExLast2(A);
//	printLL(A);
	cout<<endl;

	printLL(A);
	cout<<endl;
	cout<<"Inserting at end"<<endl;
A = insertAtEnd(A,1);
A = insertAtEnd(A,2);
A = insertAtEnd(A,3);
A = insertAtEnd(A,4);
A = insertAtEnd(A,5);
A = insertAtEnd(A,6);
A = insertAtEnd(A,2);

	printLL(A);
	cout<<endl;
	/**
	cout<<"Inserting on k node"<<endl;
A =	insertOnKthNode(A,1,30);
	printLL(A);
	cout<<endl;
	cout<<"Inserting after k node"<<endl;
A = insertAfterKthNode(A,1,30);
	printLL(A);	cout<<endl;
	cout<<"Inserting before k node"<<endl;
A = insertBeforeKthNode(A,1,30);
	printLL(A);
	cout<<endl;
A = insertBeforeP(A,2,99);
	printLL(A);
	cout<<endl;
A = insertAfterP(A,99,100);
	printLL(A);
	cout<<endl;
A = deleteFirst(A);
	printLL(A);
	cout<<endl;
A = deleteLast(A);
	printLL(A);
	cout<<endl;
A =	deleteNthNode(A,1);
	printLL(A);
	cout<<endl;
A = deleteSearch(A,99);
	printLL(A);
	cout<<endl;
A = deleteBeforeP(A,4);
	printLL(A);
	cout<<endl;
A = deleteAfterP(A,4);
	printLL(A);
	cout<<endl;
A = deleteBetweenPQ(A,1,6);
	printLL(A);
	cout<<endl;
A = deleteLast2Nodes(A);
	printLL(A);
	cout<<endl;
	// inserting for odd values
A = insertAtEnd(A,1);
A = insertAtEnd(A,2);
A = insertAtEnd(A,3);
A = insertAtEnd(A,4);
A = insertAtEnd(A,5);
A = insertAtEnd(A,6);
A = insertAtEnd(A,2);
A = insertAtEnd(A,33);
A = insertAtEnd(A,37);
A = insertAtEnd(A,13);
A = insertAtEnd(A,11);
*/
cout<<"Before Odd deletion"<<endl;
	printLL(A);
	cout<<endl;
//A = deleteOddNodes(A);
//	printLL(A);
	cout<<endl;
//A = deleteAllExLast2(A);
//	printLL(A);
	cout<<endl;
A =  deleteNNodesEnd(A,5);
	printLL(A);
	cout<<endl;
}
