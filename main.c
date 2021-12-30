#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define Q_PERSONAS 20
#define ACTIVO 1
#define INACTIVO 0

void iniciarArrayInt(int array[], int cant_elemementos, int valor);
int buscaValorenArray(int array[], int cant_elemementos, int valor);

char seguir='s';

int main()
{
    //arrays principales
    char arrayNombres[Q_PERSONAS][30];
    char arrayApellidos[Q_PERSONAS][30];
    int arrayDni[Q_PERSONAS];

    //para manejar los array principales
    char auxNombreStr[30];
    char auxApellidoStr[30];
    char auxDniStr[30];
    int auxDni;

    int getSoloNumeros(char mensaje[], char input[]);
    int getSoloLetras(char mensaje[], char input[])

    //para los lugares de la matriz
    int lugarDisponible;
    int resultadoBusqueda;

    int i,j;

//  condiciones en true para iniciar el while
    int opcion=0;

    iniciarArrayInt(arrayDni, Q_PERSONAS, -1);//marcador de posiciones vacias
    while(opcion != 6)
    {
        printf("OPCIONES DE AGENDA\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Modificar datos\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                /*
                **
                void ingreso(persona agenda[20]){
                    printf("Ingrese los datos: \n");
                    for(int i = 0 ; i < 20 ; i++){
                        if(agenda[i].estado == VACIO){
                            printf("NOMBRE : "  );
                            scanf("%s" , agenda[i].nombre);

                            printf("EDAD" : "  );
                            scanf("%d" , &agenda[i].edad);

                            printf("DNI : "  );
                            scanf("%d" , &agenda[i].dni);

                            agenda[i].status = ACTIVO;
                            break;

                        }
                    }

                }
                */
                //
                lugarDisponible = buscaValorenArray(arrayDni, Q_PERSONAS, -1);
                if(lugarDisponible == -1)
                {
                    printf("\n\nYa no hay lugares libres!\n");
                    break;
                }
                printf("AGREGAR PERSONA");

                if(!getSoloLetras("Nombre: ", auxNombreStr))
                {
                    printf("El nombre solo debe tener letras!\n");
                    break;
                }
                if(!getSoloLetras("Apellido: ", auxApellidoStr))
                {
                    printf("El apellido solo debe tener letras!\n");
                    break;
                }
                if(!getSoloNumeros("DNI: ", auxDniStr))
                {
                    printf("El DNI solo debe tener numeros!\n");
                    break;
                }
                //convertimos el dni en un int
                auxDni = atoi(auxDniStr);

                if(buscaValorenArray(arrayDni, Q_PERSONAS, auxDni) != -1)
                {
                    printf("El DNI ya estaba agendado!\n");
                    break;
                }

                //en el array X, en la posicion libre encontrada, copiamos lo ingresado en auxNombreStr
                strcpy(arrayNombres[lugarDisponible], auxNombreStr);
                strcpy(arrayApellidos[lugarDisponible], auxApellidoStr);
                arrayDni[lugarDisponible] = auxDni;

                break;

            case 2:
                printf("BORRAR PERSONA");

                if(!getSoloNumeros("Ingrese un DNI para dar de baja: ", auxDniStr));
                {
                    printf("El DNI debe ser numerico\n");
                    break;
                }
                lugarDisponible = buscaValorenArray(arrayDni, Q_PERSONAS, atoi(auxDniStr));

                //si marca vacio ese dni no puede darse de baja porque no fue ingresado
                if(lugarDisponible == -1)
                {
                    printf("\n\nNO se encuentra ese DNI\n");
                    break;
                }
                //si existiera ese dni entonces lo marco como vacio. Baja logica
                arrayDni[lugarDisponible] = -1;
                break;

            case 3:
                printf("3- Imprimir lista ordenada por nombre\n");
                for(i=0; i<Q_PERSONAS -1; i++)
                {
                    if(arrayDni[i] == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < Q_PERSONAS; j++)
                    {
                        if(arrayDni[j] == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayNombres[i],arrayNombres[j]))
                        {
                            strcpy(auxNombreStr, arrayNombres[i]);
                            strcpy(arrayNombres[i], arrayNombres[j]);
                            strcpy(arrayNombres[j], auxNombreStr);
                        }
                    }
                }
                break;
            case 4:
                //printf("4- Imprimir grafico de edades\n\n");

                break;
            case 5:
                printf("5- MODIFICAR DATOS\n");
                //valido que sea numerico
                if(!getSoloNumeros("Ingrese un DNI a modificar: ", auxDniStr))
                {
                    printf("El legajo debe ser numerico");
                    break;
                }
                //valido si ese dni está guardado en mi array
                lugarDisponible = buscaValorenArray(arrayDni,Q_PERSONAS,atoi(auxDniStr));

                if(lugarDisponible == -1)
                {
                    printf("\nEse DNI no estába guardado\n");
                    break;
                }

                if(!getSoloLetras("Ingrese un nombre: ",auxNombreStr))
                {
                    printf("\nEl nombre debe tener solo letras\n");
                    break;
                }

                if(!getSoloLetras("Ingrese un apellido: ",auxApellidoStr))
                {
                    printf("\nEl apellido debe tener solo letras\n");
                    break;
                }
                //en la posicion encontrada, dentro del array nombres, copio lo ingresado en el auxiliar
                strcpy(arrayNombres[lugarDisponible], auxNombreStr);
                strcpy(arrayApellidos[lugarDisponible], auxApellidoStr);

                break;

            case 6:
                printf("\nMOSTRAR");

                for(i=0; i < Q_PERSONAS; i++) //recorre el array
                {
                    if(arrayDni[i] != -1)//siempre y cuando no esté vacío
                    {   //mostrar nombre apellido y dni
                        printf("\n%s - %s - %d", arrayNombres[i], arrayApellidos[i], arrayDni[i]);
                    }
                }
                break;

            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

//inicia un array colocando un valor en cada posicion
void iniciarArrayInt(int array[], int cant_elementos, int valor)
{
    int i;
    for(i=0; i < cant_elementos; i++)
    {
        array[i] = valor;
    }
}

//busca un valor en un array. Indicar donde, cuantos datos hay y el valor q se busca
int buscaValorenArray(int array[], int cant_elementos, int valor)
{
    int i;
    for(i=0; i < cant_elementos; i++)
    {
        if(array[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

//


