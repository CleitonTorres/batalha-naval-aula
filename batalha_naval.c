#include <stdio.h>

#define TAM 10
#define H 5 // tamanho das matrizes de habilidades (5x5)

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[H][H], int origemLinha, int origemColuna) {
    int centro = H / 2; // centro da matriz da habilidade

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colTab = origemColuna + (j - centro);

                // Verifica se está dentro dos limites
                if (linhaTab >= 0 && linhaTab < TAM && colTab >= 0 && colTab < TAM) {
                    // Só marca se não for navio
                    if (tabuleiro[linhaTab][colTab] == 0) {
                        tabuleiro[linhaTab][colTab] = 5;
                    }
                }
            }
        }
    }
}

int main () {
    int tabuleiro[TAM][TAM] = {0};

    // ===================== POSICIONAMENTO DOS NAVIOS =====================
    int linhaNavio1 = 3, colInicio1 = 4; // Navio 1 horizontal
    for (int i = 0; i < 3; i++) tabuleiro[linhaNavio1][colInicio1 + i] = 3;

    int linhaNavio2 = 5, colInicio2 = 4; // Navio 2 vertical
    for (int i = 0; i < 3; i++) tabuleiro[linhaNavio2 + i][colInicio2] = 3;

    for (int i = 0; i < 3; i++) tabuleiro[i][i] = 3;       // Navio 3 diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[i][9 - i] = 3;   // Navio 4 diagonal secundária

    // ===================== HABILIDADES =====================

    int cone[H][H] = {0}; //criando os vetores das habilidades.
    int cruz[H][H] = {0};
    int octaedro[H][H] = {0};

    // --- Cone ---
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= (H/2 - i) && j <= (H/2 + i)) {
                cone[i][j] = 1;
            }
        }
    }

    // --- Cruz ---
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2) {
                cruz[i][j] = 1;
            }
        }
    }

    // --- Octaedro ---
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - H/2) + abs(j - H/2) <= H/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ===================== APLICAR HABILIDADES NO TABULEIRO =====================
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // cone centrado em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 6);      // cruz centrada em (6,6)
    aplicarHabilidade(tabuleiro, octaedro, 8, 3);  // octaedro centrado em (8,3)

    // ===================== IMPRIMIR TABULEIRO =====================
    printf("\n=== TABULEIRO FINAL ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");   // água
            else if (tabuleiro[i][j] == 3) printf("N "); // navio
            else if (tabuleiro[i][j] == 5) printf("* "); // habilidade
        }
        printf("\n");
    }

    return 0;
}