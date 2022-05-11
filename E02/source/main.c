#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno_st{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno_st Aluno;

char* lelinha(void);
void imprimeTurma(int n, Aluno** turma);
void imprime_aprovados(int n, Aluno** turma);
float media_turma (int n, Aluno** turma);
float calculaMedia (int n, float * valoresf);


int main(){

    int numeroDeAlunos;

    printf("Informe o numero de alunos: \n");
    scanf("%d", &numeroDeAlunos);
    printf("\n");

    Aluno** AlunosTurma = (Aluno **)malloc(numeroDeAlunos * sizeof(Aluno*));

    //inicializar a turma//

    for (int i = 0; i < numeroDeAlunos; i++)
    {
        AlunosTurma[i] = (Aluno *) malloc(sizeof(Aluno));

        printf("Aluno %d\n", i+1);
        printf("Nome: ");

        AlunosTurma[i] -> nome = lelinha();

        printf("Matricula: ");
        scanf(" %d", &(AlunosTurma[i] -> matricula));

        printf("Notas:\n");
        printf("p1 - ");
        scanf(" %f", &(AlunosTurma[i] -> p1));
        printf("p2 - ");
        scanf(" %f", &(AlunosTurma[i] -> p2));
        printf("p3 - ");
        scanf(" %f", &(AlunosTurma[i] -> p3));

        if(i < numeroDeAlunos - 1){
            printf("\n");
        }
    }

    printf("\nturma:\n");

    imprimeTurma(numeroDeAlunos, AlunosTurma);

    printf("\naprovados: \n");

    imprime_aprovados(numeroDeAlunos, AlunosTurma);

    printf("\nmedia da turma: \n");

    printf("%f", media_turma(numeroDeAlunos, AlunosTurma));

    printf("\n");

    return 0;
}
    
char* lelinha(void){

    char  linha[100]; 
    scanf(" %100[^\n]", linha);

    return strdup(linha);
}

void imprimeTurma(int n, Aluno** turma){
    for (int i = 0; i < n; i++)
    {
        printf (" - %s", turma[i] -> nome);
        printf(", %d", turma[i] -> matricula);
        
        printf(", %f", turma[i] -> p1);
        printf(", %f", turma[i] -> p2);
        printf(", %f", turma[i] -> p3);

        printf("\n");
    }
    
}

void imprime_aprovados(int n, Aluno** turma){
    for (int i = 0; i < n; i++)
    {

        float valores[3] = {turma[i] -> p1,
                            turma[i] -> p2,
                            turma[i] -> p3};

        if (calculaMedia(3, valores) >= 5.0){
        
            printf (" - %s", turma[i] -> nome);
            printf(", %d", turma[i] -> matricula);
            
            printf(", %f", turma[i] -> p1);
            printf(", %f", turma[i] -> p2);
            printf(", %f", turma[i] -> p3);

            printf("\n");

        }

    }
}

float media_turma (int n, Aluno** turma){

    float valores[n];
    

    for (int i = 0; i < n; i++)
    {
        float notasAluno[3] = { turma[i] -> p1,
                                turma[i] -> p2,
                                turma[i] -> p3 };

        valores[i] = calculaMedia(3, notasAluno);
    }
    
    return calculaMedia(n, valores);
}

float calculaMedia (int n, float * valoresf){
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += valoresf[i];
    }

    return soma/n;
}