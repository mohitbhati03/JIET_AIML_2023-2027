#include <stdio.h>

// Function to perform linear search
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main() {
    int n, target;

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

    // Ask user for the target element
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Perform linear search
    int result = linear_search(arr, n, target);

    // Print the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}






// Explanation
// The linear_search function remains the same as in the previous example.
// In the main function, we first ask the user to input the size of the array (n).
// We then create an array of size n and ask the user to input its elements.
// Next, we ask the user to input the target element to search for.
// We perform the linear search using the linear_search function and store the result.
// Finally, we print the result, indicating whether the element was found and its index if applicable.

// Time Complexity
// The time complexity of linear search is O(n), where n is the size of the array. This is because in the worst-case scenario, the algorithm must iterate through every element in the array.