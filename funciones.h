#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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

void mostrarMenu();
void ingreso(persona agenda[20]);
void inicializarArray (persona agenda[20]);
void mostrar(persona agenda[20]);

#endif // FUNCIONES_H_INCLUDED
