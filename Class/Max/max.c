#include "max.h"

void findFirstAndSecondMax(int* array, int N, int* firstMax, int* secondMax) {

    *firstMax = *array;
    *secondMax = *(array + 1);

    if(*firstMax < *secondMax) {
        int temp = *firstMax;

        *firstMax = *secondMax;
        *secondMax = temp;
    }

    for(int i = 2; i < N; i++) {
        int thirdElement = *(array+i);

        if(thirdElement >= *firstMax && thirdElement > *secondMax) {
            *secondMax = *firstMax;
            *firstMax = thirdElement;
        } else if(thirdElement < *firstMax && thirdElement > *secondMax) {
            *secondMax = thirdElement;
        }
    }

}