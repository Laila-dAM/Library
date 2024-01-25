#include <stdio.h>
#include <locale.h>
#define MAX_BOOKS 100

struct Book {
    char t[50];
    char a[50];
    int d;
};

struct library {
    struct Book book[MAX_BOOKS];
    int nl;

    };

    

