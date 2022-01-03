#include <stdio.h>
#include <stdlib.h>


#define MAX 20

#define VACIO 0
#define ACTIVO 1
#define BORRADO 2

struct nada{
    char nombre [50] ;
    char apellido[50];
    int edad;
    int dni;

    int status;
};

typedef struct nada nada ;

void printMenu();
void alta(nada agenda[MAX]);
void baja(nada agenda[MAX]);
void busqueda(nada agenda[MAX]);
void mostrar(nada agenda[MAX]);
int buscar(nada agenda[MAX]);
void ordenamiento(nada agenda[MAX]);
void mostrarOrdenado(nada agenda[MAX]);
void ordenaChar(nada agenda[MAX]);
void ordenarNombre(nada agenda [MAX]);
void Grafico(nada agenda [MAX]);


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
        switch(op){
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
void printMenu(){
   printf("\n                                           +---------------------------+\n");
    printf("                                           ¦      Menu de opciones     ¦\n");
    printf("                                           +---------------------------+\n");
    printf("                                           -----------------------------\n");
    printf("                                           ¦  1-AGREGAR PERSONA        ¦\n");
    printf("                                           ¦  2-BORRAR PERSONA         ¦\n");
    printf("                                           ¦  3-IMPRIMIR LISTA         ¦\n");
    printf("                                           ¦  4-LISTA ORDENADA         ¦\n");
    printf("                                           ¦  5-IMPRIMIR GRAFICO       ¦\n");
    printf("                                           ¦  6-BORRADO LOGICO         ¦\n");
    printf("                                           ¦  7-SALIR                  ¦\n");
    printf("                                           -----------------------------\n");
    printf("                                           ELEGIR NUMERO DE OPERACION: ");
}

////////////////////////////////////////////////////////////
void alta(nada agenda[MAX]){
    char nombre;
    printf("Ingrese los datos: \n");
    for(int i = 0 ; i < MAX ; i++){
        if(agenda[i].status == VACIO){

            printf("APELLIDO : "  );
            scanf("%s" , agenda[i].apellido);

            printf("NOMBRE : "  );
            scanf("%s" , agenda[i].nombre);

            printf("EDAD : "  );
            scanf("%d" , &agenda[i].edad);

            printf("DNI : "  );
            scanf("%d" , &agenda[i].dni);


            agenda[i].status = ACTIVO;
            break;

        }
    }

}
////////////////////////////////////////////////////////////
void baja(nada agenda[MAX]){
    printf("Baja \n");
    int posicion = buscar(agenda);

    if(posicion != -1 ){
      agenda[posicion].status = BORRADO;
      strcpy(agenda[posicion].nombre,"vacio");
      strcpy(agenda[posicion].apellido,"vacio");
      agenda[posicion].edad =0;
      agenda[posicion].dni =0;
    }else{
        printf("No se encontro la direccion");
    }
}

///////////////////////////////////////////////////////////
int buscar(nada agenda[MAX])
{
    int posicion = -1;

    char nombre2[50];
    char apellido2[50];
    int edad2;
    int dni2;



    printf("APELLIDO : " );
    scanf("%s",apellido2);

    printf("NOMBRE : " );
    scanf("%s",nombre2);

    printf("edad : ");
    scanf("%d",&edad2);

    printf("dni : ");
    scanf("%d",&dni2);

      for(int i = 0 ; i < 10 ; i++){
        if(agenda[i].status == ACTIVO &&
           strcmp(agenda[i].nombre , nombre2)==0 &&
           strcmp(agenda[i].apellido , apellido2) == 0 &&
           agenda[i].edad == edad2 &&
           agenda[i].dni == dni2){
           posicion = i;
           break;
        }
    }

    return posicion;
}


void init(nada agenda[MAX]){
    for(int i = 0 ; i < MAX ; i++){
       strcpy(agenda[i].nombre,"vacio");
       strcpy(agenda[i].apellido,"vacio");
       agenda[i].edad = 0;
       agenda[i].dni = 0;

       agenda[i].status = VACIO;
    }
}
////////////////////////////////////////////////////////////////////
void mostrar(nada agenda[MAX]){
      printf("\n                                           +---------------------------+\n");
        printf("                                           ¦      LISTADO DE DATOS     ¦\n");
        printf("                                           +---------------------------+\n");
    for(int i = 0 ; i < MAX ; i++){
        printf("                                           %s   %s   %d    %d    %d\n",
               agenda[i].apellido,
               agenda[i].nombre,
               agenda[i].edad,
               agenda[i].dni,

               agenda[i].status
               );
    }
}


void ordenarNombre(nada agenda [MAX]){

   for(int i=0; i<10 ; i++){
        for(int j=0; j<9; j++){
    if(strcmp(agenda[j].apellido,agenda[j+1].apellido)>0)
    {
        char auxa[10];
        char auxn[10];
        int auxe;
        int auxd;
        //ordena nombre
        strcpy(auxn, agenda[j].nombre);
        strcpy(agenda[j].nombre,agenda[j+1].nombre);
        strcpy(agenda[j+1].nombre,auxn);
        //ordena apellido
        strcpy(auxa, agenda[j].apellido);
        strcpy(agenda[j].apellido,agenda[j+1].apellido);
        strcpy(agenda[j+1].apellido,auxa);
        //ordena edad
        auxe=agenda[j].edad;
        agenda[j].edad=agenda[j+1].edad;
        agenda[j+1].edad=auxe;
        //ordena dni
        auxd=agenda[j].dni;
        agenda[j].dni=agenda[j+1].dni;
        agenda[j+1].dni=auxd;


    }
   }
   }
      printf("\n                                      +-----------------------------------------------+\n");
        printf("                                      ¦     LISTADO DE DATOS ORDENADOS POR NOMBRE     ¦\n");
        printf("                                      +-----------------------------------------------+\n");
    for(int i = 0 ; i < MAX ; i++){
        printf("                                                      %s %s \n ",
             agenda[i].apellido,
               agenda[i].nombre);
    }
}







void Grafico(nada agenda [MAX]) {

    int menores = 0;
    int adultos = 0;
    int mayores = 0;

    for( int i = 0 ; i < MAX ; i++ ) {
        if(agenda[i].status == ACTIVO){
            if(agenda[i].edad <= 18) {
                menores++;
            } else if(agenda[i].edad > 18 && agenda[i].edad <= 35) {
                adultos++;
            } else if(agenda[i].edad > 35) {
                mayores++;
            }
        }
    }

  ////
    int graficoDatos[MAX][3];
    for(int i=0; i<MAX; i++) {
        if(i < menores) {
            graficoDatos[i][0] = 1;
        } else {
            graficoDatos[i][0] = 0;
        }
        if(i < adultos) {
            graficoDatos[i][1] = 1;
        } else {
            graficoDatos[i][1] = 0;
        }
        if(i < mayores) {
            graficoDatos[i][2] = 1;
        } else {
            graficoDatos[i][2] = 0;
        }

    }
////

        for(int i = 9 ; i >= 0; i--){
            for(int j = 0 ; j < 3 ; j++){
               if(graficoDatos[i][j] == 1){

                printf("       *        " );//, graficoDatos[i][j]);
            }else{printf("                " );}
            }
            printf(" \n");
        }


      printf(" \n");
      printf("menores a 19    entre 19 a 35     mayores a 35");
}






