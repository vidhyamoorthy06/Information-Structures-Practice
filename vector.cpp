#include<iostream>
using namespace std;

struct vector
{
	int index;
	int val;
	
}A[10],B[10];

int main()
{
		int product=0,i=0,j=0; 
	cout<<"Enter nonzero elements in A"<<endl;
	cout<<"Index val"<<endl;
	for (int i=0; i<4; i++) 
	{
		cin>>A[i].index>>A[i].val;
	}
	cout<<"Enter nonzero elements in B"<<endl;
	cout<<"Index val"<<endl;
	for (int i=0; i<3; i++) 
	{
		cin>>B[i].index>>B[i].val;
	}

//Computing the dot product of the vector arrays

for(int i=0;i<10;i++)
{
	for(int j=0;j<10;j++)
	{
		if(i==j)
		{
				product+=(A[i].val*B[j].val);
					i++;
					j++;
		}
		else if(i<j)
		{
			i++;
		}
		
		
	}
				}
				            
	cout<<"Dot-product AB is "+product<<endl;
}
