#include <stdio.h>

void batCopy(char *source, char *destination);

int main(void) {
    char chars[100] = "Joker";

    char final[100];

    printf("\nInitial: %s\n", chars);

    batCopy(chars, final);

    printf("Final: %s\n\n", final);

    return 0;
}

void batCopy(char *source, char *destination) {
    char* point = source;
    char* destPoint = destination;

    for(int i = 0; *point != '\0'; i++) {

        *destPoint = *point;
        
        point++;
        destPoint++;
    }
}