// Given an array of nonnegative integers, design a linear algorithm and implement it using a
// program to find whether given key element is present in the array or not. Also, find total number
// of comparisons for each input case. (Time Complexity = O(n), where n is the size of input

#include <stdio.h>

int main()
{
    int n, key, i, flag = 0, cmp = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++)
    {
        cmp++; //increment the comparison counter
        if(arr[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Key element %d is present in the array\n", key);
        printf("Total number of comparisons: %d\n", cmp);
    }
    else
    {
        printf("Key element %d is not present in the array\n", key);
        printf("Total number of comparisons: %d\n", cmp);
    }
    return 0;
}
