#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "fonctions.h"


int main()
{
    char **tableau = malloc(4 * sizeof(*tableau));
    tableau[3] = NULL;
    tableau[0] = malloc(4 * sizeof(char));
    tableau[1] = malloc(4 * sizeof(char));
    tableau[2] = malloc(4 * sizeof(char));

    srand(time(NULL));


    
    partie(tableau);
    for(int i = 0; tableau[i]!=NULL;i++)
    {
        free(tableau[i]);
    }
    free(tableau);
    exit(0);
}