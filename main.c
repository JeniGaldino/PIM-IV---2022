#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200

//informacoes do profissional
struct login_do_profissional {
    char usuario[20];
    char senha[10];
    char usuario_autenticado[20];
    char senha_autenticado[10];
    int usuarioIgual;
    int senhaIgual;
};
struct login_do_profissional profissional;

//informacoes do paciente
struct informacoes_do_paciente {
    char nome[SIZE][50];
    char cpf[SIZE][50];
    char email[SIZE][50];
    char endereco[SIZE][50];
    char bairro[SIZE][50];
    char cidade[SIZE][50];
    char estado[SIZE][50];
    char comorbidade[SIZE][50];
    char cep[SIZE][50];

    //informacoes de nascimento
    int dia_nascimento[SIZE][2];
    int mes_nascimento[SIZE][2];
    int ano_nascimento;
    int idade;

    //informacoes diagnostico
    int dia_diagnostico[2];
    int mes_diagnostico[2];
    int ano_diagnostico[4];
};
struct informacoes_do_paciente paciente;

//variavel para selecionar opcao no menu
int opcao_menu;
//variavel que acompanha o numero de pacientes cadastrados
int numero_do_paciente;

//roda o programa aqui
int main() {
    cabecalho();

    criaConta();

    login();
}

void cabecalho() {
    printf("Sistema para Cadastro de Pacientes com Covid \n");
    printf(" \n");
    printf("SCPC \n");
    printf(" \n");
    printf("Versao 1.0 \n");
    printf("---------------------------------------------\n");
    printf(" \n");

}

//cria conta do profissional da saude
void criaConta() {
    printf("\nPrimeiro acesso: crie sua conta.\n");

    printf("Defina seu usuario (maximo 20 caracteres): ");
    fgets(profissional.usuario, 20, stdin);
    scanf("%[^\n]s", &profissional.usuario);

    printf("Defina sua senha (maximo 10 caracteres): ");
    fgets(profissional.senha, 10, stdin);
    scanf("%[^\n]s", &profissional.senha);
}

//checa se usuario e senha inputados sao iguais
//se ==, roda funcao menu()
//se !=, pede para tentar novamente
void login() {
    //autentica usuario:
    printf("\nPor favor, autentique sua conta; ");
    printf("\nInsira seu usuario: ");
    fgets(profissional.usuario_autenticado, 20, stdin);
    scanf("%[^\n]s", &profissional.usuario_autenticado);

    for(int letra= 0; letra< strlen(profissional.usuario); letra++) {
        if(profissional.usuario[letra]== profissional.usuario_autenticado[letra]){
            profissional.usuarioIgual= 1;
        }
    }

    //autentica senha:
    printf("\nInsira sua senha: ");
    fgets(profissional.senha_autenticado, 10, stdin);
    scanf("%[^\n]s",&profissional.senha_autenticado);

    for(int letra= 0; letra< strlen(profissional.senha); letra++) {
        if(profissional.senha[letra]== profissional.senha_autenticado[letra]) {
            profissional.senhaIgual= 1;
        }
    }

    //checa se sao iguais
    if(profissional.usuarioIgual== 1 && profissional.senhaIgual== 1) {
        printf("Login realizado com sucesso! Bem vindo, %s !", profissional.usuario);
        menu();
    }else {
        printf("Usuario e/ou senha incorretos! Tente novamente: ");
        login();
    }
}

//empurra as informacoes do paciente para o struct paciente
//calcula a idade e checa comorbidade
//se tiver comorbidade e acima dos 64 pede CEP
void cadastraPaciente() {
    int opcao_continuar_cadastro;
    int opcao_possui_comorbidade;

    void calculaIdade(){
        time_t segundos= time(NULL);
        struct tm* tempo_atual= localtime(&segundos);
        int ano_atual= (tempo_atual-> tm_year+ 1900);
        paciente.idade= ano_atual - paciente.ano_nascimento;
    }

    do{
        printf("Para cadastrar um paciente, siga os passos a seguir: \n");
        printf("Digite o nome completo do paciente: ");
        fgets(paciente.nome, SIZE, stdin);
        scanf("%[^\n]s", &paciente.nome);

        printf("Digite o CPF: ");
        fgets(paciente.cpf, SIZE, stdin);
        scanf("%[^\n]s", &paciente.nome);

        printf("Digite o email: ");
        fgets(paciente.email, SIZE, stdin);
        scanf("%[^\n]s", &paciente.email);

        printf("Informe o endereco: ");
        fgets(paciente.endereco, SIZE, stdin);
        scanf("%[^\n]s", &paciente.endereco);

        printf("Digite o bairro: ");
        fgets(paciente.bairro, SIZE, stdin);
        scanf("%[^\n]s", &paciente.bairro);

        printf("Qual a cidade do paciente? ");
        fgets(paciente.cidade, SIZE, stdin);
        scanf("%[^\n]s", &paciente.cidade);

        printf("E o estado? (Exemplo: SP) ");
        fgets(paciente.estado, SIZE, stdin);
        scanf("%[^\n]s", &paciente.estado);

        printf("Digite a data de nascimento do paciente (Ex: 00 00 0000): ");
        scanf("%d", &paciente.dia_nascimento);
        scanf("%d", &paciente.mes_nascimento);
        scanf("%d", &paciente.ano_nascimento);
        calculaIdade();

        printf("Digite a data de diagnostico do paciente (Ex: 00 00 0000): ");
        scanf("%d", &paciente.dia_diagnostico);
        scanf("%d", &paciente.mes_diagnostico);
        scanf("%d", &paciente.ano_diagnostico);

        printf("O paciente tem alguma comorbidade? Digite '1' para sim, '2' para nao: ");
        scanf("%d", &opcao_possui_comorbidade);
        if(opcao_possui_comorbidade== 1) {
            printf("Digite a comorbidade do paciente: ");
            fgets(paciente.comorbidade, SIZE, stdin);
            scanf("%[^\n]s", &paciente.comorbidade);
        }

        if(opcao_possui_comorbidade== 1 && paciente.idade>= 65) {
            printf("Por favor, informe o CEP do paciente: ");
            fgets(paciente.cep, SIZE, stdin);
            scanf("%[^\n]s", &paciente.cep);
        }

        numero_do_paciente++;
        printf("Pressione '1' para cadastrar outro paciente ou '2' para voltar ao menu. ");
        scanf("%d", &opcao_continuar_cadastro);

    }while(opcao_continuar_cadastro== 1);
}

//retorna os dados do paciente
void retornaDadosPaciente(){
    printf("\nListando Pacientes Cadastrados\n");
    for(int i= 0;i< 1; i++) {
        if(strlen(&paciente.cpf)> 0) {
            numero_do_paciente= i;
            printf("-----------------------------------\n");
            printf("Nome     = %s\n", &paciente.nome[numero_do_paciente]);
            printf("E-Mail   = %s\n", &paciente.email[numero_do_paciente]);
            printf("Endereco = %s\n", paciente.endereco[numero_do_paciente]);
            printf("Bairro   = %s\n", paciente.bairro[numero_do_paciente]);
            printf("Cidade   = %s\n", paciente.cidade[numero_do_paciente]);
            printf("Estado   = %s\n", paciente.estado[numero_do_paciente]);
            printf("Data do Diagnostico = %d/%d/%d/ \n", paciente.dia_diagnostico[numero_do_paciente], paciente.mes_diagnostico[numero_do_paciente], paciente.ano_diagnostico[numero_do_paciente]);
            printf("Comorbidade = %s\n", paciente.comorbidade[numero_do_paciente]);
        }
	 }
}

//menu aparece apos o login
//por onde acessa as opcoes
void menu() {
    do {
        printf("\n-------Menu-------\n1-Cadastrar Paciente\n2-Listar dados dos pacientes\n3-Gerar documento\n4-Encerrar programa ");
        scanf("%d", &opcao_menu);
        switch(opcao_menu) {
            case 1:
                cadastraPaciente();
                break;
            case 2:
                retornaDadosPaciente();
                break;
            case 3:
                printf("Gerando a documentacao...");
                break;
            case 4:
                printf("Obrigado por utilizar!");
                system("exit");
                break;
            default:
                printf("Opçao invalida, tente novamente!");
                break;
        }
    }while(opcao_menu!= 4);
}
