/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1241
Data        : 05/05/2026
Objetivo    : Verificar se um número B aparece no final de A".
Aprendizado : <Aprender a usar strings e comparar partes finais de texto>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char A[1001], B[1001];

    while (N--) {
        scanf("%s %s", A, B);

        int tamA = strlen(A);
        int tamB = strlen(B);

        if (tamB > tamA) {
            printf("nao encaixa\n");
        } else {
            if (strcmp(A + (tamA - tamB), B) == 0) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        }
    }

    return 0;
}
