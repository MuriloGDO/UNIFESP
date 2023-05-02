#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* TransformaString(char* A){
    for(int i = 0; i < strlen(A); i++){
        if(A[i] >= 65 && A[i] <= 90){
            A[i] = A[i] + 32;
        }
    }
    return A;
}

char* TransformaChave(char* chave){
    for(int i = strlen(chave); i >= 0; i--){
        chave[i+1] = chave[i];
    }
    chave[0] = ' ';

    return chave;
}

int Cmp(char a, char* chave){
    for(int i = 0; i < strlen(chave); i++){
        if(a == chave[i]){
            return i;
        }
    }
}

char** CountingSort(char** A, int k, int d, int QuantidadeDeLetras, int QuantidadeDePalavras, char* Chave){
    char** B;
    int* C;
    int posicao, cposicao;
    C = malloc(k*sizeof(int));
    B = malloc(QuantidadeDePalavras*sizeof(char*));
    for(int i = 0; i < QuantidadeDePalavras; i++){
        B[i] = malloc(QuantidadeDeLetras*sizeof(char));
    }

    for(int i = 0; i < k; i++){
        C[i] = 0;
    }
    for(int j = 1; j < QuantidadeDePalavras; j++){
        posicao = Cmp(A[j][d], Chave);
        C[posicao] = C[posicao] + 1;
    }
    printf("%i", C[0]);
    for(int i = 1; i < k; i++){
        C[i] = C[i] + C[i-1];
        printf(" %i", C[i]);
    }
    for(int j = (QuantidadeDePalavras-1); j > 0; j--){
        posicao = Cmp(A[j][d], Chave);
        cposicao = C[posicao];
        B[cposicao] = A[j];
        C[posicao] = C[posicao] - 1;
    }
    return B;

}

char** RadixSort(char** A, int k, int d, int QuantidadeDeLetras, int QuantidadeDePalavras, char* Chave){
    for(int n = d; n >= 0; n--){
        A = CountingSort(A, k, n, QuantidadeDeLetras, QuantidadeDePalavras, Chave);
        printf("\n");
    }
    return A;
}


int main(void){
    char** A;
    char** B;
    char* chave;
    int k = 27, d = 0, QuantidadeDeLetras, QuantidadeDePalavras;

    scanf("%i", &QuantidadeDePalavras);
    QuantidadeDePalavras++;


    chave = malloc(k*sizeof(char));
    A = malloc(QuantidadeDePalavras*sizeof(char*));
    B = malloc(QuantidadeDePalavras*sizeof(char*));
    for(int i = 0; i < QuantidadeDePalavras; i++){
        A[i] = malloc(20*sizeof(char));
        B[i] = malloc(20*sizeof(char));
    }


    scanf("%s", chave);
    chave = TransformaChave(chave);

    for(int i = 1; i < QuantidadeDePalavras; i++){
        scanf("%s", A[i]);
    }

    for(int i = 1; i < QuantidadeDePalavras; i++){
        A[i] = TransformaString(A[i]);
    }

    for(int i = 1; i < QuantidadeDePalavras; i++){
        printf("%s.\n", A[i]);
    }

    for(int i = 1; i < QuantidadeDePalavras; i++){
        if(d < strlen(A[i])){
            d = strlen(A[i]);
        }
    }
    d = d - 1;
    printf("%i\n", d+1);
    
    for(int i = 1; i < QuantidadeDePalavras; i++){
        int len = strlen(A[i]);
        memset(A[i]+len, ' ', 20-len);
        A[i][20] = '\0';
    }

    B = RadixSort(A, k, d, QuantidadeDeLetras, QuantidadeDePalavras, chave);
    
    for(int i = 1; i < QuantidadeDePalavras; i++){
        printf("%s\n", B[i]);
    }
    return 0;
}