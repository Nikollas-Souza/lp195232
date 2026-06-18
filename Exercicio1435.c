/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1435
Data        : 18/06/2026
Objetivo    : Construir uma matriz quadrada com valores crescentes até o centro.
Aprendizado : Aprendi a trabalhar com matrizes, laços e lógica de posição.
*/

#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int valor = i + 1;

                if (j + 1 < valor)
                    valor = j + 1;
                if (n - i < valor)
                    valor = n - i;
                if (n - j < valor)
                    valor = n - j;

                if (j == 0)
                    printf("%3d", valor);
                else
                    printf(" %3d", valor);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
