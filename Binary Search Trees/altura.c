#include<stdio.h>
#include<stdlib.h>


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

void inserir_versao_3(NoArv **p, int num){
    NoArv *aux = *p;
    while(aux){
        if(num < aux->valor)
            p = &aux->esquerda;
        else 
            p = &aux->direita;
        aux = *p;
    }
    aux = (NoArv *)malloc(sizeof(NoArv));
    aux->valor = num;
    aux->direita = aux->esquerda = NULL;
    *p = aux;
}

NoArv *busca_interativa(NoArv *p, int num)
{
    while(p){
        if(num < p->valor)
            p = p->esquerda;
        else if(num > p->valor)
            p = p->direita;
        else 
            return p;
    }
    return NULL;
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

int altura(NoArv *raiz){
    if(!raiz){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

void liberar_arvore(NoArv *raiz) {
    if (!raiz) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3- Busca\n\t4- Altura\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3: 
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            busca = busca_interativa(raiz, valor);
            if(busca)
                printf("Valor %d encontrado!", busca->valor);
            else
                printf("Valor nao encontrado!");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);
    liberar_arvore(raiz);
    return 0;
}