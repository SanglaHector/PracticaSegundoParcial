#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "LinkedDos.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
     int retorno = 0;
    FILE* f;

    if((f = fopen(path,"r")) != NULL)
    {
        if(parser_EmployeeFromText(f,pArrayListEmployee) != 0)
        {
            printf("\nLectura correcta!! \n");
            retorno = 1;
        }else
        {
            retorno = 0;
            printf("\nLa lectura del archivo no fue correcta.\n");
        }

    }else
    {
        printf("\nEl archivo no se pudo abrir correctamente.\n");
        retorno = 0;
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* f;

    if((f = fopen(path,"r+b")) != NULL)
    {
        if(parser_EmployeeFromBinary(f,pArrayListEmployee) != 0)
        {
            printf("\nLectura correcta!! \n");
            retorno = 1;
        }else
        {
            retorno = 0;
            printf("\nLa lectura del archivo no fue correcta.\n");
        }

    }else
    {
        printf("\nEl archivo no se pudo abrir correctamente.\n");
        retorno = 0;
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = employee_add(pArrayListEmployee);
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = employee_edit(pArrayListEmployee);
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return employee_removeEmployee(pArrayListEmployee);
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return employee_list(pArrayListEmployee);
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return employee_sort(pArrayListEmployee);
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return employee_saveAsText(path,pArrayListEmployee);
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
   return employee_saveAsBinary(path,pArrayListEmployee);


}

//***************************************************************************
int controller_mapear(LinkedList* pArrayList)
{
    return employee_map(pArrayList);
}
//**************************************************************************
int controller_filter(LinkedList* pArrayList)
{
    return employee_filter(pArrayList);
}
//**************************************************************************
int controller_reduce(LinkedList* pArrayList)
{
    return employee_reduce(pArrayList);
}
// el archivo binario una vez cargado da ok. pero al momento de mostrarlo me falta el primer registro. Debo fijarte si no es un error del guardado
// en binario o desde cargar desde binario. quizas estoy guardando desde un nuemro mayor a cero o quizas estoy cargando mal el archivo
//en el bloc de notas aparece lou que es el primero entonces estoy cargando mal desde el archivo

//****************
