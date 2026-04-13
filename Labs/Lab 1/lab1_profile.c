#include <stdio.h>

int main() {
    int releaseYear = 2025;
    float movieRating = 4.5;
    char category = 'R';
    double earnings = 1246435679.689235;

	printf("Movie Release \"Year\": %d\nRating: %f\nCategory: %c\nPrecise Earnings: %lf"
        , releaseYear
        , movieRating
        , category
        , earnings
    );

	return 0;
}