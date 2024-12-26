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
    printf("Exemplo do conversor de comprimento\n");
    printf("Exemplo 1:\n");
    // Comprimento em metros
    double comprimento = 150;
    printf("Comprimento em metros: %.2lfm\n", comprimento);
    printf("Comprimento em centímetros: %.2lfcm\n", converterComprimento(comprimento, "m", "cm"));
    printf("Comprimento em milímetros: %.2lfmm\n", converterComprimento(comprimento, "m", "mm"));

    printf("Exemplo 2:\n");
    // Comprimento em centímetros
    comprimento = 15;
    printf("Comprimento em centímetros: %.2lfcm\n", comprimento);
    printf("Comprimento em metros: %.2lfm\n", converterComprimento(comprimento, "cm", "m"));
    printf("Comprimento em milímetros: %.2lfmm\n", converterComprimento(comprimento, "cm", "mm"));



    printf("Exemplo do conversor de temperatura\n");
    double temp;
    char uni1, uni2;
    int l;
    
    // Interface simples para uso da função de conversão
    printf("Conversor de Unidades de Temperatura\n");
    do
    {
        l = 1;
        printf("Digite a sua medição (com unidade): ");
        scanf("%lf %c%*c", &temp, &uni1);
        printf("\n");
        printf("Digite a unidade para conversao: ");
        scanf("%c%*c", &uni2);

        temp = conversaoTemperatura(temp, uni1, uni2);
        //Valida entrada de unidade do usuário
        if(temp <= -500)
            printf("Unidade de temperatura não reconhecida, tente novamente\n\n");
        else{ 
            printf("%.3lf%s%c\n", temp, uni2 !='K' ? " *": " ",  uni2);
            l = 0;
        }
    } while (l);

    return 0;
}