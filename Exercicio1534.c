/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1534
Data        : 14/05/2026
Objetivo    : Ler um valor inteiro N que é o tamanho da matriz que deve ser impressa conforme o modelo fornecido..
Aprendizado : Aprender a utilizar especificadores de formatação do printf, controlando casas decimais, notação científica, alinhamento
e espaçamento de valores float e double.
*/

#include <stdio.h>

int main() {

    int N;

    while (scanf("%d", &N) != EOF) {

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                if (i + j == N - 1)
                    printf("2");

                else if (i == j)
                    printf("1");

                else
                    printf("3");
            }

            printf("\n");
        }
    }

    return 0;
}
