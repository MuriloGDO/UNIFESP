#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int cmp(char* A, char* B, char* comp){
    int i = 0;
    for(int j = 0; j < strlen(comp); j++){
        if(A[i] == comp[j] && B[i] == comp[j]){
            i++;
            j = 0;
        }
        if(A[i] == comp[j] && B[i] != comp[j]){
            return -1;
        }
        if(A[i] != comp[j] && B[i] == comp[j]){
            return 1;
        }
    }
    return 0;
}
 
int verifica(char *arr, char* comp, int QuantPalavra){
    int j = 0, k = 0, cont2 = 0;
    for(int i = 0; i < strlen(comp); i++){
        if(arr[k] == comp[0]){
            i = 0;
            k++;
        }
        if(arr[k] == comp[i]){
            i = 0;
            k++;
        }
        if(k == strlen(arr)){
            cont2++;
            return 1;
        }
    }
    return 0;
}
 
void heapify(char *arr[], int n, int i, char* comp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && cmp(arr[left], arr[largest], comp) > 0)
        largest = left;
 
    if (right < n && cmp(arr[right], arr[largest], comp) > 0)
        largest = right;
 
    if (largest != i) {
        char *temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, comp);
    }
}
 
void heapSort(char *arr[], int n, char* comp) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp);
 
    for (int i = n - 1; i >= 0; i--) {
        char *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, comp);
    }
}
 
int main() {
    char **arr;
    char *comp;
    int QuantPalavra, QuantLetra;
 
    scanf("%i", &QuantPalavra);
    scanf("%i", &QuantLetra);
 
    comp = (char*)malloc(QuantLetra*sizeof(char));
    scanf("%s", comp);
 
    arr = malloc(QuantPalavra*sizeof(char*));
    for(int i = 0; i < QuantPalavra; i++){
        arr[i] = malloc(100*sizeof(char));
    }
 
    for(int i = 0; i < QuantPalavra; i++){
        scanf("%s", arr[i]);
    }
 
    for(int i = 0; i < QuantPalavra; i++){
        if(verifica(arr[i], comp, QuantPalavra) == 0){
            printf("A palavra %s eh invalida", arr[i]);
            return 0;
        }
    }
 
    heapSort(arr, QuantPalavra, comp);
 
    for (int i = 0; i < QuantPalavra; i++){
        if(i+1 == QuantPalavra){
            printf("%s", arr[i]);
        }
        else{
            printf("%s ", arr[i]);
        }
    }
    free(comp);
    for(int i = 0; i < QuantPalavra; i++){
        free(arr[i]);
    }
}