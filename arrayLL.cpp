#include <iostream>

using namespace std;

struct node
{
	int x; node* next;
	node(int d, node* n)
	{
		x=d;
		next = n;	
	}	
};

typedef node* link;



link createFromArray(int* a, int n)
{
	link head =0;
	for(int i=0;i<n;i++)
	{
		head = new node(a[i],head);
		cout<<"head -> "<<head->x<<endl;
	}

return head;
}
int main()
{
	int a[5] = { 1,2,3,4,5};
	createFromArray(a,5);
	
}
