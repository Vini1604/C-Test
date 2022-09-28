#include<stdio.h>
#include<string.h>
#define qteNotas 4
struct Aluno {
    char matricula[8];
    char nomeAluno[50];
    double notas[qteNotas];

};

void InsereNotas(struct Aluno *a1) {
    for(int i = 0; i < qteNotas; i++){
        printf("Digite a nota P%d do Aluno: ", i + 1);
        scanf("%lf",&a1->notas[i]);
    }    
}

void ImprimeNotas(double notas[]) {
    for (int i = 0; i < qteNotas; i++){
        printf("Nota P%d = %.2lf\n", i + 1, notas[i]);
    }
      
}


double CalculaMedia(double notas[]) {
    double soma = 0.0;
    for (int i = 0; i < qteNotas; i++)
    {
        soma += notas[i];
    }
    return soma / qteNotas;
}
int main(void) {

    double mediaFinal;
    struct Aluno a1;
    printf("Digite a matricula do Aluno: ");
    gets(a1.matricula);
    printf("Digite o nome do Aluno: ");
    gets(a1.nomeAluno);
    InsereNotas(&a1);
    mediaFinal = CalculaMedia(a1.notas);
    printf("\n\nAluno #%s:\n", a1.matricula);
    printf("Nome: %s\n", a1.nomeAluno);
    ImprimeNotas(a1.notas);
    printf("Media: %.2lf", mediaFinal);
}