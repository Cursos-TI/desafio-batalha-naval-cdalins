#include <stdio.h>

// Camila Lins, curso de ADS, Estácio, 2025.1.

// Definindo os tamanhos do tabuleiro (linhas e colunas), e navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main(){
    // Declaração e inicialização do tabuleiro com zeros (zero = água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posição inicial do navio horizontal
    int coluna_navio_horizontal = 3;
    int linha_navio_horizontal = 2;

    // Posição inicial do navio vertical
    int coluna_navio_vertical = 4;
    int linha_navio_vertical = 6;

    // Verificação de limite para o navio horizontal
    if(coluna_navio_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO){
        printf("Ops, seu navio horizontal caiu no vácuo!\n");
        return 1;
    }

    // Verificação de limite para o navio vertical
    if(linha_navio_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO){
        printf("Ops, seu navio vertical caiu no vácuo!\n");
        return 1;
    }

    // Verificação de sobreposição dos dois navios
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        if(tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == 3 || tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3){
            printf("Ops, dois corpos não podem ocupar o mesmo lugar no tempo-espaço!\n");
            return 1;
        }
    }

    // Posicionando o navio horizontal
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
    }

    // Posicionando o navio vertical
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
    }

    // Exibindo o tabuleiro
    printf("✦ BATALHA NAVAL ✦\n");
    printf("✧ Tabuleiro %d ✕ %d ✧\n\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        for(int j = 0; j < TAMANHO_TABULEIRO; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Como só se chega até aqui sem erros:
    printf("\nE a batalha continua...\n\n");

    return 0;
}
