#include <stdio.h>
#include <string.h>
#include "structures.h"

// Prints the student
void printStudent(struct Student s) {
    printf("Name: %s, PID: %d, Age: %d\n", s.name, s.pid, s.age);
}

// Find student based on PID
int findStudentByPID(struct Student *s, int N, int pid) {
    for(int i = 0; i < N; i++) {
        if(s[i].pid == pid) {
            return 1;
        }
    }
    return 0;
}

// Print all students
void printAllStudents(struct Student* s, int N) {
    for(int i = 0; i < N; i++) {
        printStudent(s[i]);
    }
}

// Find student based on name
int findStudentByName(struct Student* s, int N, char* name) {
    for(int i = 0; i < N; i++) {
        if(strcmp(s[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}