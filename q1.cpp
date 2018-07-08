#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

// A struct to keep items 
struct point
{
	int x;
	int y;
}points[10];

int main()
{
	int c[10];

	cout<<"Enter the points ::"<<endl;
	cout<<"x  y"<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>points[i].x>>points[i].y;
	}
	cout<<"Distinct points"<<endl;
	cout<<"x  y"<<endl;
	for(int i=0;i<10;i++)
    {
	int j;
		for(j=0;j<i;j++)
			if((points[i].x==points[j].x)&&(points[i].y==points[j].y))
			break;
	
			if(i==j)
			cout<<points[i].x<<"  "<<points[i].y<<endl;
		
    }
     
}





