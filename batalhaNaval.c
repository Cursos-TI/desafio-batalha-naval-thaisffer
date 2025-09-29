#include <stdio.h>

#define TAMANHO 10   // tamanho fixo do tabuleiro 10x10
#define NAVIO 3      // valor que representa uma parte do navio
#define AGUA 0       // valor que representa água
#define TAM_NAVIO 3  // tamanho fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // matriz para representar o tabuleiro
    int i, j;

    // 1. Inicializar todo o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Definir coordenadas iniciais dos navios
    // Navio horizontal (linha fixa, percorre colunas)
    int linhaH = 2, colunaH = 4; // posição inicial do navio horizontal
    // Navio vertical (coluna fixa, percorre linhas)
    int linhaV = 5, colunaV = 7; // posição inicial do navio vertical

    // 3. Validar se os navios cabem no tabuleiro
    if (colunaH + TAM_NAVIO <= TAMANHO && linhaV + TAM_NAVIO <= TAMANHO) {
        
        // 4. Posicionar navio horizontal
        for (j = 0; j < TAM_NAVIO; j++) {
            // garantir que não vai sobrepor
            if (tabuleiro[linhaH][colunaH + j] == AGUA) {
                tabuleiro[linhaH][colunaH + j] = NAVIO;
            }
        }

        // 5. Posicionar navio vertical
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == AGUA) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    } else {
        printf("Erro: coordenadas inválidas. O navio não cabe no tabuleiro.\n");
        return 1;
    }

    // 6. Exibir o tabuleiro
    printf("===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
