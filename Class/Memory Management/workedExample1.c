#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

int main(void) {

    int numStudents;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // Allocate a 2D block: numStudents rows, MAX_NAME cols
    char (*names)[MAX_NAME] = calloc(numStudents, sizeof(*names));
    if(names == NULL) {
        printf("Memory allocation faled.\n");
        return 1;
    }

    // Fill the array
    for(int i = 0; i < numStudents; i++) {
        printf("Ender name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // Search
    char target[MAX_NAME];
    printf("Search for: ");
    scanf("%s", target);

    int found = 1;
    for(int i = 0; i < numStudents; i++) {
        found = 1;

        if(!strcmp(names[i], target)) { found = 0; break; }

        if(found == 1) {
            printf("Found \"%s\" at index %d.\n", target, i);
            break;
        }
    }

    if(!found) {
        printf("\"%s\" not found.\n", target);
    }

    return 0;
}