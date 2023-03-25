// Given an unsorted array of integers, design an algorithm and implement it using a program to
// sort an array of elements by partitioning the array into two subarrays based on a pivot element
// such that one of the sub array holds values smaller than the pivot element while another sub
// array holds values greater than the pivot element. Pivot element should be selected randomly
// from the array. Your program should also find number of comparisons and swaps required for
// sorting the array programm in c

// Given an unsorted array of integers, design an algorithm and implement it using a program to
// find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high, int* comp, int* swap) {
    int pivot = arr[high]; // Select the last element as the pivot
    int i = low - 1; // Initialize the index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swap)++;
        }
        (*comp)++;
    }
    // Swap arr[i + 1] and arr[high]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swap)++;
    return i + 1; // Return the partition index
}

void quicksort(int arr[], int low, int high, int* comp, int* swap) {
    if (low < high) {
        // Select a random pivot
        srand(time(NULL));
        int random = low + rand() % (high - low + 1);
        // Swap the pivot with the last element
        int temp = arr[random];
        arr[random] = arr[high];
        arr[high] = temp;
        (*swap)++;
        
        // Partition the array and get the partition index
        int pi = partition(arr, low, high, comp, swap);

        // Recursively sort the subarrays
        quicksort(arr, low, pi - 1, comp, swap);
        quicksort(arr, pi + 1, high, comp, swap);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comp = 0, swap = 0;
    quicksort(arr, 0, n - 1, &comp, &swap);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }}