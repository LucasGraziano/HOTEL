#ifndef HOTELVIEW_H_INCLUDED
#define HOTELVIEW_H_INCLUDED
#include "HotelModel.h"

void limparTelaTerminal();
void limparBufferTeclado();
void pausarTelaTerminal();
void entrarAndarApto(int *and, int *apt);
tipoHospede entradaInfoHospede(void);
void entraCPF(char cpf[]);
void exibirOcupacaoHotel(tipoApartamento ht[ANDARES][APTOS]);
void exibirInfoHospedes(tipoHospede listaHospedes[],int n);
bool verificaCheckinReserva();
int exibirMenuPrincipalApp();



#endif // HOTELVIEW_H_INCLUDED