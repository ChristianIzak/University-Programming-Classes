#include <stdio.h>

/* * Copies the string from 'source' to 'dest'.
 */
void string_copy(char* source, char* dest) {
    while(*dest != '\0') dest++;

    while(*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    *dest = '\0';
}

int main() {
    char src[100];
    char dest[100]; 
    
    // Read a full line of text into 'src'
    // Note: The %[^\n] specifier reads string until newline
    scanf("%[^\n]", src);
    
    string_copy(src, dest);
    
    printf("%s", dest);
    return 0;
}