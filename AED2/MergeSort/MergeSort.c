#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de cada nó da lista
typedef struct Lista{
    int chave;
    struct Lista* prox;
} Lista;

// Função para intercalar duas listas ordenadas
Lista* merge(Lista* left, Lista* right) {
    // Caso base: se uma das listas é nula, retorna a outra lista
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    Lista* result;

    // Comparando os nós das duas listas e intercalando-os
    if (left->chave <= right->chave) {
        result = left;
        result->prox = merge(left->prox, right);
    }
    else {
        result = right;
        result->prox = merge(left, right->prox);
    }

    return result;
}

// Função para dividir a lista em duas partes
void DividirListaNoMeio(Lista* lista, Lista** left, Lista** right) {
    Lista* fast;
    Lista* lento;
    lento = lista;
    fast = lista->prox;

    // Avançando o ponteiro fast duas vezes mais rápido que o ponteiro lento
    while (fast != NULL && fast->prox != NULL) {
        fast = fast->prox;
        if (fast != NULL && fast->prox != NULL) {
            lento = lento->prox;
            fast = fast->prox;
        }
    }

    // O ponteiro lento aponta para o nó do meio, então dividimos a lista em dois
    *left = lista;
    *right = lento->prox;
    lento->prox = NULL;
}

// Função principal para ordenar a lista utilizando o algoritmo de merge sort
void mergeSort(Lista** lista, int* cont, int cont2) {
    Lista* atual = *lista;
    Lista* left;
    Lista* right;

    if(*cont < cont2){
        *cont = cont2;
    }

    // Caso base: se a lista for nula ou tiver apenas um nó, já está ordenada
    if (atual == NULL || atual->prox == NULL) {
        return;
    }

    // Dividindo a lista em duas partes
    DividirListaNoMeio(atual, &left, &right);
    
    // *cont = *cont + 1; // contando as quantidades de recursão
    // Chamando mergeSort() recursivamente para ordenar as duas metades
    mergeSort(&left, cont, -1);
    mergeSort(&right, cont, cont2+1);
    
    // *cont = *cont + 1;
    // Intercalando as duas metades ordenadas usando merge()
    *lista = merge(left, right);

    // if(*cont < cont2){
    //     *cont = cont2;
    // }

    // *cont = *cont + 1;

}

// Função para adicionar um nó ao final da lista
void addLista(Lista** lista, int chave) {
    Lista* newLista = (Lista*)malloc(sizeof(Lista)); // alocando memória para o novo nó
    newLista->chave = chave;
    newLista->prox = NULL; // o novo nó será o último da lista, então seu ponteiro prox será nulo

    if (*lista == NULL) { // se a lista estiver vazia, o novo nó será o primeiro
        *lista = newLista;
        return;
    }

    Lista* lastLista = *lista;
    while (lastLista->prox != NULL) { // percorrendo a lista até o último nó
        lastLista = lastLista->prox;
    }

    lastLista->prox = newLista; // o último nó será conectado ao novo nó
}

// Função para imprimir a lista
void printList(Lista* Lista) {
    while (Lista != NULL) {
        printf("%d ", Lista->chave);
        Lista = Lista->prox;
    }
}

// Função principal
int main() {
    Lista* lista = NULL; // criando uma lista vazia
    int NumDeChave, chave, contador = -1, contador2 = 0; 

    // armazenando os dados
    scanf("%i", &NumDeChave);
    for (int i = 0; i < NumDeChave; i++){
        scanf("%i", &chave);
        addLista(&lista, chave);
    }

    // ordenando a lista
    mergeSort(&lista, &contador, contador2);

    // imprimindo a lista
    printList(lista);

    // imprimindo a quantidade de recursão
    printf("\n%i", contador);

    return 0;
}
