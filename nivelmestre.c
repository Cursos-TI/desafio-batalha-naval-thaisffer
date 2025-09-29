#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5  // 5x5 para habilidades
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// ---------------------------------------------------------
// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// ---------------------------------------------------------
// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ---------------------------------------------------------
// Posiciona um navio horizontal fixo para visualização
void posicionarNaviosExemplo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // navio horizontal na linha 2, colunas 3 a 5
    for (int j = 3; j < 6; j++) {
        tabuleiro[2][j] = NAVIO;
    }
    // navio vertical na coluna 7, linhas 5 a 7
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = NAVIO;
    }
}

// ---------------------------------------------------------
// Cria matriz de habilidade em forma de cone (apontando para baixo)
void criarMatrizCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2; // posição central

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condição: a cada linha abaixo do topo, a largura do cone aumenta
            int largura = i; // cresce conforme desce
            if (j >= meio - largura && j <= meio + largura)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// ---------------------------------------------------------
// Cria matriz de habilidade em forma de cruz
void criarMatrizCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == meio || j == meio)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// ---------------------------------------------------------
// Cria matriz de habilidade em forma de octaedro (losango)
void criarMatrizOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância de Manhattan <= meio -> forma um losango
            int dist = abs(i - meio) + abs(j - meio);
            if (dist <= meio)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// ---------------------------------------------------------
// Aplica uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {

    int meio = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - meio);
                int colunaTab = origemColuna + (j - meio);

                // Verifica se está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {

                    // Marca área de habilidade com 5
                    // (mantém navio se já houver, mas poderia sobrepor se quisesse)
                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// ---------------------------------------------------------
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    posicionarNaviosExemplo(tabuleiro);

    // Matrizes das habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Coordenadas no tabuleiro (definidas no código)
    int origemConeLinha = 1, origemConeColuna = 1;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 8, origemOctaedroColuna = 2;

    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    exibirTabuleiro(tabuleiro);

    return 0;
}
