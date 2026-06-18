/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1030
Data        : 18/06/2026
Objetivo    : Descobrir quem será o último sobrevivente no círculo.
Aprendizado : Aprendi a usar lógica matemática, laços e funções recursivas/iterativas.
*/

#include <stdio.h>

int josephus(int n, int k) {
    int resultado = 0;

    for (int i = 1; i <= n; i++) {
        resultado = (resultado + k) % i;
    }

    return resultado + 1;
}

int main() {
    int nc, n, k;

    scanf("%d", &nc);

    for (int i = 1; i <= nc; i++) {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k));
    }

    return 0;
}
