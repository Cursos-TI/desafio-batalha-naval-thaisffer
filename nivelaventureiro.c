#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição está livre
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

// Função para posicionar navio horizontal
int posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    // Verifica se há espaço livre
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha, coluna + i)) return 0;
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha + i, coluna)) return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio diagonal ↘ (linha e coluna crescem)
int posicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha + i, coluna + i)) return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio diagonal ↙ (linha cresce, coluna decresce)
int posicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha + i, coluna - i)) return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // --- POSICIONAMENTO DOS 4 NAVIOS ---
    // Navio 1 - Horizontal
    if (!posicionarHorizontal(tabuleiro, 1, 2))
        printf("Falha ao posicionar navio horizontal.\n");

    // Navio 2 - Vertical
    if (!posicionarVertical(tabuleiro, 5, 7))
        printf("Falha ao posicionar navio vertical.\n");

    // Navio 3 - Diagonal ↘
    if (!posicionarDiagonalPrincipal(tabuleiro, 3, 3))
        printf("Falha ao posicionar navio diagonal ↘.\n");

    // Navio 4 - Diagonal ↙
    if (!posicionarDiagonalSecundaria(tabuleiro, 0, 9))
        printf("Falha ao posicionar navio diagonal ↙.\n");

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
