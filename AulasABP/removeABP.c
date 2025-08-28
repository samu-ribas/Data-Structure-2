#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *direita, *esquerda;
}NoABP;

/*
    remove ABP
    1 - buscar pela chave a ser removida
    dica: busque pelo ponteiro de ponteiro da chave pois isso facilitará
    as alterações necessárias à ABP. Em outras palavras, passaremos a árvore
    (isto é, o ponteiro) por referência, em vez de por valor posto que 
    pretendemos alterar valores dos campos árvores
    2 - devolve o ponteiro de ponteiro (p) para um árvore ou subárvore dados o 
    ponteiro de ponteiro para a sub-árvore e uma chave de pesquisa (k). p deve
    ser tal que k = (*p)->chave. Ou devolve NULL tal qual condicao nao possa ser satisfeita.
*/
/// fazer a busca do subistituo e a remoção 
NoABP **buscappRec(NoABP **raiz, int k){
    // suposição: raiz nunca é nulo, advem de um &
    if(!*raiz) return NULL;

    if((*raiz)->chave == k) return raiz;

    if((*raiz)->chave > k) 
        return buscappRec(&((*raiz)->esquerda), k);
    else
        return buscappRec(&((*raiz)->direita), k);   
}

NoABP *remove(NoABP **raiz)
{
    
}

NoABP **busca_subs(NoABP **raiz, int k){
    
}