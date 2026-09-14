#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char category[100];
    int year;
    double price;
} Book;

typedef enum {
    SORT_BY_TITLE = 1,
    SORT_BY_AUTHOR,
    SORT_BY_CATEGORY,
    SORT_BY_YEAR,
    SORT_BY_PRICE
} SortField;

SortField currentSortField;

void printBook(const Book* b) {
    printf("Title: %s | Author: %s | Category: %s | Year: %d | Price: %.2f\n",
        b->title, b->author, b->category, b->year, b->price);
}

void printLibrary(const Book* arr, int size) {
    if (size == 0) {
        printf("Library is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d) ", i + 1);
        printBook(&arr[i]);
    }
}

int addBook(Book** arr, int size) {
    Book newBook;

    printf("Enter title: ");
    scanf(" %99[^\n]", newBook.title);

    printf("Enter author: ");
    scanf(" %99[^\n]", newBook.author);

    printf("Enter category: ");
    scanf(" %99[^\n]", newBook.category);

    printf("Enter year: ");
    scanf("%d", &newBook.year);

    printf("Enter price: ");
    scanf("%lf", &newBook.price);

    Book* tmp = realloc(*arr, (size + 1) * sizeof(Book));
    if (!tmp) {
        printf("Memory error!\n");
        return size;
    }

    *arr = tmp;
    (*arr)[size] = newBook;
    size++;

    printf("Book added!\n");
    return size;
}

void deleteBook(Book** arr, int* size) {
    if (*size == 0) {
        printf("Library is empty.\n");
        return;
    }

    int index;
    printf("Enter book number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *size) {
        printf("Invalid number.\n");
        return;
    }

    index--;
    for (int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    (*size)--;
    *arr = realloc(*arr, (*size) * sizeof(Book));

    printf("Book deleted.\n");
}

void saveToFile(Book* arr, int size) {
    FILE* f = fopen("books.txt", "w");
    if (!f) {
        printf("Failed to open file!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(f, "%s\n%s\n%s\n%d\n%lf\n",
            arr[i].title, arr[i].author, arr[i].category, arr[i].year, arr[i].price);
    }

    fclose(f);
    printf("Saved to books.txt\n");
}

void loadFromFile(Book** arr, int* size) {
    FILE* f = fopen("books.txt", "r");
    if (!f) {
        printf("File not found.\n");
        return;
    }

    if (*arr != NULL) {
        free(*arr);
        printf("Previous data cleared!\n");
    }
    *arr = NULL;
    *size = 0;
    Book temp;

    while (fscanf(f, " %99[^\n]", temp.title) == 1 &&
        fscanf(f, " %99[^\n]", temp.author) == 1 &&
        fscanf(f, " %99[^\n]", temp.category) == 1 &&
        fscanf(f, "%d", &temp.year) == 1 &&
        fscanf(f, "%lf", &temp.price) == 1)
    {
        Book* tmp = realloc(*arr, (*size + 1) * sizeof(Book));
        if (!tmp) {
            printf("Memory error!\n");
            fclose(f);
            return;
        }

        *arr = tmp;
        (*arr)[*size] = temp;
        (*size)++;
    }

    fclose(f);
    printf("File loaded.\n");
}
int compareBooks(const void* a, const void* b) {
    const Book* A = (const Book*)a;
    const Book* B = (const Book*)b;

    switch (currentSortField) {
    case SORT_BY_TITLE:
        return strcmp(A->title, B->title);
    case SORT_BY_AUTHOR:
        return strcmp(A->author, B->author);
    case SORT_BY_CATEGORY:
        return strcmp(A->category, B->category);
    case SORT_BY_YEAR:
        return A->year - B->year;
    case SORT_BY_PRICE:
        return (A->price > B->price) - (A->price < B->price);
    }
    return 0;
}

void sortBooks(Book* arr, int size) {
    printf("Choose sort field:\n");
    printf("1 - by title\n2 - by author\n3 - by category\n4 - by year\n5 - by price\n");

    int choice;
    scanf("%d", &choice);
    currentSortField = choice;

    Book temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compareBooks(&arr[i], &arr[j]) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorting done.\n");
}int main(void)
{
    Book* library = NULL;
    int size = 0;

    while (1) {
        printf("\n=== Menu ===\n");
        printf("1 - show library\n");
        printf("2 - add book\n");
        printf("3 - delete book\n");
        printf("4 - save to file\n");
        printf("5 - load from file\n");
        printf("6 - sort\n");
        printf("0 - exit\n");
        printf("Your choice: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
        case 1: printLibrary(library, size); break;
        case 2: size = addBook(&library, size); break;
        case 3: deleteBook(&library, &size); break;
        case 4: saveToFile(library, size); break;
        case 5: loadFromFile(&library, &size); break;
        case 6: sortBooks(library, size); break;
        case 0:
            free(library);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    free(library);
    return 0;
}