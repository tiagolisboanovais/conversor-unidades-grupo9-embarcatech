#include <stdio.h>

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


int main(void){
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