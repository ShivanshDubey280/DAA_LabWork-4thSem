#include <stdio.h>
#include <math.h>

// Jump Search function
int jumpSearch(int arr[], int n, int key)
{
    // Finding block size to be jumped
    int jump = sqrt(n);
    
    // Finding the block where the key may exist
    int left = 0;
    int right = jump;
    while (right < n && arr[right] <= key) {
        left = right;
        right += jump;
    }
    
    // Performing a linear search in the block where the key may exist
    for (int i = left; i <= fmin(right, n-1); i++) {
        if (arr[i] == key)
            return i;
    }
    
    // If the key is not found
    return -1;
}

// Main function to test the Jump Search algorithm
int main()
{
    // Input the sorted array and the key to be searched
    int arr[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 35;
    
    // Performing the Jump Search and printing the result
    int index = jumpSearch(arr, n, key);
    if (index != -1)
        printf("Key %d is found at index %d.\n", key, index);
    else
        printf("Key %d is not found.\n", key);
    
    return 0;
}
