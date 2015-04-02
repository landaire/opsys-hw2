#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "words.h"

#define MAX 100

void flushStdin();

int menu();
FILE * openFile();
void strip(char *array);
int countRecords(FILE * fin, int lines);
Node * buildNode(FILE * in, void *(*buildData)(FILE * in) );
void buildList(LinkedList * myList, FILE * fin, int total, void * (*buildData)(FILE * in));

#endif // UTILITY_H
