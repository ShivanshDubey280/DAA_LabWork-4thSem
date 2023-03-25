#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key, int* count) {
    if (high < low) {
        return -1;  // Key not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid;  // Key found at mid index
    } else if (arr[mid] < key) {
        (*count)++;
        return binarySearch(arr, mid + 1, high, key, count);  // Search in right half of array
    } else {
        (*count)++;
        return binarySearch(arr, low, mid - 1, key, count);  // Search in left half of array
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 5;
    int count = 1;  // Counter for total number of comparisons

    int result = binarySearch(arr, 0, n - 1, key, &count);

    if (result == -1) {
        printf("Key not found in the array\n");
    } else {
        printf("Key found at index %d\n", result);
    }

    printf("Total number of comparisons: %d\n", count);

    return 0;
}
