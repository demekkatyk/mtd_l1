#include <stdio.h>
#include <stdlib.h>

// Задание 4: добавление уникального значения в динамический массив
int contains(int* arr, int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value) return 1;
    return 0;
}

// Задание 5a: рекурсивная сумма первых N чисел
int summa(int num) {
    if (num == 0) return 0;
    return num + summa(num - 1);
}

// Задание 5b: рекурсивное число Фибоначчи
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

// Задание 7: функция возвращает указатель на минимальный элемент
int* myMin(int a[], int n) {
    int* min = a;
    for (int i = 1; i < n; i++)
        if (a[i] < *min) min = &a[i];
    return min;
}

int main(void) {
    printf("=== Task 4: unique dynamic array ===\n");
    int cap = 4;
    int* arr = malloc(cap * sizeof(int));
    int size = 0;
    int values[] = {3, 5, 3, 7, 5, 9};
    int count = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < count; i++) {
        if (!contains(arr, size, values[i])) {
            if (size == cap) {
                cap *= 2;
                arr = realloc(arr, cap * sizeof(int));
            }
            arr[size++] = values[i];
        }
    }
    printf("unique values: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    printf("\n=== Task 5a: recursive sum ===\n");
    printf("summa(10) = %d\n", summa(10));

    printf("\n=== Task 5b: recursive fibonacci ===\n");
    for (int i = 0; i <= 10; i++) printf("fib(%d) = %d\n", i, fib(i));

    printf("\n=== Task 7: return address, min set to 0 ===\n");
    int arr7[] = {5, 2, 9, -3, 7};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    *myMin(arr7, n7) = 0;
    printf("after zeroing min: ");
    for (int i = 0; i < n7; i++) printf("%d ", arr7[i]);
    printf("\n");

    return 0;
}