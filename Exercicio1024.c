/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1024
Data        : 18/06/2026
Objetivo    : Criptografar uma mensagem em três etapas.
Aprendizado : Aprendi a manipular strings, inverter texto e alterar caracteres.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    char texto[1001];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(texto, sizeof(texto), stdin);

        int tamanho = strlen(texto);

        if (texto[tamanho - 1] == '\n') {
            texto[tamanho - 1] = '\0';
            tamanho--;
        }

        for (int j = 0; j < tamanho; j++) {
            if (isalpha(texto[j])) {
                texto[j] = texto[j] + 3;
            }
        }

        for (int j = 0; j < tamanho / 2; j++) {
            char temp = texto[j];
            texto[j] = texto[tamanho - 1 - j];
            texto[tamanho - 1 - j] = temp;
        }

        for (int j = tamanho / 2; j < tamanho; j++) {
            texto[j] = texto[j] - 1;
        }

        printf("%s\n", texto);
    }

    return 0;
}
