#include<stdio.h>
/*
Apresente um programa em C contendo uma função que realiza uma busca em um vetor de inteiros dado. 
Nada sabe-se sobre o vetor. No entanto, sua função deverá utilizar uma estratégia recursiva que faz 
lembrar a busca binária para vetores ordenados: i) verifique se a chave está no meio do vetor, se não estiver, 
ii) procure recursivamente a chave dada no subvetor esquerdo e, se não encontrar, iii) procure no subvetor direito. 
Tome as suposições típicas de um algoritmo de busca para projetar sua função. 

Present a C program containing a function that performs a search in a vector of given integers. 
You know nothing about the vector. However, your function should use a recursive strategy 
reminiscent of binary search for sorted vectors: i) check if the key is in the middle of the vector; 
if not, ii) recursively search for the given key in the left sub-vector; and if not, iii) search in the 
right sub-vector. Use typical assumptions of a search algorithm to design your function.
*/

int search(int vet[], int key, int fim, int inicio);
int verificaVetorVazio(int vetor[], int key, int dim);

int main()
{
    int v[] = {10, 5, 7, 3, 11, 8, 2}; // array test
    int dim = sizeof(v) / 4; //pega o tamanho do vetor

    int key = 8; // chave teste
    int *p = start_search(v, key, dim); 
    if(p)
        printf("Found key %d ,(index = %p)\n", key, p);
    else 
        printf("Key %d not found\n", key);

    return 0;
}

int* start_search(int vetor[], int tamanho, int chave) {
    if (!vetor || tamanho <= 0) 
        return NULL;
    return search_rec(vetor, chave, 0, tamanho - 1);
}

int* search_rec (int vetor[], int chave, int inicio, int fim) {
    // Caso Base
    if(inicio > fim)
        return NULL; 

    int meio = inicio + (fim - inicio) / 2;

    //Verifica se a chave está no meio
    if(vetor[meio] == chave)
        return &vetor[meio];

    //Procura recursivamente no subvetor esquerdo
    int* p = search_rec(vetor, chave, inicio, meio-1);

    //Se o ponteiro retornado não for null, a chave foi encontrada na esquerda.=
    if(p)
        return p;

    //Se não encontrou, procura no subvetor direito
    return search_rec(vetor, chave, meio+1, fim);
}
