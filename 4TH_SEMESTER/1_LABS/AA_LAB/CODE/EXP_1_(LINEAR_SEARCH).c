#include <stdio.h>
#include <time.h>

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    clock_t start_search = clock();
    int result = linear_search(arr, n, target);
    clock_t end_search = clock();
    double search_time = (double)(end_search - start_search) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    printf("Time taken for linear search: %f seconds\n", search_time);

    return 0;
}