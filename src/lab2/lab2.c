#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 1. Размер типов данных в памяти
    printf("sizeof(char) = %zu byte\n", sizeof(char));
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(long) = %zu bytes\n", sizeof(long));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));
    printf("sizeof(int*) = %zu bytes\n", sizeof(int*));

    // 2. Переменная и её адрес в памяти
    int a = 10;
    int* pa = &a;
    printf("\nvalue of a = %d\n", a);
    printf("address of a = %p\n", (void*)pa);
    printf("value via pointer *pa = %d\n", *pa);

    // 3. Изменение значения через указатель
    *pa = 20;
    printf("after *pa = 20 -> a = %d\n", a);

    // 4. Арифметика указателей на массиве
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr;
    printf("\narray elements via pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (address %p)\n", i, *(p + i), (void*)(p + i));
    }

    // 5. Динамическое выделение памяти
    int n;
    printf("\nhow many numbers to allocate dynamically? ");
    scanf("%d", &n);

    int* dynArr = (int*)malloc(n * sizeof(int));
    if (dynArr == NULL) {
        printf("memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        dynArr[i] = i * i;
    }

    printf("dynamic array contents:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");

    free(dynArr);
    dynArr = NULL;

    return 0;
}