#ifndef SECRETS_H
#define SECRETS_H

#include <stdlib.h>
#include <stdio.h>

struct Entry {
    char* message;
    int clearanceLevel;
};

struct Book {
    struct Entry* entries;
    int count;
    int capacity;
};

struct Book* createBook(int capacity);

void addSecret(struct Book* b, char* test, int level);

void decryptSecret(struct Book* b, int index);

void burnBook(struct Book* b);

#endif