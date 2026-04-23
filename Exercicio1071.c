/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1071
Data        : 18/04/2026
Objetivo    : Ler 2 valores inteiros, calcular e mostrar a soma dos numeros ímpares entre eles".
Aprendizado : <a implementação do for e a compreensão de como pode ser utilizado>
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int X, Y, soma = 0;

    scanf("%d %d", &X, &Y);

    int inicio = X < Y ? X : Y;
    int fim = X > Y ? X : Y;

    for (int i = inicio + 1; i < fim; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }

    printf("%d\n", soma);

    return 0;
}
