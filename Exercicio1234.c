/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1234
Data        : 18/06/2026
Objetivo    : Fazer a frase ficar com letras maiúsculas e minúsculas alternadas.
Aprendizado : Aprendi a mexer com strings, laços e funções para alterar letras.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char line[256];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }

        int upper_next = 1;
        for (size_t i = 0; i < len; i++) {
            char c = line[i];
            if (c == ' ') {
                /* preserva espaço e não altera o alternador */
                putchar(' ');
            } else {
                if (upper_next)
                    putchar(toupper((unsigned char)c));
                else
                    putchar(tolower((unsigned char)c));
                upper_next = !upper_next;
            }
        }
        putchar('\n');
    }
    return 0;
}
