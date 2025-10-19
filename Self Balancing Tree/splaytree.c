#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
} Node;

/* cria nó */
Node *new_node(int k){
    Node *n = (Node*)malloc(sizeof(Node));
    if(!n) { perror("malloc"); exit(1); }
    n->key = k;
    n->left = n->right = n->parent = NULL;
    return n;
}

/* rotação simples à esquerda em x:
   y = x->right passa a ocupar o lugar de x */
void rotate_left(Node **root, Node *x){
    Node *y = x->right;
    if(!y) return;
    x->right = y->left;
    if(y->left) y->left->parent = x;

    y->parent = x->parent;
    if(x->parent == NULL) {
        *root = y;
    } else if(x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

/* rotação simples à direita em x:
   y = x->left passa a ocupar o lugar de x */
void rotate_right(Node **root, Node *x){
    Node *y = x->left;
    if(!y) return;
    x->left = y->right;
    if(y->right) y->right->parent = x;

    y->parent = x->parent;
    if(x->parent == NULL) {
        *root = y;
    } else if(x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

/* === rotações duplas (procedimentos solicitados) ===
   Cada função assume que x é o nó que será splayado
   e que a configuração dos ponteiros é válida (x, p=x->parent, g=p->parent).
*/

/* zig-zig left  (LL): x é filho esquerdo de p e p é filho esquerdo de g
   ordem: rotate_right(g); rotate_right(p); */
void zig_zig_left(Node **root, Node *x){
    Node *p = x->parent;
    Node *g = p ? p->parent : NULL;
    if(!p || !g) return;
    rotate_right(root, g);
    rotate_right(root, p);
}

/* zig-zig right (RR): x é filho direito de p e p é filho direito de g
   ordem: rotate_left(g); rotate_left(p); */
void zig_zig_right(Node **root, Node *x){
    Node *p = x->parent;
    Node *g = p ? p->parent : NULL;
    if(!p || !g) return;
    rotate_left(root, g);
    rotate_left(root, p);
}

/* zig-zag left-right (LR): x é filho direito de p e p é filho esquerdo de g
   ordem: rotate_left(p); rotate_right(g); */
void zig_zag_left_right(Node **root, Node *x){
    Node *p = x->parent;
    Node *g = p ? p->parent : NULL;
    if(!p || !g) return;
    rotate_left(root, p);
    rotate_right(root, g);
}

/* zig-zag right-left (RL): x é filho esquerdo de p e p é filho direito de g
   ordem: rotate_right(p); rotate_left(g); */
void zig_zag_right_left(Node **root, Node *x){
    Node *p = x->parent;
    Node *g = p ? p->parent : NULL;
    if(!p || !g) return;
    rotate_right(root, p);
    rotate_left(root, g);
}

/* Função splay que usa os procedimentos acima */
void splay(Node **root, Node *x){
    if(!x) return;
    while(x->parent){
        Node *p = x->parent;
        Node *g = p->parent;

        if(!g){
            /* zig (rot. simples) */
            if(x == p->left) rotate_right(root, p);
            else rotate_left(root, p);
        } else if(x == p->left && p == g->left){
            /* zig-zig left */
            zig_zig_left(root, x);
        } else if(x == p->right && p == g->right){
            /* zig-zig right */
            zig_zig_right(root, x);
        } else if(x == p->right && p == g->left){
            /* zig-zag left-right */
            zig_zag_left_right(root, x);
        } else { /* x is left child and p is right child */
            /* zig-zag right-left */
            zig_zag_right_left(root, x);
        }
    }
}

/* ---- Funções auxiliares de exemplo para teste ---- */
void inorder_print(Node *r){
    if(!r) return;
    inorder_print(r->left);
    printf("%d ", r->key);
    inorder_print(r->right);
}

/* busca simples (retorna ponteiro para nó, não splaya) */
Node *search(Node *root, int k){
    Node *cur = root;
    while(cur){
        if(k == cur->key) return cur;
        if(k < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return NULL;
}

/* insere nó como em BST normal (retornando novo root via *root) */
void bst_insert(Node **root, Node *nd){
    if(!*root){ *root = nd; return; }
    Node *cur = *root;
    Node *parent = NULL;
    while(cur){
        parent = cur;
        if(nd->key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    nd->parent = parent;
    if(nd->key < parent->key) parent->left = nd;
    else parent->right = nd;
}

/* Exemplo mínimo de uso */
int main(void){
    Node *root = NULL;

    /* inserir alguns nós (BST insert) */
    int vals[] = {100, 50, 200, 25, 75, 150, 250, 60, 80};
    for(int i=0;i<9;i++) bst_insert(&root, new_node(vals[i]));

    printf("In-order antes splay: ");
    inorder_print(root);
    printf("\n");

    /* escolher um nó para splayar (ex.: 60) */
    Node *x = search(root, 60);
    if(x){
        splay(&root, x);
        printf("Após splay(60), raiz = %d\n", root->key);
        printf("In-order após splay: ");
        inorder_print(root);
        printf("\n");
    } else {
        printf("Nó não encontrado\n");
    }

    return 0;
}
