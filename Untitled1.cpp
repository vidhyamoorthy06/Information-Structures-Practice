/*
VENKATA CHAITANYA BHAVIRISETTY 
CWID 50189569  
*/

/*
Course Assignment 1: All distinct points from a given list of 10 points
*/

#include <iostream>
using namespace std;

// A struct to keep items 
struct point
{
	int x;
	int y; 
}
p[10];
int main()
{
//	int a[10];

	cout<<"Enter the points "<<endl;     //Inputting the points in the list
	cout<<"x  y"<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>p[i].x>>p[i].y;   // accessing struct points
	}
	cout<<"Distinct points are" <<endl;
	cout<<"x  y"<<endl;
	for(int i=0;i<10;i++)
    {
	int j;                  //checking previous points with present line
		for(j=0;j<i;j++)
			
			if((p[i].x==p[j].x)&&(p[i].y==p[j].y))    // checking if points are same
			
			break;          // eliminate if same 
	
			if(i==j)
			
			cout<<p[i].x<<"  "<<p[i].y<<endl;   // printing distinct elements
		
    }
     
}


