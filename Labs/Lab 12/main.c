#include "secrets.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    struct Book* book = createBook(10);
    struct Entry* entry;

    while(1) {
        printf("New Secret: ");
        scanf("%s", entry->message);

        if(strcmp(entry->message, "quit") == 0) { break; }

        printf("Clearance level: ");
        scanf("%d", &entry->clearanceLevel);

        addSecret(book, entry->message, entry->clearanceLevel);

        printf("Index to Decrypt: ");
        scanf("%d", &entry->clearanceLevel);

        decryptSecret(book, entry->clearanceLevel);
    }

    burnBook(book);

    return 0;
}