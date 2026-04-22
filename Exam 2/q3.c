#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[50];
    double rating;
};

/*
 * Returns a pointer to the Movie with the highest rating.
 */
struct Movie* find_best_movie(struct Movie* library, int size) {
    double maxRating = 0;
    int index = 0;

    if(library == NULL || size <= 0) return NULL;

    for(int i = 0; i < size; i++) {
        if(library[i].rating > maxRating) {
            maxRating = library[i].rating;
            index = i;
        }
    }
    
    return &library[index];
}

int main() {
    int n;
    
    // Read number of movies
    scanf("%d", &n);
    
    // Consume the newline character left in the buffer by scanf
    getchar(); 

    // Allocate array for movies based on input size
    struct Movie* movies = malloc(n * sizeof(struct Movie));
    
    for (int i = 0; i < n; i++) {
        // Read the title
        scanf("%s %lf", movies[i].title, &movies[i].rating);
    }
    
    struct Movie* best = find_best_movie(movies, n);
    
    if (best != NULL) {
        printf("Best: %s (%.1f)", best->title, best->rating);
    } else {
        printf("NULL");
    }
    
    free(movies);
    return 0;
}