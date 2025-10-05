#include <stdio.h>

int main() {
    int ID, stock, añadirProducto;
    int numVenta;
    stock = 0;
    char opcion;
    float precioUnitario, precioTotal, ganancia;
    precioUnitario = 3.50; 
    ganancia = 0;
    
    do {
        printf("Ingresar los datos del inventario\n");
        printf("Ingrese el ID del producto que desea registrar: ");
        scanf("%d", &ID);
                
        if (ID == 135) {
            printf("La cantidad del producto 135 en stock es: %d\n", stock);
            printf("Ingrese la cantidad de producto que desea añadir al stock: ");
            scanf("%d", &añadirProducto);
            
            while (añadirProducto < 0) {
                printf("Error: no se pueden ingresar datos negativos: ");
                scanf("%d", &añadirProducto);
            }
            stock = stock + añadirProducto;
            printf("Stock actualizado: %d unidades\n", stock);
        } else {
            printf("El producto con el ID: %d no existe\n", ID);
        }

        
        while (getchar() != '\n');
        
        do {
            if (stock > 0) {
                printf("\nVENTA\n");
                printf("Stock disponible: %d unidades\n", stock);
                printf("Ingrese la cantidad de producto que desea vender: ");
                scanf("%d", &numVenta);
                
                while (numVenta > stock || numVenta < 0) {
                    if (numVenta > stock) {
                        printf("Stock insuficiente\n");
                    } else {
                        printf("No se puede vender cantidad negativa\n");
                    }
                    printf("La cantidad de producto en stock es: %d\n", stock);
                    printf("Ingrese una cantidad válida: ");
                    scanf("%d", &numVenta);
                }
                
                precioTotal = precioUnitario * numVenta;
                stock = stock - numVenta; 
                ganancia = ganancia + precioTotal;
                
                printf("El precio por producto es: %.2f $\n", precioUnitario);
                printf("El precio total de su compra es: %.2f $\n", precioTotal);
                printf("Stock restante: %d unidades\n", stock);
                printf("Ganancias acumuladas: %.2f $\n", ganancia);
            } else {
                printf("No hay stock disponible para vender\n");
                break;
            }
            
            while (getchar() != '\n');
            
            printf("¿Desea hacer más ventas? (S/N): ");
            scanf("%c", &opcion);
            
        } while(opcion == 'S' || opcion == 's');
    
        while (getchar() != '\n');
        
        printf("¿Desea continuar en el sistema? (S/N): ");
        scanf("%c", &opcion);
        
    } while(opcion == 'S' || opcion == 's');

    printf("Salió del sistema\n");
    printf("Ganancias totales: %.2f $\n", ganancia);
    
    return 0;
}