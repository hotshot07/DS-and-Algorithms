#include<iostream>
#include<cstdio>

using namespace std;

void printArray(int arr[], int n)
{
int i;
for (i=0; i < n; i++)
	printf("%d ", arr[i]);
printf("\n");
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
	key = arr[i];
	j = i-1;
	cout << "key:" << key << " j: " << j <<"\n";

	printArray(arr,n);
	while (j >= 0 && arr[j] > key)
	{
		arr[j+1] = arr[j];
		j = j-1;
		printArray(arr,n);
	}
	arr[j+1] = key;

	cout << "key:" << key <<"\n";
	printArray(arr,n);
	cout <<"\n";
}
}

/* Driver program to test insertion sort */
int main()
{
	int arr[] = {12, 7, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

// OUTPUT
/*
key:7 j: 0
12 7 11 13 5 6
12 12 11 13 5 6
key:7
7 12 11 13 5 6

key:11 j: 1
7 12 11 13 5 6
7 12 12 13 5 6
key:11
7 11 12 13 5 6

key:13 j: 2
7 11 12 13 5 6
key:13
7 11 12 13 5 6

key:5 j: 3
7 11 12 13 5 6
7 11 12 13 13 6
7 11 12 12 13 6
7 11 11 12 13 6
7 7 11 12 13 6
key:5
5 7 11 12 13 6

key:6 j: 4
5 7 11 12 13 6
5 7 11 12 13 13
5 7 11 12 12 13
5 7 11 11 12 13
5 7 7 11 12 13
key:6
5 6 7 11 12 13

5 6 7 11 12 13
*/
