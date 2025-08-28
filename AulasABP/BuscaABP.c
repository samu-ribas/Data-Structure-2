#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *direita, *esquerda;
}NoABP;

/*
    Recebe uma chave de busca k e uma ABP
    Devolve um ponteiro raiz tal que raiz->chave == k ou
    devolve NULL caso tal condição não possa ser satisfeita,
    isto é, não exista nó contendo a chave de valor k. 
*/

NoABP *buscaABP(NoABP *raiz, int k){
    while(raiz){
        if(k == raiz->chave)
            return raiz;
        if(k < raiz->chave)
            raiz = raiz->esquerda;
        else 
            raiz = raiz->direita;
    }
    return NULL;
}

// versão recursiva para busca ABP
/*
    Definição recursiva de uma AB num contexto de estrutura de dados
    - uma árvore binária é um ponteiro, caso base (raiz = NULL) >> árvore vazia
    - possibilidade 2, (raiz!=null), então meu ponteiro raiz certamente aponta para um nó, esse nó contêm duas ABs
*/
NoABP *buscaABPrec(NoABP *raiz, int k){
    if(raiz){
        if(raiz->chave == k)
            return raiz;
        if(k < raiz->chave)
            return buscaABPrec(raiz->esquerda, k);
        else
            return buscaABPrec(raiz->direita, k);
    }
    return NULL;
}

/* 
    recebe uma abp e uma chave k a ser inserida nesta abp
    devolve um ponteiro raiz tal que raiz->chave == k ou devolve NULL do nó falhe.
*/
NoABP *insereABPrec(NoABP **raiz, int k){
    if(!*raiz){
        NoABP *novo = (NoABP *)malloc(sizeof(NoABP));
        if(!novo)
            return NULL;
        novo->chave = k;
        novo->esquerda = novo->direita = NULL;
        *raiz = novo;
        return novo;
    }
    //assumindo k único
    if ( k < (*raiz)->chave)
        return insereABPrec (&((*raiz)->esquerda), k);
    else
        return insereABPrec (&((*raiz)->direita), k);
}