/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 23/06/2026
Objetivo    : Verificar se uma matriz 9x9 preenchida é uma solução válida de Sudoku,
              checando se cada linha, coluna e região 3x3 contém os números de 1 a 9.
Aprendizado : Uso de arrays bidimensionais, funções de verificação com contador de
              frequência e leitura de múltiplas instâncias de entrada.
*/

#include <stdio.h>

int verificar(int m[9][9]) {
    int freq[10];

    for (int i = 0; i < 9; i++) {
        for (int k = 1; k <= 9; k++) freq[k] = 0;
        for (int j = 0; j < 9; j++) freq[m[i][j]]++;
        for (int k = 1; k <= 9; k++) if (freq[k] != 1) return 0;
    }

    for (int j = 0; j < 9; j++) {
        for (int k = 1; k <= 9; k++) freq[k] = 0;
        for (int i = 0; i < 9; i++) freq[m[i][j]]++;
        for (int k = 1; k <= 9; k++) if (freq[k] != 1) return 0;
    }

    for (int bi = 0; bi < 3; bi++) {
        for (int bj = 0; bj < 3; bj++) {
            for (int k = 1; k <= 9; k++) freq[k] = 0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    freq[m[bi*3+i][bj*3+j]]++;
            for (int k = 1; k <= 9; k++) if (freq[k] != 1) return 0;
        }
    }
    
    return 1;
}

int main() {
    int n, m[9][9];
    scanf("%d", &n);
    
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &m[i][j]);
        
        printf("Instancia %d\n", k);
        printf("%s\n\n", verificar(m) ? "SIM" : "NAO");
    }
    
    return 0;
}
