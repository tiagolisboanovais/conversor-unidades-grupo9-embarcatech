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
    printf("Exemplo do conversor de comprimento\n");
    printf("Exemplo 1:\n");
    // Comprimento em metros
    double comprimento = 150;
    printf("Comprimento em metros: %.2lfm\n", comprimento);
    printf("Comprimento em centímetros: %.2lfcm\n", converterComprimento(comprimento, "m", "cm"));
    printf("Comprimento em milímetros: %.2lfmm\n", converterComprimento(comprimento, "m", "mm"));
    return 0;
}