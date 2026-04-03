#include <stdio.h>
#include <stdlib.h>

struct Musician {
    char instrument[20];
    int yearsEx;
};

int main(void) {
    int N;

    printf("How many musicians in the section? :");
    scanf("%d", &N);

    struct Musician* section = calloc(N, sizeof(*section));

    for(int i = 0; i < N; i++) {
        printf("Band member %d\nInstrument: ", i+1);
        scanf("%s", section[i].instrument);
        printf("Years of Experience: ");
        scanf("%d", &section[i].yearsEx);
    }

    float avEx = 0;

    for(int i = 0; i < N; i++) {
        avEx = avEx + section[i].yearsEx;
    }

    avEx = avEx/N;

    printf("Average Years of Experience: %f\n", avEx);

    return 0;
}