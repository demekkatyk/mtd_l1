#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Rotates a square matrix 90 degrees in place.
 *
 * Supports two rotation directions:
 *   - 'R' for clockwise rotation
 *   - 'L' for counter-clockwise rotation
 *
 * The matrix is assumed to be square (size x size) and allocated
 * dynamically as an array of row pointers.
 *
 * The rotation is performed in place: the original matrix is modified.
 *
 * @param matrix    Pointer to the dynamically allocated 2D array.
 * @param size      Number of rows and columns (matrix is size x size).
 * @param direction 'R' for clockwise, 'L' for counter-clockwise.
 * @return          0 on success, 1 if direction is neither 'R' nor 'L'.
 */
 
int rotateMatrix(int** matrix, unsigned int size, char direction)
{
    if (direction != 'R' && direction != 'L') return 1;

    /* Allocate a temporary matrix to hold rotated values. */
    int** tmp = malloc(size * sizeof(int*));
    for (unsigned int i = 0; i < size; i++)
        tmp[i] = malloc(size * sizeof(int));

    /* Fill temporary matrix with rotated values. */
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (direction == 'R')
                tmp[i][j] = matrix[size - 1 - j][i];
            else
                tmp[i][j] = matrix[j][size - 1 - i];
        }
    }
     /* Copy rotated values back into the original matrix. */
    for (unsigned int i = 0; i < size; i++)
        for (unsigned int j = 0; j < size; j++)
            matrix[i][j] = tmp[i][j];

    /* Free the temporary matrix. */
    for (unsigned int i = 0; i < size; i++) free(tmp[i]);
    free(tmp);

    return 0;
}

int main()
{
    unsigned int a;

    printf("input non-negative number:\n");
    scanf("%u", &a);

    printf("the value of `a` is %u\n", a);

    unsigned int* pa = &a;
    printf("the pointer value is %p\n", pa);

    int b_renamed;
    printf("input a number:\n");
    scanf("%d", &b_renamed);
    printf("the value of `b_renamed` is %d\n", b_renamed);

        /* --- Task 4.4 test: rotateMatrix --- */
    unsigned int n = 3;
    int** m = malloc(n * sizeof(int*));
    for (unsigned int i = 0; i < n; i++)
        m[i] = malloc(n * sizeof(int));

    int vals[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++)
            m[i][j] = vals[i][j];

    printf("Before rotation:\n");
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) printf("%d ", m[i][j]);
        printf("\n");
    }

    rotateMatrix(m, n, 'R');

    printf("After clockwise rotation:\n");
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) printf("%d ", m[i][j]);
        printf("\n");
    }

    /* Test invalid direction */
    if (rotateMatrix(m, n, 'X') == 1)
        printf("Invalid direction correctly rejected.\n");

    for (unsigned int i = 0; i < n; i++) free(m[i]);
    free(m);
    /* --- end Task 4.4 test --- */
    return 0;
}