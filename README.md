# Grupo 9 - Embarca Tech 🚀

Repositório criado pelo **Grupo 9** do programa **Embarca Tech** com o objetivo de colocar em prática os conhecimentos de **versionamento de código** e **trabalho colaborativo** utilizando **Git** e **GitHub**.

O projeto consiste no desenvolvimento de um **Conversor de Unidades** em linguagem **C**, onde cada integrante da equipe é responsável por uma funcionalidade específica, seguindo um fluxo de trabalho organizado com branches, commits e pull requests.

Este repositório é uma simulação de um ambiente de desenvolvimento real, promovendo a prática de habilidades essenciais como:

- **Colaboração em equipe**  
- **Uso eficiente do Git e GitHub**  
- **Integração de código**  
- **Testes e depuração**  

🚀 **Vamos juntos embarcar no aprendizado!** 🚀



## Como utilizar as funções

### Menu Principal
O programa vai mostrar um menu com as seguintes opções:
```
=== CONVERSOR DE UNIDADES ===
1 - Converter Temperatura
2 - Converter Velocidade
3 - Converter Comprimento
4 - Converter Massa
5 - Converter Tempo
0 - Sair
```
Basta digitar o número no terminal e dar enter que será direcionado para a opção selecionada

### 1. Conversor de Temperatura
- **Unidades**: C (Celsius), F (Fahrenheit), K (Kelvin)
- **Exemplo de uso**:
```
Digite o valor: 100
Digite a unidade de entrada (C/F/K): C
Digite a unidade de saída (C/F/K): F
Resultado: 212.00
```

### 2. Conversor de Velocidade
- **Unidades**: km (quilômetros/hora), m (metros/segundo), ml (milhas/hora)
- **Exemplo de uso**:
```
Digite o valor: 100
Digite a unidade de entrada (km/m/ml): km
Digite a unidade de saída (km/m/ml): m
Resultado: 27.78
```

### 3. Conversor de Comprimento
- **Unidades**: m (metros), cm (centímetros), mm (milímetros)
- **Exemplo de uso**:
```
Digite o valor: 1
Digite a unidade de entrada (m/cm/mm): m
Digite a unidade de saída (m/cm/mm): cm
Resultado: 100.00
```

### 4. Conversor de Massa
- **Unidades**: kg (quilogramas), g (gramas), t (toneladas)
- **Exemplo de uso**:
```
Digite o valor: 1
Digite a unidade de entrada (kg/g/t): kg
Digite a unidade de saída (kg/g/t): g
Resultado: 1000.00
```

### 5. Conversor de Tempo
- **Unidades**: h (horas), min (minutos), s (segundos)
- **Exemplo de uso**:
```
Digite o valor: 1
Digite a unidade de entrada (h/min/s): h
Digite a unidade de saída (h/min/s): min
Resultado: 60.00
```

### Observações Importantes
- Use ponto (.) para números decimais
- O programa retorna -1 ou -500 em caso de erro na conversão
- Para sair do programa, digite 0 no menu principal


## Como colaborar
1. Clone o repositório com `git clone https://github.com/tiagolisboanovais/conversor-unidades-grupo9-embarcatech/ `
2. Abra o vscode na pasta criada
3. Digite no terminal do vscode `git checkout -b feature/suaconversão`
4. Faça seu código e faça `git commit -m "Sua mudança"` de acordo com as alterações que fizer e quiser salvar
5. Ao finalizar seu código é hora de subir para o repositório com `git push --set-upstream origin feature/suaconversão`
6. Abra o github, entre na sua branch e envie um pull request para o líder aprovar
