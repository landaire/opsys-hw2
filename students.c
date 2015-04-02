//
// Created by Lander Brandt on 4/1/15.
//

#include "students.h"
#include "utility.h"

void printStudent(void * passedIn) {
    Student *st = (Student*)passedIn;
    printf("%d: %s\n", st->id, st->word);
}

void * buildStudent(FILE *fin) {
    Student *st = calloc(1, sizeof(Student));
    char line[MAX];

    if (fin == stdin) {
        printf("Name (leave blank if deleting): ");
    }

    fgets(line, MAX, fin);
    // should check for EOF here but screw it


    strip(line);
    char *name = calloc(strlen(line) + 1, sizeof(char));

    if (fin == stdin) {
        printf("ID: ");
    }

    fscanf(fin, "%d", &(st->id));
    strcpy(name, line);

    // Read the linefeed
    fgets(line, MAX, fin);

    st->word = name;

    return st;
}

void cleanStudent(void *student) {
    free(((Student*)student)->word);
    free(student);
}

int compareTwoStudents(const void *a, const void *b) {
    // this is for debugging purposes. could easily be simplified to one statement
    Student **w1 = (Student**)a;
    Student **w2 = (Student**)b;
    int result = (*w1)->id - (*w2)->id;
    return result;
}
