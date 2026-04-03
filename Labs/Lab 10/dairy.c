#include <stdio.h>
#include <stdlib.h>

struct IceCream {
    char flavor[30];
    int gallonsLeft;
    float price;
};

void sellScoop(struct IceCream *ic);

int main(void) {
    struct IceCream strawberry = {"Strawberry", 1, 2.99};

    sellScoop(&strawberry);

    sellScoop(&strawberry);

    return 0;
}

void sellScoop(struct IceCream *ic) {
    if(ic->gallonsLeft > 0) {
        printf("Scoop Served!\n");
        ic->gallonsLeft--;
    } else {
        printf("Sold out of %s!\n", ic->flavor);
    }
}