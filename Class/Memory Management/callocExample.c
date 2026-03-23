#include <stdio.h>

int main(void) {
    int *students;
    int numStudents = 12;

    students = calloc(numStudents, sizeof(int));

    printf("%d\n", numStudents * sizeof(int));
    // Prints 48 (12 Elements * 4 bytes each)

    return 0;
}