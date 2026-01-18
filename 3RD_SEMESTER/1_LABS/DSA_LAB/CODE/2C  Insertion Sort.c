#include <stdio.h>

// Function to perform insertion sort
void insertion_sort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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

    // Perform insertion sort
    insertion_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}



















// Insertion sort is a simple sorting algorithm that works by dividing the input into a sorted and an unsorted region. Each subsequent element from the unsorted region is inserted into the sorted region at the correct position.

// Explaination
// The insertion_sort function takes two arguments: arr (the array to sort) and n (the size of the array).
// The function iterates through the array, starting from the second element (index 1).
// For each element, it compares it with the previous elements and shifts those elements one position to the right until it finds the correct position to insert the current element.
// The print_array function is used to print the array.
// In the main function, we first ask the user to input the size of the array (n).
// We then create an array of size n and ask the user to input its elements.
// We print the original array using the print_array function.
// We perform the insertion sort using the insertion_sort function.
// Finally, we print the sorted array using the print_array function.

// Time Complexity
// The time complexity of insertion sort is O(n^2), where n is the size of the array. This is because the algorithm has two nested loops, each iterating n times.


