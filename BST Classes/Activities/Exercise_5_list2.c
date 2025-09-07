#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
    5) Apresente um programa que preenche uma árvore binária de pesquisa com um 
    milhão de chaves geradas aleatoriamente. Após cada inserção, grave em um arquivo 
    de textos a quantidade de nós da árvore e a altura da árvore. Gere um arquivo PDF 
    contendo o gráfico quantidade de nos vs altura e uma breve discussão indicando se a
    árvore pode se considerada tão rápida quanto a busca binária em um vetor ordenado ou não.
    DICA: você pode manter uma variável chamada altura (inicializada com valor -1) e atualizá-la
    toda vez que o nó recém-inserido for colocado em um nível maior que a variável altura.

    5) Present a program that fills a binary search tree with one million randomly
    keys. After each insertion, save in a text file the number of nodes in the tree and
    the height of the tree. Generate a PDF file containing the graph number of nodes vs height
    and a brief discussion indicating whether the tree can be considered as fast as binary search
    in an ordered vector or not.
    TIP: you can keep a variable called height (initialized with value -1) and update it
    whenever the newly inserted node is placed at a level greater than the height variable.
*/

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

int inserir(Node **p, int key){
    Node *aux = *p; 
    int height = 0;
    while(aux){ 
        if(key<aux->data) // se a chave for menor
            p = &(aux->left); // p recebe endereco do ponteiro esq de aux
        else
            p = &(aux->right);// p recebe endereco do ponteiro dir de aux
        aux = *p; // aux recebe o conteudo de p
        height++;
    }

    aux = (Node *)malloc(sizeof(Node));
    if(!aux) return -1;
    aux->data = key;
    aux->left = aux->right = NULL;
    *p = aux;
    return height;
}

int main()
{
    Node *root = NULL;
    FILE *fp = fopen("insercoes.txt", "w");
    if(!fp) return 1;

    int nodes = 0, height = -1;

    

    // inserindo 1 milhão de vezes randomicamente
    srand(time(NULL));
    for(int i = 0 ; i<1000000 ; i++){
        int k = rand();
        int depth = inserir(&root, k);

        if(depth < 0){
            //falha de alocação. encerra gravando o que temos
            fprintf(stderr, "malloc falhou na insercao %d\n", i);
            break;
        }
        nodes++;    
        if(depth > height){
            height = depth;
            fprintf(fp, "%d %d\n", nodes, height);
        }
    }
    fclose(fp);
    return 0;
}