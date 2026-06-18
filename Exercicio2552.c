/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2552
Data        : 18/06/2026
Objetivo    : Montar o tabuleiro mostrando os pães de queijo e quantos existem ao redor.
Aprendizado : Aprendi a usar matrizes e verificar posições vizinhas.
*/

#include <stdio.h>

int main() {
    int n, m;
    int matriz[100][100];

    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matriz[i][j] == 1) {
                    printf("9");
                } else {
                    int cont = 0;

                    if (i > 0 && matriz[i - 1][j] == 1) cont++;
                    if (i < n - 1 && matriz[i + 1][j] == 1) cont++;
                    if (j > 0 && matriz[i][j - 1] == 1) cont++;
                    if (j < m - 1 && matriz[i][j + 1] == 1) cont++;

                    printf("%d", cont);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
