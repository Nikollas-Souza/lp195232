/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 23/04/2026
Objetivo    : Ler 100 valores inteiros e apresentar o maior valor lido e a posição dentre os 100 valores lidos".
Aprendizado : <utilização de vetor junto com o for>
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int v[100];
    int maior, posicao;

    // Leitura dos 100 valores
    for (int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);
    }

    // Inicializa com o primeiro valor
    maior = v[0];
    posicao = 1;

    // Procura o maior
    for (int i = 1; i < 100; i++) {
        if (v[i] > maior) {
            maior = v[i];
            posicao = i + 1; // +1 porque posição começa em 1
        }
    }

    // Saída
    printf("%d\n", maior);
    printf("%d\n", posicao);

    return 0;
}
