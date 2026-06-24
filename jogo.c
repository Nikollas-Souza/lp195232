/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : jogo sudoku
Data        : 23/06/2026
Objetivo    : Jogo interativo de Sudoku no console com leitura de arquivo input2.txt
Aprendizado : Manipulação de arquivos, lógica de validação, interface interativa no console
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define VERMELHO    "\033[31m"
#define VERDE       "\033[32m"
#define AMARELO     "\033[33m"
#define AZUL        "\033[34m"
#define MAGENTA     "\033[35m"
#define CIANO       "\033[36m"
#define BRANCO      "\033[37m"
#define FUNDO_AZUL  "\033[44m"
#define FUNDO_CINZA "\033[100m"

int original[9][9];   
int jogador[9][9];    
int erros;
int movimentos;

int valido(int m[9][9], int lin, int col, int num) {
    int i, j;

    for (j = 0; j < 9; j++)
        if (m[lin][j] == num) return 0;

    for (i = 0; i < 9; i++)
        if (m[i][col] == num) return 0;

    int bi = (lin / 3) * 3;
    int bj = (col / 3) * 3;
    for (i = bi; i < bi + 3; i++)
        for (j = bj; j < bj + 3; j++)
            if (m[i][j] == num) return 0;

    return 1;
}

int concluido() {
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            if (jogador[i][j] == 0) return 0;
    return 1;
}

int verificar_solucao(int m[9][9]) {
    int freq[10], i, j, bi, bj;

    for (i = 0; i < 9; i++) {
        memset(freq, 0, sizeof(freq));
        for (j = 0; j < 9; j++) freq[m[i][j]]++;
        for (j = 1; j <= 9; j++) if (freq[j] != 1) return 0;
    }

    for (j = 0; j < 9; j++) {
        memset(freq, 0, sizeof(freq));
        for (i = 0; i < 9; i++) freq[m[i][j]]++;
        for (i = 1; i <= 9; i++) if (freq[i] != 1) return 0;
    }

    for (bi = 0; bi < 3; bi++) {
        for (bj = 0; bj < 3; bj++) {
            memset(freq, 0, sizeof(freq));
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    freq[m[bi*3+i][bj*3+j]]++;
            for (i = 1; i <= 9; i++) if (freq[i] != 1) return 0;
        }
    }

    return 1;
}

int ler_arquivo(const char *nome, int instancia) {
    FILE *f = fopen(nome, "r");
    if (!f) {
        printf(VERMELHO "Erro: arquivo '%s' nao encontrado!\n" RESET, nome);
        return 0;
    }

    int n;
    fscanf(f, "%d", &n);

    if (instancia < 1 || instancia > n) {
        printf(VERMELHO "Instancia %d invalida. O arquivo tem %d instancia(s).\n" RESET, instancia, n);
        fclose(f);
        return 0;
    }

    int i, j, inst;
    for (inst = 1; inst <= instancia; inst++) {
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++) {
                fscanf(f, "%d", &original[i][j]);
                if (inst == instancia)
                    jogador[i][j] = original[i][j];
            }
    }

    fclose(f);
    return 1;
}


void limpar_tela() {
    printf("\033[2J\033[H");
}

void exibir_titulo() {
    printf(BOLD CIANO);
    printf("  +==================================+\n");
    printf("  |        SUDOKU INTERATIVO         |\n");
    printf("  +==================================+\n");
    printf(RESET);
}

void exibir_tabuleiro(int linha_sel, int col_sel) {
    int i, j;

    printf("\n");
    printf(BOLD "      1   2   3   4   5   6   7   8   9\n" RESET);
    printf("    +-----------+-----------+-----------+\n");

    for (i = 0; i < 9; i++) {
        if (i == 3 || i == 6)
            printf("    +-----------+-----------+-----------+\n");

        printf(BOLD " %d  " RESET, i + 1);

        for (j = 0; j < 9; j++) {
            if (j == 0 || j == 3 || j == 6)
                printf("|");
            else
                printf(" ");

            int selecionado = (i == linha_sel && j == col_sel);

            if (jogador[i][j] == 0) {
                if (selecionado)
                    printf(FUNDO_AZUL "   " RESET);
                else
                    printf("   ");
            } else if (original[i][j] != 0) {
                if (selecionado)
                    printf(FUNDO_AZUL BOLD BRANCO " %d " RESET, jogador[i][j]);
                else
                    printf(BOLD BRANCO " %d " RESET, jogador[i][j]);
            } else {
                if (selecionado)
                    printf(FUNDO_AZUL VERDE " %d " RESET, jogador[i][j]);
                else
                    printf(VERDE " %d " RESET, jogador[i][j]);
            }
        }

        printf("|\n");
    }

    printf("    +-----------+-----------+-----------+\n");
}

void exibir_status(int linha_sel, int col_sel) {
    printf("\n");
    printf(AMARELO "  Movimentos: %d   " RESET, movimentos);
    printf(VERMELHO "Erros: %d\n" RESET, erros);

    if (linha_sel >= 0)
        printf(CIANO "  Celula selecionada: linha %d, coluna %d\n" RESET,
               linha_sel + 1, col_sel + 1);

    printf("\n");
    printf(BOLD "  COMANDOS:\n" RESET);
    printf("  [1-9]      -> Linha desejada\n");
    printf("  [1-9]      -> Coluna desejada\n");
    printf("  [1-9]      -> Numero a inserir\n");
    printf("  [0]        -> Apagar celula\n");
    printf("  [v]        -> Verificar solucao\n");
    printf("  [r]        -> Reiniciar\n");
    printf("  [s]        -> Sair\n");
    printf("\n");
}


void reiniciar() {
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            jogador[i][j] = original[i][j];
    erros = 0;
    movimentos = 0;
}

void jogar() {
    int linha, col, num;
    char cmd[10];

    erros = 0;
    movimentos = 0;

    while (1) {
        limpar_tela();
        exibir_titulo();
        exibir_tabuleiro(-1, -1);
        exibir_status(-1, -1);

        if (concluido()) {
            if (verificar_solucao(jogador)) {
                printf(VERDE BOLD "\n  *** PARABENS! Sudoku resolvido corretamente! ***\n\n" RESET);
            } else {
                printf(VERMELHO BOLD "\n  Tabuleiro completo, mas com erros!\n\n" RESET);
            }
            printf("  Pressione ENTER para sair...");
            getchar(); getchar();
            break;
        }

        printf(AMARELO "  Digite a LINHA (1-9) ou comando (v/r/s): " RESET);
        scanf("%s", cmd);

        if (cmd[0] == 's' || cmd[0] == 'S') {
            printf(CIANO "\n  Saindo do jogo. Ate logo!\n\n" RESET);
            break;
        }

        if (cmd[0] == 'r' || cmd[0] == 'R') {
            reiniciar();
            printf(AMARELO "\n  Jogo reiniciado!\n" RESET);
            continue;
        }

        if (cmd[0] == 'v' || cmd[0] == 'V') {
            limpar_tela();
            exibir_titulo();
            exibir_tabuleiro(-1, -1);
            if (verificar_solucao(jogador))
                printf(VERDE BOLD "\n  Solucao CORRETA! SIM\n\n" RESET);
            else
                printf(VERMELHO BOLD "\n  Solucao INCORRETA! NAO\n\n" RESET);
            printf("  Pressione ENTER para continuar...");
            getchar(); getchar();
            continue;
        }

        linha = cmd[0] - '1';
        if (linha < 0 || linha > 8) {
            printf(VERMELHO "  Linha invalida!\n" RESET);
            getchar(); getchar();
            continue;
        }

        limpar_tela();
        exibir_titulo();
        exibir_tabuleiro(linha, -1);
        exibir_status(linha, -1);
        printf(AMARELO "  Digite a COLUNA (1-9): " RESET);
        scanf("%s", cmd);

        col = cmd[0] - '1';
        if (col < 0 || col > 8) {
            printf(VERMELHO "  Coluna invalida!\n" RESET);
            getchar(); getchar();
            continue;
        }

        if (original[linha][col] != 0) {
            limpar_tela();
            exibir_titulo();
            exibir_tabuleiro(linha, col);
            printf(VERMELHO "\n  Essa celula e fixa e nao pode ser alterada!\n" RESET);
            printf("  Pressione ENTER para continuar...");
            getchar(); getchar();
            continue;
        }

        limpar_tela();
        exibir_titulo();
        exibir_tabuleiro(linha, col);
        exibir_status(linha, col);
        printf(AMARELO "  Digite o NUMERO (1-9) ou 0 para apagar: " RESET);
        scanf("%s", cmd);

        num = cmd[0] - '0';

        if (num == 0) {
            jogador[linha][col] = 0;
            printf(CIANO "\n  Celula apagada.\n" RESET);
            getchar(); getchar();
            continue;
        }

        if (num < 1 || num > 9) {
            printf(VERMELHO "  Numero invalido!\n" RESET);
            getchar(); getchar();
            continue;
        }

        movimentos++;

        jogador[linha][col] = 0;

        if (!valido(jogador, linha, col, num)) {
            jogador[linha][col] = num;
            erros++;
            limpar_tela();
            exibir_titulo();
            exibir_tabuleiro(linha, col);
            printf(VERMELHO "\n  Numero %d invalido nessa posicao! (Erro #%d)\n" RESET, num, erros);
            printf("  Pressione ENTER para continuar...");
            getchar(); getchar();
        } else {
            jogador[linha][col] = num;
            limpar_tela();
            exibir_titulo();
            exibir_tabuleiro(linha, col);
            printf(VERDE "\n  Numero %d inserido com sucesso!\n" RESET, num);
            printf("  Pressione ENTER para continuar...");
            getchar(); getchar();
        }
    }
}


void menu_principal() {
    char arq[100];
    int inst;
    char cmd[10];

    limpar_tela();
    exibir_titulo();

    printf(BOLD "\n  Bem-vindo ao Sudoku Interativo!\n\n" RESET);
    printf("  [1] Jogar com input2.txt\n");
    printf("  [2] Jogar com outro arquivo\n");
    printf("  [3] Apenas verificar arquivo (modo beecrowd)\n");
    printf("  [s] Sair\n\n");
    printf(AMARELO "  Escolha: " RESET);
    scanf("%s", cmd);

    if (cmd[0] == 's' || cmd[0] == 'S') return;

    if (cmd[0] == '1') {
        strcpy(arq, "input2.txt");
    } else if (cmd[0] == '2') {
        printf(AMARELO "  Nome do arquivo: " RESET);
        scanf("%s", arq);
    } else if (cmd[0] == '3') {
        printf(AMARELO "  Nome do arquivo de entrada: " RESET);
        scanf("%s", arq);
        FILE *f = fopen(arq, "r");
        if (!f) { printf(VERMELHO "  Arquivo nao encontrado!\n" RESET); return; }
        int n, i, j, k;
        fscanf(f, "%d", &n);
        int mat[9][9];
        limpar_tela();
        exibir_titulo();
        printf("\n");
        for (k = 1; k <= n; k++) {
            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    fscanf(f, "%d", &mat[i][j]);
            printf(BOLD "  Instancia %d\n" RESET, k);
            if (verificar_solucao(mat))
                printf(VERDE "  SIM\n\n" RESET);
            else
                printf(VERMELHO "  NAO\n\n" RESET);
        }
        fclose(f);
        printf("  Pressione ENTER para sair...");
        getchar(); getchar();
        return;
    } else {
        printf(VERMELHO "  Opcao invalida.\n" RESET);
        return;
    }

    printf(AMARELO "  Instancia do arquivo (1, 2, ...): " RESET);
    scanf("%d", &inst);

    if (!ler_arquivo(arq, inst)) {
        printf("  Pressione ENTER...");
        getchar(); getchar();
        return;
    }

    jogar();
}


int main() {
    menu_principal();
    return 0;
}
