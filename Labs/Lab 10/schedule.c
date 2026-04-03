#include <stdio.h>
#include <stdlib.h>

struct Date {
    int month;
    int day;
    int year;
};

struct Game {
    char opponent[50];
    struct Date gameday;
    int ticketSold;
};

int main(void) {
    struct Game game1 = {"Michigan", {2, 12, 2026}, 15000};

    printf("Year of game: %d\n", game1.gameday.year);

    return 0;
}