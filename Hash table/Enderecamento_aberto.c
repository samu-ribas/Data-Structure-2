#include<stdio.h>
#define m 7
/*
    Quando o número de registros a serem armazenados na tabela puder ser 
    previamente estimado, então não haverá necessidade de usar apontadores 
    para armazenar os registros.
    Existem vários métodos para armazenar N registros em uma tabela M>N,
    os quais utilizam os lugares vazios na própria tabela para resolver as colisões 
    Tais métodos são chamados endereçamento aberto(open addressing ; Knuth, 1973, p.518)
*/

void inicializa_vetor(int vet[]){
    for(int i=0 ; i<m ; i++){
        vet[i] = -1;
    }
}

int funchash(int chave){
    return chave % m;
}

void inserir_sond_linear(int chave, int vetor[]){
    int k=funchash(chave);
    while(vetor[k] != -1){
        if(k == m-1)
            k = 0;
        else
            k++;
    }
    vetor[k] = chave;
}

/*
void inserir_sond_dupla(int chave, int vetor[]){ 
    int k, i;
    for(i = 0 ; i<m ; i++){
        k = (chave + (i*i)) % m;
        if(vetor[k] == -1 || vetor[k] == chave)
            break;
    }
    assert(i<m);
    vetor[k] = chave;
}
*/

void imprimir_vetor(int vet[]){
    for(int i=0 ; i<m ; i++){
        printf("\n%d", vet[i]);
    }
}

int main()
{

    int vet[m];
    int chave;
    inicializa_vetor(vet);
    for(int i=0 ; i<5 ; i++){
        printf("Digite o valor: ");
        scanf("%d", &chave);
        inserir_sond_linear(chave, vet);
    }
    imprimir_vetor(vet);
    return 0;
}