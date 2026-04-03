#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Student {
  char name[50];
  int pid;
  int age;
};

// Prints the student
void printStudent(struct Student s);

// Find student based on PID
int findStudentByPID(struct Student *s, int N, int pid);

// Print all students
void printAllStudents(struct Student* s, int N);

// Find student based on name
int findStudentByName(struct Student* s, int N, char* name);

#endif