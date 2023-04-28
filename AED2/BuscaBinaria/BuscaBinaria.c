#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int arr[], int menor, int maior, int numeroBuscado, int QuantDeRecur) {
    if (maior >= menor) {
        int meio = menor + (maior - menor) / 2;
 
        if (arr[meio] == numeroBuscado)
            return QuantDeRecur;
 
        if (arr[meio] > numeroBuscado)
            return BuscaBinaria(arr, menor, meio - 1, numeroBuscado, QuantDeRecur + 1);
 
        return BuscaBinaria(arr, meio + 1, maior, numeroBuscado, QuantDeRecur + 1);
    }
 
    return -1;
}
 
int main(void) {
    int *arr, num, numeroBuscado, QuantDeRecur=0, tamanhoDeArr;
    scanf("%i", &num);
    arr = malloc(num * sizeof(int));
    for(int i=0; i<num; i++){
        scanf("%i", &arr[i]);
    }
    scanf("%i", &numeroBuscado);
    if(BuscaBinaria(arr, 0, num-1, numeroBuscado, QuantDeRecur) == -1){
        printf("%i nao foi encontrado", numeroBuscado);
    }
    else{
        printf("%i", BuscaBinaria(arr, 0, num-1, numeroBuscado, QuantDeRecur));
    }
    free(arr);
    return 0;
}