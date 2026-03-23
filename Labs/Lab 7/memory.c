#include <stdio.h>

int main(void) {
    int var = 1;
    char chara = 'a';

    int *point = &var;
    char *pchar = &chara;

    printf("%p\n", point);
    printf("%p\n\n", pchar);

    point++;
    pchar++;

    printf("%p\n", point);
    printf("%p\n", pchar);

    return 0;
}