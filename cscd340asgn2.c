#include "linkedList.h"
#include "utility.h"
#include "words.h"

int main()
{

    int total, choice;
	FILE * fin = NULL;
	LinkedList * myList = linkedList();

	fin = openFile();
	total = countRecords(fin, 1);
    buildList(myList, fin, total, buildWord);
    fclose(fin);

    do
    {
        choice = menu();

        switch(choice)
        {
            case 1: printList(myList, printWord);
                    break;

            case 2: addFirst(myList, buildNode(stdin, buildWord));
                    break;

            case 3: addLast(myList, buildNode(stdin, buildWord));
                    break;

            case 4: sort(myList, compareTwoWords);
                    break;

            case 5: removeItem(myList, buildNode(stdin, buildWord), cleanWord, compareTwoWords);
                    break;
        }// end switch

    }while(choice != 6);

    clearList(myList, cleanWord);
    free(myList);
    myList = NULL;

	return 0;

}// end main

