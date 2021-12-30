#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <windows.h>

#define MAX 20

/*struct persona {
    char nombre[50];
    int edad;
    int dni;
    int estado;
};
 typedef struct persona persona;*/
 typedef struct {

    char nombre[30];
    int edad;
    int dni;
    int estado;
}persona;


int main()
{
   persona agenda[20];
   inicializarArray(agenda);
   float A=0, B=0, resultado=0, num=0;
    int opcion=0;


    while(opcion != 6)
    {
        mostrarMenu();
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1 :
            system("cls");
            ingreso(agenda);
            break;
        case 2 :
            system ("cls");

            break;
        case 3 :
            system("cls");
            mostrar(agenda);
            break;
        case 4 :
            system("cls");

            break;
        case 5 :
            system ("cls");


            break;
        case 6 :
            system ("cls");


            break;
        case 7 :

            break;

        default:
            printf("Valor ingresado fuera de rango. Volver a ingresar: ");

        }
    }
}
