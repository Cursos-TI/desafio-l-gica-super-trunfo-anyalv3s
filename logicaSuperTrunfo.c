#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(Carta c) {
    return c.populacao / c.area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(Carta c) {
    return c.pib / c.populacao;
}

// Função para comparar as cartas e determinar a vencedora
void compararCartas(Carta c1, Carta c2) {
    // Escolhemos o atributo "População" para a comparação
    printf("\nComparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", c1.nome_cidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n\n", c2.nome_cidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Definição das duas cartas
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 699.28, 25};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.27, 400.45, 30};
    
    // Exibição das informações das cartas
    printf("=== Cartas Cadastradas ===\n");
    printf("\nCarta 1 - %s (%s):\n", carta1.nome_cidade, carta1.estado);
    printf("População: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\n", 
           carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per capita: %.2f\n", 
           calcularDensidadePopulacional(carta1), calcularPibPerCapita(carta1));
    
    printf("\nCarta 2 - %s (%s):\n", carta2.nome_cidade, carta2.estado);
    printf("População: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\n", 
           carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per capita: %.2f\n", 
           calcularDensidadePopulacional(carta2), calcularPibPerCapita(carta2));
    
    // Comparação das cartas
    compararCartas(carta1, carta2);
    
    return 0;
}