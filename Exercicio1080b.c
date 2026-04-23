

#include <stdio.h>

int main() {
    int v[100];
    int maior, posicao;

    // Leitura dos 100 valores
    for (int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);
    }

    // Inicializa com o primeiro valor
    maior = v[0];
    posicao = 1;

    // Procura o maior
    for (int i = 1; i < 100; i++) {
        if (v[i] > maior) {
            maior = v[i];
            posicao = i + 1; // +1 porque posição começa em 1
        }
    }

    // Saída
    printf("%d\n", maior);
    printf("%d\n", posicao);

    return 0;
}
