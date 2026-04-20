#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secrets.h"

struct Book* createBook(int capacity) {
    struct Book* book = malloc(capacity * sizeof(struct Book));

    book->count = 0;
    book->capacity = capacity;
    book->entries = calloc(capacity, sizeof(struct Entry));

    return book;
}

void addSecret(struct Book* b, char* test, int level) {
    if(b->count < b->capacity) {
        int i = b->count;
        b->entries[i].clearanceLevel = level;
        b->entries[i].message = malloc((strlen(test) + 1) * sizeof(char));
        strcpy(b->entries[i].message, test);
        b->count++;
    } else {
        printf("Book is full!\n");
    }
}

void decryptSecret(struct Book* b, int index) {
    char* str = b->entries[index].message;

    while (*str != '\0') {
        *str = *str - 1;
        str++;
    }

    printf("%s\n", b->entries[index].message);
}

void burnBook(struct Book* b) {
    printf("The Book of Secrets has been destroyed.\n");
    
    for(int i = 0; i < b->count; i++) {
        free(b->entries[i].message);
        b->entries[i].message = NULL;
    }

    free(b);
    free(b->entries);
    b = NULL;
}