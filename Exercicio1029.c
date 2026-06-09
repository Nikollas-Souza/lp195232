/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1029
Data        : 27/05/2026
Objetivo    : Calcular Fibonacci e contar chamadas recursivas.
Aprendizado : Recursão e contagem de chamadas com variável global.
*/

#include <stdio.h>

int calls;

int fib(int n) {
    calls++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N, X;

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &X);
        calls = 0;
        int result = fib(X);
        printf("fib(%d) = %d calls = %d\n", X, calls - 1, result);
    }

    return 0;
}
