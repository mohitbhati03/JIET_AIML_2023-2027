#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randomizedPartition(int arr[], int low, int high) {

    int randomPivot = low + rand() % (high - low + 1);

    swap(&arr[randomPivot], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, lower, upper;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the range of numbers (lower upper): ");
    scanf("%d %d", &lower, &upper);

    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }

    printf("Generated array: ");
    printArray(arr, n);

    clock_t start = clock();

    randomizedQuickSort(arr, 0, n - 1);

    clock_t end = clock();

    printf("Sorted array: ");
    printArray(arr, n);

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort the array: %.6f seconds\n", timeTaken);

    return 0;
}
