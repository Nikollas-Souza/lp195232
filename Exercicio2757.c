/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1000
Data        : 18/04/2026
Objetivo    : Ler tres variaveis e organiza-las com espaçamento".
Aprendizado : <a utilização do espaçamento de caracteres e uma identação específica>
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int A, B, C;
    
    if (scanf("%d %d %d", &A, &B, &C) != 3) return 0;

    printf("A = %d, B = %d, C = %d\n", A, B, C);

    printf("A = %10d, B = %10d, C = %10d\n", A, B, C);

    printf("A = %010d, B = %010d, C = %010d\n", A, B, C);

    printf("A = %-10d, B = %-10d, C = %-10d\n", A, B, C);

    return 0;
}
