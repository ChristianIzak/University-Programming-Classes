#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N;
    int L;
    char* strings;

    scanf("%d", &N);
    scanf("%d", &L);

    char* target = malloc(L * sizeof(char));

    strings = malloc((N * L) * sizeof(char));

    for(int i = 0; i < N; i++) {
        int offset = i*L;
        printf("Code %d: ", i+1);
        scanf("%s", &strings[offset]);
    }

    printf("Target Code: ");
    scanf("%s", target);

    for (int i = 0; i < N; i++) {
        int found = 1;
        for(int j = 0; j < L; j++) {
            printf("%c | %c\n", target[j], strings[(i*L)+j]);
            if (target[j] != strings[(i*L)+j]) {
                found = 0;
                printf("Incorrect.\n");
                break;
            }
        }

        if(found == 1) {
            printf("Found %s at index %d!\n", target, i);
            break;
        }
    }

    free(strings);

    strings = NULL;

    return 0;
}