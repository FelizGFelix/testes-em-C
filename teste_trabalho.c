#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void remover_quebra_linha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void cadastrar(){
    limpar();
    setlocale(LC_ALL, "Portuguese");
    
    FILE *arquivo = fopen("funcionarios.txt", "a");

    struct ficha_funcionario{
        int id;
        char nome[100];
        char cpf[14];
        float credito;
        char endereco[100];
        char cep[9];
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
    remover_quebra_linha(funcionario.nome);
    printf("Digite o seu CPF: \n");
    scanf("%s", funcionario.cpf, stdin);
    printf("Digite o seu limite de crédito: \n");
    scanf("%*c");
    fgets(credito_temporario, sizeof(credito_temporario), stdin);
    remover_quebra_linha(credito_temporario);
    printf("Digite o seu endereço: \n");
    fgets(funcionario.endereco, sizeof(funcionario.endereco), stdin);
    remover_quebra_linha(funcionario.endereco);
    printf("Digite o seu cep: \n");
    scanf("%*c");
    fgets(funcionario.cep, sizeof(funcionario.cep), stdin);
    remover_quebra_linha(funcionario.cep);
    printf("Digite a sua cidade: \n");
    scanf("%*c");
    fgets(funcionario.cidade, sizeof(funcionario.cidade), stdin);
    remover_quebra_linha(funcionario.cidade);
    printf("Digite o estado em que mora: \n");
    scanf("%s", funcionario.estado, stdin);

    funcionario.credito = atof(credito_temporario);

    fseek(arquivo, funcionario.id++, SEEK_END);
    fprintf(arquivo, "%d, ", funcionario.id);

    fprintf(arquivo, "%s,", funcionario.nome);
    fprintf(arquivo, "%s,", funcionario.cpf);
    fprintf(arquivo, "%f,", funcionario.credito);
    fprintf(arquivo, "%s,", funcionario.endereco);
    fprintf(arquivo, "%s,", funcionario.cep);
    fprintf(arquivo, "%s,", funcionario.cidade);
    fprintf(arquivo, "%s", funcionario.estado);
    fprintf(arquivo, "%s", "\n");


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