#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[30];
    int edad;
    int dni;
    int estado;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona arrarPersona[], int dni);

//pasar el mensaje y donde queremos que se guarde
void getString(char mensaje[], char input[]);
int getSoloLetras(char mensaje[], char input[]);
int getSoloNumeros(char mensaje[], char input[]);




#endif // FUNCIONES_H_INCLUDED
