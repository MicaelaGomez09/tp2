int getInt(char mensaje[])
{
    int aux; //variable int que contendr� el valor de mensaje
    printf("%s", mensaje);//solicita un string
    scanf("%d", &aux);//toma el string y lo guarda tido %d en la variable
    return aux;// retorna la variable con el dato guardado
}

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int getSoloNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getSoloLetras(char mensaje[], char input[])
{
  char datoIngresado[256];
  getString(mensaje, datoIngresado);//(placeholder, &duardado_en)
  if(esSoloLetras(datoIngresado)) //si lo que ingresó el usuario son solo letras
  {
    strcpy(input, datoIngresado);//copiamos el dato ingresado en 'inpu'
    return 1;
  }
  return 0;
}

void getString(char mensaje[], char input[])
{
  printf("%s", mensaje);
  scanf("%s", input);
}

void ordenar(int array[Q_PERSONAS])
{
    for(int i =0; i < Q_PERSONAS; i++)
    {
        int estaOk = 0;//flag para evitar iteraciones innecesarias
        for(int j =0; j < Q_PERSONAS -1 -i; j++)//el -i evita comparar con las ultimas posiciones q ya sabemos q fueron ordenadas
        {
            if(vector[j] > vector[j+1])
            {
                int aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
                estaOk = 1;//indica q no esta OK
            }
        }
        if(estaOk == 0)//pregunta final del flag
        {
            break;
        }
    }
}
