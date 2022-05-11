// -----EXERCICIO #02------//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI  3.14159265358979323846

// #01 - Calcula a area e volume de uma esfera de raio "r"
void calc_esfera (float r, float* area, float*volume);

// #02 - Calcula as raizes "x1" e "x2 de uma equacao quadratica na forma "a * x^2 + b * x + c"
int raizes (float a, float b, float c, float* x1, float* x2);

// #03 - Retorna a quantidade de numeros pares de um vetor apontado por "vet"
int pares (int n, int* vet);

// #04 - Inverte a ordem dos elementos de um vetor apontado por "vet"
void inverte (int n, int* vet);

// #05 - Retorna o valor de uma funcao quadratica considerando um valor para a variavel "x";
double avalia (double* poli, int grau, double x);

// FUNCOES PROPRIAS

void * AlocaVetor( int n, size_t tamanho);
void LiberaVetor(void * vet);

void ImprimeVetorInt(int n, int * vet);

int main (){

    

    //#01
    float raio_esfera = 4.0f;
    float area_esfera, volume_esfera;

    calc_esfera(raio_esfera, &area_esfera, &volume_esfera);

    //printando para verificar
    printf("#01 --------------\n");
    printf("A area da esfera de raio %f = %f\n", raio_esfera, area_esfera);
    printf("O volume da esfera de raio %f = %f\n", raio_esfera, volume_esfera);

    //#02
    float a = 1, b = 2, c = 0;
    float  x1, x2;
    int retorno;

    retorno = raizes(a, b, c, &x1, &x2);

    printf("#02 --------------\n");
    printf("O retorno da funcao de raizes foi %d\n", retorno);
    printf("As raizes da equacao sao x1 = %f, x2 = %f\n", x1, x2);

    //#03
    int * vetor = (int *) AlocaVetor(10, sizeof(int));
    int numeroDepares;

    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 5;
    vetor[5] = 6;
    vetor[6] = 7;
    vetor[7] = 8;
    vetor[8] = 9;
    vetor[9] = 10;

    numeroDepares = pares(10, vetor);

    printf("#03 --------------\n");
    printf("Vetor: \n");
    ImprimeVetorInt(10, vetor);
    printf("O numero de pares no vetor eh %d\n", numeroDepares);

    //#04
    printf("#04 --------------\n");
    printf("O mesmo vetor ao contrario: \n");
    inverte(10, vetor);
    ImprimeVetorInt(10, vetor);

    //#05
    printf("#05 --------------\n");

    double * meuPolinomio = (double *) AlocaVetor(3, sizeof(double));

    meuPolinomio[0] = 1.0;
    meuPolinomio[1] = 2.0;
    meuPolinomio[2] = 3,0;

    double valorPolinomio;

    valorPolinomio = avalia(meuPolinomio, 2, 1.0);
    printf("O valor do polinomio quando x = 1.0 eh %f\n", valorPolinomio);

    LiberaVetor((double *) meuPolinomio);
    LiberaVetor((int *) vetor);


    return 0;
}

// #01
void calc_esfera (float r, float* area, float*volume){

    if (!(area && volume)){
        printf("ERRO\n");
        exit(0);
    }

    // area_esfera = 4 * pi * r^2
    *area = 4.0f * PI * r * r;

    // volume_esfera = (1/3) * (4 * pi * r^3)
    *volume = (*area) * (r/3.0f);
}

// #02
int raizes (float a, float b, float c, float* x1, float* x2){

    if (!(x1 && x2)){
        printf("ERRO\n");
        exit(0);
    }

    // Formula da eq. quadratica: x =  (-b (+|-) sqrt(delta) )/ 2 * a
    //              delta = b^2 - 4 * a * c

    float delta = (b * b) - (4.0f * a * c);

    if (delta < 0.0f)
        return 1;

    *x1 = (-(b) + sqrt(delta))/(2.0f * a);
    *x2 = (-(b) - sqrt(delta))/(2.0f * a);

    return 0;
    
}

// #03
int pares (int n, int* vet){
    if (!vet){
        printf("ERRO\n");
        exit(0);
    }

    int pares = 0;

    for (int i = 0; i < n; i++){
        if(!(vet[i] % 2))
            pares++;
    }

    return pares;
}

// #04
void inverte (int n, int* vet){

    // "i" incrementa do primeiro ateo meio
    // "j" decrementa do ultimo ate o meio

    for(int i = 0, j = n-1; i < (n/2); i++, j--){
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp; 
    }

    //naturalmente o elemento central nao se modifica
}

// #05
double avalia (double* poli, int grau, double x){

    if (!poli){
        printf("ERRO\n");
        exit(0);
    }

    //forma geral de um polinomio: a_1 * x^n + a_2 * x^(n - 1) + a_3 * x^(n - 2)...
    // onde n > 0 representa o grau, a_i sao os coeficientes (a_1 nao pode ser zero), e x a variavel

    if(grau <= 0 || poli[grau] == 0.0){
        printf("O polinomio nao possui o grau definido... \n");
        printf("...o valor retornado foi 0\n");

        return 0.0;
    }

    double value = 0.0;

    for(int i =  0; i <= grau; i++){
        value += pow(x, i) * poli[i];
    }

    return value;

}

//=====================//

void * AlocaVetor( int n, size_t tamanho){
    return malloc(n * tamanho);
}

void LiberaVetor(void * vet){
    free(vet);
}

void ImprimeVetorInt(int n, int * vet){
    printf("[");
    for ( int i =  0; i < n; i++){
        printf("%d", vet[i]);

        if(i < n-1){
            printf(", ");
        }
    }
    printf("]\n");
}