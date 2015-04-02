//
// Created by Lander Brandt on 4/1/15.
//

#include <stdio.h>
#include "utility.h"

void flushStdin() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int menu() {
    int response = -1;
    int read = 0;

    while (response < 1 || response > 6 || read != 1) {
        printf("\n1) Print the List\n");
        printf("2) Add First\n");
        printf("3) Add Last\n");
        printf("4) Sort the List (ascending order)\n");
        printf("5) Delete a word\n");
        printf("6) Quit --\n");

        read = scanf("%d", &response);
        flushStdin();
        printf("\n");
    }


    return response;
}

/**
 * Prompts the user for a file to open, and continues prompting until a valid file is given
 */
FILE * openFile() {
    FILE *returnFile = NULL;

    char fileName[MAX];
    int result = 0;
    while (returnFile == NULL) {
        printf("Enter the path of the file you'd like to open: ");
        // vulnerable to buffer overflow, but screw it
        result = scanf("%s", fileName);
        if (result != 1) {
            continue;
        }

        returnFile = fopen(fileName, "r");
    }

    return returnFile;
}

void strip(char *array) {
    if (array == NULL) {
        return;
    }

    int i;
    for (i = 0; array[i] != '\0'; i++) {
        if (array[i] == '\r' || array[i] == '\n') {
            array[i] = '\0';
            return;
        }
    }
}

/**
 * Counts the number of lines in a file and divides by "lines"
 */
int countRecords(FILE * fin, int lines) {
    rewind(fin);

    int count = 0;

    while (!feof(fin)) {
        if (fgetc(fin) == '\n') {
            count++;
        }
    }

    if (count < lines || lines == 0) {
        perror("File had 0 records");
    }

    count /= lines;


    return count;
}

Node * buildNode(FILE * in, void *(*buildData)(FILE * in) ) {
    Node *temp = calloc(1, sizeof(Node));

    temp->data = buildData(in);

    return temp;
}

void buildList(LinkedList * myList, FILE * fin, int total, void * (*buildData)(FILE * in)) {
    rewind(fin);

    int i;
    for (i = 0; i < total && !feof(fin); i++) {
        addLast(myList, buildNode(fin, buildData));
    }
}
