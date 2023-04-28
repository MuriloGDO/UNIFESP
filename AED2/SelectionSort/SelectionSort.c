#include <stdio.h>
#include <stdlib.h>

// Função para ordenar o vetor em ordem crescente utilizando o selection sort
void selectionSort(int *vetor, int tamanho) {
    int i, j, min, aux;
    for (i = 0; i < tamanho-1; i++) {
        min = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

int main() {
    // Lendo a quantidade de pacientes
    int n;

    scanf("%d", &n);
    
    // Alocando memória para os vetores
    int *microrganismos = malloc(n * sizeof(int));
    int *potencias = malloc(n * sizeof(int));
    
    // Lendo os valores de microrganismos e potências para cada paciente
    for (int i = 0; i < n; i++) {
        scanf("%d", &microrganismos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &potencias[i]);
    }
    
    // Ordenando o vetor
    selectionSort(potencias, n);
    selectionSort(microrganismos, n);
    
    // Verificando se as doses são suficientes para curar todos os pacientes
    int suficientes = 1;
    for (int i = 0; i < n; i++) {
        if (microrganismos[i] >= potencias[i]) {
            suficientes = 0;
            break;
        }
    }
    
    // Imprimindo o resultado
    if (suficientes) {
        printf("sim");
    } else {
        printf("nao");
    }
    
    // Liberando a memória alocada
    free(microrganismos);
    free(potencias);
    
    return 0;
}