#ifndef WORDS_H
#define WORDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
        char * word;
        int id;
};

typedef struct student Student;

void printStudent(void * passedIn);
void * buildStudent(FILE *);
int compareTwoStudents(const void * p1, const void * p2);
void cleanStudent(void *);


#endif // WORDS_H
