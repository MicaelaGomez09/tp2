#include <stdio.h>
#include <stdlib.h>


#define MAX 10

#define VACIO 0
#define ACTIVO 1
#define BORRADO 2

struct nada{
    char nombre [50] ;
    int edad;
    int dni;

    int status;
};

typedef struct nada nada ;

void printMenu();
void alta(nada agenda[10]);
void baja(nada agenda[10]);
void busqueda(nada agenda[10]);
void mostrar(nada agenda[10]);
int buscar(nada agenda[10]);
void ordenamiento(nada agenda[10]);
void mostrarOrdenado(nada agenda[10]);
void ordenaChar(nada agenda[10]);
void ordenarNombre(nada agenda [10]);
void Grafico(nada agenda [MAX]);


///////////////////////////////////////////////////////////////
int main()
{


    nada agenda[10];
    init(agenda);
    char aux[20];
    char auxDniStr[30];
    int i,j;
    int lugarDisponible;

    int op = 0;
    do{
        system("cls");
        printMenu();
        scanf("%d", &op);
        switch(op){
            case 1 :
                system("cls");
                alta(agenda);
               // getch();
                break;
            case 2 :
                system("cls");
                baja(agenda);
               // getch();
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
                mostrar(agenda);
                getch();
                break;
        }

    }while(op!= 7);
    return 0;
}
/////////////////////////////////////////////////////////////
void printMenu(){
    printf("MENU AGENDA2 \n");
    printf("1.AGREGAR PERSONA \n");
    printf("2.BORRAR PERSONA \n");
    printf("3.IMPRIMIR LISTA \n");
    printf("4.IMPRIMIR LISTA ORDENADA POR NOMBRE \n");
    printf("5.IMPRIMIR GRAFICO \n");
    printf("6.BORRADO LOGICO \n");
    printf("7.Salir \n\n");
}

////////////////////////////////////////////////////////////
void alta(nada agenda[10]){
    printf("Ingrese los datos: \n");
    for(int i = 0 ; i < MAX ; i++){
        if(agenda[i].status == VACIO){
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
void baja(nada agenda[10]){
    printf("Baja \n");
    int posicion = buscar(agenda);

    if(posicion != -1 ){
      agenda[posicion].status = BORRADO;
      strcpy(agenda[posicion].nombre,"vacio");
      agenda[posicion].edad =0;
      agenda[posicion].dni =0;
    }else{
        printf("No se encontro la direccion");
    }
}

///////////////////////////////////////////////////////////
int buscar(nada agenda[10])
{
    int posicion = -1;

    char nombre2[50];
    int edad2;



    printf("nombre : " );
    scanf("%s",nombre2);

   printf("edad : ");
    scanf("%d",&edad2);

      for(int i = 0 ; i < 10 ; i++){
        if(agenda[i].status == ACTIVO &&
           strcmp(agenda[i].nombre , nombre2) == 0 &&
           agenda[i].edad == edad2){
           posicion = i;
           break;
        }
    }

    return posicion;
}


void init(nada agenda[10]){
    for(int i = 0 ; i < MAX ; i++){
       strcpy(agenda[i].nombre,"vacio");
       agenda[i].edad = 0;
       agenda[i].dni = 0;

       agenda[i].status = VACIO;
    }
}
////////////////////////////////////////////////////////////////////
void mostrar(nada agenda[10]){
    printf("Listado de todos los datos\n");
    for(int i = 0 ; i < MAX ; i++){
        printf("%s %d %d %d\n",
               agenda[i].nombre,
               agenda[i].edad,
               agenda[i].dni,

               agenda[i].status
               );
    }
}

///////////////////////////////////////////////////////////////

//colocar structura auxiliar para ordenar
void colocarAux(nada agendaaux[10], nada agenda[10])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(agendaaux[i].nombre, agenda[i].nombre);
        agendaaux[i].edad = agenda[i].edad;
        agendaaux[i].dni = agenda[i].dni;
        agendaaux[i].status = agenda[i].status;
    }
}


void ordenarNombre(nada agenda [MAX]){

   for(int i=0; i<10 ; i++){
        for(int j=0; j<9; j++){
    if(strcmp(agenda[j].nombre,agenda[j+1].nombre)>0)
    {
        char auxn[10];
        int auxe;
        int auxd;
        //ordena nombre
        strcpy(auxn, agenda[j].nombre);
        strcpy(agenda[j].nombre,agenda[j+1].nombre);
        strcpy(agenda[j+1].nombre,auxn);
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
   printf("Listado datos ordenados\n");
    for(int i = 0 ; i < MAX ; i++){
        printf("%s \n",
               agenda[i].nombre);
    }
}







void Grafico(nada agenda [MAX]) {
     int menores =0;
     int adultos =0;
     int mayores =0;

     for(int i=0; i<MAX; i++){
        if(agenda[i].status == ACTIVO){
            if(agenda[i].edad <=18){
                menores++;
            }else if(agenda[i].edad>18&&agenda[i].edad<=35){
            adultos++;
            }else if(agenda[i].edad>35){
            mayores++;
            }
        }
     }
int grafico[MAX][3];
for(int i=0; i<menores; i++){
    printf("*",grafico[i][1]);
    
    for(int i=19; i>=0; i++){
    for(int j =0; j<3; j++){
        printf("      %d      ", grafico[i][j]);
    }
    printf("  \n");
}
printf("  \n");
printf("menores         adultos             mayores    \n");




    /*if(i<menores){

grafico[i] [0]=1;
    }else{
    grafico[i] [0]=0;
    }
    if(i<adultos){
        grafico[i] [1]=1;
    }else{
    grafico[i] [1]=0;
    }
    if(i<mayores){
        grafico[i] [2]=1;
    }else{
    grafico[i] [2]=0;
    }
}

for(int i=19; i>=0; i++){
    for(int j =0; j<3; j++){
        printf("      %d      ", grafico[i][j]);
    }
    printf("  \n");
}
printf("  \n");
printf("menores         adultos             mayores    \n");*/
}
}
