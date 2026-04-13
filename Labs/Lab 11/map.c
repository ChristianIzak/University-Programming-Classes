#include <stdio.h>
#include <stdlib.h>
#include "map.h"

struct Map* activateMap() {
    struct Map* map = malloc(sizeof(struct Map));

    if (map == NULL) {
        return NULL;
    }

    map->x = 0;
    map->y = 0;
    map->mana = 100;
    map->count = 0;
    map->footprints = calloc(MAX_FOOTPRINTS, sizeof(int));

    return map;
}

void walk(struct Map* m, char direction) {
    switch (direction) {
        case 'w':
            m->y++;
            break;
        case 's':
            m->y--;
            break;
        case 'd':
            m->x++;
            break;
        case 'a':
            m->x--;
            break;
        case 'r':
            revealPerson(m);
            break;
    }

    m->mana = m->mana*.9;

    if(m->mana <= 0) { printf("The ink fades... You are blind.\n"); }
}

void revealPerson(struct Map* m) {
    if(m->count < MAX_FOOTPRINTS) {
        int id = rand() % 999;

        m->footprints[m->count] = id;
        m->count+=1;

        printf("Person revealed at (%d, %d)!\n", m->x, m->y);
    } else {
        printf("Map is too crowded! Cannot track more.\n");
    }
}

void showMap(struct Map* m) {
    printf("Player Coords: (%d, %d)\nMana: %d\nRevealed IDs: ", m->x, m->y, m->mana);
    for(int i = 0; i < m->count; i++) {
        printf("%d ", m->footprints[i]);
    }
    printf("\n");
}

void mischiefManaged(struct Map* m) {
    printf("Mischief Managed. Closing map...\n");

    free(m->footprints);
    free(m);
    m = NULL;
}