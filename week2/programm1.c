// Given a sorted array of positive integers containing few duplicate elements, design an algorithm
// and implement it using a program to find whether the given key element is present in the array or
// not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
#include <stdio.h>

int binarySearch(int arr[], int n, int key, char searchFirst) {
    int low = 0, high = n - 1, result = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            result = mid;
            
            if (searchFirst)
                high = mid - 1;
            else
                low = mid + 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int n, key, count = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array in ascending order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the key element to search: ");
    scanf("%d", &key);
    
    int firstIndex = binarySearch(arr, n, key, 1);
    
    if (firstIndex == -1) {
        printf("Element not found in the array.\n");
    } else {
        int lastIndex = binarySearch(arr, n, key, 0);
        count = lastIndex - firstIndex + 1;
        
        printf("Element found in the array %d times.\n", count);
    }
    
    return 0;
}

