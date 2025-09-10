/*
    8) Apresente um programa para ordenar um vetor dado. 
    Seu programa necessariamente deverá utilizar uma árvore binária de pesquisa 
    como estratégia intermediária da ordenação. DICA: use uma travessia em ordem 
    para preencher o vetor ordenado. Discuta e compare o desempenho deste algoritmo 
    de ordenação com o algoritmo QuickSort.

    8) Present a program to sort a given array.
    Your program must necessarily use a binary search tree  
    as an intermediate sorting strategy. TIP: use an in-order traversal
    to fill the sorted array. Discuss and compare the performance of this sorting algorithm
    with the QuickSort algorithm.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *direita, *esquerda;
}NoABP;

NoABP* criaNo(int chave){
    NoABP* novo = NULL;
    novo = (NoABP*) malloc(sizeof(NoABP));
    if(novo){
        novo->chave = chave;
        novo->direita = NULL;
        novo->esquerda = NULL;
    }
    return novo;
}

void inserir(NoABP **raiz, int chave)
{
    NoABP *aux = NULL;
    aux = *raiz;
    while(aux)
    {
        if(aux->chave > chave)
            raiz = &(aux->esquerda);
        else
            raiz = &(aux->direita);
        aux = *raiz;
    }
    NoABP *novo = criaNo(chave);
    if(novo)
        *raiz = novo;
}

// travessia em ordem que preenche vet[]
void in_order(NoABP *p, int vet_out[], int *k){ // passa o endereço de k para alterar o inteiro na main 
    if(!p)
        return;
    in_order(p->esquerda, vet_out, k);
    vet_out[(*k)++] = p->chave;
    in_order(p->direita, vet_out, k);
}


// libera árvore em pós-ordem
void remover_tudo(NoABP **p){
    if (p == NULL || *p == NULL) return;
    remover_tudo(&(*p)->esquerda);
    remover_tudo(&(*p)->direita);
    free(*p);
    *p = NULL;
}


int main()
{
    NoABP *root = NULL;

    int vetor[] = {7, 5, 9, 2, 6, 8} ;
    // calcula o tamanho do vetor usando o tamanho em bytes da quantidade de elemento do vetor (24) e do primeiro indice em bytes (int 4)
    int tamanho = sizeof(vetor) / sizeof(vetor[0]) ; 
    // vetor de saída (out) deve ter espaço para 'tamanho' elementos
    int i;

    //insere na árvore
    for (i = 0 ; i < tamanho ; i++)
        inserir(&root, vetor[i]);

    // preencher out com travessia em ordem
    int k = 0;
    in_order(root, vetor, &k);

    // imprimi o resultado
    printf("Vetor out ordenado:\n ");
    for (i=0 ; i<k ; i++) 
        printf("[%d] ", vetor[i]);
    printf("\n");

    remover_tudo(&root);
    return 0;
    
}

/*
Complexidade (sem balanceamento):
BST‑sort (construir BST não balanceada + in‑order): média O(n log n), pior caso O(n²) (quando inserções geram cadeia).
QuickSort (pivô razoável / aleatorizado): média O(n log n), pior caso O(n²) — mas você normalmente usa variações (aleatorizado / introsort) que evitam o pior caso prático.

Complexidade (com árvore balanceada):
Usando AVL/Red‑Black: construção O(n log n) garantido, total O(n log n) no pior caso. Constantes maiores que QuickSort.

Memória e alocação:
BST‑sort: requer O(n) memória extra para nós + overhead de mallocs (alto custo em tempo/allocations; pior localidade de cache).
QuickSort in‑place: O(1) extra (além da pilha recursiva O(log n) em média); bem mais cache‑friendly.

Estabilidade:
QuickSort padrão: não estável (existem versões estáveis mais lentas).
BST‑sort: pode ser estável se a estrutura armazenar ordem de chegada; depende da implementação.

Constantes e desempenho prático:
QuickSort costuma ser mais rápido na prática devido à melhor localidade e menores overheads por elemento.
BST‑sort sofre com overhead de ponteiros e alocações dinâmicas; só competitiva se você já tem os elementos em uma BST por outras razões.

Uso indicado:
BST‑sort faz sentido se você precisa inserir/consultar dinamicamente e também iterar em ordem (estrutura de dado dinâmica).
Para ordenar um vetor estático, QuickSort (ou introsort usado por std::sort) é quase sempre a escolha melhor.

Robustez:
Para garantias de pior caso use introsort (std::sort) ou mergesort/heap‑sort; para BST use árvore balanceada.

Conclusão curta:
Para ordenar um vetor estático: prefira QuickSort/Introsort (melhor desempenho prático e uso de memória).
Se precisa de conjunto dinâmico com iteração ordenada: use árvore balanceada (AVL/Red‑Black). BST não balanceada só se o dado for aleatório e você aceitar risco de pior caso.
*/