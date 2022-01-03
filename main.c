#include <stdio.h>
#include <stdlib.h>




#define MAX 20

#define VACIO 0
#define ACTIVO 1
#define BORRADO 2
#include "funciones.h"
///////////////////////////////////////////////////////////////
int main()
{


    nada agenda[MAX];
    init(agenda);
    char aux[20];
    char auxDniStr[30];
    int i,j;
    int lugarDisponible;

    int op = 0;
    while(op != 7)
    {
        system("cls");
        system("color 0B");
        printf("\n");
        printf("                                  _____    _____     ______   ___   __    _____     _____    \n");
        printf("                                 |  _  |  |  ___|   |   ___| |   | |  |  |     |   |  _  |  \n");
        printf("                                 |     |  | |  __   |  |__   |    ||  |  |  ||  |  |     |  \n");
        printf("                                 |  _  |  | | |_ |  |   __|  |        |  |  ||  |  |  _  |  \n");
        printf("                                 | | | |  | |__| |  |  |___  |  ||    |  |      |  | | | |  \n");
        printf("                                 |_| |_|  |______|  |______| |__| |___|  |_____/   |_| |_|  \n\n\n\n");
        printMenu();
        scanf("%d", &op);
        switch(op)
        {
        case 1 :
            system("cls");
            alta(agenda);
            system ("cls");
            break;
        case 2 :
            system("cls");
            baja(agenda);
            system ("cls");
            break;
        case 3 :
            system("cls");
            mostrar(agenda);
            getch();
            break;
        case 4 :
            system("cls");
            ordenarNombre(agenda);
            getch();
            break;
        case 5 :
            system("cls");
            Grafico(agenda);
            getch();
            break;
        case 6 :
            system("cls");
            init(agenda);
            mostrar(agenda);
            getch();
            break;
        case 7 :

            break;

        default:
            printf("Valor ingresado fuera de rango ");
            system("pause");
        }
    }


    return 0;
}
/////////////////////////////////////////////////////////////



