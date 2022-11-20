#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 200

char nome[SIZE][50];
char endereco[SIZE][50];
char bairro[SIZE][50];
char cidade[SIZE][50];
char estado[SIZE][50];
char email[SIZE][50];
char comorbidade[SIZE][50];

int data_nasc[SIZE];
int data_diag[SIZE];
int op;

char usuario;
char senha;
_Bool logged;

int main(){
printf("Sistema para Cadastro de Pacientes com Covid \n");
    printf(" \n");
    printf("SCPC \n");
    printf(" \n");
    printf("Versao 1.0 \n");
    printf("---------------------------------------------\n");
    printf(" \n");

menu();
}


void criarConta(){

        printf("\nInsira seu usuario: \n");
        scanf("%s", &usuario);

        printf("\nInsira sua senha: \n");
        scanf("%d", &senha);

        printf("Profissional da saude logado com sucesso. ");
        logged= true;

}


void cadastro(){
static int linha;

do{
    printf("\nBem vindo! Por favor, digite o nome do paciente: ");
    scanf("%s", &nome[linha]);

    printf("Digite o email: ");
    scanf("%s", &email[linha]);

    printf("Informe o endereço: ");
    scanf("%s", &endereco[linha]);

    printf("Digite o bairro: ");
    scanf("%s", &bairro[linha]);

    printf("Qual a cidade do paciente? ");
    scanf("%s", &cidade[linha]);

    printf("E o estado? (Exemplo: SP) ");
    scanf("%s", &estado[linha]);

    printf("Digite a data de nascimento do paciente (somente números, sem espaço): ");
    scanf("%d", &data_nasc[linha]);

    printf("Digite a data de diagnóstico do paciente (somente números, sem espaço) ");
    scanf("%d", &data_diag[linha]);

    printf("O paciente tem alguma comorbidade? Qual? ");
    scanf("%s", &comorbidade[linha]);

    printf("Pressione 1 para cadastrar outro paciente ou 2 para voltar ao menu. ");
    scanf("%d", &op);
    linha++;

}while(op==1);

}

void menu(){
do{

    printf("\n-------Menu-----------------\n1-Criar conta\n2-Cadastrar Pacientes\n3-Listar dados dos pacientes\n4-Gerar documento\n5-Encerrar programa ");
    scanf("%d", &op);

    switch(op){
case 1:
    criarConta();
    break;
case 2:
    cadastro();
    break;
case 3:
    printf("Listar pacientes");
    break;
case 4:
    printf("Gerar doc");
    break;
case 5:
    printf("Obrigada por utilizar!");
    system("exit");
    break;
default:
    printf("Opção inválida, tente novamente!");
    break;
    }
}while(op!=5);

}


 

