#include<stdio.h>
#include<stdlib.h>
#define TAM 31

typedef struct no
{
    int chave;
    struct no *prox;
}Tno;

Tno *alocarNo(int valor)
{
    Tno *novo = NULL;
    novo = (Tno *)malloc(sizeof(Tno));
    if(novo){
        novo->chave = valor;
        novo->prox = NULL;
    }
    return novo;
}

void inserir_na_lista(Tno **p, int k)
{
    Tno *novo = alocarNo(k);
    if(novo){
        novo->prox = *p;
        *p = novo;
    }else
        printf("Erro no malloc.\n");
}

void inicializa_tabela(Tno *vet[])
{
     for(int i = 0 ; i<TAM ; i++)
        vet[i] = NULL;
}

int funcaoHash(int chave)
{
    int r = chave % TAM;
    return (r < 0) ? r + TAM : r;
}

void inserir_hash(Tno *vet[], int valor)
{
    int id = funcaoHash(valor);
    inserir_na_lista(&vet[id], valor);
}

Tno *busca_na_lista(int chave_busca, Tno *head) {
    Tno *aux = head;
    while (aux != NULL && aux->chave != chave_busca) {
        aux = aux->prox;
    }
    return aux;
}

Tno *busca_na_tabela(Tno *vet[], int k)
{
    int id = funcaoHash(k);
    printf("\nIndice gerado: %d\n", id);
    return busca_na_lista(k, vet[id]);
}

void imprimir_lista(Tno *p)
{
    if(!p){
        printf("Lista vazia.\n");
        return;
    }
    Tno *aux = p;
    while(aux)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    
}

void imprimir_tabela(Tno *vet[])
{
    for(int i=0 ; i<TAM ; i++)
    {
        printf("%2d = ", i);
        imprimir_lista(vet[i]);
        printf("\n");
    }
}


int main(void) {
    Tno *vetor[TAM];
    int num, opcao;

    inicializa_tabela(vetor);

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        printf("Opção: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Qual valor deseja inserir? ");
                while (scanf("%d", &num) != 1) {
                    while (getchar() != '\n');
                    printf("Valor inválido. Tente novamente: ");
                }
                inserir_hash(vetor, num);
                break;

            case 2: {
                printf("Qual valor deseja buscar? ");
                while (scanf("%d", &num) != 1) {
                    while (getchar() != '\n');
                    printf("Valor inválido. Tente novamente: ");
                }
                Tno *resultado = busca_na_tabela(vetor, num);
                if (resultado)
                    printf("\tValor encontrado: %d\n", resultado->chave);
                else
                    printf("\tValor não encontrado!\n");
                break;
            }

            case 3:
                imprimir_tabela(vetor);
                break;

            case 0:
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
