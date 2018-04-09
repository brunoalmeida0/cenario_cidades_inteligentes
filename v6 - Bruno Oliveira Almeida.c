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

void empilhar(TREGISTRO registro, TPILHA *pPilha){

    struct TNO *novaPosicao;

    novaPosicao = (struct TNO *) malloc(sizeof(struct TNO));

    novaPosicao -> registro = registro;
    novaPosicao -> prox = NULL;

    if(*pPilha == NULL){
        (*pPilha) = novaPosicao;
    } else {
        novaPosicao -> prox = (*pPilha);
        (*pPilha) = novaPosicao;
    }

}

TREGISTRO desempilhar(TPILHA *pPilha){
    TREGISTRO aux;

    aux = (*pPilha)->registro;
    (*pPilha) = (*pPilha)-> prox;

    return aux;
}

void imprimePilha(TPILHA pPilha){

    TPILHA pilhaAux = pPilha;

    printf("Coordenadas já passadas: \n");

    while(pilhaAux != NULL){

        printf("Coordenada (x, y): (%i, %i)\n", pilhaAux -> registro.registroX, pilhaAux -> registro.registroY);
        printf("Horario - %i:%i\n\n", pilhaAux -> registro.horas, pilhaAux -> registro.minutos);
        pilhaAux = pilhaAux -> prox; 
    }

}

int menu(){
    int opcao;

    printf("------- MENU -------\n");
    printf("(1) Captura pontos\n");
    printf("(2) Visualiza pontos\n");
    printf("(3) Ver histórico\n");
    printf("(4) Apagar última coordenada do histórico\n");
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
                system("clear");
                registro = capturarPontos(registro);
                empilhar(registro, &pilha);
            }
            break;

            case 2:{
                system("clear");
                if(verificaPilha(pilha) == 0){
                    printf("Sem coordenadas\n");
                } else {
                    visualizaPontos(registro);
                }
            }
            break;

            case 3:{
                system("clear");
                if(verificaPilha(pilha) == 0){
                    printf("Sem coordenadas\n");
                } else {
                    imprimePilha(pilha);
                }
                
            }
            break;

            case 4:{
                system("clear");
                if(verificaPilha(pilha) == 0){
                    printf("Sem coordenadas\n");
                } else {
                    desempilhar(&pilha);
                }
            }
            break;

            default:{
                system("clear");
                printf("Comando inválido\n");
            }
        }

    }

}
