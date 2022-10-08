#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Pilha{

    int topo;
    int capacidade;
    int *vetorPilha;
};

void CriarPilha(struct Pilha *pilha, int capacidade){
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    pilha->vetorPilha = (int*) malloc(sizeof(int) * capacidade);
}

bool PilhaCheia(struct Pilha *pilha){
    if (pilha->topo == pilha->capacidade-1){
        return true;
    }
    else{
        return false;
    }   
}

bool PilhaVazia(struct Pilha *pilha){
    if (pilha->topo == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Empilha(struct Pilha *pilha, int numero){
    if (PilhaCheia(pilha))
    {
        printf("A pilha está cheia");
    }
    else
    {
        pilha->topo++;
        pilha->vetorPilha[pilha->topo] = numero;
        printf("Elemento %d adicionado na pilha\n", pilha->vetorPilha[pilha->topo]);
    }   
}

void Desempilha(struct Pilha *pilha, int elementos){
    for (int i = 0; i < elementos; i++)
    {
        if (PilhaVazia(pilha))
        {
            printf("A pilha está vazia");
            break;
        }
        else
        {
            printf("Elemento %d removido da pilha\n", pilha->vetorPilha[pilha->topo]);
            pilha->topo--;
        }
    }   
}

void MostrarPilha(struct Pilha *pilha){
    for (int i = 0; i <= pilha->topo; i++)
    {
        printf("%d ", pilha->vetorPilha[i]);
    }
    
}

int main(){
    struct Pilha p1;
    CriarPilha(&p1, 5);
    Empilha(&p1, 1);
    Empilha(&p1, 2);
    Empilha(&p1, 3);
    Empilha(&p1, 4);
    Empilha(&p1, 5);
    Desempilha(&p1, 3);
    Empilha(&p1, 8);
    MostrarPilha(&p1);
    return 0;
}

