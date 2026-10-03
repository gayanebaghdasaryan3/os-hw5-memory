#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char **arr;
    char **temp;

    arr = (char **)malloc(3 * sizeof(char *));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        arr[i] = (char *)malloc(51 * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");

            for (int j = 0; j < i; j++) {
                free(arr[j]);
                arr[j] = NULL;
            }

            free(arr);
            arr = NULL;
            return 1;
        }
    }

    printf("Enter 3 strings: ");

    for (i = 0; i < 3; i++) {
        scanf("%50s", arr[i]);
    }

    temp = (char **)realloc(arr, 5 * sizeof(char *));

    if (temp == NULL) {
        printf("Memory reallocation failed\n");

        for (i = 0; i < 3; i++) {
            free(arr[i]);
            arr[i] = NULL;
        }

        free(arr);
        arr = NULL;
        return 1;
    }

    arr = temp;

    for (i = 3; i < 5; i++) {
        arr[i] = (char *)malloc(51 * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");

            for (int j = 0; j < i; j++) {
                free(arr[j]);
                arr[j] = NULL;
            }

            free(arr);
            arr = NULL;
            return 1;
        }
    }

    printf("Enter 2 more strings: ");

    for (i = 3; i < 5; i++) {
        scanf("%50s", arr[i]);
    }

    printf("All strings: ");

    for (i = 0; i < 5; i++) {
        printf("%s ", arr[i]);
    }

    printf("\n");

    for (i = 0; i < 5; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr);
    arr = NULL;

    return 0;
}
