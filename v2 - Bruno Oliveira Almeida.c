#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int registroX;
    int registroY;
    int horas;
    int minutos;
} TREGISTRO;

struct TNO {
    TREGISTRO registro;
    struct TNO *prox;
};

typedef struct TNO *TPILHA;

int menu(){
    int opcao;

    printf("------- MENU -------\n");
    printf("(1) Captura pontos\n");
    printf("(2) Visualiza pontos\n");
    printf("(9) Sair\n\n");

    printf("Opção: ");
    scanf("%i", &opcao);

    return opcao;
}

TREGISTRO capturarPontos(TREGISTRO registro){
    printf("Posição X: ");
    scanf("%i", &registro.registroX);
    printf("registro Y: ");
    scanf("%i", &registro.registroY);
    printf("Horário de leitura da posição(HH:MM): ");
    scanf("%i", &registro.horas);
    scanf("%i", &registro.minutos);

    return registro; 
}

void visualizaPontos(TREGISTRO registro){
    printf("Coordenada (x, y): (%i, %i)\n", registro.registroX, registro.registroY);
    printf("Horario - %i:%i\n\n", registro.horas, registro.minutos);
}

int main(){

    int opcao;
    TREGISTRO registro;


    while(opcao != 9){

        opcao = menu();

        switch(opcao){
            case 1:{
                registro = capturarPontos(registro);
            }
            break;

            case 2:{
                visualizaPontos(registro);
            }
            break;

            default:{
                printf("Comando inválido");
            }
        }

    }

}