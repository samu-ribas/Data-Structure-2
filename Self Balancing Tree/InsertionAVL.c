#include<stdio.h>
#include<stdlib.h>
typedef struct no{
    int key, fb;
    struct no *esq, *dir;
}Nodetree;

Nodetree *alocar(int k);
int insereAVL(Nodetree **p, int k);
void rotacao_esq(Nodetree **p);
void rotacao_dir(Nodetree **p);
void rotacao_dupla(Nodetree **p);
void pre_ordem(Nodetree *p);

int main() {
    Nodetree *raiz = NULL;
    int opcao, valor;

    do {
        printf("\n--- Teste de Insercao AVL ---\n");
        printf("1. Inserir um valor\n");
        printf("2. Mostrar a arvore (Em Ordem)\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insereAVL(&raiz, valor);
                break;

            case 2:
                if (raiz) {
                    printf("\nArvore AVL (Em preordem - Chave (FB)): \n");
                    pre_ordem(raiz);
                    printf("\n");
                } else {
                    printf("A arvore esta vazia.\n");
                }
                break;

            case 3:
                printf("Encerrando o programa de testes.\n");
                // Em um código de produção, você liberaria a memória da árvore aqui
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}


Nodetree *alocar(int k){
    Nodetree *novo = NULL;
    novo = (Nodetree *)malloc(sizeof(Nodetree));
    if(novo){
        novo->key = k;
        novo->dir = novo->esq = NULL;
        novo->fb = 0;
    }
    return novo;
}

int insereAVL(Nodetree **p, int k){
    int cresceu;
    if(!*p){
        *p = alocar(k);
        if(!*p){
            printf("\nErro no malloc\n");
            exit(1);
        }
        cresceu = 1;
    }
    else if((*p)->key > k)
    {
        cresceu = insereAVL(&((*p)->esq), k);
        if(cresceu){
            switch((*p)->fb){
                // se a árvore direita era maior não há crescimento
                case 1:
                    (*p)->fb = 0;
                    cresceu = 0;
                break;

                case 0:
                    (*p)->fb = -1;
                    cresceu = 1;
                break;

                case -1: // caso da quebra
                    if((*p)->esq->fb == -1)
                    {
                        rotacao_dir(p);
                        (*p)->fb = (*p)->dir->fb = 0;
                    }
                    else
                        rotacao_dupla(p); // passa o endereço do nó pai
                    cresceu = 0;
                break;
            
            }
        }
    }
    else if((*p)->key < k)
    {
        cresceu = insereAVL(&((*p)->dir), k);
        if(cresceu){
            switch((*p)->fb){
                // se a árvore direita era maior não há crescimento
                case -1:
                    (*p)->fb = 0;
                    cresceu = 0;
                break;

                case 0:
                    (*p)->fb = 1;
                    cresceu = 1;
                break;

                case 1: // caso da quebra
                    if((*p)->dir->fb == 1)
                    {
                        rotacao_esq(p);
                        (*p)->fb = (*p)->esq->fb = 0;
                    }
                    else
                        rotacao_dupla(p);
                    cresceu = 0;
                break;
            
            }
        }
    }
    else
        cresceu = 0;
    
    return cresceu;
}

void rotacao_esq(Nodetree **p)
{
    Nodetree *aux = *p;
    *p = (*p)->dir;
    aux->dir = (*p)->esq;
    (*p)->esq = aux;
}

void rotacao_dir(Nodetree **p)
{
    Nodetree *aux = *p;
    *p = (*p)->esq;
    aux->esq = (*p)->dir;
    (*p)->dir = aux;
}

void rotacao_dupla(Nodetree **p){
    /*
    * essa rotação dupla só é valida para 'quebras" 
    * de fator de balanceamento na inserção
    * e vamos assumir que a função de inserção ja 
    * identificou que é necessario fazer uma rotação dupla
    */
    if((*p)->fb < 0){                       // verifica se o fb do pai é negativo
        rotacao_esq( &( (*p)->esq ) );      // rotaciona primeiro o filho
        rotacao_dir(p);                     // depois o pai
    }
    else{                                   // se não é negativo então é positivo
        rotacao_dir( &( (*p)->dir ) );
        rotacao_esq(p);
    }
        // Atualização dos fatores de balanceamento
    if((*p)->fb == -1)
    {
        (*p)->esq->fb = 0;
        (*p)->dir->fb = 1;
    }
    else
    {
        (*p)->dir->fb = 0;
        (*p)->esq->fb = -(*p)->fb; 
    }
    (*p)->fb = 0;
}

void pre_ordem(Nodetree *p) {
    if (p) {
        printf("%d (FB: %d) | ", p->key, p->fb);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}
