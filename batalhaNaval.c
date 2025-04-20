#include <stdio.h> 

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Constantes para o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com valor 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função que verifica se o navio pode ser posicionado sem sair do tabuleiro ou sobrepor outro
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (horizontal ? 0 : i);
        int c = coluna + (horizontal ? i : 0);

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }

        if (tabuleiro[l][c] != 0) {
            return 0; // Já tem navio nessa posição
        }
    }
    return 1;
}

// Copia o valor 3 nas posições do tabuleiro correspondentes ao navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (horizontal ? 0 : i);
        int c = coluna + (horizontal ? i : 0);
        tabuleiro[l][c] = 3;
    }
}

// Exibe o tabuleiro completo no console com 0 (água) e 3 (navios)
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n--- TABULEIRO ---\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (pré-definidas no código)
    int linhaNavio1 = 2, colunaNavio1 = 4; // Navio horizontal
    int linhaNavio2 = 5, colunaNavio2 = 6; // Navio vertical

    // Validação e posicionamento dos navios
    if (podePosicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 1)) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 1);
    } else {
        printf("Erro: Navio 1 não pode ser posicionado nas coordenadas informadas.\n");
    }

    if (podePosicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 0)) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 0);
    } else {
        printf("Erro: Navio 2 não pode ser posicionado nas coordenadas informadas.\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}