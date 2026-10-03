#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;
    int sum = 0;
    int *arr;
    double average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Array after calloc: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter %d integers: ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("Updated array: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    average = (double)sum / n;

    printf("\nAverage of the array: %.1f\n", average);

    free(arr);
    arr = NULL;

    return 0;
}
