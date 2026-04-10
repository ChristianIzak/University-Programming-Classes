#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int lines;
    int words_per_line;

    scanf("%d", &lines);
    scanf("%d", &words_per_line);

    int* memoryBlock = calloc(lines, words_per_line * sizeof(int));

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < words_per_line; j++) {
            memoryBlock[(i * words_per_line + j)] = i+j;
            printf("%d ", memoryBlock[(i * words_per_line + j)]);
        }
        printf("\n");
        memoryBlock++;
    }

    free(memoryBlock);
    memoryBlock = NULL;

    return 0;
}