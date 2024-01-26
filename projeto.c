#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int yearPublication;
};

struct Library {
    struct Book books [MAX_BOOKS];
    int numBooks;
};

void addBook(struct Library *library) {
    if (library->numBooks < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter book title:");
        scanf("%s", newBook.title);
        printf("Enter author:");
        scanf("%s",newBook.author);
        printf("Enter year of publication:");
        scanf("%d", &newBook.yearPublication);

        library->books[library->numBooks] = newBook;
        library->numBooks++;

        printf("Book added successfully!\n");
    }
    else {
        printf("The library is full. Cannot add more books.\n");
    }
}





