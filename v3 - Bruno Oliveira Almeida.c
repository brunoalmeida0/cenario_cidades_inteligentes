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

TPILHA inicializarPilha(){
    return NULL;    
}

int verificaPilha(TPILHA pPilha){
    if(pPilha == NULL){
        return 0;
    } else {
        return 1;
    }
}

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
    TPILHA pilha;

    pilha = inicializarPilha();

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

            case 3:{
                if(verificaPilha(pilha) == 0){
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
            }
            break;

            default:{
                printf("Comando inválido");
            }
        }

    }

}