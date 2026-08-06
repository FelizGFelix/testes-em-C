#include <stdio.h>
#include <locale.h>

int cadastrar(){
    printf("teste bem concluído!");
}

int main(){
    int escolha = 0;

    printf("Bem-vindo ao sistema de cadastro de funcionários da Hells Market!\n");
    printf("Escolha uma das opções:\n1 - Cadastrar Funcionário \n");
    scanf("%d", &escolha);


    if (escolha == 1){
        cadastrar();
    }
}