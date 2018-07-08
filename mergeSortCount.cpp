#include<iostream>

using namespace std;

int merge(int a[], int l, int m, int r) 
{
	int count1 = 0;

	int i, j;

	static int aux[100];

	for (i = m + 1; i > l; i--)

		aux[i - 1] = a[i - 1];

	for (j = m; j < r; j++)

		aux[r + m - j] = a[j + 1];

	for (int k = l; k <= r; k++) 
	{
		count1++;

		if (aux[j] < aux[i])

			a[k] = aux[j--];

		else

			a[k] = aux[i++];
	}
	return count1;
}

int mergesort(int a[], int l, int r) 
{	
	int count = 0;

	if (r <= l)

		return 0;

	int m = (r + l) / 2;

	count = count + mergesort(a, l, m);

	count = count + mergesort(a, m + 1, r);

	count = count + merge(a, l, m, r);

	return count;

}

int main() 
{
	int mergeCount = 0;

	int arr[100], size;

	cout << "Enter the size of the input array" << endl;

	cin >> size;

	cout << "Enter the array of elements" << endl;

	for (int i = 0; i < size; i++)
		cin >> arr[i];
		
	cout << "Given array is : " << endl;

	for (int i = 0; i < size; i++)

		cout << arr[i] << " ";

	cout << endl;

	mergeCount = mergesort(arr, 0, size - 1);		// count returned by mergesort function stored in mergeCount variable

	cout << "Sorted array using Merge Sort is : " << endl;

	for (int i = 0; i < size; i++)

		cout << arr[i] << " ";				// printing given array

	cout << endl;

	cout << "Total comparisons for Merge Sort is : " << mergeCount << endl;	// No.of comparisons

	//system("pause");
}
