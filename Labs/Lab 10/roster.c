#include <stdio.h>
#include <stdlib.h>

struct Player {
    int number;
    char name[50];
    float speed;
};

int main(void) {
    struct Player players[4] = {
        {1, "Reed", 20.5}, 
        {11, "Nailor", 21.3}, 
        {9, "Walker", 19.8}, 
        {18, "White", 18.5}
    };

    float speedData[2] = {0, 0};
    for(int i = 0; i < 4; i++) {
        if(players[i].speed > speedData[0]) {
            speedData[0] = players[i].speed;
            speedData[1] = i;
        }
    }

    printf("Fastest Player: %s\nSpeed: %f\n", players[(int)speedData[1]].name, speedData[0]);

    return 0;
}