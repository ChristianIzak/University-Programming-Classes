#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int Sc, Sd;
    int* masterClueList;

    scanf("%d", &Sc);
    scanf("%d", &Sd);

    int* charlotte = malloc(Sc * sizeof(int));
    int* dogood = malloc(Sd * sizeof(int));

    for(int i = 0; i < Sc; i++) {
        charlotte[i] = 10*(i+1);
    }

    for(int i = 0; i < Sd; i++) {
        dogood[i] = 5*(i+1);
    }

    masterClueList = malloc((Sc+Sd) * sizeof(int));

    for (int i = 0; i < (Sc+Sd); i++) {
        if(i < Sc) {
            masterClueList[i] = charlotte[i];
        } else {
            masterClueList[i] = dogood[i - Sc];
        }

        printf("%d ", masterClueList[i]);
    }

    free(charlotte);
    free(dogood);
    free(masterClueList);

    charlotte = NULL;
    dogood = NULL;
    masterClueList = NULL;

    return 0;
}