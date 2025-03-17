#include <stdio.h>

// Função recursiva para movimento da Torre (vertical ou horizontal)
void moveTorre(int casas, char* direcao, int atual) {
    if (atual > casas) return;  // Caso base da recursão
    printf("%s\n", direcao);
    moveTorre(casas, direcao, atual + 1);  // Chamada recursiva
}

// Função recursiva para movimento do Bispo (diagonal)
void moveBispoRecursivo(int casas, int atual) {
    if (atual > casas) return;  // Caso base
    printf("Cima\n");
    printf("Direita\n");
    moveBispoRecursivo(casas, atual + 1);
}

// Função com loops aninhados para o Bispo
void moveBispoLoop(int casas) {
    for (int vertical = 1; vertical <= casas; vertical++) {    // Loop externo vertical
        for (int horizontal = 1; horizontal <= 1; horizontal++) {  // Loop interno horizontal
            printf("Cima\n");
            printf("Direita\n");
        }
    }
}

// Função recursiva para movimento da Rainha (combinação de Torre e Bispo)
void moveRainha(int casas, int atual) {
    if (atual > casas) return;  // Caso base
    printf("Cima\n");           // Movimento vertical
    printf("Direita\n");        // Movimento diagonal
    moveRainha(casas, atual + 1);
}

// Função com loops complexos para o Cavalo (L: 2 cima, 1 direita)
void moveCavalo(int repeticoes) {
    int contador = 0;
    for (int i = 0; i < repeticoes; i++) {
        for (int cima = 0; cima < 2; cima++) {    // 2 casas para cima
            printf("Cima\n");
            contador++;
            if (contador >= repeticoes * 3) break;  // Controle de limite
        }
        printf("Direita\n");    // 1 casa para direita
        contador++;
        if (contador >= repeticoes * 3) break;     // Break para sair do loop externo
        continue;
    }
}

int main() {
    // Definindo constantes para número de casas
    const int CASAS_TORRE = 3;
    const int CASAS_BISPO = 3;
    const int CASAS_RAINHA = 3;
    const int REPETICOES_CAVALO = 2;

    // Movimentação da Torre
    printf("Movimento da Torre:\n");
    moveTorre(CASAS_TORRE, "Cima", 1);
    printf("\n");

    // Movimentação do Bispo (recursivo)
    printf("Movimento do Bispo (recursivo):\n");
    moveBispoRecursivo(CASAS_BISPO, 1);
    printf("\n");

    // Movimentação do Bispo (loops aninhados)
    printf("Movimento do Bispo (loops):\n");
    moveBispoLoop(CASAS_BISPO);
    printf("\n");

    // Movimentação da Rainha
    printf("Movimento da Rainha:\n");
    moveRainha(CASAS_RAINHA, 1);
    printf("\n");

    // Movimentação do Cavalo
    printf("Movimento do Cavalo:\n");
    moveCavalo(REPETICOES_CAVALO);
    printf("\n");
    

    return 0;
}