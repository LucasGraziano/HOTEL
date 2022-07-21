#ifndef HOTELMODEL_H_INCLUDED
#define HOTELMODEL_H_INCLUDED

#define ANDARES 20
#define APTOS 14
#define MAXHOTEL 280

typedef enum status {LIVRE,OCUPADO,RESERVADO} tipoStatusApto;

typedef struct Apartamento
{
    int andar;
    int numeroQuarto;
    tipoStatusApto situacao;
} tipoApartamento;

typedef struct Hospede
{
    char nome[60]; 
    char endereco[100];
    char telefone[20];
    char cpf[13];
    int idade;
    char email[40];
    tipoApartamento apartamento;
} tipoHospede;



void inicializarAptosHotel(tipoApartamento ht[ANDARES][APTOS]);
int checkinSemReserva(tipoHospede hospede, tipoHospede listaHospedes[], tipoApartamento hotel[ANDARES][APTOS],int posicao, int andar, int apto);
bool checkinComReserva (char cpf[], tipoHospede listaHospedes[], tipoApartamento hotel[ANDARES][APTOS], int n);
bool checkoutHotel(tipoApartamento ht[ANDARES][APTOS],int andar, int apto);
bool cancelarReserva(tipoApartamento ht[ANDARES][APTOS],int andar, int apto);
int reservarApto(tipoHospede hospede, tipoHospede listaHospedes[], tipoApartamento hotel[ANDARES][APTOS],int posicao, int andar, int apto);
float calcularTaxaOcupacao(tipoApartamento ht[ANDARES][APTOS]);
int incluirHospede(tipoHospede listaHospedes[], tipoHospede hosp, int n);
bool localizarHospede(tipoHospede listaHospedes[],char cpf[], int n, int *posicao);



#endif // HOTELMODEL_H_INCLUDED