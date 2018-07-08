#include<iostream>
using namespace std;
int const maxN=28;



int* partition(int a[], int l, int r)
  { 
  int i = l-1, j = r; int v = a[r]; int count=0;
  int partition_compCount[2];
    for (;;)
      {
      	count++;
        while (a[++i] < v) // array a elements are compared
		{
        	count++;
		}
		count++;
        while (v < a[--j]) // array a elements are compared
		{
			count++;
        	if (j == l) break;
		}
        if (i >= j) break;
        // swap a[i] and a[j]
        int t = a[i];
        a[i]= a[j];
        a[j] = t;
      }
   //swap a[i] and a[r]
   int temp = a[i];
        a[i]= a[r];
        a[r] = temp;
    partition_compCount[0]=i; // partition is in "0" index
    partition_compCount[1]=count; // count of comparisons is in "1" index
    return partition_compCount;
  }
  

int quicksort(int a[], int l, int r)
  {
    if (r <= l) return 0;
   /* call for partition function that you modify */
   int *p = partition(a,l,r);
   int i = p[0]; // has the partition index from partition() function
    p[1] += quicksort(a, l, i-1);
    p[1] += quicksort(a, i+1, r);  
    return p[1]; // has the number of comparisons in quick sort
  }



  int main()
  {
  	int input[maxN];
  	for(int i=0;i<maxN;i++)
  	{
  		cin>>input[i];
	}
  	
  	int compCount = quicksort(input,0,maxN);
  	
  	cout<<"After Quick Sort, The sorted Array is "<<endl;
  		for(int i=0;i<maxN;i++)
  	{
  		cout<<input[i]<<" ";
	}
	cout<<endl;
	cout<<"The number of comparisons performed in quick sort is "<<compCount<<endl;
  	
  }

 
