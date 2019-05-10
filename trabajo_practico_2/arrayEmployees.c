#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#include "bibliotecaGetsYComprobaciones.h"

int initEmployees(sEmployee listEmployees[], int len)
{
    int flag = -1;
    int i;
    for(i = 0 ; i < len; i++)
    {
        listEmployees[i].isEmpty = FREE;
        flag = 0;
    }

    return flag;
}

int addEmployee(sEmployee listEmployees[])
{
    int flag;
    int indexFreeSlot;

    indexFreeSlot = findFreeSlot(listEmployees, LEN_EMP);
    if(indexFreeSlot == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        flag = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listEmployees[indexFreeSlot] = setEmployee(listEmployees);
    flag = 0;

    return flag;
}

sEmployee setEmployee(sEmployee listEmployees[])
{
    sEmployee employee;

    employee.id = nextId(listEmployees, LEN_EMP);

    fflush(stdin);
    getStringOnly("Ingrese el nombre: ", employee.name);

    fflush(stdin);
    getStringOnly("Ingrese el apellido: ", employee.lastName);

    employee.salary = getFloatOnly("Ingrese el salario: ");

    employee.sector = getIntOnly("Ingrese el sector: ");

    employee.isEmpty = TAKEN;

    return employee;
}

int findFreeSlot(sEmployee listEmployees[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listEmployees[i].isEmpty == FREE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int nextId(sEmployee listEmployee[],int len)
{
    int value = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(listEmployee[i].isEmpty== TAKEN)
        {
            if(listEmployee[i].id > value)
            {
                value = listEmployee[i].id;
            }
        }
    }
    return value + 1;
}

int modifyEmployee(sEmployee listEmployees[])
{
    int auxId;
    int indexPosition;
    int flag;

    system("cls");
    printf("MODIFICAR\n\n");
    printEmployees(listEmployees, LEN_EMP);
    auxId = getIntOnly("Ingrese el Id a modificar: ");
    indexPosition = findEmployeeById(listEmployees, LEN_EMP, auxId);
    if(indexPosition == -1)
    {
        printf("\nLa Id no existe.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        modifyMenu(listEmployees, indexPosition);
        flag = 0;
    }

    return flag;
}

void printAnEmployee(sEmployee listEmployees[], int index)
{
    if(listEmployees[index].isEmpty == TAKEN)
    {
        printf("Id: %5d | Nombre: %-8s , %-8s | Salario: %6.2f | Sector: %d\n", listEmployees[index].id, listEmployees[index].name,
               listEmployees[index].lastName, listEmployees[index].salary, listEmployees[index].sector);
    }
}

void printEmployees(sEmployee listEmployees[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(listEmployees[i].isEmpty != FREE)
        {
            printAnEmployee(listEmployees, i);
        }
    }
}

int findEmployeeById(sEmployee listEmployee[], int len, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listEmployee[i].isEmpty != FREE && listEmployee[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void modifyMenu(sEmployee listEmployee[], int position)
{
    int choice;

    do
    {
        system("cls");
        choice = getIntOnly("MODIFICAR\n\n1.Nombre \n2.Apellido \n3.Salario \n4.Sector \n5.Regresar \n Ingrese una opcion: ");
        switch(choice)
        {
        case 1: //modificar nombre
            modifyName(listEmployee, position);
            break;
        case 2: //modificar apellido
            modifyLastName(listEmployee, position);
            break;
        case 3: //modificar salario
            modifySalary(listEmployee, position);
            break;
        case 4: //modificar sector
            modifySector(listEmployee, position);
            break;
        case 5://regresar
            choice = 5;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
    }
    while(choice != 5);
}

void modifyName(sEmployee listEmployee[], int position)
{
    char auxName[100];
    system("cls");
    printf("Modificacion del nombre\n\n");
    printAnEmployee(listEmployee, position);
    getStringOnly("\nIngrese el nuevo nombre: ", auxName);
    printf("\nEsta seguro que desea cambiar el nombre?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listEmployee[position].name, auxName);
    }
}

void modifyLastName(sEmployee listEmployee[], int position)
{
    char auxLastName[100];
    system("cls");
    printf("Modificacion del apellido\n\n");
    printAnEmployee(listEmployee, position);
    getStringOnly("\nIngrese el nuevo apellido: ", auxLastName);
    printf("\nEsta seguro que desea cambiar el apellido?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listEmployee[position].lastName, auxLastName);
    }
}

void modifySalary(sEmployee listEmployee[], int position)
{
    float auxSalary;
    system("cls");
    printf("Modificacion del salario\n\n");
    printAnEmployee(listEmployee, position);
    auxSalary = getFloatOnly("\nIngrese el nuevo salario: ");
    printf("\nEsta seguro que desea cambiar el salario?(s/n): ");
    if(getch() == 's')
    {
        listEmployee[position].salary = auxSalary;
    }
}

void modifySector(sEmployee listEmployee[], int position)
{
    int auxSector;
    system("cls");
    printf("Modificacion del sector\n\n");
    printAnEmployee(listEmployee, position);
    auxSector = getIntOnly("\nIngrese el nuevo sector: ");
    printf("\nEsta seguro que desea cambiar el sector?(s/n): ");
    if(getch() == 's')
    {
        listEmployee[position].sector = auxSector;
    }
}

int removeEmployee(sEmployee listEmployee[], int len)
{
    int auxId;
    int index;
    int flag;

    system("cls");
    printf("BAJA\n\n");
    printEmployees(listEmployee, len);
    auxId = getIntOnly("\nIngrese el numero de Id a dar de baja: ");
    index = findEmployeeById(listEmployee, len, auxId);
    if(index == -1)
    {
        printf("No se encuentra ese Id.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listEmployee[index].isEmpty = FREE;
            flag = 0;
        }
    }
    return flag;
}

int sortEmployees(sEmployee listEmployees[], int len, int order)
{
    int flag = 0;
    if(order == 1)//ascendente
    {
        sortUp(listEmployees, len);
        flag = 1;
    }
    else//descendente
    {
        sortDown(listEmployees, len);
        flag = 1;
    }
    system("cls");
    printEmployees(listEmployees, len);
    system("pause");

    return flag;
}

void sortMenu(sEmployee listEmplyees[], int len)
{
    int choice;
    int flag;

    do
    {
        system("cls");
        choice = getIntOnly("Menu de ordenamiento\n\n1.Ascendente\n2.Descendente\n3.Regresar\nIngrese una opcion: ");
        switch(choice)
        {
        case 1://ascendente
            flag = sortEmployees(listEmplyees, len, 1);
            if (flag == 0)
            {
                printf("Se ordeno correctamente");
            }
            break;
        case 2://descendente
            flag = sortEmployees(listEmplyees, len, 0);
            if (flag == 0)
            {
                printf("Se ordeno correctamente");
            }
            break;
        case 3:
            choice = 3;
            break;
        default:
            system("cls");
            printf("\nNo es una opcion correcta.\n");
        }
    }
    while(choice != 3);

}

void infoMenu(sEmployee listEmployees[], int len)
{
    int choice;

    do
    {
        system("cls");
        choice = getIntOnly("Informes\n\n1.Ordenar listado\n2.Datos de salarios\n3.Regresar\nIngrese una opcion: ");

        switch(choice)
        {
        case 1://odernamiento
            sortMenu(listEmployees, len);
            break;
        case 2://salarios
            salaryInfo(listEmployees, len);
            break;
        case 3:
            choice = 3;
            break;
        default:
            system("cls");
            printf("\nNo es una opcion correcta.\n");
        }
        system("cls");
    }
    while(choice != 3);
}

void sortDown(sEmployee listEmployees[], int len)
{
    sEmployee employeeAux;
    int i;
    int j;

    for(i = 0; i < len - 1; i++)
    {
        if(listEmployees[i].isEmpty == FREE)
        {
            continue;
        }
        for(j = i + 1; j < len; j++)
        {
            if(listEmployees[j].isEmpty == FREE)
            {
                continue;
            }
            if(strcmp(listEmployees[j].lastName, listEmployees[i].lastName) > 0)
            {
                employeeAux = listEmployees[j];
                listEmployees[j] = listEmployees[i];
                listEmployees[i] = employeeAux;
            }
            else if(strcmp(listEmployees[j].lastName, listEmployees[i].lastName) == 0)
            {
                if(listEmployees[i].sector < listEmployees[j].sector)
                {
                    employeeAux = listEmployees[j];
                    listEmployees[j] = listEmployees[i];
                    listEmployees[i] = employeeAux;
                }
            }
        }
    }
}

void sortUp(sEmployee listEmployees[], int len)
{
    sEmployee employeeAux;
    int i;
    int j;

    for(i = 0; i < len - 1; i++)
    {
        if(listEmployees[i].isEmpty == FREE)
        {
            continue;
        }
        for(j = i + 1; j < len; j++)
        {
            if(listEmployees[j].isEmpty == FREE)
            {
                continue;
            }
            if(strcmp(listEmployees[j].lastName, listEmployees[i].lastName) < 0)
            {
                employeeAux = listEmployees[j];
                listEmployees[j] = listEmployees[i];
                listEmployees[i] = employeeAux;
            }
            else if(strcmp(listEmployees[j].lastName, listEmployees[i].lastName) == 0)
            {
                if(listEmployees[i].sector > listEmployees[j].sector)
                {
                    employeeAux = listEmployees[j];
                    listEmployees[j] = listEmployees[i];
                    listEmployees[i] = employeeAux;
                }
            }
        }
    }
}

void salaryInfo(sEmployee listEmployee[], int len)
{
    float totalSalary;
    float promSalary;
    int qtyEmpSalProm = 0;
    int qtyEmployees = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if(listEmployee[i].isEmpty == TAKEN)
        {
            totalSalary = totalSalary + listEmployee[i].salary;
            qtyEmployees++;
        }
    }

    promSalary = totalSalary / qtyEmployees;

    for(i = 0; i < len; i++)
    {
        if(listEmployee[i].isEmpty == TAKEN)
        {
            if(listEmployee[i].salary > promSalary)
            {
                qtyEmpSalProm++;
            }
        }
    }
    system("cls");
    printf("El salario total es de: %.2f\nEl salario promedio es de: %.2f\nLa cantidad de empleados que superan "
            "el salario promedio son: %d\n", totalSalary, promSalary, qtyEmpSalProm);
    system("pause");
}

void abmEmployees()
{
    sEmployee listEmployees[LEN_EMP];
    int choice;
    int isError;
    int isErrorAdd;
    int isErrorModify;
    int isErrorRemove;
    int flagIsCharged = 0;
    do
    {
        isError = initEmployees(listEmployees, LEN_EMP);
    }while(isError == -1);

    do
    {
        choice = getIntOnly(" Nomina de empleados.\n\n1. Dar de alta un empleado. \n2. Modificar datos de un empleado. \n3. Dar de baja un empleado. \n"
                            "4. Informes. \n5. Salir. \nIngrese una opcion: ");

        switch(choice)
        {
            case 1: //Alta
                isErrorAdd = addEmployee(listEmployees);
                if(isErrorAdd == 0)
                {
                    flagIsCharged = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido cargar el empleado.\n");
                }
                break;
            case 2: //Modificar
                if(flagIsCharged != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
                isErrorModify = modifyEmployee(listEmployees);
                if(isErrorModify == 0)
                {
                    system("cls");
                    printf("\nSe modifico correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido modificar el empleado.\n");
                }
                break;
            case 3: //Baja
                if(flagIsCharged != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
               isErrorRemove = removeEmployee(listEmployees, LEN_EMP);
               if(isErrorRemove == 0)
                {
                    system("cls");
                    printf("\nSe dio de baja correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido dar de baja al empleado.\n");
                }
                break;
            case 4: //Informar
                if(flagIsCharged != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
                infoMenu(listEmployees, LEN_EMP);
                break;
            case 5:
                choice = 5;
                break;
            default:
                system("cls");
                printf("No es una opcion valida.");
        }
        system("pause");
        system("cls");
    }
    while(choice != 5);
}
