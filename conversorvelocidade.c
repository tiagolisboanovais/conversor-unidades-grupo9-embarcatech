#include <stdio.h>

void converterVelocidade(float valor, int entrada, int saida) {
    float convertido = 0.0;

    // Conversão para m/s como base intermediária
    if (entrada == 1) {         // De km/h para m/s
        valor /= 3.6;
    } else if (entrada == 3) {  // De mph para m/s
        valor /= 2.237;
    }

    // Conversão de m/s para a unidade desejada
    if (saida == 1) {           // Para km/h
        convertido = valor * 3.6;
    } else if (saida == 2) {    // Para m/s
        convertido = valor;
    } else if (saida == 3) {    // Para mph
        convertido = valor * 2.237;
    }

    printf("Velocidade convertida: %.2f\n", convertido);
}

int main() {
    int entrada, saida;
    float valor;

    printf("Conversor de Unidades de Velocidade\n");
    printf("Escolha a unidade de entrada:\n");
    printf("1. km/h\n2. m/s\n3. mph\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &entrada);

    printf("Digite o valor da velocidade: ");
    scanf("%f", &valor);

    printf("Escolha a unidade de saída:\n");
    printf("1. km/h\n2. m/s\n3. mph\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &saida);

    if (entrada < 1 || entrada > 3 || saida < 1 || saida > 3) {
        printf("Opção inválida.\n");
    } else {
        converterVelocidade(valor, entrada, saida);
    }

    return 0;
}