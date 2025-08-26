#include <stdio.h>

int main () {
    int tabuleiro[10][10] = {0}; 
    int navio1[3]; // navio horizontal
    int navio2[3]; // navio horizontal
    int navio3[3]; // navio diagonal
    int navio4[3];  // navio diagonal

    // --- Posicionamento do navio 1 (horizontal) ---
    int linhaNavio1 = 3; // Linha fixa onde o navio horizontal ficará
    int colInicio1 = 4;  // Coluna inicial
    for (int i = 0; i < 3; i++) {
        navio1[i] = 3; // vetor do navio com valor 3
        tabuleiro[linhaNavio1][colInicio1 + i] = navio1[i];
    }

    // --- Posicionamento do navio 2 (vertical) ---
    int linhaNavio2 = 5; // Linha fixa onde o navio vertical ficará
    int colInicio2 = 4;  // Coluna inicial
    for (int i = 0; i < 3; i++) {
        navio2[i] = 3; // vetor do navio com valor 3
        if (tabuleiro[linhaNavio2 + i][colInicio2] == 0) {
            tabuleiro[linhaNavio2 + i][colInicio2] = navio2[i];
        } else {
            printf("ERRO: Sobreposição detectada navio 2!\n");
            return 1;
        }
    }

    // --- Posicionamento do navio 3 (diagonal principal) ---
    int linhaInicio3 = 0; // começa em (0,0)
    int colInicio3 = 0;
    for (int i = 0; i < 3; i++) {
        navio3[i] = 3;
        if (tabuleiro[linhaInicio3 + i][colInicio3 + i] == 0) {
            tabuleiro[linhaInicio3 + i][colInicio3 + i] = navio3[i];
        } else {
            printf("ERRO: Sobreposição detectada navio 3!\n");
            return 1;
        }
    }

    // --- Posicionamento do navio 4 (diagonal secundaria) ---
    int linhaInicio4 = 0; // começa em (0,9)
    int colInicio4 = 9;
    for (int i = 0; i < 3; i++) {
        navio4[i] = 3;
        if (tabuleiro[linhaInicio4 + i][colInicio4 - i] == 0) {
            tabuleiro[linhaInicio4 + i][colInicio4 - i] = navio4[i];
        } else {
            printf("ERRO: Sobreposição detectada navio 4!\n");
            return 1;
        }
    }

    

    //Mostrar matriz inicializada
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d | ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}