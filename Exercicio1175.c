/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1175
Data        : 18/06/2026
Objetivo    : Inverter os valores de um vetor de 20 posições.
Aprendizado : Aprendi a trocar valores em vetores usando variável auxiliar.
*/

#include <stdio.h>

int main() {
    int N[20], temp;

    for (int i = 0; i < 20; i++) {
        scanf("%d", &N[i]);
    }

    for (int i = 0; i < 10; i++) {
        temp = N[i];
        N[i] = N[19 - i];
        N[19 - i] = temp;
    }

    for (int i = 0; i < 20; i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
