#include <stdio.h>

int main (int argc, char *argv[]){
    int dia;
    printf ("Ingerse el dia de la semana\n");
    scanf ("%d", &dia);

    switch (dia)
    {
    case 1:
        printf("Lunes");
        break;
    case 2:
        printf("Martes");
        break;
    case 3:
        printf("Miercoles");
        break;
    case 4:
        printf("Jueves");
        break;
    case 5:
        printf("Viernes");
        break;
    case 6:
        printf("Sadado ");
        break;
    case 7:
        printf("Domingo");
        break;
    
    
    default: {
        printf ("Dato no valido");
    }
        break;
    }
    
}