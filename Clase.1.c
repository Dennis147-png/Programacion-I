#include <stdio.h>

int main (int argc, char *argv[]) {
    float promedio;
    promedio = 15;
    
  /*
    if (promedio>=6)
    {
        printf ("Felicitaciones, su promedio es %.2f, usted ha aprovado el semestre\n", promedio);
    } else {
        printf ("Su promedio es %.2f, lastimosamente usted no ah aporvado el semestre\n");
    }
    */
   if (promedio<=10)
   {
    if (promedio>=9)
    {
        printf ("Nota: %2.f\nApreciacion Cualitativa: Sobresaliente\n",promedio);
    }else if (promedio >= 7)
    {
        printf ("Nota: %2.f\nApreciacion Cualitativa: Muy bueno\n",promedio);
    }else if (promedio >= 6)
    {
        printf ("Nota: %2.f\nApreciacion Cualitativa: Bueno\n",promedio);
    }else if (promedio >= 3)
    {
        printf ("Nota: %2.f\nApreciacion Cualitativa: Regular\n",promedio);
    }else{
        printf("Nota: %2.f\nApreciacion Cualitativa: Insuficiente\n",promedio);
    }
   }else {
    printf ("La nota no es valida");
   }
    
}