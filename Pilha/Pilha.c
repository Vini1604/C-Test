#include<stdio.h>
#include<stdlib.h>
struct Pilha{
    int topo;
    int capacidade;
    int *vetorPilha;    
};

void CriarPilha(struct Pilha*minhaPilha, int capacidade){
    minhaPilha->topo = -1;
    minhaPilha->capacidade = capacidade;
    minhaPilha->vetorPilha = (int*) malloc(capacidade * sizeof(int));
}

void Empilha(struct Pilha* minhaPilha, int elemento){
    minhaPilha->topo++;
    minhaPilha->vetorPilha[minhaPilha->topo] = elemento;
}

int Desempilha(struct Pilha* minhaPilha){
    minhaPilha->topo--;
    return minhaPilha->vetorPilha[minhaPilha->topo];
}

int main(){
    struct Pilha p1;
    int capacidade = 4;
    CriarPilha(&p1, capacidade);
    Empilha(&p1, 1);
    Empilha(&p1, 3);
    Empilha(&p1, 5);
    Desempilha(&p1);
    Empilha(&p1, 6);
    Empilha(&p1, 7);
    for (int i = 0; i < capacidade; i++)
    {
        printf("%d ", p1.vetorPilha[i]);
    }
    return 0;
}