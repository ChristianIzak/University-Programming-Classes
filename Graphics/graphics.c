#include <stdio.h>
#include <math.h>
#include <time.h>

struct Obj {
    int mass;
    float staticFriction;
    double posX;
    double posY;
};

int main() {
    struct timespec ts;
    ts.tv_sec = 0;          // Seconds part
    ts.tv_nsec = 100000000; // 500 milliseconds in nanoseconds (500 * 1,000,000)

    struct Obj box;
    int angle;
    box.mass = 400;
    box.staticFriction = 0.5;
    box.posY = 100;
    float velocity = 16.0;

    for(float time = 0; time < 10; time+=0.1) {
        box.posY = velocity + ((-9.8)*time);
        box.posX = velocity + ((-0.1)*time);

        if(box.posY <= 0) {printf("Hit ground."); break;}

        printf("X: %lf Y: %lf\n", box.posX, box.posY);

        nanosleep(&ts, NULL);
    }

    return 0;
}
