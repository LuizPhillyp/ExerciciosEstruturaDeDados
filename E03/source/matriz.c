#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{

    int linhas;
    int colunas;
    int ** matriz;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){

    Matriz* matriz_retorno = (Matriz*) malloc(sizeof(Matriz));

    matriz_retorno -> matriz = (int**) malloc(nlinhas * sizeof(int*));

    

    for (int i = 0; i < nlinhas; i++){

        matriz_retorno -> matriz[i] = (int*) malloc(ncolunas * sizeof(int));  
    }

    matriz_retorno -> linhas = nlinhas;
    matriz_retorno -> colunas = ncolunas;


    return matriz_retorno;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat -> matriz[linha][coluna] = elem;
}

void imprimeMatriz(Matriz* mat){

    int nlinhas = mat -> linhas;
    int ncolunas = mat -> colunas;
    int ** matriz = mat -> matriz;

    printf("[");
    for (int i = 0; i < nlinhas; i++){
        
        if (i > 0)
            printf(" [");
        else
            printf("[");
        

        for(int j = 0; j < ncolunas; j++){

            printf("%d", matriz[i][j]);

            if(j < ncolunas-1)
                printf(", ");
        }

        if (i < nlinhas - 1)
            printf("]\n");
        else
            printf("]");
    }
    printf("]");
}

void destroiMatriz(Matriz* mat){

    int nlinhas = mat -> linhas;
    int ** matriz = mat -> matriz;

    for (int i = 0; i < nlinhas; i++){
        free(matriz[i]);  
    }

    free(matriz);
    free(mat);
}