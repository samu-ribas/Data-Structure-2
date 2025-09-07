#include<stdio.h>
/*
        4) Apresente uma função que recebe o ponteiro para um nó de 
        uma árvore binária de pesquisa e devolve 1 se o nó for folha ou
        zero caso contrário. A entrada será um ponteiro para um nó de uma
        árvore binária de pesquisa. Lembre que uma árvore pode ser vazia.
        Apresente a struct.

        4) Present a function that receives a pointer to a node of a binary 
        search tree and returns 1 if the node is a leaf or
        zero otherwise. The input will be a pointer to a node of a binary search tree.
        Remember that a tree can be empty. Present the struct.
*/
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

int check_node(Node *p){
    if(!p) return 0;

    if(!p->right && !p->left)
        return 1;
    return 0;
}