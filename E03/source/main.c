#include <stdio.h>
#include "matriz.h"

int main(){

    Matriz* minhaMatriz = inicializaMatriz(5, 5);

    for (int i = 0 ; i < 5; i++){
        for(int j = 0; j < 5; j++){
           modificaElemento(minhaMatriz, i, j, i+j);
        }
    }

   imprimeMatriz(minhaMatriz);
   printf("\n");

   destroiMatriz(minhaMatriz);

    return 0;
}