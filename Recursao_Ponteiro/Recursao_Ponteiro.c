#include<stdio.h>
int fat(int n){
    if (n == 1)
    {
        return 1;
    }
    return n * fat(n - 1);
}

int main(){
    int n,*ponteiroN, copiaN;
    printf("Digite um numero: ");
    scanf("%d", &n);
    ponteiroN = &n;
    copiaN = n;
    printf("N = %d\n", n);
    printf("Valor PonteiroN =  %d\n", *ponteiroN);
    printf("Valor Copia N = %d\n\n", copiaN);
    n = 4;
    printf("N =  %d\n", n);
    printf("Valor PonteiroN =  %d\n", *ponteiroN);
    printf("Valor Copia N = %d\n\n", copiaN);
    printf("Fatorial de %d = %d\n", n, fat(n));
    return 0;
}