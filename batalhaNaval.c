#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Criar tabuleiro 10x10 e inicializar com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definição dos navios
    int tamanho_navio = 3; // Todos os navios terão tamanho 3

    // Posições fixas escolhidas diretamente no código

    // Navio 1 - Horizontal (linha 0, colunas 0 a 2)
    for (int j = 0; j < tamanho_navio; j++) {
        tabuleiro[0][j] = 3;
    }

    // Navio 2 - Vertical (coluna 5, linhas 2 a 4)
    for (int i = 2; i < 2 + tamanho_navio; i++) {
        tabuleiro[i][5] = 3;
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Posicionar Navio 3 - Diagonal principal (linha 6, coluna 6 até 6+2,6+2)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[6 + i][6 + i] = 3;
    }

    // Posicionar Navio 4 - Diagonal secundária (linha 3, coluna 6 até 3+2,6-2)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[3 + i][6 - i] = 3;
    }

    // Exibir o tabuleiro completo
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

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
    // Tamanho da matriz de habilidade
    int tamanho = 5;
    int meio = tamanho / 2;

    // Matriz Cone
    int cone[5][5] = {0};
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (j >= meio - i && j <= meio + i && i <= meio)
                cone[i][j] = 1;
        }
    }

    // Matriz Cruz
    int cruz[5][5] = {0};
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == meio || j == meio)
                cruz[i][j] = 1;
        }
    }

    // Matriz Octaedro
    int octaedro[5][5] = {0};
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
        }
    }

    // Função para aplicar matriz de habilidade no tabuleiro
    void aplicarHabilidade(int tab[10][10], int hab[5][5], int origemX, int origemY) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int x = origemX + i - 2;
                int y = origemY + j - 2;
                if (x >= 0 && x < 10 && y >= 0 && y < 10 && hab[i][j] == 1 && tab[x][y] == 0) {
                    tab[x][y] = 5; // Marca área afetada pela habilidade
                }
            }
        }
    }

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 1);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);

    // Exibir o tabuleiro final com áreas afetadas pelas habilidades
    printf("\nTabuleiro com Áreas Afetadas (0 = água, 3 = navio, 5 = habilidade):\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

 return 0;
}

