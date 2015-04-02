//
// Created by Lander Brandt on 3/30/15.
//

#include "words.h"
#include "utility.h"

void printWord(void * passedIn) {
    printf("%s\n", ((Words*)passedIn)->word);
}

void * buildWord(FILE *fin) {
    char line[MAX];

    fgets(line, MAX, fin);
    // should check for EOF here but screw it

    strip(line);
    char *temp = calloc(strlen(line) + 1, sizeof(char));
    strcpy(temp, line);


    Words *word = calloc(1, sizeof(Words));
    word->word = temp;
    word->length = (int)strlen(temp);

    return word;
}

void cleanWord(void *word) {
    free(((Words*)word)->word);
    free(word);
}

int compareTwoWords(const void *a, const void *b) {
    // this is for debugging purposes. could easily be simplified to one statement
    Words **w1 = (Words**)a;
    Words **w2 = (Words**)b;
    int result = strcmp((*w1)->word, (*w2)->word);
    return result;
}
