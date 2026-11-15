#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>


void init_tableau(char ** tableau)
{
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++) 
        {
            tableau[x][y] = ' ';
        }
    }
}

void affichage(char ** tableau) 
{
    printf("\n┏━━━┳━━━┳━━━┓\n");
    printf("┃ %c ┃ %c ┃ %c ┃\n", tableau[0][0], tableau[0][1], tableau[0][2]);
    printf("┣━━━╋━━━╋━━━┫\n");
    printf("┃ %c ┃ %c ┃ %c ┃\n", tableau[1][0], tableau[1][1], tableau[1][2]);
    printf("┣━━━╋━━━╋━━━┫\n");
    printf("┃ %c ┃ %c ┃ %c ┃\n", tableau[2][0], tableau[2][1], tableau[2][2]);
    printf("┗━━━┻━━━┻━━━┛\n");
}

void bot(char ** tableau)
{
    bool zbeub = 1;
    while(zbeub)
    {
        int randomy = rand() % 3;
        int randomx = rand() % 3;
        if(tableau[randomy][randomx] == ' ')
        {
            tableau[randomy][randomx] = 'O';
            zbeub = 0;
        }
        else
        {
            printf(".");
        }
    }
}

void joueur(char ** tableau)
{
    int casey;
    int casex;
    int casen;
    bool zbeub = 1;
    while(zbeub)
    {
        printf("entrez la case que vous voulez jouer (entre 0 et 8)");
        scanf("%d", &casen);
        casey = casen / 3;
        casex = casen % 3;
        if(casen >= 0 && casen <= 8 && tableau[casey][casex] == ' ')
        {
            tableau[casey][casex] = 'X';
            zbeub = 0;
        }
        else
        {
            printf("joue un autre nombre\n");
        }
    }
}


bool victoire(char ** tableau)
{
    if (tableau[0][0] != ' ' && tableau[0][0] == tableau[0][1] && tableau[0][1] == tableau[0][2])
        return (1);
    if (tableau[1][0] != ' ' && tableau[1][0] == tableau[1][1] && tableau[1][1] == tableau[1][2])
        return (1);
    if (tableau[2][0] != ' ' && tableau[2][0] == tableau[2][1] && tableau[2][1] == tableau[2][2])
        return (1);
    if (tableau[0][0] != ' ' && tableau[0][0] == tableau[1][0] && tableau[1][0] == tableau[2][0])
        return (1);
    if (tableau[0][1] != ' ' && tableau[0][1] == tableau[1][1] && tableau[1][1] == tableau[2][1])
        return (1);
    if (tableau[0][2] != ' ' && tableau[0][2] == tableau[1][2] && tableau[1][2] == tableau[2][2])
        return (1);
    if (tableau[0][0] != ' ' && tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2])
        return (1);
    if (tableau[0][2] != ' ' && tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0])
        return (1);
    return (0);
}


void partie(char ** tableau)
{
    printf("Bienvenue sur ce jeu de morpion.\nPour jouer une case il faut entrer un nombre de 0 à 8,.\nLe but est de gagner contre l'ordinateur.");
    init_tableau(tableau);
    affichage(tableau);
    int coups = 0;
    bool run = 1;
    while(coups <=9 && run)
    {
        if(coups == 9)
        {
            printf("Egalité.");
            coups = coups + 1;
            break;
            //ppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
        }
        joueur(tableau);
        if(victoire(tableau))
        {
            system("clear");
            affichage(tableau);
            printf("Vous avez gagné.");
            run = 0;
            break;
        }
        coups = coups + 1;
        bot(tableau);
        if(victoire(tableau))
        {
            system("clear");
            affichage(tableau);
            printf("Vous avez perdu.");
            run = 0;
            break;
        }
        coups = coups + 1;
        //ppppppppppppppppppppppppppppppppppppppppppppppppppp
        system("clear");
        affichage(tableau);
    }
}

