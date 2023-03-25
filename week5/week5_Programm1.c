// Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
// implement it using a program to find which alphabet has maximum number of occurrences and
// print it. (Time Complexity = O(n)) (Hint: Use counting sort

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 256 // Maximum number of characters

// Function to count the frequency of characters
void count_frequency(char *arr, int n, int *count)
{
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
}

// Function to find the maximum frequency element
char find_max_frequency(char *arr, int n)
{
    int count[MAX_CHAR] = {0}; // Initialize all counts to zero

    count_frequency(arr, n, count); // Count the frequency of characters

    char max_char = arr[0];
    int max_count = count[arr[0]];

    for (int i = 1; i < n; i++) {
        if (count[arr[i]] > max_count) {
            max_char = arr[i];
            max_count = count[arr[i]];
        }
    }

    return max_char;
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'a', 'a', 'b', 'c', 'c', 'c'};
    int n = sizeof(arr) / sizeof(arr[0]);

    char max_char = find_max_frequency(arr, n);

    printf("Maximum frequency Character is '%c'\n", max_char);

    return 0;
}