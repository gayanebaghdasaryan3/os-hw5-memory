#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *arr;
    int *temp;

    arr = (int *)malloc(10 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter 10 integers: ");

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    temp = (int *)realloc(arr, 5 * sizeof(int));

    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        free(arr);
        arr = NULL;
        return 1;
    }

    arr = temp;

    printf("Array after resizing: ");

    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}
