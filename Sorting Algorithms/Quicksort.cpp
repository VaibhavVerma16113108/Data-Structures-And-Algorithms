#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;
#define ll long long

/* 
To understand the logic of the partition function, refer to https://www.youtube.com/watch?v=MZaf_9IZCrc
*/
int partition(int arr[], int low, int high){
	int pivot = arr[high]; // pivot element
	int i = low - 1;	// initialise i to one less than the lower index

	for(int j = low; j < high; j++){
		// If current element is lesser than or equal to pivot
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i+1], arr[high]);
	return i + 1;
}

void quicksort(int arr[], int low, int high){
	if(low < high){
		int p = partition(arr, low, high);
		quicksort(arr, low, p-1);
		quicksort(arr, p+1, high);
	}
}

void print(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}

int main(){

	int n = 9;
	int arr[] = {5, 10, 8, 7, 3, 6, 12, 2, 7};
	quicksort(arr, 0, n);
	cout << "Sorted array:" << endl;
	print(arr, n);
	return 0;
}