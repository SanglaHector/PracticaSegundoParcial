#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int primeraCarga = 0;
    int datosCargados = 0;
    int cargadoDesdeBinario = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

            system("cls");
            printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
            printf("\n2.Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
            printf("\n3.Alta de empleado");
            printf("\n4.Modificar datos de empleado");
            printf("\n5.Baja de empleado");
            printf("\n6.Listar empleados");
            printf("\n7.Ordenar empleados");
            printf("\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).");
            printf("\n9.Guardar los datos de los empleados en el archivo data.bin (modo binario).");
            printf("\n10.Aumentar sueldos");
            printf("\n11.Filtrar por horas");
            printf("\n12.Reducir por sueldo");
            printf("\n13.Salir");
            printf("\nIngrese una opcion: ");
            scanf("%d", &option);
        switch(option)
        {
            case 1:
                if ( primeraCarga == 0)
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        datosCargados = 1;
                        primeraCarga = 1;
                    }else
                    {
                        printf("\nError en cargar archivo");
                    }
                }else
                {
                    printf("\nSolo se pueden cargar una vez los archivos.");
                }
                break;

            case 2:
                if ( primeraCarga == 0)
                {
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        datosCargados = 1;
                        primeraCarga = 1;
                        cargadoDesdeBinario = 1;
                    }else
                    {
                        printf("\nError en cargar archivo");
                    }
                }else
                {
                    printf("\nSolo se pueden cargar una vez los archivos.");
                }
                break;

            case 3:

                if ( datosCargados == 1)
                {
                    if(controller_addEmployee(listaEmpleados))
                    {
                        printf("\nAlta dada correctamente!!");
                    }else
                    {
                        printf("\nEl alta fallo");
                    }
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;

            case 4:
                if ( datosCargados == 1)
                {
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("\nModificacion correcta!!");
                    }
                    else
                    {
                        printf("\nError en la modificacion");
                    }
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;

            case 5:
                 if ( datosCargados == 1)
                {
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("\nLa baja se ha ejecutado correctamente.");
                    }else
                    {
                        printf("\nLa baja ha fallado.");
                    }
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;

            case 6:
                if ( datosCargados == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
            case 7:
                if ( datosCargados == 1)
                {
                    controller_sortEmployee(listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
            case 8:
                if ( datosCargados == 1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
            case 9:
                if ( datosCargados == 1)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
            case 10:
                if ( datosCargados == 1)
                {
                    controller_mapear(listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
            case 11:
                if ( datosCargados == 1)
                {
                    controller_filter(listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
             case 12:
                if ( datosCargados == 1)
                {
                    controller_reduce(listaEmpleados);
                }else
                {
                    printf("\nDebe cargar datos antes de ingresar a una opcion!");
                }
                break;
            case 13:
                printf("\nSaliendo...");
                break;
            default:
                printf("\nIngrese una opcion correcta");
        }
        printf("\n");
        system("pause");
        printf("\n");
    }while(option != 13);
    return 0;
}
