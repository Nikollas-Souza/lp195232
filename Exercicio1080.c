/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 23/04/2026
Objetivo    : Ler 100 valores inteiros e apresentar o maior valor lido e a posição dentre os 100 valores lidos".
Aprendizado : <utilização for if e else if dentro do for>
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int valor, maior, posicao;

    for (int i = 1; i <= 100; i++) {
        scanf("%d", &valor);

        if (i == 1) {
            maior = valor;
            posicao = i;
        } else if (valor > maior) {
            maior = valor;
            posicao = i;
        }
    }

    printf("%d\n", maior);
    printf("%d\n", posicao);

    return 0;
}
