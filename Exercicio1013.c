/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1013
Data        : 18/04/2026
Objetivo    : Mostrar o maior de 3 numeros".
Aprendizado : <introdução do if e else>
*/

#include <stdio.h>

int main() {

    int n1, n2, n3;

    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 > n2 && n1 > n3) {
        printf("%d eh o maior\n", n1);
    } 
    else if (n2 > n3) {
        printf("%d eh o maior\n", n2);
    } 
    else {
        printf("%d eh o maior\n", n3);
    }

    return 0;
}
