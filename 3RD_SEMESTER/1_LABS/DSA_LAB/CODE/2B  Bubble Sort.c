#include <stdio.h>

// Function to perform bubble sort
void bubble_sort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Ask user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Create an array of size n
    int arr[n];

    // Ask user to input elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    print_array(arr, n);

    // Perform bubble sort
    bubble_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}










// Overview
// Bubble sort is a simple sorting algorithm that works by repeatedly iterating through the array, comparing adjacent elements, and swapping them if they are in the wrong order. This process is repeated until the array is sorted.

// Explanation
// The bubble_sort function takes two arguments: arr (the array to sort) and n (the size of the array).
// The function iterates through the array, comparing adjacent elements and swapping them if they are in the wrong order.
// The print_array function is used to print the array.
// In the main function, we first ask the user to input the size of the array (n).
// We then create an array of size n and ask the user to input its elements.
// We print the original array using the print_array function.
// We perform the bubble sort using the bubble_sort function.
// Finally, we print the sorted array using the print_array function.

// Time Complexity
// The time complexity of bubble sort is O(n^2), where n is the size of the array. This is because the algorithm has two nested loops, each iterating n times