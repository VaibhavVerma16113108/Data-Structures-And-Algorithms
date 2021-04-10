#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;
#define ll long long


void merge(int arr[], int left, int right)
{
    int mid = (left + right) / 2;
    int lsize = mid - left + 1, rsize = right - mid;
    int pos = left;
    int leftarr[lsize];
    int rightarr[rsize];

    // Create a copy of left and right sorted arrays.
    for (int i = 0; i < lsize; i++)
        leftarr[i] = arr[left+i];
    for (int i = 0; i < rsize; i++)
        rightarr[i] = arr[mid+1+i];

    // Keep adding the smaller element to C
    int i = 0, j = 0;
    while (i < lsize && j < rsize)
    {
        if (leftarr[i] <= rightarr[j])
            arr[pos++] = leftarr[i++];
        else
            arr[pos++] = rightarr[j++];
    }

    // Add the remaining elements in either of the two arrays.
    while (i < lsize)
        arr[pos++] = leftarr[i++];
    while (j < rsize)
        arr[pos++] = rightarr[j++];
}

/*
    Function mergeSort recursively call itself on the left half
    and right half and then calls merge function to merge the two
    sorted halves
*/
void mergeSort(int arr[], int left, int right)
{
    // The following if condition is the base case.
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, right);
}

int main()
{
    int a[] = {10, 20, 5, 8, 7, 2, 15, 12};
    int n = 8;

    // Display the array
    cout << "Initial array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    /*
        Call function mergeSort on input array
        mergeSort(array, start, end)
    */
    mergeSort(a, 0, n-1);

    // Display the array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}