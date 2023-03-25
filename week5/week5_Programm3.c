// III. You have been given two sorted integer arrays of size m and n. Design an algorithm and
// implement it using a program to find list of elements which are common to both. (Time
// Complexity = O(m+n))

//codeBySHIVANSHDUBEY

#include <stdio.h>
void findCommonElements(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    printf("Common elements: ");

    while (i < m && j < n) {
        // If both elements are same, print it and move both pointers
        if (arr1[i] == arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        // If the first element is smaller, move the first pointer
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        // If the second element is smaller, move the second pointer
        else {
            j++;
        }
    }
}

int main() {
    int m, n;
    printf("Enter the size of array 1: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter the elements of array 1 in sorted order: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of array 2: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter the elements of array 2 in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    findCommonElements(arr1, arr2, m, n);
    return 0;
}