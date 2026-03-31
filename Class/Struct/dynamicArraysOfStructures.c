#include <stdio.h>
#include <stdlib.h>

struct Movie {
    char title[50];
    int year;
    double rating;
};

int main(void) {
    int capacity = 2;
    int count = 2;

    struct Movie *database = malloc(capacity * sizeof(struct Movie));

    if(database == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(database[0].title, "Inception");
    database[0].year = 2010;
    database[0].rating = 8.8;

    strcpy(database[1].title, "The Matrix");
    database[1].year = 1999;
    database[1].rating = 8.7;

    // We want to add a 3rd movie but we only have a capacity of 2

    capacity = 4;
    database = realloc(database, capacity * sizeof(struct Movie));

    if(database == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Add new movie
    strcpy(database[2].title, "Interstellar");
    database[2].year = 2014;
    database[2].rating = 8.6; // We now have 3

    return 0;
}