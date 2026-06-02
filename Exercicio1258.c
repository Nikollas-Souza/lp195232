/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1258
Data        : 02/06/2026
Objetivo    : Ordenar lista de camisetas por cor, tamanho e nome
Aprendizado : Uso de qsort com struct e leitura mista com fgets/scanf
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[200];
    char color[10];
    char size[3];
} Shirt;

int size_order(char *size) {
    if (strcmp(size, "P") == 0) return 0;
    if (strcmp(size, "M") == 0) return 1;
    return 2;
}

int compare(const void *a, const void *b) {
    Shirt *sa = (Shirt *)a;
    Shirt *sb = (Shirt *)b;

    int cmp_color = strcmp(sa->color, sb->color);
    if (cmp_color != 0) return cmp_color;

    int cmp_size = size_order(sa->size) - size_order(sb->size);
    if (cmp_size != 0) return cmp_size;

    return strcmp(sa->name, sb->name);
}

int main() {
    int n;
    int first_case = 1;

    while (scanf("%d", &n) == 1 && n != 0) {
        Shirt shirts[60];
        getchar();

        for (int i = 0; i < n; i++) {
            fgets(shirts[i].name, sizeof(shirts[i].name), stdin);
            shirts[i].name[strcspn(shirts[i].name, "\n")] = '\0';

            scanf("%s %s", shirts[i].color, shirts[i].size);
            getchar();
        }

        qsort(shirts, n, sizeof(Shirt), compare);

        if (!first_case) printf("\n");
        first_case = 0;

        for (int i = 0; i < n; i++) {
            printf("%s %s %s\n", shirts[i].color, shirts[i].size, shirts[i].name);
        }
    }

    return 0;
}
