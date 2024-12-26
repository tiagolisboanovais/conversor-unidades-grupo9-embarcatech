#include <stdio.h>

int opcao;
float unidade, resultado;

int main(){
    printf("Qual conversao de tempo deseja fazer? Digite o numero correspondente:\n");
    printf("1 - horas para minutos\n");
    printf("2 - horas para segundos\n");
    printf("3 - minutos para horas\n");
    printf("4 - minutos para segundos\n");
    printf("5 - segundos para horas\n");
    printf("6 - segundos para minutos\n");
    scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Insira o valor em horas: \n");
            scanf("%f", &unidade);
            resultado = unidade * 60;
            printf("%.2f horas = %.2f minutos", unidade, resultado);
            break;
        case 2:
            printf("Insira o valor em horas: \n");
            scanf("%f", &unidade);
            resultado = unidade * 3600;
            printf("%.2f horas = %.2f segundos", unidade, resultado);
            break;
        case 3:
            printf("Insira o valor em minutos: \n");
            scanf("%f", &unidade);
            resultado = unidade / 60;
            printf("%.2f minutos = %.2f horas", unidade, resultado);
            break;
        case 4:
            printf("Insira o valor em minutos: \n");
            scanf("%f", &unidade);
            resultado = unidade * 60;
            printf("%.2f minutos = %.2f segundos", unidade, resultado);
            break;
        case 5:
            printf("Insira o valor em segundos: \n");
            scanf("%f", &unidade);
            resultado = unidade / 3600;
            printf("%.2f segundos = %.2f horas", unidade, resultado);
            break;
        case 6:
            printf("Insira o valor em segundos: \n");
            scanf("%f", &unidade);
            resultado = unidade / 60;
            printf("%.2f segundos = %.2f minutos", unidade, resultado);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
}