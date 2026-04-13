#include "utils.h"
#include "types.h"
#include <stdio.h>

// struct Movie {
//     char name[50];
//     int rating;
//     char director[50];
//     int releaseDate;
// };

// struct MovieDatabase {
//     struct Movie* movies;
//     int size;
// };

void printMovies(struct MovieDatabase* mdb) {
    for(int i = 0; i < mdb->size; i++) {
        printMovie(&mdb->movies[i]);
    }
}

void printMovie(struct Movie* m) {
    printf("%s\n", m->name);
    printf("%d\n", m->rating);
    printf("%s\n", m->director);
    printf("%d\n", m->releaseDate);
}

struct Movie* findMovieWithHighestRating(struct MovieDatabase* mdb) {
    struct Movie maxRatingMovie = mdb->movies[0];
    int maxMovieIndex = 0;
    
    for(int i = 0; i < mdb->size; i++) {
        if (mdb->movies[i].rating > maxRatingMovie.rating) {
            maxMovieIndex = i;
        }
    }

    return &mdb->movies[maxMovieIndex];
}