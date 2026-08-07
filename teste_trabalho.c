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
    char nome[100] = "";
    char cpf[11] = "";
    float credito = 0;
    char endereco[500] = "";
    char cep[8];
    char cidade[20] = "";
    char estado[20] = "";
    char retornar[] = "";

    printf("Bem-Vindo ao sistema de cadastro da Hells Market!\n");
    printf("Preencha o campo de informações: \n");
    printf("Digite o seu nome: \n");
    scanf("%*c");
    fgets(nome, sizeof(nome), stdin);
    printf("Digite o seu CPF: \n");
    scanf("%s", cpf);
    printf("Digite o seu limite de crédito: \n");
    scanf("%f", &credito);
    printf("Digite o seu endereço: \n");
    scanf("%*c");
    fgets(endereco, sizeof(endereco), stdin);
    printf("Digite o seu cep: \n");
    scanf("%s", cep);
    printf("Digite a sua cidade: \n");
    scanf("%*c");
    fgets(cidade, sizeof(cidade), stdin);
    printf("Digite o estado em que mora: \n");
    scanf("%*c");
    fgets(estado, sizeof(estado), stdin);

    int num_cod = rand()%100;


    printf("Cadastro concluído!\n");
    printf("Seu número identificador é de: %d\n", num_cod);
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