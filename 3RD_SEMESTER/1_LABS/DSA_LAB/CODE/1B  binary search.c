#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index of the target element
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
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

    // Ask user to input elements of the array in sorted order
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask user for the target element
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binary_search(arr, 0, n - 1, target);

    // Print the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}






// Explanation
// The binary_search function takes four arguments: arr (the array to search), low (the lower bound of the search interval), high (the upper bound of the search interval), and target (the element to search for).
// The function repeatedly divides the search interval in half and searches for the element in one of the two halves.
// If the target is found, the function returns its index.
// If the target is not found, the function returns -1.
// In the main function, we first ask the user to input the size of the array (n).
// We then create an array of size n and ask the user to input its elements in sorted order.
// Next, we ask the user to input the target element to search for.
// We perform the binary search using the binary_search function and store the result.
// Finally, we print the result, indicating whether the element was found and its index if applicable.

// Time Complexity
// The time complexity of binary search is O(log n), where n is the size of the array. This is because the algorithm repeatedly divides the search interval in half, reducing the number of comparisons needed to find the element.