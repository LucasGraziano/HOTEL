#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "HotelView.h"


bool localizarHospede(tipoHospede listaHospedes[],char cpf[], int n, int *posicao)
{
    bool achouReserva;
    int i;

    achouReserva = false;
    for(i=0; i<n && !achouReserva; i++)
        if (strcmp(cpf,listaHospedes[i].cpf) == 0)
        {
            achouReserva = true;
            *posicao = i-1;
        }

    return achouReserva;
}

int incluirHospede(tipoHospede listaHospedes[], tipoHospede hosp, int n) //
{
    listaHospedes[n] = hosp; 
    n++; // atualização do contador de hospedes

    return n;
}

int incluirHospedes ()
{


}

void inicializarAptosHotel(tipoApartamento hotel[ANDARES][APTOS])
{
    int andar,apto;


    for(andar = 0; andar < ANDARES; andar++) 
    {
        for(apto = 0; apto < APTOS; apto++)
        {
            hotel[andar][apto].situacao = LIVRE; // marca os aparamentos como livres 
            hotel[andar][apto].numeroQuarto = apto+1;
            hotel[andar][apto].andar = andar+1;
        }
    }

}

int checkinSemReserva(tipoHospede hospede, tipoHospede listaHospedes[], tipoApartamento hotel[ANDARES][APTOS],int n, int andar, int apto)
{


    hotel[andar-1][apto-1].situacao = OCUPADO; // aloca o quarto para o hospede
    hospede.apartamento = hotel[andar-1][apto-1]; // atribui o quarto para o hospede;
    n = incluirHospede(listaHospedes,hospede,n);

    return n;

}

bool checkinComReserva (char cpf[], tipoHospede listaHospedes[], tipoApartamento hotel[ANDARES][APTOS], int n)
{

    int pos;
    int andar,apto;
    bool achouReserva = false;

    achouReserva = localizarHospede(listaHospedes,cpf,n,&pos);
    if (achouReserva == true)
        {
            andar = listaHospedes[pos].apartamento.andar;
            apto = listaHospedes[pos].apartamento.numeroQuarto;
            hotel[andar-1][apto-1].situacao = OCUPADO;
            listaHospedes[pos].apartamento.situacao = OCUPADO;


        }
    return achouReserva;
}

bool checkoutHotel(tipoApartamento ht[ANDARES][APTOS],int andar, int apto)
{
    bool status = false;

    if (ht[andar-1][apto-1].situacao == OCUPADO)   // verifica se quarto está ocupado ou não
    {
        ht[andar-1][apto-1].situacao = LIVRE; // desaloca o quarto
        status = true;
    }

    return status;
}

bool cancelarReserva (tipoApartamento ht[ANDARES][APTOS],int andar, int apto)
{
    bool status = false;

    if (ht[andar-1][apto-1].situacao == RESERVADO)   // verifica se quarto está reservado ou não
    {
        ht[andar-1][apto-1].situacao = LIVRE; // desaloca o quarto
        status = true;
    }

    return status;
}

int reservarApto(tipoHospede hospede, tipoHospede listaHospedes[], tipoApartamento hotel[ANDARES][APTOS],int n, int andar, int apto)
{


    hotel[andar-1][apto-1].situacao = RESERVADO; // reserva o quarto para o hospede
    hospede.apartamento = hotel[andar-1][apto-1]; // atribui o quarto para o hospede;
    listaHospedes[n] = hospede;
    n++; // atualização do contador de hospedes

    return n;

}

float calcularTaxaOcupacao(tipoApartamento ht[ANDARES][APTOS])
{

    int andar,apto;
    float ocupados,taxaOcupacao;

    for(andar = 0, ocupados = 0.0; andar < ANDARES; andar++)
        for(apto = 0; apto < APTOS; apto++)
            if (ht[andar][apto].situacao == OCUPADO) ocupados++;
    taxaOcupacao = (ocupados/(ANDARES*APTOS))*100.0;

    return taxaOcupacao;

}