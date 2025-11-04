#include<stdio.h> 
#define M 7

void inicializaVetor(int vet[]){
    for(int i = 0 ; i<M ; i++){
        vet[i] = 0;
    }
}

int inserir(int chave, int vet[])
{
    int k = chave % M;
    if(vet[k]!=0)
        return 0;
    vet[k] = chave;
    return 1;
}

int main()
{
    int vetor[M], chave, contador = 0;
    inicializaVetor(vetor);
    for(int i = 0 ; i<4 ; i++){
        printf("Digite a chave: ");
        scanf("%d", &chave);
        if(!inserir(chave, vetor))
            contador ++;
    }
    printf("\nresultado: %d", contador);
    return 0;
}