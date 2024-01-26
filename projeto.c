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

void listBooks(const struct Library *library) {
    printf("List of Books in Library:\n");
    for (int i=0; i<library->numBooks; i++){
        printf("%d. %s, by %s (%d)\n", i+1, library->books[i].title, library->books[i].author, library->books[i].yearPublication);
    }
}

int fetchBook(const struct Library *library, const char *title) {
    for (int i=0; i<library->numBooks; i++){
        if (strcmp(library->books[i].title, title) == 0){
            return i;
        }
    }

    return -1;
}

void removeBook(struct Library *library) {
    char title[50];
    printf("Enter the title of the book to remove:");
    scanf("%s", title);

    int index = fetchBook(library, title);
    if (index !=-1){
        for (int i = index; i < library->numBooks - 1; i++){
            library->books[i] = library->books[i+1];
        }
    }
}





