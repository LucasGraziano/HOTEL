#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "HotelView.c"
#include "HotelModel.c"


int rodarController() {
    tipoApartamento hotel[ANDARES][APTOS]; 
    tipoHospede hospedes[MAXHOTEL];

    int andar, apto;
    int n = 0; // controla a quantidade de hospedes no hotel
    int opcao;
    bool fim = false;  // sentinela que controla o fim do programa
    char cpfReserva[13];
    float taxaOcupacao;

    setlocale(LC_ALL, "Portuguese");
    //inicializa a ocupação do hotel e numeração dos apartamentos
    inicializarAptosHotel(hotel);

    do
    {
        opcao = exibirMenuPrincipalApp();

        switch (opcao)
        {
        case 1: // Opção de check-in
            if (verificaCheckinReserva())
            {
                entraCPF(cpfReserva);
                if (checkinComReserva(cpfReserva,hospedes,hotel,n)) {
                    printf("Checkin realizado com sucesso! \n");
                    pausarTelaTerminal();
                }

                else{
                    printf("Reserva não localizada! \n");
                    pausarTelaTerminal();
                }
            }
            else
            {
                entrarAndarApto(&andar, &apto);
                if (hotel[andar-1][apto-1].situacao == OCUPADO || hotel[andar-1][apto-1].situacao == RESERVADO) { // verifica se quarto está ocupado/reservado ou não
                          printf("O apartamento %d do andar %d está ocupado!\n",apto,andar);
                          pausarTelaTerminal();
                }
                else {

                    tipoHospede hosp = entradaInfoHospede();
                    n = checkinSemReserva(hosp,hospedes,hotel,n,andar,apto);
                }
            }
            break;

        case 2:  // opção de check-out
            entrarAndarApto(&andar, &apto);
            if (checkoutHotel(hotel,andar,apto)){
                printf("Check-out realizado com sucesso! \n");
                pausarTelaTerminal();
            } else {
               printf("Check-out não realizado! Apartamento informado já está desocupado!\n");
               pausarTelaTerminal();
            }

            break;
        case 3:  // opção de fazer reserva de apto
            entrarAndarApto(&andar, &apto);
            if (hotel[andar-1][apto-1].situacao == OCUPADO || hotel[andar-1][apto-1].situacao == RESERVADO) {// verifica se quarto está ocupado ou já reservado
                printf("O apartamento %d do andar %d está ocupado ou reservado!\n",apto,andar);
                pausarTelaTerminal();
            }
            else
            {
                tipoHospede hosp = entradaInfoHospede();
                n = reservarApto(hosp,hospedes,hotel,n,andar,apto);
            }
            break;
        case 4:  //Funcionalidade de Cancelar reserva
            entrarAndarApto(&andar, &apto);
            if (cancelarReserva(hotel,andar,apto)){
                printf("Cancelamento realizado com sucesso! \n");
                pausarTelaTerminal();
            } else {
               printf("Cancelamento não realizado! Apartamento informado já está desocupado!\n");
               pausarTelaTerminal();
            }
            break;
        case 5: // opção de exibição de ocupação dos aptos
            exibirOcupacaoHotel(hotel);
            break;
        case 6:
            taxaOcupacao = calcularTaxaOcupacao(hotel);
            printf("A taxa de ocupação do hotel é de : %.2f%%\n",taxaOcupacao);
            pausarTelaTerminal();
            break;
        case 7:
            exibirInfoHospedes(hospedes,n);
            break;
        case 8:
            fim = true;
            break;
        default:
            printf("Opcao do menu invalida\n");
            pausarTelaTerminal();
        }
    }
    while (!fim);
    return 0;
}