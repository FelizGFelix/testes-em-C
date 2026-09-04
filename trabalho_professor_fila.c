#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
int tam_clientes = 0;     // quantidade de clientes atualmente cadastrados
int capacidade = 0;       // quantas fichas cabem no bloco de memória alocado atualmente
 
typedef struct {
    int ID;
    char Cliente[30];
    char Endereco[50];
    float Renda;
} Cliente_ficha;
 
Cliente_ficha *admnistrar = NULL;
 
void limpar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
 
void garantir_espaco(){
    if (tam_clientes < capacidade) {
        return; 
    }
 
    int nova_capacidade = (capacidade == 0) ? 4 : capacidade * 2;
 
    Cliente_ficha *novo_bloco = realloc(admnistrar, nova_capacidade * sizeof(Cliente_ficha));
    if (novo_bloco == NULL) {
        printf("Erro: falha ao alocar memória!\n");
        exit(1);
    }
 
    admnistrar = novo_bloco;
    capacidade = nova_capacidade;
}
 
void inserir_cliente(){
    limpar();
    garantir_espaco();
 
    printf("Digite o ID do Cliente: \n");
    scanf("%d", &admnistrar[tam_clientes].ID);
 
    printf("Digite o valor para a renda do Cliente: \n");
    scanf("%f", &admnistrar[tam_clientes].Renda);
 
    admnistrar[tam_clientes].Endereco[0] = '\0';
 
    tam_clientes++;
}
 
void inserir_endereco(){
    limpar();
 
    if (tam_clientes == 0) {
        printf("Nenhum cliente cadastrado ainda!\n");
        return;
    }
 
    int id_busca;
    printf("Digite o ID do Cliente para inserir o endereço: \n");
    scanf("%d", &id_busca);
 
    for (int i = 0; i < tam_clientes; i++) {
        if (admnistrar[i].ID == id_busca) {
            printf("Digite o endereço do Cliente: \n");
            scanf(" %49[^\n]", admnistrar[i].Endereco);
            printf("Endereço inserido com sucesso!\n");
            return;
        }
    }
 
    printf("Cliente com esse ID não encontrado!\n");
}
 
void retirar_cliente(){
    limpar();
 
    if (tam_clientes == 0) {
        printf("Nenhum cliente para remover!\n");
        return;
    }
 
    int id_busca;
    printf("Digite o ID do Cliente a remover: \n");
    scanf("%d", &id_busca);
 
    int indice = -1;
    for (int i = 0; i < tam_clientes; i++) {
        if (admnistrar[i].ID == id_busca) {
            indice = i;
            break;
        }
    }
 
    if (indice == -1) {
        printf("Cliente com esse ID não encontrado!\n");
        return;
    }
 
    for (int i = indice; i < tam_clientes - 1; i++) {
        admnistrar[i] = admnistrar[i + 1];
    }
    tam_clientes--;
 
    printf("valor retirado com sucesso!\n");
 
    if (capacidade > 4 && tam_clientes <= capacidade / 4) {
        int nova_capacidade = capacidade / 2;
        Cliente_ficha *novo_bloco = realloc(admnistrar, nova_capacidade * sizeof(Cliente_ficha));
        if (novo_bloco != NULL) {
            admnistrar = novo_bloco;
            capacidade = nova_capacidade;
        }
    }
}
 
void retirar_endereco(){
    limpar();
 
    if (tam_clientes == 0) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
 
    int id_busca;
    printf("Digite o ID do Cliente cujo endereço deseja apagar: \n");
    scanf("%d", &id_busca);
 
    for (int i = 0; i < tam_clientes; i++) {
        if (admnistrar[i].ID == id_busca) {
            admnistrar[i].Endereco[0] = '\0';
            printf("valor retirado com sucesso!\n");
            return;
        }
    }
 
    printf("Cliente com esse ID não encontrado!\n");
}
 
void exibir_cliente(){
    limpar();
 
    if (tam_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
 
    for (int i = 0; i < tam_clientes; i++) {
        printf("ID: %d, Renda: %.2f\n", admnistrar[i].ID, admnistrar[i].Renda);
    }
}
 
void exibir_endereco(){
    limpar();
 
    if (tam_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
 
    for (int i = 0; i < tam_clientes; i++) {
        printf("ID: %d, Endereco: %s\n", admnistrar[i].ID, admnistrar[i].Endereco);
    }
}
 
void liberar_tudo(){
    free(admnistrar);
    admnistrar = NULL;
}
 
int main(){
    int valor = 0;
 
    while (true){
        printf("1 - inserir elemento no Cliente\n2 - inserir endereço\n3 - retirar valor do Cliente\n4 - retirar endereço\n5 - exibir renda clientes\n6 - exibir endereços\n0 - sair\n->");
        scanf("%d", &valor);
 
        if (valor == 1){
            inserir_cliente();
        }
        else if (valor == 2){
            inserir_endereco();
        }
        else if (valor == 3){
            retirar_cliente();
        }
        else if (valor == 4){
            retirar_endereco();
        }
        else if (valor == 5){
            exibir_cliente();
        }
        else if (valor == 6){
            exibir_endereco();
        }
        else if (valor == 0){
            break;
        }
    }
 
    liberar_tudo();
    return 0;
}
