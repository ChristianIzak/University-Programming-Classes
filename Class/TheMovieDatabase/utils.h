#ifndef UTILS_H
#define UTILS_H

#include "types.h"

void printMovies(struct MovieDatabase* mdb);

void printMovie(struct Movie* m);

struct Movie* findMovieWithHighestRating(struct MovieDatabase* mdb);

#endif