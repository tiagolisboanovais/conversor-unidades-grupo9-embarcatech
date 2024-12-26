#include <stdio.h>

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

double converterTempo(double tempo, char unidadeEntrada[], char unidadeSaida[]) {
    if (strcmp(unidadeEntrada, "h") == 0 && strcmp(unidadeSaida, "min") == 0) {
        return tempo * 60;
    } else if (strcmp(unidadeEntrada, "h") == 0 && strcmp(unidadeSaida, "s") == 0) {
        return tempo * 3600;
    } else if (strcmp(unidadeEntrada, "min") == 0 && strcmp(unidadeSaida, "h") == 0) {
        return tempo / 60;
    } else if (strcmp(unidadeEntrada, "min") == 0 && strcmp(unidadeSaida, "s") == 0) {
        return tempo * 60;
    } else if (strcmp(unidadeEntrada, "s") == 0 && strcmp(unidadeSaida, "h") == 0) {
        return tempo / 3600;
    } else if (strcmp(unidadeEntrada, "s") == 0 && strcmp(unidadeSaida, "min") == 0) {
        return tempo / 60;
    } else {
        printf("Unidade de conversão inválida.\n");
        return -1;
    }
}

void exemplosTemperatura() {
    printf("\n=== Exemplos de Conversão de Temperatura ===\n");
    printf("0°C para Fahrenheit: %.2f°F\n", conversaoTemperatura(0, 'C', 'F'));
    printf("98.6°F para Celsius: %.2f°C\n", conversaoTemperatura(98.6, 'F', 'C'));
    printf("300K para Celsius: %.2f°C\n", conversaoTemperatura(300, 'K', 'C'));
}

void exemplosVelocidade() {
    printf("\n=== Exemplos de Conversão de Velocidade ===\n");
    printf("100 km/h para m/s: %.2f m/s\n", converterVelocidade(100, "km", "m"));
    printf("60 mph para km/h: %.2f km/h\n", converterVelocidade(60, "ml", "km"));
    printf("15 m/s para km/h: %.2f km/h\n", converterVelocidade(15, "m", "km"));
}

void exemplosComprimento() {
    printf("\n=== Exemplos de Conversão de Comprimento ===\n");
    printf("1 metro para centímetros: %.2f cm\n", converterComprimento(1, "m", "cm"));
    printf("50 cm para mm: %.2f mm\n", converterComprimento(50, "cm", "mm"));
    printf("1000 mm para metros: %.2f m\n", converterComprimento(1000, "mm", "m"));
}

void exemplosMassa() {
    printf("\n=== Exemplos de Conversão de Massa ===\n");
    printf("1 kg para gramas: %.2f g\n", converterMassa(1, "kg", "g"));
    printf("1000000 g para toneladas: %.2f t\n", converterMassa(1000000, "g", "t"));
    printf("2 toneladas para kg: %.2f kg\n", converterMassa(2, "t", "kg"));
}

void exemplosTempo() {
    printf("\n=== Exemplos de Conversão de Tempo ===\n");
    printf("1 hora para minutos: %.2f min\n", converterTempo(1, "h", "min"));
    printf("120 minutos para horas: %.2f h\n", converterTempo(120, "min", "h"));
    printf("3600 segundos para horas: %.2f h\n", converterTempo(3600, "s", "h"));
}

int main() {
    printf("=== EXEMPLOS DE CONVERSÕES ===\n");
    
    exemplosTemperatura();
    exemplosVelocidade();
    exemplosComprimento();
    exemplosMassa();
    exemplosTempo();
    
    return 0;
}