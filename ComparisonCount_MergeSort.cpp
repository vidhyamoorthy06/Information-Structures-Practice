#include<iostream>
using namespace std;
int const maxN=28;
int merge(int a[], int l, int m, int r)

  { int i, j, count=0;

    static int aux[maxN];

    for (i = m+1; i > l; i--) aux[i-1] = a[i-1];

    for (j = m; j < r; j++) aux[r+m-j] = a[j+1];
    for (int k = l; k <= r; k++)

       if (aux[j] < aux[i]) // array elements are compared
       {
       	 a[k] = aux[j--];
       	 count++;
	   }
	   else 
		{
		  	a[k] = aux[i++];
		  	count++;
		}
return count;
  }

 

int mergesort(int a[], int l, int r)
  { 
  int count=0;
  	if (r <= l) return 0;
    int m = (r+l)/2;
   count += mergesort(a, l, m); 
    count += mergesort(a, m+1, r);
   count += merge(a, l, m, r);
return count;
  }
  
  int main()
  {
  	int input[maxN];
  	for(int i=0;i<maxN;i++)
  	{
  		cin>>input[i];
	}
  	
  	int compCount = mergesort(input,0,maxN-1);
  	
  	cout<<"After Merge Sort, The sorted Array is "<<endl;
  		for(int i=0;i<maxN;i++)
  	{
  		cout<<input[i]<<" ";
	}
	cout<<endl;
	cout<<"The number of comparisons performed in merge sort is "<<compCount<<endl;
  	
  }

 
