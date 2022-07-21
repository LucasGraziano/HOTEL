#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "HotelModel.h"

void limparTelaTerminal() {
  system("cls");
}

void limparBufferTeclado() {
     char op;

     while( (op = fgetc(stdin)) != EOF && op != '\n') {};
}

void pausarTelaTerminal() {
  system("pause");
}


void entrarAndarApto(int *andar, int *apto) //sai pq é ponteiro
{
    bool valida = false;

    do
    {
        printf("Entre com o numero do andar (1 a 20): ");
        scanf("%d",andar); 
        printf("Entre com o nomero do apto (1 a 14): ");
        scanf("%d",apto); 
        if ((*andar >= 1 && *andar <= ANDARES) && (*apto >= 1 && *apto <= APTOS))
            valida = true;
        else {
                printf("Entrada inválida!\n");
                pausarTelaTerminal();
        }
    }
    while(!valida);

}

tipoHospede entradaInfoHospede(void)
{
    tipoHospede hosp;


    printf("*********************** Cadastro de Hospedes ******************************\n");
    printf("Entre com as informações do hospede\n");
    printf("Entre com o nome: ");
    limparBufferTeclado();
    fgets(hosp.nome,60,stdin);
    printf("Entre com o CPF: ");
    fgets(hosp.cpf,13,stdin);
    printf("Entre com o endereço: ");
    fgets(hosp.endereco,100,stdin);
    printf("Entre com o telefone: ");
    fgets(hosp.telefone,20,stdin);
    printf("Entre com o email: ");
    fgets(hosp.email,40,stdin);
    printf("Entre com a idade: ");
    scanf("%d",&hosp.idade);

    return hosp;
}

void entraCPF(char cpf[])
{
    printf("Entre com o CPF: ");
    limparBufferTeclado();
    fgets(cpf,13,stdin);

}

void exibirOcupacaoHotel(tipoApartamento ht[ANDARES][APTOS])
{
    int andar,apto;
    char msgSituacao[3][11] = {"LIVRE","OCUPADO","RESERVADO"};

    for(andar = 0; andar < ANDARES; andar++)
    {
        printf("Andar %2d\n", andar+1);
        for(apto = 0; apto < APTOS; apto++)
            printf("%s   ", msgSituacao[ht[andar][apto].situacao]);
        printf("\n");
    }
    pausarTelaTerminal();

}

void exibirInfoHospedes(tipoHospede listaHospedes[],int n)
{
    int i;
    char msgSituacao[3][11] = {"LIVRE","OCUPADO","RESERVADO"};

    for(i=0; i<n; i++)
    {
        printf("Hospede #%d\n", i+1);
        printf("Nome: %s\n",listaHospedes[i].nome);
        printf("Email: %s \n",listaHospedes[i].email);
        printf("Situação do hospede: %s\n",msgSituacao[listaHospedes[i].apartamento.situacao]);
        printf("Andar %d e Apto %d\n",listaHospedes[i].apartamento.andar,listaHospedes[i].apartamento.numeroQuarto);
        printf("****************************************************************\n");
    }
    pausarTelaTerminal();
}

bool verificaCheckinReserva()
{
    bool reserva = false;
    char ch;

    do
    {
        printf("O hospede possui Reserva (S/N): ");
        limparBufferTeclado();
        ch = getchar();
    }
    while (toupper(ch) != 'S' && toupper(ch) != 'N');

    if (toupper(ch) == 'S') reserva = true;

    return reserva;

}



int exibirMenuPrincipalApp() {

       int opcao;

        limparTelaTerminal();
        printf("************ Sistema de Controle de Hotel v1.0 ************\n");
        printf("\n(1) - Check-in de Hospede\n");
        printf("(2) - Check-out de Hospede\n");
        printf("(3) - Reservar Apartamento\n");
        printf("(4) - Cancelar reserva\n");
        printf("(5) - Exibir a ocupação do hotel\n");
        printf("(6) - Taxa de ocupação do hotel\n");
        printf("(7) - Exibir Informaçoes dos Hospedes do Hotel\n");
        printf("(8) - Sair do programa\n");
        printf("\n");
        printf("Entre com a opção: ");
        scanf("%d",&opcao);
        limparTelaTerminal();

        return opcao;

}