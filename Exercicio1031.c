/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1031
Data        : 18/06/2026
Objetivo    : Encontrar o menor salto para que a região 13 seja desligada por último.
Aprendizado : Aprendi a aplicar o problema de Josephus e testar valores em repetição.
*/

#include <stdio.h>

int josephus(int n, int m) {
    int pos = 0;

    for (int i = 2; i < n; i++) {
        pos = (pos + m) % i;
    }

    return pos;
}

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int m = 1;

        while (1) {
            if (josephus(n, m) == 11) {
                printf("%d\n", m);
                break;
            }
            m++;
        }
    }

    return 0;
}
