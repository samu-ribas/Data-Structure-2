#include<stdio.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;


/*
    In portuguese: Travessia->> Imprime todos os valores chave de uma árvore binária dada
    In english: crossing->> Print all key values ​​of a given binary tree 
*/


void preorder(TreeNode *r) {      // Root, Left, Right
    if (!r) return;

    printf("%d ", r->key);      // visitação / visitation
    preorder(r->left);
    preorder(r->right);
}
// print in order
void inorder(TreeNode *r) {       // Left, Root, Right
    if (!r) return;

    inorder(r->left);
    printf("%d ", r->key);        // visitação / visitation
    inorder(r->right);
}

void postorder(TreeNode *r) {     // Left, Right, Root
    if (!r) return;

    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->key);         // visitação / visitation
}