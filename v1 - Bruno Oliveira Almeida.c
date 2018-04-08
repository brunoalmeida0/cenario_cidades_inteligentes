#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int posicaoX;
    int posicaoY;
    int horas;
    int minutos;
} TPOSICAO;

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

TPOSICAO capturarPontos(TPOSICAO posicao){
    printf("Posição X: ");
    scanf("%i", &posicao.posicaoX);
    printf("Posicao Y: ");
    scanf("%i", &posicao.posicaoY);
    printf("Horário de leitura da posição(HH:MM): ");
    scanf("%i", &posicao.horas);
    scanf("%i", &posicao.minutos);

    return posicao; 
}

void visualizaPontos(TPOSICAO posicao){
    printf("Coordenada (x, y): (%i, %i)\n", posicao.posicaoX, posicao.posicaoY);
    printf("Horario - %i:%i\n\n", posicao.horas, posicao.minutos);
}

int main(){

    int opcao;
    TPOSICAO posicao;


    while(opcao != 9){

        opcao = menu();

        switch(opcao){
            case 1:{
                posicao = capturarPontos(posicao);
            }
            break;

            case 2:{
                visualizaPontos(posicao);
            }
            break;

            default:{
                printf("Comando inválido");
            }
        }

    }
    

}