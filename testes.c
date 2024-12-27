#include <stdio.h>
#include <string.h>
#include <assert.h>

// Protótipos das funções
double conversaoTemperatura(double medicao, char unidade, char conversao);
double converterVelocidade(double valor, char entrada[], char saida[]);
double converterComprimento(double comprimento, char unidadeEntrada[], char unidadeSaida[]);
double converterMassa(double massa, char unidadeEntrada[], char unidadeSaida[]);
double converterTempo(double tempo, char unidadeEntrada[], char unidadeSaida[]);

void testarTemperatura() {
    printf("\nTestando conversões de temperatura...\n");
    
    // Celsius para Fahrenheit
    assert((int)conversaoTemperatura(0, 'C', 'F') == 32);
    assert((int)conversaoTemperatura(100, 'C', 'F') == 212);
    
    // Celsius para Kelvin
    assert((int)conversaoTemperatura(0, 'C', 'K') == 273);
    assert((int)conversaoTemperatura(100, 'C', 'K') == 373);
    
    // Fahrenheit para Celsius
    assert((int)conversaoTemperatura(32, 'F', 'C') == 0);
    assert((int)conversaoTemperatura(212, 'F', 'C') == 100);
    
    // Fahrenheit para Kelvin
    assert((int)conversaoTemperatura(32, 'F', 'K') == 273);
    
    // Kelvin para Celsius
    assert((int)conversaoTemperatura(273, 'K', 'C') == 0);
    
    // Kelvin para Fahrenheit
    assert((int)conversaoTemperatura(273, 'K', 'F') == 32);
    
    printf("Todos os testes de temperatura passaram!\n");
}

void testarVelocidade() {
    printf("\nTestando conversões de velocidade...\n");
    
    // km/h para m/s
    assert((int)converterVelocidade(36, "km", "m") == 10);
    
    // km/h para mph
    assert((int)converterVelocidade(100, "km", "ml") == 62);
    
    // m/s para km/h
    assert((int)converterVelocidade(10, "m", "km") == 36);
    
    // m/s para mph
    assert((int)converterVelocidade(10, "m", "ml") == 22);
    
    printf("Todos os testes de velocidade passaram!\n");
}

void testarComprimento() {
    printf("\nTestando conversões de comprimento...\n");
    
    // metros para centímetros
    assert((int)converterComprimento(1, "m", "cm") == 100);
    
    // metros para milímetros
    assert((int)converterComprimento(1, "m", "mm") == 1000);
    
    // centímetros para metros
    assert(converterComprimento(100, "cm", "m") == 1);
    
    // centímetros para milímetros
    assert((int)converterComprimento(1, "cm", "mm") == 10);
    
    printf("Todos os testes de comprimento passaram!\n");
}

void testarMassa() {
    printf("\nTestando conversões de massa...\n");
    
    // kg para g
    assert((int)converterMassa(1, "kg", "g") == 1000);
    
    // kg para t
    assert(converterMassa(1000, "kg", "t") == 1);
    
    // g para kg
    assert(converterMassa(1000, "g", "kg") == 1);
    
    // t para kg
    assert((int)converterMassa(1, "t", "kg") == 1000);
    
    printf("Todos os testes de massa passaram!\n");
}

void testarTempo() {
    printf("\nTestando conversões de tempo...\n");
    
    // horas para minutos
    assert((int)converterTempo(1, "h", "min") == 60);
    
    // horas para segundos
    assert((int)converterTempo(1, "h", "s") == 3600);
    
    // minutos para horas
    assert(converterTempo(60, "min", "h") == 1);
    
    // segundos para minutos
    assert(converterTempo(60, "s", "min") == 1);
    
    printf("Todos os testes de tempo passaram!\n");
}

int main() {
    printf("Iniciando testes...\n");
    
    testarTemperatura();
    testarVelocidade();
    testarComprimento();
    testarMassa();
    testarTempo();
    
    printf("\nTodos os testes passaram com sucesso!\n");
    return 0;
}


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
