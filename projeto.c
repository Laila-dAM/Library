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
        library->numBooks--;
        printf("=== Book removed successfully! ===\n");
    }
    else {
        printf("=== Book not found in library ===\n");
    }
}

int main(){
    setlocale (LC_ALL, "en_US");

    struct Library library;
    library.numBooks = 0;

    int choice;
    do {
        printf("\n === Menu ===\n");
        printf("1. Add a book\n");
        printf("2. List all books\n");
        printf("3. Remove a book\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
      case 1:
      addBook(&library);
      break;

      case 2:
      listBooks(&library);
      break;

      case 3:
      removeBook(&library);
      break;

      case 4:
      printf("Exiting program.\n");
      break;

      default:
      printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
    while (choice !=4);
    return 0;
}





