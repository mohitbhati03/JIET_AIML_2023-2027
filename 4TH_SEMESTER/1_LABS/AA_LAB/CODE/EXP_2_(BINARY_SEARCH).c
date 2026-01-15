#include <stdio.h>
#include <time.h>

int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    clock_t start_search = clock();
    int result = binary_search(arr, 0, n - 1, target);
    clock_t end_search = clock();
    double search_time = (double)(end_search - start_search) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    printf("Time taken for binary search: %f seconds\n", search_time);

    return 0;
}