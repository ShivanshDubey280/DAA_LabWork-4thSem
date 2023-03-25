// Given a sorted array of positive integers, design an algorithm and implement it using a program
// to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. 

#include <stdio.h>

void findTriplets(int arr[], int n) {
    int i, j, k;
    for (i = 0; i < n - 2; i++) {
        j = i + 1;
        k = n - 1;
        while (j < k) {
            if (arr[i] + arr[j] == arr[k]) {
                printf("%d, %d, %d\n", i, j, k);
                return;
            }
            else if (arr[i] + arr[j] < arr[k])
                j++;
            else
                k--;
        }
    }
    printf("No triplet found\n");
}

int main() {
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}
