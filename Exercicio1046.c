/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1046
Data        : 21/05/2026
Objetivo    : Calcular a duração de um jogo em horas.
Aprendizado : Uso de estruturas condicionais e operações.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int inicio, fim, duracao;

    scanf("%d %d", &inicio, &fim);

    if (inicio < fim) {
        duracao = fim - inicio;
    } else {
        duracao = 24 - inicio + fim;
    }

    printf("O JOGO DUROU %d HORA(S)\n", duracao);

    return 0;
}
