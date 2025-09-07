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

    Remove ABP (Binary Search Tree)
    1 - Search for the key to be removed
    Tip: Search for the key's pointer pointer, as this will facilitate
    the necessary changes to the ABP. In other words, we will pass the tree
    (i.e., the pointer) by reference, rather than by value, since
    we intend to change the values ​​of the tree fields.
    2 - Returns the pointer pointer (p) to a tree or subtree given the
    pointer pointer to the subtree and a search key (k). p must
    be such that k = (*p) -> key. Or, return NULL if the condition cannot be satisfied.
*/
/// fazer a busca do subistituo e a remoção 
 ///search for the substitute and remove it
NoABP **searchppRec(NoABP **raiz, int k){
    // suposição: raiz nunca é nulo, advem de um &
    // assumption: root is never null, it comes from a &
    if(!*raiz) return NULL;

    if((*raiz)->chave == k) return raiz;

    if((*raiz)->chave > k) 
        return searchppRec(&((*raiz)->esquerda), k);
    else
        return searchppRec(&((*raiz)->direita), k);   
}
