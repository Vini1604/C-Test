#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char matricula[8];
    char nomeAluno[50];
    double *notas;

} Aluno;

void InsereNotas(Aluno *a1, int n) {
    for(int i = 0; i < n; i++){
        printf("Digite a nota P%d do Aluno: ", i + 1);
        scanf("%lf",&a1->notas[i]);
    }
}

void ImprimeNotas(double notas[], int n) {
    for (int i = 0; i < n; i++){
        printf("Nota P%d = %.2lf\n", i + 1, notas[i]);
    }
}


double CalculaMedia(double notas[], int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += notas[i];
    }
    return soma / n;
}

void CriaEspacoNotas(Aluno *a, int n){
    a->notas = (double*) malloc(n * sizeof(double));
}
int main(void) {

    int n;
    double mediaFinal;
    Aluno a1;
    printf("Digite a matricula do Aluno: ");
    gets(a1.matricula);
    printf("Digite o nome do Aluno: ");
    gets(a1.nomeAluno);
    printf("Digite a quantidade de notas a serem inseridas: ");
    scanf("%d", &n);
    CriaEspacoNotas(&a1, n);
    InsereNotas(&a1, n);
    mediaFinal = CalculaMedia(a1.notas, n);
    printf("\n\nAluno #%s:\n", a1.matricula);
    printf("Nome: %s\n", a1.nomeAluno);
    ImprimeNotas(a1.notas, n);
    printf("Media: %.2lf", mediaFinal);
}
