#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MAX 20

typedef struct
{
    char nombre [50] ;
    char apellido[50];
    int edad;
    int dni;

    int status;
} nada;

//typedef struct nada nada ;

void init(nada agenda[]);
void printMenu();
void alta(nada agenda[]);
void baja(nada agenda[MAX]);
void mostrar(nada agenda[MAX]);
int buscar(nada agenda[MAX]);
void ordenarNombre(nada agenda [MAX]);
void Grafico(nada agenda [MAX]);


#endif // FUNCIONES_H_INCLUDED
