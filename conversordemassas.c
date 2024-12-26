#include <stdio.h>

void quilograma_para_grama(float kg) {
    printf("%.2f quilograma(s) = %.2f grama(s)\n", kg, kg * 1000);
}

void quilograma_para_tonelada(float kg) {
    printf("%.2f quilograma(s) = %.6f tonelada(s)\n", kg, kg / 1000);
}

void grama_para_quilograma(float g) {
    printf("%.2f grama(s) = %.6f quilograma(s)\n", g, g / 1000);
}

void grama_para_tonelada(float g) {
    printf("%.2f grama(s) = %.9f tonelada(s)\n", g, g / 1000000);
}

void tonelada_para_grama(float t) {
    printf("%.2f tonelada(s) = %.2f grama(s)\n", t, t * 1000000);
}

void tonelada_para_quilograma(float t) {
    printf("%.2f tonelada(s) = %.2f quilograma(s)\n", t, t * 1000);
}

int main() {
    int opcao;
    float valor;

    printf("Escolha a conversão que deseja realizar:\n");
    printf("1 - Quilograma para Grama\n");
    printf("2 - Quilograma para Tonelada\n");
    printf("3 - Grama para Quilograma\n");
    printf("4 - Grama para Tonelada\n");
    printf("5 - Tonelada para Grama\n");
    printf("6 - Tonelada para Quilograma\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Digite o valor em quilogramas: ");
            scanf("%f", &valor);
            quilograma_para_grama(valor);
            break;
        case 2:
            printf("Digite o valor em quilogramas: ");
            scanf("%f", &valor);
            quilograma_para_tonelada(valor);
            break;
        case 3:
            printf("Digite o valor em gramas: ");
            scanf("%f", &valor);
            grama_para_quilograma(valor);
            break;
        case 4:
            printf("Digite o valor em gramas: ");
            scanf("%f", &valor);
            grama_para_tonelada(valor);
            break;
        case 5:
            printf("Digite o valor em toneladas: ");
            scanf("%f", &valor);
            tonelada_para_grama(valor);
            break;
        case 6:
            printf("Digite o valor em toneladas: ");
            scanf("%f", &valor);
            tonelada_para_quilograma(valor);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
