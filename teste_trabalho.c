#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Definição do contador*/
int contador_id = 0;

void incrementar_contador(){
    contador_id ++;
}

void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void cadastrar(){
    limpar();
    setlocale(LC_ALL, "Portuguese");
    
    FILE *arquivo = fopen("funcionarios.txt", "w");

    struct ficha_funcionario{
        int id;
        char nome[100];
        char cpf[14];
        float credito;
        char endereco[500];
        char cep[8];
        char cidade[20];
        char estado[3];
    };

    struct ficha_funcionario funcionario;
    
    char retornar[]= "";

    char credito_temporario[500] = "";

    printf("Sistema de cadastro\n");
    printf("Preencha o campo de informações: \n");
    printf("Digite o seu nome: \n");
    scanf("%*c");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    printf("Digite o seu CPF: \n");
    scanf("%s", funcionario.cpf, stdin);
    printf("Digite o seu limite de crédito: \n");
    scanf("%*c");
    fgets(credito_temporario, sizeof(credito_temporario), stdin);
    printf("Digite o seu endereço: \n");
    scanf("%*c");
    fgets(funcionario.endereco, sizeof(funcionario.endereco), stdin);
    printf("Digite o seu cep: \n");
    scanf("%s", funcionario.cep);
    printf("Digite a sua cidade: \n");
    scanf("%*c");
    fgets(funcionario.cidade, sizeof(funcionario.cidade), stdin);
    printf("Digite o estado em que mora: \n");
    scanf("%*c");
    fgets(funcionario.estado, sizeof(funcionario.estado),stdin);

    funcionario.credito = atof(credito_temporario);

    incrementar_contador();
    funcionario.id = contador_id;

    fprintf(arquivo, "%d,", funcionario.id);
    fprintf(arquivo, "%s,", funcionario.nome);
    fprintf(arquivo, "%s,", funcionario.cpf);
    fprintf(arquivo, "%f,", funcionario.credito);
    fprintf(arquivo, "%s,", funcionario.endereco);
    fprintf(arquivo, "%s,", funcionario.cep);
    fprintf(arquivo, "%s,", funcionario.cidade);
    fprintf(arquivo, "%s", funcionario.estado);


    fclose(arquivo);

    printf("Cadastro concluído!\n");
    printf("Digite qualquer valor para retornar: ");
    scanf("%s", retornar);
    limpar();
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int escolha = 0;

    while (true){
        printf("Bem-vindo ao sistema de funcionários da Hells Market!\n");
        printf("Escolha uma das opções:\n1 - Cadastrar Funcionário \n");
        scanf("%d", &escolha);


        if (escolha == 1){
            cadastrar();
        }
    }
}