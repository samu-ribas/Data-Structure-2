/*
    6) Apresente um programa que remove o menor nó de uma árvore binária de pesquisa.

    6) Present a program that removes the smallest node from a binary search tree.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

void inserir(Node **p, int key)
{
    Node *aux = NULL;
    aux = *p;
    while(aux)
    {
        if(key<aux->data)
            p = &(aux->left);
        else
            p = &(aux->right);
        aux = *p;
    }
    aux = (Node *)malloc(sizeof(Node));
    if(aux){
        aux->data = key;
        aux->left = aux->right = NULL;
        *p = aux;
    }
}

void travessia(Node *p)
{
    if(p){
        printf("%d\n", p->data);
        travessia(p->left);
        travessia(p->right);
    }
}

Node **search_small(Node **raiz){
    if(!*raiz) return NULL; // árvore vazia

    if((*raiz)->left)   // ainda há filho a esquerda
        return search_small(&((*raiz)->left)); // raiz aponta para o menor nó
    return raiz ;
}

void remover_menor(Node **p)
{
    Node **aux = search_small(p);
    if (!aux) //nda a remover
        return;

    Node *menor = *aux;
    *aux = menor->right; // substitui pelo filho direito
    free(menor);
    menor = NULL;
}

int main()
{
    Node *root = NULL;
    inserir(&root, 5);
    inserir(&root, 3);
    inserir(&root, 7);
    inserir(&root, 1);
    inserir(&root, 2);
    inserir(&root, 4);
    inserir(&root, 6);
    inserir(&root, 8);
    printf("Arvore antes da remocao do menor no:\n");
    travessia(root);
    remover_menor(&root);
    printf("Arvore apos a remocao do menor no:\n");
    travessia(root);




    return 0;
}