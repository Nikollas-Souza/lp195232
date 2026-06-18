/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 18/06/2026
Objetivo    : Encontrar o menor valor de um vetor e sua posição.
Aprendizado : Aprendi a percorrer vetores e comparar valores.
*/

#include <stdio.h>

int main() {
    int n, x[1000];
    int menor, posicao;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);

        if (i == 0 || x[i] < menor) {
            menor = x[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
