/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1169
Data        : 05/05/2026
Objetivo    : Calcular a quantidade de kg de trigo no tabuleiro de damas.
Aprendizado : Uso de uint64_t para inteiros de 64 bits e conversão de unidades.
*/

#include <stdio.h>
#include <stdint.h>

int main() {
    int N, X;

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &X);

        uint64_t graos = 0;
        uint64_t quadrado = 1;

        for (int i = 0; i < X; i++) {
            graos += quadrado;
            quadrado *= 2;
        }

        uint64_t gramas = graos / 12;
        uint64_t kg = gramas / 1000;

        printf("%llu kg\n", kg);
    }

    return 0;
}
