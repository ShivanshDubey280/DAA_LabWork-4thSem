// Given an unsorted array of integers, design an algorithm and implement it using a program to
// find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using the last element as pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to find the Kth smallest element in the array
int findKthSmallest(int arr[], int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low == k - 1)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex - low > k - 1)
        {
            return findKthSmallest(arr, low, pivotIndex - 1, k);
        }
        else
        {
            return findKthSmallest(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
        }
    }
    return -1; // If k is out of range of array size
}

int main()
{
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of K: ");
    scanf("%d", &k);

    int kthSmallest = findKthSmallest(arr, 0, n - 1, k);
    if (kthSmallest == -1)
    {
        printf("Invalid K value!");
    }
    else
    {
        printf("The %dth smallest element in the array is %d", k, kthSmallest);
    }

    return 0;
}