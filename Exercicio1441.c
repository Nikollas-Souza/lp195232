/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1441
Data        : 03/05/2026
Objetivo    : Encontrar o maior número na Sequência de Granizo.
Aprendizado : Estrutura de repetição com condição de parada e rastreamento de valor máximo.
*/

#include <stdio.h>

int main() {
    int h;

    while (scanf("%d", &h) && h != 0) {
        int max = h;
        int n = h;

        while (n != 1) {
            if (n % 2 == 0)
                n = n / 2;
            else
                n = 3 * n + 1;

            if (n > max)
                max = n;
        }

        printf("%d\n", max);
    }

    return 0;
}
