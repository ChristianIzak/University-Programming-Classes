#include <stdio.h>
#include <stdlib.h>

struct Car {
    int make;
    int model;
    char color;
    int year;
    double cost;
}; // Semi-Colon at the end

struct CarArray {
    char brand[30];
    char model[30];
    int year;
};

void updateYear(struct Car *c) {
    c->year = 2025; // Modifying the original struct using ->
}

void printCars(struct Car cars[30]) {
    for(int i = 0; i < 5; i++) {
        printf("Car %d: Model %d, Make %d, Year %d\n", i + 1, cars[i].model, cars[i].make, cars[i].year);
    }
}

int main(void) {
    struct Car car1, car2;
    struct CarArray carArr = {"BMW", "X5", 1999};
    struct Car cars[50]; // Array of 50 Car structs

    car1.make   = 1242;
    car1.model  = 134;
    car1.color  = 's';
    car1.year   = 2011;
    car1.cost   = 9000.00;

    car2 = car1;
    // This copies everything in car1 to car2. (all values in struct)

    struct CarArray *ptr = &carArr;

    printf("Brand: %s\n", ptr->brand);
    printf("Year: %d\n", ptr->year);

    updateYear(&car1);

    for(int i = 0; i < 5; i++) {
        scanf("%d", &cars[i].model);
        scanf("%d", &cars[i].make);
        scanf("%d", &cars[i].year);
    }

    printCars(cars);

    return 0;
}