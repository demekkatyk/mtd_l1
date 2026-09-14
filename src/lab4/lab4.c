#include <stdio.h>
#include <stdlib.h>

// Задание 1: обмен значений через указатели
void swap(int* i, int* j) {
    int t = *i;
    *i = *j;
    *j = t;
}

// Задание 2a: минимум во встроенном двухмерном массиве
int findMinStatic(int a[3][4], int rows, int cols) {
    int min = a[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (a[i][j] < min) min = a[i][j];
    return min;
}

// Задание 2b: минимум в динамическом двухмерном массиве
int findMinDynamic(int** arr, int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] < min) min = arr[i][j];
    return min;
}

// Задание 3: сравнение строк
int myStrCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main(void) {
    printf("=== Task 1: swap ===\n");
    int a1 = 5, b1 = 10;
    swap(&a1, &b1);
    printf("swap(5, 10) -> %d %d\n", a1, b1);

    printf("\n=== Task 2a: min in static 2D array ===\n");
    int a[3][4] = {
        {5, 8, -2, 3},
        {7, 0, 9, 1},
        {4, -6, 2, 10}
    };
    printf("min = %d\n", findMinStatic(a, 3, 4));

    printf("\n=== Task 2b: min in dynamic 2D array ===\n");
    int rows = 2, cols = 3;
    int** dyn = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dyn[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            dyn[i][j] = (i + 1) * 10 + j - 5;
        }
    }
    printf("min = %d\n", findMinDynamic(dyn, rows, cols));
    for (int i = 0; i < rows; i++) free(dyn[i]);
    free(dyn);

    printf("\n=== Task 3: string compare ===\n");
    printf("myStrCmp(\"abc\", \"abd\") = %d\n", myStrCmp("abc", "abd"));
    printf("myStrCmp(\"abc\", \"abc\") = %d\n", myStrCmp("abc", "abc"));
    printf("myStrCmp(\"abd\", \"abc\") = %d\n", myStrCmp("abd", "abc"));

    return 0;
}