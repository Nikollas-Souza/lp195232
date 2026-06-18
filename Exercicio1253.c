/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1253
Data        : 18/06/2026
Objetivo    : Decodificar palavras usando a Cifra de César.
Aprendizado : Aprendi a usar strings, laços e manipular letras no alfabeto.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n, deslocamento;
    char palavra[51];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", palavra);
        scanf("%d", &deslocamento);

        int tamanho = strlen(palavra);

        for (int j = 0; j < tamanho; j++) {
            palavra[j] = palavra[j] - deslocamento;

            if (palavra[j] < 'A') {
                palavra[j] = palavra[j] + 26;
            }
        }

        printf("%s\n", palavra);
    }

    return 0;
}
