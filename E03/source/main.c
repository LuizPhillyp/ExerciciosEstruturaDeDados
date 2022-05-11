#include <stdio.h>
#include "matriz.h"

int main(){

    Matriz* minhaMatriz = inicializaMatriz(5, 5);

    for (int i = 0 ; i < 5; i++){
        for(int j = 0; j < 5; j++){

            modificaElemento(minhaMatriz, i, j, i * 5 +j);
        }
    }

    printf("Matriz01 -> %d X %d", recuperaNLinhas(minhaMatriz), recuperaNColunas(minhaMatriz));
    printf("\n");

    imprimeMatriz(minhaMatriz);
    printf("\n");

    printf("\n");
    printf("elemento [3][3] = %d", recuperaElemento(minhaMatriz, 3, 3));
    printf("\n");

    Matriz* minhaMatriz2 = inicializaMatriz(5, 5);

    for (int i = 0 ; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (i == j)
                modificaElemento(minhaMatriz2, i, j, 10);
            else
                modificaElemento(minhaMatriz2, i, j, 0);
        }
    }

    printf("\n");
    printf("Matriz02 -> %d X %d", recuperaNLinhas(minhaMatriz2), recuperaNColunas(minhaMatriz2));
    printf("\n");

    imprimeMatriz(minhaMatriz2);
    printf("\n");

    printf("\n");
    printf("elemento [3][3] = %d", recuperaElemento(minhaMatriz2, 1, 1));
    printf("\n");

    destroiMatriz(minhaMatriz2); 
    destroiMatriz(minhaMatriz);

    return 0;
}