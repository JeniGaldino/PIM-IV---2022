#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 200

struct informacoes_do_paciente
{
	int CPF [SIZE][11];
    char nome[SIZE][50];
    int telefone[SIZE][11];
    char email[SIZE][20];
    char endereco[SIZE][50];
    int numero[SIZE][10];
    char bairro[SIZE][50];
    int CEP[SIZE][8];
    char cidade[SIZE][50];
    char estado[SIZE][50];
    char comorbidade[SIZE][50];
    
    int dia_diag[SIZE][2];
	int mes_diag[SIZE][2];
	int ano_diag[SIZE][2];
	int dia_nasc[SIZE][2];
	int mes_nasc[SIZE][2];
	int ano_nasc[SIZE][2];
    int op;
};
struct informacoes_do_paciente paciente;

struct login_do_profissional
{
    char usuario[30];
    char senha[10];
    _Bool logged;
};
struct login_do_profissional profissional;

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
        fgets(profissional.usuario, 30, stdin);
        scanf("%[^\n]s", &profissional.usuario);

        printf("\nInsira sua senha: \n");
        fgets(profissional.senha, 10, stdin);
        scanf("%[^\n]s", &profissional.senha);

        printf("Profissional da saude logado com sucesso. ");
        profissional.logged= true;

}

void cadastro(){
static int linha;

do{
    printf("Bem vindo! Por favor, insira os dados do paciente: \n");
    printf("Digite o nome completo do paciente: ");
    fgets(paciente.nome, 50, stdin);
    scanf("%[^\n]s", &paciente.nome[linha]);

    printf("Digite o email: ");
    fgets(paciente.email, 20, stdin);
    scanf("%[^\n]s", &paciente.email[linha]);

    printf("Informe o endereço: ");
    fgets(paciente.endereco, 20, stdin);
    scanf("%[^\n]s", &paciente.endereco[linha]);

    printf("Digite o bairro: ");
    fgets(paciente.bairro, 50, stdin);
    scanf("%[^\n]s", &paciente.bairro[linha]);

    printf("Qual a cidade do paciente? ");
    fgets(paciente.cidade, 50, stdin);
    scanf("%[^\n]s", &paciente.cidade[linha]);

    printf("E o estado? (Exemplo: SP) ");
    fgets(paciente.estado, 50, stdin);
    scanf("%[^\n]s", &paciente.estado[linha]);

    printf("Digite a data de nascimento do paciente: (Ex: 00/00/0000): ");
    scanf("%d/%d/%d", &paciente.dia_nasc[linha], &paciente.mes_nasc[linha], &paciente.ano_nasc[linha]);

    printf("Digite a data de diagnóstico do paciente: (Ex: 00/00/0000):  ");
    scanf("%d/%d/%d", &paciente.dia_diag[linha], &paciente.mes_diag[linha], &paciente.ano_diag[linha]);

    printf("O paciente tem alguma comorbidade? Qual? ");
    fgets(paciente.comorbidade, 50, stdin);
    scanf("%[^\n]s", &paciente.comorbidade[linha]);

    printf("Pressione 1 para cadastrar outro paciente ou 2 para voltar ao menu. ");
    scanf("%d", &paciente.op);
    linha++;

}while(paciente.op==1);

}

int grupoRisco() {

  	int idade = paciente.ano_diag - paciente.ano_nasc;
  	int aux = paciente.mes_diag + paciente.mes_nasc;
  	
  	switch(aux) {
  		case 'aux < 12 || aux > 23':
  			idade  = idade - 1;
  			break;
  		case 'aux > 12 && aux < 23': 
	  		idade;
	  		break;
  		default: 
  			idade;
  	  }

    if (idade >= 65 || paciente.comorbidade != null)
    {
    	printf("---------------------------------------------\n");
    	prinf("Nome: %s\n", paciente.nome);
        printf("CPF: %d\n", paciente.CPF);
		printf("Data de nascimento do paciente: %d/%d/%d\n", dia_nasc, mes_nasc, ano_nasc);
		prinf("Comorbidade: %s\n", paciente.comorbidade);
		prinf("CEP: %s\n", paciente.CEP);
		printf("---------------------------------------------\n");
    } else 
	{
    	printf("---------------------------------------------\n");
    	prinf("Nome: %s\n", paciente.nome);
        printf("CPF: %d\n", paciente.CPF);
        printf("Data de nascimento do paciente: %d/%d/%d\n", dia_nasc, mes_nasc, ano_nasc);
        prinf("Telefone: %d\n", paciente.telefone);
        printf("Email: %s\n", paciente.email);
        printf("Data de diagnostico do paciente: %d/%d/%d\n", dia_diag, mes_diag, ano_diag);
        printf("Endereco: %s\n", paciente.endereco);
        printf("Numero: %d\n", paciente.numero);
        printf("Bairro: %s\n", paciente.bairro);
        printf("Cidade: %s\n", paciente.cidade);
        printf("Estado: %s\n", paciente.estado);
		prinf("CEP: %d\n", paciente.CEP);
		prinf("Comorbidade: %s\n", paciente.comorbidade);
		printf("---------------------------------------------\n");
	}
}

void menu(){
do{

    printf("\n-------Menu-----------------\n1-Criar conta\n2-Cadastrar Pacientes\n3-Listar dados dos pacientes\n4-Gerar documento\n5-Encerrar programa ");
    scanf("%d", &paciente.op);

    switch(paciente.op){
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
}while(paciente.op!=5);

}




