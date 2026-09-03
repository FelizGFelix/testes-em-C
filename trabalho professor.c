#include <stdio.h>
#include <string.h>
#define MAX 10
 
struct cliente_info {
    int ID;
    char Cliente[30];
    char Endereco[50];
    float Renda;
};
 
struct cliente_info pilha[MAX];
int topo = -1;
 
void empilhar(struct cliente_info c) {
    if (topo == MAX - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    topo++;
    pilha[topo] = c;
}
 
struct cliente_info desempilhar() {
    struct cliente_info vazio = {0, "", "", 0};
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return vazio;
    }
    return pilha[topo--];
}
 
void exibir() {
    printf("\n--- Pilha (topo -> base) ---\n");
    for (int i = topo; i >= 0; i--) {
        printf("ID: %d | Nome: %s | Endereco: %s | Renda: %.2f\n",
               pilha[i].ID, pilha[i].Cliente, pilha[i].Endereco, pilha[i].Renda);
    }
}
 
struct cliente_info ler_cliente() {
    struct cliente_info c;
 
    printf("ID: ");
    scanf("%d", &c.ID);
    getchar(); /* limpa o \n deixado pelo scanf */
 
    printf("Nome do cliente: ");
    fgets(c.Cliente, sizeof(c.Cliente), stdin);
    c.Cliente[strcspn(c.Cliente, "\n")] = '\0'; /* remove o \n do fgets */
 
    printf("Endereco: ");
    fgets(c.Endereco, sizeof(c.Endereco), stdin);
    c.Endereco[strcspn(c.Endereco, "\n")] = '\0';
 
    printf("Renda: ");
    scanf("%f", &c.Renda);
    getchar();
 
    return c;
}

 
int main() {
    int opcao;
 
    do {
        printf("\n1 - Empilhar cliente\n");
        printf("2 - Desempilhar cliente\n");
        printf("3 - Exibir pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();
 
        if (opcao == 1) {
            struct cliente_info c = ler_cliente();
            empilhar(c);
        } else if (opcao == 2) {
            struct cliente_info removido = desempilhar();
            if (removido.ID != 0)
                printf("Removido: %s\n", removido.Cliente);
        } else if (opcao == 3) {
            exibir();
        }
 
    } while (opcao != 0);
 
    return 0;
}
