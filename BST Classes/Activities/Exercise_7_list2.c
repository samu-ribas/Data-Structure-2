/*
    7) Apresente um programa que faz uma busca em uma árvore binária.
    Note que a árvore não necessariamente é de pesquisa.

    7) Present a program that performs a search in a binary tree.
    Note that the tree is not necessarily a search tree.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

static Node *create_node(int v)
{
    Node *n = malloc(sizeof(Node));
    if(!n) return NULL;
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

/* 
    monta manualmente uma árvore qualquer exemplo 
     estrutura criada:
        1
       / \
      2   3
     / \
    4   5
*/
void build_arbitrary_tree_ab(Node **root)
{
    *root = create_node(1);
    if(!*root) return;
    (*root)->left  = create_node(2); 
    (*root)->right = create_node(3); 
    (*root)->left->left  = create_node(4);
    (*root)->left->right = create_node(5);
}
Node *busca(Node *root, int key)
{
    if (!root) return NULL;
    if (root->data == key) return root;

    Node *r = busca(root->left, key);
    if (r) return r;
    return busca(root->right, key);
}


void remover_tudo(Node **p)
{
    if(*p){
        remover_tudo(&((*p)->left));
        remover_tudo(&((*p)->right));
        free(*p);
        *p = NULL;
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


int main()
{
    Node *root = NULL;

    // monta árvore arbitrária 
    build_arbitrary_tree_ab(&root);

    // busca exemplos
    int chave = 5;
    Node *res = busca(root, chave);
    if (res)
        printf("Chave %d encontrada (endereco %p)\n", res->data, res);
    else
        printf("Chave %d nao encontrada\n", chave);

    chave = 42;
    res = busca(root, chave);
    if (res)
        printf("Chave %d encontrada (endereco %p)\n", res->data, res);
    else
        printf("Chave %d nao encontrada\n", chave);
    travessia(root);
    remover_tudo(&root);
    printf("-------------\n");
    travessia(root);
    return 0;
}
