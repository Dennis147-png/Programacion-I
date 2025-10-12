#include <stdio.h>

int main() {
    int num_estudiantes, num_materias;
    int i, j;

    do {
        printf("¿Cuántos estudiantes hay en el paralelo? ");
        
        if (scanf("%d", &num_estudiantes) != 1) {
            printf("Error: Debe ingresar solo números enteros.\n");
            while (getchar() != '\n'); 
        } 
        else if (num_estudiantes <= 0) {
            printf("Error: Debe haber al menos 1 estudiante.\n");
        } 
        else {
            while (getchar() != '\n');
            break; 
        }
    } while (1);

    do {
        printf("¿Cuántas materias tiene cada estudiante? ");
        
        if (scanf("%d", &num_materias) != 1) {
            printf("Error: Debe ingresar solo números enteros.\n");
            while (getchar() != '\n');
        } 
        else if (num_materias <= 0) {
            printf("Error: Debe haber al menos 1 materia.\n");
        } 
        else {
            while (getchar() != '\n');
            break;
        }
    } while (1);

    float notas[num_estudiantes][num_materias];
    float promedios[num_estudiantes];
    float promedio_general = 0;

    printf("\n INGRESAR NOTAS (0-10) \n");
    for(i = 0; i < num_estudiantes; i++) {
        printf("\n ESTUDIANTE %d \n", i + 1);
        
        for(j = 0; j < num_materias; j++) {
            do {
                printf("Materia %d: ", j + 1);
                if (scanf("%f", &notas[i][j]) != 1) {
                    printf("Error: Ingrese un número válido.\n");
                    while (getchar() != '\n');
                }
                else if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: La nota debe estar entre 0 y 10.\n");
                }
                else {
                    while (getchar() != '\n');
                    break;
                }
            } while(1);
        }
    }

    for(i = 0; i < num_estudiantes; i++) {
        float suma = 0;
        for(j = 0; j < num_materias; j++) {
            suma += notas[i][j];
        }
        promedios[i] = suma / num_materias;
        promedio_general += promedios[i];
    }
    promedio_general /= num_estudiantes;

    float max_materia[num_materias], min_materia[num_materias];
    int aprobados_materia[num_materias], reprobados_materia[num_materias];
    
    for(j = 0; j < num_materias; j++) {
        max_materia[j] = notas[0][j];
        min_materia[j] = notas[0][j];
        aprobados_materia[j] = 0;
        reprobados_materia[j] = 0;
    }
    
    for(j = 0; j < num_materias; j++) {
        for(i = 0; i < num_estudiantes; i++) {
            if(notas[i][j] > max_materia[j]) {
                max_materia[j] = notas[i][j];
            }
            if(notas[i][j] < min_materia[j]) {
                min_materia[j] = notas[i][j];
            }
            if(notas[i][j] >= 6.0) {
                aprobados_materia[j]++;
            } else {
                reprobados_materia[j]++;
            }
        }
    }


    printf("\nREPORTE ACADÉMICO");

    printf("\nNOTAS INDIVIDUALES\n");
    for(i = 0; i < num_estudiantes; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("  Notas: ");
        for(j = 0; j < num_materias; j++) {
            printf("%.1f ", notas[i][j]);
        }
        printf("\n  Promedio: %.2f - ", promedios[i]);
        
        if(promedios[i] >= 6.0) {
            printf(" APROBADO");
        } else {
            printf(" REPROBADO");
        }
    }

    printf("\nESTADÍSTICAS DEL PARALELO\n");
    
    int mejor_est = 0, peor_est = 0;
    for(i = 1; i < num_estudiantes; i++) {
        if(promedios[i] > promedios[mejor_est]) mejor_est = i;
        if(promedios[i] < promedios[peor_est]) peor_est = i;
    }

    printf("Promedio general del paralelo: %.2f\n", promedio_general);
    printf("Mejor promedio: Estudiante %d con %.2f\n", mejor_est + 1, promedios[mejor_est]);
    printf("Peor promedio: Estudiante %d con %.2f\n", peor_est + 1, promedios[peor_est]);

    int aprobados = 0, reprobados = 0;
    for(i = 0; i < num_estudiantes; i++) {
        if(promedios[i] >= 6.0) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    printf("Estudiantes aprobados: %d\n", aprobados);
    printf("Estudiantes reprobados: %d\n", reprobados);
    printf("Porcentaje de aprobación: %.1f%%\n", (float)aprobados / num_estudiantes * 100);

    printf("\n ESTADÍSTICAS POR MATERIA\n");
    for(j = 0; j < num_materias; j++) {
        float suma_materia = 0;
        for(i = 0; i < num_estudiantes; i++) {
            suma_materia += notas[i][j];
        }
        float promedio_materia = suma_materia / num_estudiantes;
        
        printf("\nMateria %d:\n", j + 1);
        printf("  Promedio: %.2f\n", promedio_materia);
        printf("  Nota máxima: %.1f\n", max_materia[j]);
        printf("  Nota mínima: %.1f\n", min_materia[j]);
        printf("  Aprobados: %d\n", aprobados_materia[j]);
        printf("  Reprobados: %d\n", reprobados_materia[j]);
        printf("  Porcentaje de aprobación: %.1f%%\n", 
               (float)aprobados_materia[j] / num_estudiantes * 100);
    }

    return 0;
}