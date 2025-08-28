#include<string.h>
#include<stdio.h>
#define TAM 15



typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
}Endereco;

typedef struct{
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
}Contrato;

typedef struct{
    char nome[50];
    int cpf;
    Data dataNas;
    Endereco end;
    Contrato contr;
}Pessoa; 

// procedimentos para impressão
void imprimirData(Data d){
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end){
    printf("\tEndereco:\n");
    printf("\t\tRua: %s", end.rua);
    printf("\t\tBairro: %s", end.bairro);
    printf("\t\tCidade: %s", end.cidade);
    printf("\t\tPais: %s", end.pais);
    printf("\t\tNumero: %d\n", end.num);
    printf("\t\tCep: %d\n", end.cep);
}

void imprimirContrato(Contrato c){
    printf("\tContrato %d:\n", c.codigo);
    printf("\t\tCargo: %s", c.cargo);
    printf("\t\tSalario R$%.2f\n", c.salario);
    printf("\t\tData de ad.: ");
    imprimirData(c.dataAss);
}

void imprimirPessoa(Pessoa p){
    printf("\n\tNome: %s", p.nome);
    printf("\tCpf: %d\n", p.cpf);
    printf("\tData de nas.: ");
    imprimirData(p.dataNas);
    imprimirEndereco(p.end);
    imprimirContrato(p.contr);
}
//Leitura dos dados de uma Pessoa
Data lerData(){
    Data d;
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
    getchar();
    return d;
}

Endereco lerEndereco(){
    Endereco end;
    getchar();
    printf("\nRua: ");
    fgets(end.rua, sizeof(end.rua), stdin);
    printf("\nBairro: ");
    fgets(end.bairro, sizeof(end.bairro), stdin);
    printf("\nCidade: ");
    fgets(end.cidade, sizeof(end.cidade), stdin);
    printf("\nPais: ");
    fgets(end.pais, sizeof(end.pais), stdin);
    printf("\nNumero: ");
    scanf("%d", &end.num);
    printf("\nCep: ");
    scanf("%d", &end.cep);
    getchar();
    return end;
}
Contrato lerContrato(){
    Contrato c;
    printf("\nCodigo do contrato: ");
    scanf("%d", &c.codigo);
    printf("\nData de assinatura: ");
    c.dataAss = lerData();
    printf("\nCargo: ");
    fgets(c.cargo, sizeof(c.cargo), stdin);
    printf("\nSalario: R$");
    scanf("%f", &c.salario);
    getchar();
    return c;
}
Pessoa lerPessoa(){
    Pessoa p;
    getchar();
    printf("\nNome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    printf("\nCpf: ");
    scanf("%d", &p.cpf);
    printf("\nData de nascimento: ");
    p.dataNas = lerData();
    p.contr = lerContrato();
    p.end = lerEndereco();
    return p;
}

//funções e procedimentos para tabela hash

void inicializar_tabela(Pessoa t[]){
    for(int i = 0 ; i<TAM ; i++)
        t[i].cpf = 0;
}



int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Pessoa t[]){
    Pessoa p = lerPessoa();
    int id = funcaoHash(p.cpf);
    while(t[id].cpf != 0)
        id = funcaoHash(id+1);
    t[id] = p;
}

Pessoa *busca(Pessoa vet[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice gerada: %d\n", id);
    while(vet[id].cpf != 0)
    {
        if(vet[id].cpf == chave)
           return &vet[id];
        else
           id = funcaoHash(id + 1);
    }
    return NULL;
}

void imprimir(Pessoa vet[]){
    for(int i = 0 ; i<TAM ; i++)
    {
        printf("%d\n", i);
        if(vet[i].cpf != 0)
            imprimirPessoa(vet[i]);
        printf("\n---------------------------------\n");
    }
}


int main()
{
    int opcao, valor;
    Pessoa *buscar, vetor[TAM];

    inicializar_tabela(vetor);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            inserir(vetor);
            break;
        case 2:
            printf("\tQual CPF desseja buscar? ");
            scanf("%d", &valor);
            buscar = busca(vetor, valor);
            if(buscar){
                printf("\nCPF encontrado:\n");
                imprimirPessoa(*buscar);
            }
            else
                printf("\nCPF nao encontrado!\n");
            break;
        case 3:
            imprimir(vetor);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 0);


    return 0;
}