/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1179
Data        : 21/05/2026
Objetivo    : Separar números pares e ímpares em vetores e exibi-los.
Aprendizado : Uso de vetores, estruturas de repetição e condicionais.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int valor;
    int par[5], impar[5];
    int i, p = 0, imp = 0;

    for(i = 0; i < 15; i++) {
        scanf("%d", &valor);

        if(valor % 2 == 0) {
            par[p] = valor;
            p++;

            if(p == 5) {
                for(int j = 0; j < 5; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                p = 0;
            }

        } else {
            impar[imp] = valor;
            imp++;

            if(imp == 5) {
                for(int j = 0; j < 5; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                imp = 0;
            }
        }
    }

    for(i = 0; i < imp; i++) {
        printf("impar[%d] = %d\n", i, impar[i]);
    }

    for(i = 0; i < p; i++) {
        printf("par[%d] = %d\n", i, par[i]);
    }

    return 0;
}
