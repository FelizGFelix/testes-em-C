#include <stdlib.h>
#include <stdio.h>
#define _MAX 10
#include <stdbool.h>


int Pilha[_MAX];
int tam=0;

void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void inserir(){
    int valor = 0;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    Pilha[tam] = valor;
    tam++;

    if (tam == _MAX){
        printf("\nPilha cheia!");
    }
    else{
        printf("\nvalor adicionado com sucesso!");
    }
}

int retirar(){
    printf("Valor retirado com sucesso!\n");
    return Pilha[--tam];
}

void exibir(){
    limpar();
    int i = 0;
    for(i=0; i<tam; i++){
        printf("%d, ", Pilha[i]);
    }
}

int main(){
    int opcao = 0;

    while(true){
        printf("escolha uma das opções:\n1- inserir valores\n2- retirar valores\n3- exibir valores\n->");
        scanf("%d", &opcao);

        if (opcao == 1){
            inserir();
        }

        else if (opcao == 2){
            retirar();
        }

        else{
            exibir();
        }
    }
}


