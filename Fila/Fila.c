#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Fila{
    int primeiro;
    int ultimo;
    int *vetorFila;
    int capacidade;
};

void criaFila(struct Fila *f, int capacidade){
    f->capacidade = capacidade;
    f->primeiro = capacidade - 1;
    f->ultimo = capacidade;
    f->vetorFila = (int*) malloc (capacidade * sizeof(int));
}

bool FilaVazia(struct Fila *f){
    if (f->capacidade == f->ultimo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FilaCheia(struct Fila *f){
    if (f->ultimo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    //f->ultimo == 0 ? true : false;
}

void OrganizaFila(struct Fila *f){
    for (int i = f->primeiro; i > f->ultimo ; i--)
    {
        f->vetorFila[i] = f->vetorFila[i-1];
    }
    f->ultimo++;
}
void Enfileira(struct Fila *f, int n){
    if (FilaCheia(f))
    {
        printf("A fila está cheia! \n");
    }
    else
    {
        f->ultimo--;
        f->vetorFila[f->ultimo] = n;
    }
    
}

void Desenfileira(struct Fila *f){
    if (FilaVazia(f))
    {
        printf("A fila está vazia!\n");
    }
    else
    {
        printf("Elemento %d removido\n", f->vetorFila[f->primeiro]);
        OrganizaFila(f);
    }
    
}

void MostrarFila(struct Fila *f){
    for (int i = f->ultimo; i < f->capacidade; i++)
    {
        printf("%d ", f->vetorFila[i]);
    }
    
}

int main(){
    struct Fila f1;
    criaFila(&f1, 5);
    Enfileira(&f1, 1);
    Enfileira(&f1, 2);
    Enfileira(&f1, 3);
    Enfileira(&f1, 4);
    Enfileira(&f1, 5);
    Desenfileira(&f1);
    Desenfileira(&f1);
    Enfileira(&f1, 10);
    Enfileira(&f1, 11);
    Desenfileira(&f1);
    Desenfileira(&f1);
    Desenfileira(&f1);
    Desenfileira(&f1);
    MostrarFila(&f1);
}