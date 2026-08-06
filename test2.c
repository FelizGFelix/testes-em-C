#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL, "Portuguese");
    char nome[] = "";
    int idade = 0;

    printf("Digite o seu nome: \n");
    scanf("%s", &nome);
    printf("Olá %s \n", nome);

    printf("Digite sua idade: \n");
    scanf("%d", &idade);
    printf("Caramba, você tem %d anos de idade? que maneiro!\n", idade);

    if (idade >= 18) {
        printf("Você é maior de idade!");
    }

    else {
        printf("Você é menor de idade!");
    }
}