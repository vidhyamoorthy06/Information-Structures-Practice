/**
Comparison of Quick Sort and Insertion Sort in Randomly genereated 1024 integer in dynamically crated arrays.
Inference is that Quick Sort performs better than Insertion Sort
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;


		void swap(int A[], int i, int min);
		bool small(int a, int b);
		void print(int A[]);
		void fillRandom(int A[], int size);
		void insertionSort(int A[], int size);
		void quickSort(int A[], int lo, int hi);
		

void insertionSort(int A[], int size)
{
	 // Insertion sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
        	 if ( small(A[j], A[j-1]) == true) // compare
                	swap(A, j, j-1); // exchange or swap
            else break;
		}
           
    }	
	
}
int partition(int A[], int lo, int hi)
{
   int i = lo, j = hi+1; // to handle pre increement and pre decreement
   while (true)
   {
      while (small(A[++i], A[lo]))  // find item on left to swap
         if (i == hi) break;

      while (small(A[lo], A[--j]))  // find item on right to swap
         if (j == lo) break;
     
      if (i >= j) break;	//check if pointers cross
      swap(A, i, j);
   }
   swap(A, lo, j);
   return j;			// return index of item now known to be in place
} 
void quickSort(int A[], int lo, int hi)
   {
      if (hi <= lo) return;
      int j = partition(A, lo, hi);
      quickSort(A, lo, j-1);
      quickSort(A, j+1, hi);
  }




bool small(int a, int b)
{
    if (a < b) return true;
    return false;
}

void swap(int A[], int i, int k)
{
    int tmp= A[i];
    A[i]=A[k];
    A[k]=tmp;
}


void fillRandom(int A[], int size)
{	
	for (int i = 0; i < size; i++)
		A[i]=rand() % 50;	
}

void print(int A[])
{	
	for (int i = 0; i < 1024; i++)
		cout << A[i] << ", ";
	cout << endl;
}
       
int main()
{
   int input[1024];

	clock_t start, stop; 
	double totalTime;
   cout<<"\t\tGenerating 1024 elements"<<endl;  
   	fillRandom(input,1024); //ramdomly filling input array	
   	print(input);
   	cout<<endl;
   	cout<<"Sort"<<"\t\t\t"<<"Time taken"<<endl;
   			// Insertion sort
		start = clock();		
		insertionSort(input,1024);		
		stop = clock();			
		totalTime = (stop - start) / (double)CLOCKS_PER_SEC;

	cout<<"Insertion Sort"<<"\t\t\t"<<totalTime<<endl;	
		
		fillRandom(input,1024); //ramdomly filling input array
		
		// Quick Sort
		start = clock();
		quickSort(input,0,1023);
		stop = clock();			
		totalTime = (stop - start) / (double)CLOCKS_PER_SEC;	
	
	cout<<"Quick Sort"<<"\t\t\t"<<totalTime<<endl;	

}



