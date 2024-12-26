#include <stdio.h>
#include <string.h>

// Cabecalho das funções
double conversaoTemperatura(double medicao, char unidade, char conversao);
double converterVelocidade(double valor, char entrada[], char saida[]);
double converterComprimento(double comprimento, char unidadeEntrada[], char unidadeSaida[]);
double converterMassa(double massa, char unidadeEntrada[], char unidadeSaida[]);

/*Função de conversão de medida de temperatura*/
double conversaoTemperatura(double medicao, char unidade, char conversao){
    
    // Estrutura switch case que verifica qual unidade a medicao está
    switch (unidade)
    {
    
    //Caso esteja em graus Celsius
    case 'C':
        
        //Caso conversão seja para graus Fahrenheit
        if(conversao == 'F')
            medicao = (medicao * 1.8) + 32;
        else
            //Caso conversão seja a escala Kelvin
            if(conversao == 'K')
                medicao = medicao + 273;
            else
                medicao = -500;

        break;

    //Caso esteja em graus Fahrenheit
    case 'F':
        
        //Caso conversão seja para graus Celsius
        if(conversao == 'C')
            medicao = (medicao - 32) * (10.0 / 18);
        else
            //Caso conversão seja a escala Kelvin
            if(conversao == 'K')
                medicao = (medicao - 32) * (10.0 / 18) + 273;
            else
                medicao = -500;

        break;

    //Caso esteja na escala absoluta Kelvin
    case 'K':
        
        //Caso conversão seja para graus Celsius
        if(conversao == 'C')
            medicao = medicao - 273;
        else
            //Caso conversão seja para graus Fahrenheit
            if(conversao == 'F')
                medicao = (medicao - 273) * (18.0 / 10) + 32;
            else
                medicao = -500;

        break;
    
    default:
        // Caso a unidade da medida ou conversão não seja identificada, função retorna -500
        return -500;
    }

    return medicao;
}

double converterVelocidade(double valor, char entrada[], char saida[]) {
    double convertido = 0.0;

    // Conversão para m/s como base intermediária
    if (strcmp(entrada, "km") == 0){         // De km/h para m/s
        valor /= 3.6;
    } else if (strcmp(entrada, "ml") == 0)  {  // De mph para m/s
        valor /= 2.237;
    }

    // Conversão de m/s para a unidade desejada
    if (strcmp(saida, "km") == 0)  {           // Para km/h
        convertido = valor * 3.6;
    } else if (strcmp(saida, "m") == 0)   {    // Para m/s
        convertido = valor;
    } else if (strcmp(saida, "ml") == 0)   {    // Para mph
        convertido = valor * 2.237;
    }

    return convertido;
}

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

double converterMassa(double massa, char unidadeEntrada[], char unidadeSaida[]) {
    if (strcmp(unidadeEntrada, "kg") == 0 && strcmp(unidadeSaida, "g") == 0) {
        return massa * 1000;
    } else if (strcmp(unidadeEntrada, "kg") == 0 && strcmp(unidadeSaida, "t") == 0) {
        return massa / 1000;
    } else if (strcmp(unidadeEntrada, "g") == 0 && strcmp(unidadeSaida, "kg") == 0) {
        return massa / 1000;
    } else if (strcmp(unidadeEntrada, "g") == 0 && strcmp(unidadeSaida, "t") == 0) {
        return massa / 1000000;
    } else if (strcmp(unidadeEntrada, "t") == 0 && strcmp(unidadeSaida, "g") == 0) {
        return massa * 1000000;
    } else if (strcmp(unidadeEntrada, "t") == 0 && strcmp(unidadeSaida, "kg") == 0) {
        return massa * 1000;
    } else {
        printf("Unidade de conversão inválida.\n");
        return -1;
    }
}

int main (void){
    int opcao;
    double valor;
    char unidadeEntrada[3], unidadeSaida[3];

    do {
        printf("\n=== CONVERSOR DE UNIDADES ===\n");
        printf("1 - Converter Temperatura\n");
        printf("2 - Converter Velocidade\n");
        printf("3 - Converter Comprimento\n");
        printf("4 - Converter Massa\n");
        printf("5 - Converter Tempo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n=== Conversão de Temperatura ===\n");
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Digite a unidade de entrada (C/F/K): ");
                scanf(" %c", &unidadeEntrada[0]);
                printf("Digite a unidade de saída (C/F/K): ");
                scanf(" %c", &unidadeSaida[0]);
                printf("Resultado: %.2lf\n", 
                    conversaoTemperatura(valor, unidadeEntrada[0], unidadeSaida[0]));
                break;

            case 2:
                printf("\n=== Conversão de Velocidade ===\n");
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Digite a unidade de entrada (km/m/ml): ");
                scanf("%s", unidadeEntrada);
                printf("Digite a unidade de saída (km/m/ml): ");
                scanf("%s", unidadeSaida);
                printf("Resultado: %.2lf\n", 
                    converterVelocidade(valor, unidadeEntrada, unidadeSaida));
                break;

            case 3:
                printf("\n=== Conversão de Comprimento ===\n");
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Digite a unidade de entrada (m/cm/mm): ");
                scanf("%s", unidadeEntrada);
                printf("Digite a unidade de saída (m/cm/mm): ");
                scanf("%s", unidadeSaida);
                printf("Resultado: %.2lf\n", 
                    converterComprimento(valor, unidadeEntrada, unidadeSaida));
                break;

            case 4:
                printf("\n=== Conversão de Massa ===\n");
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Digite a unidade de entrada (kg/g/t): ");
                scanf("%s", unidadeEntrada);
                printf("Digite a unidade de saída (kg/g/t): ");
                scanf("%s", unidadeSaida);
                printf("Resultado: %.2lf\n", 
                    converterMassa(valor, unidadeEntrada, unidadeSaida));
                break;
            
            case 5:
                printf("\n=== Conversão de Tempo ===\n");
                printf("Em desenvolvimento...\n");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}