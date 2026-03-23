#include <stdio.h>
#include "max.h"

int main() {

    int N, numbers[100];

    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        scanf("%d", &numbers[i]);
    }

    int firstMax, secondMax;

    findFirstAndSecondMax(numbers, N, &firstMax, &secondMax);

    printf("The max values (1 and 2) are: %d, %d\n", firstMax, secondMax);

    return 0;
}