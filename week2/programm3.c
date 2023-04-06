// Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K. 

#include <stdio.h>
#include <stdlib.h>


// Comparator function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int countPairsWithDifference(int arr[], int n, int K) {
    int count = 0;
    int left = 0, right = 1;
    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), cmpfunc);
    // Loop through the array
    while (right < n) {
        int diff = arr[right] - arr[left];
        // If the difference is equal to K, increment the counter and move both pointers
        if (diff == K) {
            count++;
            left++;
            right++;
        }
        // If the difference is less than K, move the right pointer
        else if (diff < K) {
            right++;
        }
        // If the difference is greater than K, move the left pointer
        else {
            left++;
        }
    }
    return count;
}
//24 71 16 92 12 28 48 14 20 22
int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;
    int result = countPairsWithDifference(arr, n, K);
    printf("Number of pairs with difference %d: %d\n", K, result);
    return 0;
}
