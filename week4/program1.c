// Given an unsorted array of integers, design an algorithm and implement it using a program to
// sort an array of elements by dividing the array into two subarrays and combining these subarrays
// after sorting each one of them. Your program should also find number of comparisons and
// inversions during sorting the array 

#include <stdio.h>

void merge(int arr[], int l, int m, int r, int *cmp, int *inv) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j, k;

    // copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // merge the temporary arrays back into arr[l..r]
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        (*cmp)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            (*inv) += n1 - i;
            arr[k++] = R[j++];
        }
    }

    // copy the remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // copy the remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r, int *cmp, int *inv) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // sort first and second halves
        mergeSort(arr, l, m, cmp, inv);
        mergeSort(arr, m + 1, r, cmp, inv);

        // merge the sorted halves
        merge(arr, l, m, r, cmp, inv);
    }
}

int main() {
    int n, i, cmp = 0, inv = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1, &cmp, &inv);

    printf("Sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons: %d\n", cmp);
    printf("Number of inversions: %d\n", inv);

    return 0;
}