//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utilidades.h"

//Função de validação de datas
int vData(int dia, int mes, int ano) {
    if (ano >= 1900 && ano <= 9999) {
        if (mes >= 1 && mes <= 12) {
            if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
                return 1;
            else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
                return 1;
            else if ((dia >= 1 && dia <= 28) && (mes == 2))
                return 1;
            else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
                return 1;
            else
                return 0;
        }
        else return 0;
    }
    return 0;
}

//Função de validação de hora
int vHora(int hora, int min)
{
    if(hora >= 0 && hora <= 23)
    {
        if(min >= 0 && min <= 59)
            return 1;
        else
            return 0;
    }
    return 0;
}

//Função Sleep
void pausa(int seg) {
    int t = 1000 * seg;
    clock_t i = clock();
    while (clock() < i + t) {
        
    }
}