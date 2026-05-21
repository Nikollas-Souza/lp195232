/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1168
Data        : 21/05/2026
Objetivo    : Calcular a quantidade de leds necessária para formar números.
Aprendizado : Uso de vetores, strings e estruturas de repetição.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char numero[101];
    
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s", numero);

        int total = 0;

        for(j = 0; j < strlen(numero); j++) {
            total += leds[numero[j] - '0'];
        }

        printf("%d leds\n", total);
    }

    return 0;
}
