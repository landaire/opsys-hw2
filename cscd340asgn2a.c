#include "linkedList.h"
#include "utility.h"
#include "students.h"

int main()
{

    int total, choice;
	FILE * fin = NULL;
	LinkedList * myList = linkedList();

	fin = openFile();
	total = countRecords(fin, 2);
    buildList(myList, fin, total, buildStudent);
    fclose(fin);

    do
    {
        choice = menu();

        switch(choice)
        {
            case 1: printList(myList, printStudent);
                    break;

            case 2: addFirst(myList, buildNode(stdin, buildStudent));
                    break;

            case 3: addLast(myList, buildNode(stdin, buildStudent));
                    break;

            case 4: sort(myList, compareTwoStudents);
                    break;

            case 5: removeItem(myList, buildNode(stdin, buildStudent), cleanStudent, compareTwoStudents);
                    break;
        }// end switch

    }while(choice != 6);

    clearList(myList, cleanStudent);
    free(myList);
    myList = NULL;

	return 0;

}// end main

