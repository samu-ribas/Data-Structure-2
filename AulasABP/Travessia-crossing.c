#include<stdio.h>

typedef struct noABP
{
    int data;
    struct noABP *left, *right;
}TnoABP;

/*
    In portuguese: Travessia->> Imprime todos os valores chave de uma árvore binária dada
    In english: crossing->> Print all key values ​​of a given binary tree 
*/

void preorder(TnoABP *root)
{
    if(root){
        printf("%d\n", root->data); // visitação / visitation
        preorder(root->left);
        preorder(root->right); 
    }
}

void inordem(TnoABP *root)
{
    if(root){
        preorder(root->left);
        printf("%d\n", root->data);
        preorder(root->right); 
    }
}