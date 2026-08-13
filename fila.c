#include <stdlib.h>
#include <stdio.h>
#define _MAX 8
#include <stdbool.h>


int Fila[_MAX];
int tam=0;

void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Retira(){
    limpar();
    int elm = Fila[0], i;
    for (i=0; i<tam; i++){
        Fila[i]=Fila[i+1];
    }
    tam--;

    printf("valor retirado com sucesso!");
}

void inserir(){
    int elm;
    printf("Digite um valor: \n");
    scanf("%d", &elm);
    Fila[tam] = elm;
    tam ++;

    if (tam == _MAX){
        printf("Fila cheia");
    }

    else {
        printf("%d adicionado com sucesso!\n", elm);
    }
}

void exibir(){
    limpar();
    int i;
    for (i=0;i<tam;i++){
        printf("%d, ", Fila[i]);
    }

}


int main (){
    int escolha;

    while(true){
    
        printf("Escolha uma das opções: \n1- inserir valores\n2- retirar valores\n3- exibir valores\n->");
        scanf("%d", &escolha);

        if (escolha == 1){
            inserir();
        }   

        else if (escolha == 2){
            Retira();
        }

        else{
            exibir();
        }

    }

    return 0;
}