#include <stdio.h>
int main(int argc, char const *argv[])
{
    // Ingresar el numero de estudiantes, sus notas y sacar el promedio
    int numEstudiantes;
    int nota;
    float suma;
    float promedio;
    suma=0;
    promedio=0;
    printf ("Ingrese el numero de estudiantes que desea calcular\n");
    
    while (scanf ("%d", &numEstudiantes) != 1 )
    {
        printf("Error: No se ingreso un numero, Intente nuevamentre\n");
        while (getchar() != '\n');
    }
    while (numEstudiantes<=0)
    {
        printf("Error: No se ingreso un dato valido, (solo numeros positivos)\n");
        scanf ("%d", &numEstudiantes);
    }
    for (int i = 1; i <= numEstudiantes; i++)
    {
        printf("Estudiante Nº:%d\n", i);

        do {
            printf("Ingrese la nota del estudiante entre 1 y 10\n");
            scanf("%d", &nota);
            if (nota<1 || nota>10)
            {
                printf ("Error: No se ingreso un dato valido, (solo numeros entre 1 y 10)\n");
                while (getchar() != '\n');
            }
            
        } while(nota<1 || nota>10);
        
        suma=suma+nota;
    }   
    promedio=suma/numEstudiantes;
    printf ("El promedio de los estudiantes es: %0.2f", promedio);    
    return 0;
}
