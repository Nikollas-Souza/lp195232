/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1028
Data        : 03/06/2026
Objetivo    : Encontrar o tamanho máximo das pilhas usando MDC.
Aprendizado : Algoritmo de Euclides para calcular o MDC.
*/

#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, F1, F2;

    scanf("%d", &N);

    while (N--) {
        scanf("%d %d", &F1, &F2);
        printf("%d\n", mdc(F1, F2));
    }

    return 0;
}
