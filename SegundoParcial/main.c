/**
1) Realizar un programa que lea un archivo (cuyo nombre se pasa como parámetro por
línea de comandos), con los datos de los dominios del registro automotor, guardándolos
en un linkedList de entidades eDominio.
2) Listar todos los vehiculos ordenados por dominio Datos:
Utilizar getters, setters y constructores, según corresponda.
 eDominio
o id
o dominio
o anio
o tipo
 data.csv
 auto.csv
 moto.csv
NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas linkedList y dominio (desarrollando las funciones setter y getter
necesarias).
#include <stdio.h>
#include <stdlib.h>
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Dominio.h"
int ordenarPorDominio(eDominio* elemento1, eDominio* elemento2);
int main()
{

    LinkedList* lista;
    lista = ll_newLinkedList();
    char path[100];

    FILE* f;

      int opcion = 0;
    do{
        printf("\n1.Cargar Datos");
        printf("\n2.Ordenar datos y mostrar");
        printf("\n3.Salir\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                printf("\nIngrese el nombre del archivo que quiera cargar.");
                scanf("%s", path);

                if((f = fopen(path,"r")) != NULL)
                {
                    if(parser_FromText(f,lista) != 0)
                    {
                        printf("\nLectura correcta!! \n");

                    }else
                    {
                        printf("\nError en parceo");
                    }
                }else
                {
                    printf("\nError al abrir al archivo");
                }
                break;
            case 2:
                if(ll_len(lista) > 0)
                {
                    ll_sort(lista,ordenarPorDominio,1);
                    d_list(lista);
                }
                break;
        }
    }while(opcion != 3);

}
//*********************************************************************
int ordenarPorDominio(eDominio* elemento1, eDominio* elemento2)
{
    char dominioUno[200];
    char dominioDos[200];

    d_getNombre(elemento1,dominioUno);
    d_getNombre(elemento2,dominioUno);
    if(strcmp( dominioUno , dominioDos) > 0 )
        {
         return 1;
        }
        if(strcmpi( elemento1->dominio , elemento2->dominio) < 0 )
        {
         return -1;
        }
        return 0;
}
//**************************************************
