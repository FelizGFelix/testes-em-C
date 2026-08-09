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

void cadastrar(){
    limpar();
    setlocale(LC_ALL, "Portuguese");

    struct ficha_funcionario{
        int cod_id;
        char nome[100];
        char cpf[11];
        float credito;
        char endereco[500];
        char cep[8];
        char cidade[20];
        char estado[20];
    };

    struct ficha_funcionario codigo_identificador;
    struct ficha_funcionario nome_funcionario;
    struct ficha_funcionario cpf_funcionario;
    struct ficha_funcionario credito_funcionario;
    struct ficha_funcionario endereco_funcionario;
    struct ficha_funcionario cep_funcionario;
    struct ficha_funcionario cidade_funcionario;
    struct ficha_funcionario estado_funcionario;
    
    
    char retornar[]= "";

    printf("Bem-Vindo ao sistema de cadastro da Hells Market!\n");
    printf("Preencha o campo de informações: \n");
    printf("Digite o seu nome: \n");
    scanf("%*c");
    fgets(nome_funcionario.nome, sizeof(nome_funcionario.nome), stdin);
    printf("Digite o seu CPF: \n");
    scanf("%s", cpf_funcionario.cpf);
    printf("Digite o seu limite de crédito: \n");
    scanf("%f", &credito_funcionario.credito);
    printf("Digite o seu endereço: \n");
    scanf("%*c");
    fgets(endereco_funcionario.endereco, sizeof(endereco_funcionario.endereco), stdin);
    printf("Digite o seu cep: \n");
    scanf("%s", cep_funcionario.cep);
    printf("Digite a sua cidade: \n");
    scanf("%*c");
    fgets(cidade_funcionario.cidade, sizeof(codigo_identificador.cidade), stdin);
    printf("Digite o estado em que mora: \n");
    scanf("%*c");
    fgets(estado_funcionario.estado, sizeof(estado_funcionario.estado), stdin);

    codigo_identificador.cod_id = rand()%100;


    printf("Cadastro concluído!\n");
    printf("Seu número identificador é de: %d\n", codigo_identificador.cod_id);
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