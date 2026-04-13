#ifndef TYPES_H
#define TYPES_H

#include "utils.h"

struct Movie {
    char name[50];
    int rating;
    char director[50];
    int releaseDate;
};

struct MovieDatabase {
    struct Movie* movies;
    int size;
};

#endif