
// Tabela Hash linear com vetor
#include<stdio.h>
#define TAM 31 // 2 * quantidade de elementos = número primo mais próximo do resultado

void inicializa_zero(int vet[])
{
    for(int i = 0 ; i<TAM ; i++){
        vet[i] = 0;
    } 
}

int hash(int chave)
{
    return chave % TAM;
}

void inserir(int vet[], int valor)
{
    int id = hash(valor);
    while(vet[id] != 0){
        id = hash(id+1);
    }
    vet[id] = valor;
}

int busca(int vet[], int chave)
{
    int id = hash(chave);
    while(vet[id] != 0)
    {
        if(vet[id] == chave)
           return vet[id];
        else
           id = hash(id + 1);
    }
    return 0;
}

void imprimir(int vet[])
{
    for(int i = 0 ; i<TAM ; i++)
    {
        printf("%d = %d\n", i, vet[i]);
    }
}

int main()
{
    int vetor[TAM], opcao, valor, retorno;

    inicializa_zero(vetor);
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(vetor, valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(vetor, valor);
            if(retorno != 0)
                printf("\tValor encontrado: %d\n", retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            imprimir(vetor);
            break;
        default:
            printf("Opcao invalida!\n");
        }
        
    }while(opcao != 0);
    return 0;
   
}