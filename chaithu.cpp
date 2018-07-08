#include<iostream>
using namespace std;
int main()
{

int Arr[20],i,small,large;
cout<<"Enter the number of elements you want to insert"<<endl;


for (i=0;i<20;i++)
{
	cin>>Arr[i];
}

	small=Arr[0];
	large=Arr[0];
	
	for (i=0;i<20;i++)
{
if (Arr[i]<small)
{
	small=Arr[i];
}

if(Arr[i]>large)
{
	large=Arr[i];
}

}
cout<<"largest number is;" <<large<<endl;
cout<<"smallest number is;" <<small<<endl;
return 0;
}
