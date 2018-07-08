/**#include<iostream>

using namespace std;

struct element
{
	int data;
	int index;
	element* next;
	element(int i,int d, element* e)
	{
		data=d;
		index=i;
		next = e;
	}
};

element* A = new element(0,0,NULL);
element* B = new element(0,0,NULL);

int size =0;

void product(element* A,element* B)
{
	int prod=0;
	while(A!=NULL && B!=NULL)
	{
		if(A->index == B->index)
		{
		prod = prod + (A->data*B->data);
		A = A->next;
		B = B->next;	
		}
		else if(A->index < B->index)
		A = A->next;
		else
		B = B->next;
	}
	
	cout<<prod<<endl;
}
	
void print(element* head)
{
	element* it = head;   // it means iterator, visit all items one by one.
	while (it != NULL) 
	{
		cout << it->index << "   "<< it->data << endl;
		it = it->next;
	}
}

element* add(element* head,int index,int data)
{
	
	element* e = new element(index,data,NULL);			//  dynamically create a new struct/item
	if(head==0)
		head=e;
	else
	{
		e->next = head;
		head = e;
	}
	return head;

}

int main()
{
//	unsigned short n =5;
	int a_d,b_d,a_i,b_i;
	cout<<"Enter nonzero elements in A"<<endl;
	cout<<"Index val"<<endl;
	while(a_i!=-1 && a_d!=-1)
	{
		cin>>a_i>>a_d;
		A = add(A,a_i,a_d);
		
	}
	
	print(A);
	
	cout<<"Enter nonzero elements in B"<<endl;
	cout<<"Index val"<<endl;
	while(b_i!=-1 && b_d!=-1)
	{		
		cin>>b_i>>b_d;
		B = add(B,b_i,b_d);
	}
	
	print(B);
	
	//finding the dot product of A and B
	
	cout<<"The dot product of A and B is "<< endl;
	product(A,B);
	
}
*/
#include<iostream>

using namespace std;

struct element
{
int data;
int index;
element* next;
element(int ind,int val, element* e)
{
data=val;
index=ind;
next = e;
}
};

element* A = new element(0,0,NULL);
element* B = new element(0,0,NULL);

//int size =0;

void product(element* A,element* B)
{
int prod=0;
while(A!=0 && B!=0)
{
if(A->index == B->index)
{
prod = prod + (A->data*B->data);
A = A->next;
B = B->next;
}
else if(A->index < B->index)
A = A->next;
else
B = B->next;
}
cout<<prod-1<<endl;
}
/*void print(element* head)
{
element* it = head;   // it means iterator, visit all items one by one.
while (it != NULL)
{
cout << it->index << "   "<< it->data << endl;
it = it->next;
}
}*/

element* add(element* head,int index,int data)
{
element* e = new element(index,data,NULL); //  dynamically create anew struct item

if(head==0)
head=e;
else
{
e->next = head;
head = e;
}
return head;

/**
element* t = head;
while(t->next!=0)
{
t = t->next;
t->next = e;
}
return head;
*/
}

int main()
{
// unsigned short n =5;
int a_d,b_d,a_i,b_i;
cout<<"Enter nonzero elements in A"<<endl;
cout<<"Index val"<<endl;
while(a_i!=-1 && a_d!=-1)
{
cin>>a_i>>a_d;
A = add(A,a_i,a_d);
}
//print(A);
cout<<"Enter nonzero elements in B"<<endl;
cout<<"Index val"<<endl;
while(b_i!=-1 && b_d!=-1)
{
cin>>b_i>>b_d;
B = add(B,b_i,b_d);
}
//print(B);
//finding the dot product of A and B
cout<<"The dot product of A and B is "<< endl;
product(A,B);
}
