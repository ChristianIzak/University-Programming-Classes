#ifndef MAP_H
#define MAP_H

#define MAX_FOOTPRINTS 5

struct Map {
    int x;
    int y;
    int mana;
    int* footprints;
    int count;
};

struct Map* activateMap();

void walk(struct Map* m, char direction);

void revealPerson(struct Map* m);

void showMap(struct Map* m);

void mischiefManaged(struct Map* m);

#endif