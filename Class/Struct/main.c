#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(void) {
    int N;
    printf("Enter number of students: ");
    scanf("%d", &N);

    struct Student* s = calloc(N, sizeof(*s));

    for(int i = 0; i < N; i++) {
        printf("Name, PID, Age:\n");
        scanf("%s %d %d", s[i].name, &s[i].pid, &s[i].age);
    }

    printAllStudents(s, N);

    char* target = calloc(50, sizeof(char));
    printf("\nEnter student name to search: ");
    scanf("%s", target);

    printf("Found student with name: %d\n", findStudentByName(s, N, target));

    int pidTarget;
    printf("\nEnter student PID to search: ");
    scanf("%d", &pidTarget);

    printf("Found student with pid: %d\n", findStudentByPID(s, N, pidTarget));

    free(s);
    s = NULL;

    return 0;
}