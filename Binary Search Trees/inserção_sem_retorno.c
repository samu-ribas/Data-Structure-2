#include<stdio.h>
#include<stdlib.h>


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv *alocar(int k){
    NoArv *novo = NULL;
    novo = (NoArv *)malloc(sizeof(NoArv));
    if(novo){
        novo->valor = k;
        novo->direita = novo->esquerda = NULL;
    }
    return novo;
}

void inserir_versao_2(NoArv **raiz, int num){
    if(!*raiz){
        *raiz = alocar(num);
        if(!*raiz)
            printf("Erro no malloc\n");
    }else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&(*raiz)->esquerda, num);
        else
            inserir_versao_2(&(*raiz)->direita, num);
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){ //imprime em ordem crescente
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

void liberar_arvore(NoArv *raiz) {
    if (!raiz) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int main(){

    NoArv *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            inserir_versao_2(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);
    liberar_arvore(raiz);
    return 0;
}