#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char usuario[20];
    char senha[15];
    _Bool logged;

    //cria uma conta com usuario e senha
    //define logged como true para rodar o resto do programa
    void criaConta(){

        printf("Defina seu usuario: \n");
        scanf("%s", &usuario);

        printf("Defina sua senha: ");
        scanf("%s", &senha);

        printf("Paciente %s foi cadastrado no sistema. ", usuario);
        logged= true;

    }

criaConta();

    if(logged) {

    char nome_c,
    endereco,
    bairro,
    cidade,
    estado,
    comorbidade,
    email;


    int dia_nasc,
    mes_nasc,
    ano_nasc,
    dia_diag,
    mes_diag,
    ano_diag,
    risco = 1;


    printf("Bem vindo! Por favor, digite seu nome completo: ");
    scanf("%s", &nome_c);

    printf("Digite seu email: ");
    scanf("%s", &email);

    printf("Informe seu endereço: ");
    scanf("%s", &endereco);

    printf("Digite seu bairro: ");
    scanf("%s", &bairro);

    printf("Qual sua cidade? ");
    scanf("%s", &cidade);

    printf("E o estado? (Exemplo: SP) ");
    scanf("%s", &estado);

    printf("Digite o dia do seu nascimento com até 2 digitos: ");
    scanf("%d", &dia_nasc);

    printf("Agora o mês com até 2 digitos: ");
    scanf("%d", &mes_nasc);

    printf("Por fim, o ano do seu nascimento com 4 digitos: ");
    scanf("%d", &ano_nasc);

    printf("Digite o dia da descoberta do diagnóstico com até 2 digitos: ");
    scanf("%d", &dia_diag);

    printf("Agora, o mês da descoberta do diagnóstico com até 2 digitos: ");
    scanf("%d", &mes_diag);

    printf("Por fim, o ano da descoberta do diagnóstico com 4 digitos: ");
    scanf("%d", &ano_diag);


    printf("Você tem alguma comorbidade? 1-Sim 2-Não ");
    scanf("%d", &risco);

    if(risco==1){
        int choseOp;
        while(choseOp <0 || choseOp>5){

        printf("Qual sua comorbidade? \n1-Diabetes\n2-Obesidade\n3-Hipertensão\n4-Tuberculose\n5-Outros\n ");
        scanf("%d", &choseOp);

        }
        switch(choseOp){
            case 1:
            comorbidade = "Diabetes";
            printf("Cadastro realizado com sucesso!");
            break;

            case 2:
            comorbidade = "Obesidade";
            printf("Cadastro realizado com sucesso!");
            break;

            case 3:
            comorbidade = "Hipertensão";
            printf("Cadastro realizado com sucesso!");
            break;

            case 4:
            comorbidade = "Tuberculose";
            printf("Cadastro realizado com sucesso!");
            break;

            case 5:
            comorbidade = "Outros";
            printf("Cadastro realizado com sucesso!");
            break;

            default:
            printf("Opção inválida, tente novamente! \n");
            break;

        }


    }else{
        printf("Cadastro feito com sucesso!");
    }
}
    }



