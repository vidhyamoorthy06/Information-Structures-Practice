
// DOT PRODUCT OF VECTORS USING ARRAY STRUCTURES


#include<iostream>
using namespace std;
struct vector
{
int index;
int val;	
};

int main()

{
	vector A[10];
	vector B[10];
	int i=0;
	int j=0;
	int n=5;
	int product;
	cout<<"enter the non zero elements into A:"<<endl;
	cout<<"index val"<<endl;
	for (int i=0;i<n;i++)
	cin>>A[i].index>>A[i].val;	
	cout<<"enter the non zero elements into B:"<<endl;
	cout<<"index val"<<endl;
	for (int j=0;j<n-1;j++)
	cin>>B[j].index>>B[j].val;
	
	//dot product
	while (A[i].index!= -1 && B[j].index!= -1)
{
	if(A[i].index==B[j].index)
	{
		product+=A[i].val * B[j].val;
		i++;
		j++;
	}
	else if (A[i].index<B[j].index)
	 i++;
	else
	j++;
}	
cout<<"The dot product of A and B is "<<product;

}
