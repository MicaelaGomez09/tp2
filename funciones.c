
//MENUU////////
void mostrarMenu()
{
    printf("\n                                               +---------------------------+      \n");
    printf("                                           ¦            Menu de opciones           ¦\n");
    printf("                                           +---------------------------------------+\n");
    printf("                                           -----------------------------------------\n");
    printf("                                           ¦  1-AGREGAR PERSONA                    ¦\n");
    printf("                                           ¦  2-BORRAR PERSONA                     ¦\n");
    printf("                                           ¦  3-IMPRIMIR LISTA ORDENADA POR NOMBRE ¦\n");
    printf("                                           ¦  4-IMPRIMIR GRAFICO DE EDADES         ¦\n");
    printf("                                           ¦  5-BORRADO LOGICO                     ¦\n");
    printf("                                           ¦  6-SALIR                              ¦\n");
    printf("                                           -----------------------------------------\n");
    printf("                                           ELEGIR NUMERO DE OPERACION: ");

}
////// INICIALIZACION////
void inicializarArray(persona agenda[20]){
    for(int i = 0 ; i < 20 ; i++){
       strcpy(agenda[i].nombre,"vacio");
       agenda[i].edad = 0;
       agenda[i].dni = 0;

       agenda[i].estado = VACIO;
    }
}
//ingreso////
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

            agenda[i].estado = ACTIVO;
            break;

        }
    }

}
////MOSTRAR LISTA
void mostrar(persona agenda[20]){
    printf("Lista de personas\n");
    for(int i = 0 ; i < 20 ; i++){
        printf("%s %d %s %d %d\n",
               agenda[i].nombre,
               agenda[i].edad,
               agenda[i].dni,
               agenda[i].estado,

               );
    }
}


