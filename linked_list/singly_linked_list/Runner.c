#include <stdio.h>
#include <conio.h>
#include "Singly.h"

int main()
{

    insertSingly(4);
    insertSingly(5);
    displaySingly();

    deleteFirstSingly();
    displaySingly();

    deleteFirstSingly();
    displaySingly();

    insertSingly(4);
    insertSingly(5);
    displaySingly();

    deleteLastSingly();
    displaySingly();

    deleteLastSingly();
    displaySingly();
    displaySingly();

    insertSingly(4);
    insertSingly(5);
    displaySingly();
    return 0;
}