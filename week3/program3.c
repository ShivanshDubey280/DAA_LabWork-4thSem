// Given an unsorted array of positive integers, design an algorithm and implement it using a
// program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
// Complexity = O(n log n)

#include <stdio.h>
#include <stdlib.h>

// comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}
// function to check whether there are any duplicate elements in an array
int hasDuplicates(int arr[], int n) {
    // sort the array
    qsort(arr, n, sizeof(int), (const void *) compare);

    // check for duplicates
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            return 1; // found a duplicate
        }
    }

    return 0; // no duplicates found
}


// main function to test the hasDuplicates function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasDuplicates(arr, n)) {
        printf("Duplicates found.\n");
    } else {
        printf("No duplicates found.\n");
    }

    return 0;
}
