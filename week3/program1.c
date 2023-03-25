// Given an unsorted array of integers, design an algorithm and a program to sort the array using
// insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -total number of times the array elements are shifted from their place) required for sorting the
// array program in c

#include <stdio.h>
void insertion_sort(int arr[], int n, int *comparisons, int *shifts) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        *shifts += 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
            *shifts += 1;
            *comparisons += 1;
        }
        arr[j+1] = key;
        *shifts += 1;
    }
}

int main() {
    int arr[] = {63, 42, 223, 645, 652, 31, 324, 22, 553, -12, 54, 65, 86, 46, 325};
    int n = sizeof(arr)/sizeof(arr[0]);
    int comparisons = 0;
    int shifts = 0;
    
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    insertion_sort(arr, n, &comparisons, &shifts);
    
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of shifts: %d\n", shifts);
    
    return 0;
}
