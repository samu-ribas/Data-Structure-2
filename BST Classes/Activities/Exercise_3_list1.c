#include<stdio.h>
    /*Apresente um programa eficiente em C contendo uma função
    que realiza uma busca em um vetor de inteiros dado. Assuma que
    segunda metade do vetor está ordenada. Tome as suposições típicas 
    de um algoritmo de busca para projetar sua função.
    
    Present an efficient C program containing a function that performs a search in a given
    vector of integers. Assume that the second half of the vector is sorted. 
    Use typical assumptions of a search algorithm to design your function.*/

int *start_search(int array[], int key, int dim);
int *sequential_search(int array[], int key, int first, int last);
int *binary_search(int array[], int key, int first, int last);

int main()
{
    int array[] = {15, 9, 10 , 8, 3 , 4, 5, 7};
    int dim = sizeof(array)/ sizeof(array[0]); // faz tamanho em bits do vetor / tamanho em bits do primeiro elemento

    int *busca = start_search(array, 5, dim); // colocando chaves testes

    if(busca)
        printf("Key %d found, address(%p)", *busca, busca);
    else
        printf("Key not found");

    return 0;
}

int *start_search(int array[], int key, int dim)
{
    if(dim<=0) return NULL; // retorna nulo se tamanho do vetor for zero ou nulo

    int *p = NULL;
    p = sequential_search(array, key, 0, (dim/2)-1); //busca sequencial no subvetor esquerdo
    if(!p)
        return binary_search(array, key, dim/2, dim-1); // se precisar, busca binaria no subvetor direito
    return p;
}

int *sequential_search(int array[], int key, int first, int last)
{
    if(first>last)  // retorno nulo se indice first for mais que last
        return NULL;
    
    if(array[last] == key) //compara os valores
        return &array[last];
    
    return sequential_search(array, key, first, last - 1); // returno a recursão diminuindo o valor do indice last
}

int *binary_search(int array[], int key, int first, int last)
{
    if(last<first) // caso base
        return NULL;

    int middle = first + ((last - first) / 2) ; // pega o valor do meio do subvetor 

    if(array[middle] == key) //compara valores
        return &array[middle]; // retorno enedereço caso for verdade
    
    if(key < array[middle])
        return binary_search(array, key, first, middle - 1);    // busca na metade esquerda
    else
        return binary_search(array, key, middle + 1, last);     // busca na metade direita
}