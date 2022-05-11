#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"



// Implementacao usando double-pointer
struct matriz{
    
    int linhas;
    int colunas;
    int ** matriz;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){

    //checagem de condicoes
    if (nlinhas <= 0 || ncolunas <=0){
        printf("\n\n --ERRO: Inicializacao. O numero de linhas ou colunas da matriz deve ser um numero maior que zero \n\n");
        exit(-1);
    }

    // Alocacao do objeto "Matriz"
    Matriz* matriz_retorno = (Matriz*) malloc(sizeof(Matriz));

    // Alocacao dos elementos da matriz (nesse caso, usando double-pointer)
    matriz_retorno -> matriz = (int**) malloc(nlinhas * sizeof(int*));

    for (int i = 0; i < nlinhas; i++){

        matriz_retorno -> matriz[i] = (int*) malloc(ncolunas * sizeof(int));  
    }

    // Inicializacao dos outros valores
    matriz_retorno -> linhas = nlinhas;
    matriz_retorno -> colunas = ncolunas;


    return matriz_retorno;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){

    if(!mat){
        printf("\n\n --ERRO: Nao foi possivel acessar o objero Matriz \n\n");
        exit(-1);
    }

    if ((linha < 0 || linha >= (mat -> linhas)) || (coluna < 0 || coluna >= (mat -> colunas))){
        printf("\n\n --ERRO: Modificacao. Tentativa de modificacao fora dos limites da matriz \n\n");
        exit(-1);
    }

    mat -> matriz[linha][coluna] = elem;
}


int recuperaElemento(Matriz* mat, int linha, int coluna){

    
    if(!mat){
        printf("\n\n --ERRO: Nao foi possivel acessar o objero Matriz \n\n");
        exit(-1);
    }

    if ((linha < 0 || linha >= (mat -> linhas)) || (coluna < 0 || coluna >= (mat -> colunas))){
        printf("\n\n --ERRO: Acesso. Tentativa de acesso fora dos limites da matriz \n\n");
        exit(-1);
    }

    return mat -> matriz[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    
    if(!mat){ 
        printf("\n\n --ERRO: Nao foi possivel acessar o objero Matriz \n\n");
        exit(-1);
    }

    return mat -> colunas;
}

    
int recuperaNLinhas (Matriz* mat){

    if(!mat){ 
        printf("\n\n --ERRO: Nao foi possivel acessar o objero Matriz \n\n");
        exit(-1);
    }

    return mat -> linhas;

}

Matriz* transposta (Matriz* mat){

}


void imprimeMatriz(Matriz* mat){

    if(!mat){
        printf("\n\n --ERRO: Nao foi possivel acessar o objero Matriz \n\n");
        exit(-1);
    }

    int nlinhas = mat -> linhas;
    int ncolunas = mat -> colunas;
    int ** matriz = mat -> matriz;

    for (int i = 0; i < nlinhas; i++){
        
        // (1), (2) e (3) Tratam da formatacao da saida

        //---(1)
        if (i > 0)
            printf(" [");
        else
            printf("[[");
        

        for(int j = 0; j < ncolunas; j++){
            
            //impressao dos inteiros na matriz
            printf("%d", matriz[i][j]);

            // ---(2)
            if(j < ncolunas-1)
                printf(", ");
        }

        // ---(3)
        if (i < nlinhas - 1)
            printf("]\n");
        else
            printf("]]");
    }
}

void destroiMatriz(Matriz* mat){

    if(!mat){
        printf("\n\n --ERRO: Nao foi possivel acessar o objero Matriz \n\n");
        exit(-1);
    }

    // copiando em uma variavel local para melhor manipulacao
    int nlinhas = mat -> linhas;
    int ** matriz = mat -> matriz;

    // liberacao de memoria na ordem inversa de alocacao
    for (int i = 0; i < nlinhas; i++){
        free(matriz[i]);  
    }
    free(matriz);
    free(mat);
}