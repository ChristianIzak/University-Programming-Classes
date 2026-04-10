#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int* artifacts = calloc(N, sizeof(int));

    for(int i = 0; i < N; i++) {
        printf("%d ", i+1);
    }

    free(artifacts);
    artifacts = NULL;

    return 0;
}