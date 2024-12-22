#include <stdio.h>
#include <string.h>

double converterComprimento(double comprimento, char unidadeEntrada[], char unidadeSaida[]) {
    if (strcmp(unidadeEntrada, "m") == 0 && strcmp(unidadeSaida, "cm") == 0) {
        return comprimento * 100;
    }else if (strcmp(unidadeEntrada, "m") == 0 && strcmp(unidadeSaida, "mm") == 0) {
        return comprimento * 1000;
    }else if (strcmp(unidadeEntrada, "cm") == 0 && strcmp(unidadeSaida, "m") == 0) {
        return comprimento / 100;
    }else if (strcmp(unidadeEntrada, "cm") == 0 && strcmp(unidadeSaida, "mm") == 0) {
        return comprimento * 10;
    }else if (strcmp(unidadeEntrada, "mm") == 0 && strcmp(unidadeSaida, "m") == 0) {
        return comprimento / 1000;
    }else if (strcmp(unidadeEntrada, "mm") == 0 && strcmp(unidadeSaida, "cm") == 0) {
        return comprimento / 10;
    }else {
        printf("Unidade de conversão inválida.\n");
        return -1;
    }
}


int main (void){
    return 0;
}