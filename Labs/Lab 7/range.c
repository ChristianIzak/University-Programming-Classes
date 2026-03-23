#include <stdio.h>
#include <string.h>

int main(void) {
    char string[100];
    char* plet = string;

    int length = 0;

    strcpy(string, "Arkham Asylum");

    for(int i = 0; i < 100; i++) {
        if(*plet == ' ' || *plet == '\0') { break; }
        plet++;
        length++;
    }

    printf("%d\n", length);

    return 0;
}