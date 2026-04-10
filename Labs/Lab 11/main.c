#include <stdio.h>
#include "map.h"

int main (void) {
    struct Map *mainMap = activateMap();

    while(1) {
        char direction;
        showMap(mainMap);
        printf("Direction to move: ");
        scanf("%c", &direction);
        walk(mainMap, direction);
        if(mainMap->mana <= 0) { break; }
    }

    mischiefManaged(mainMap);
    
    return 0;
}