/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1017
Data        : 21/05/2026
Objetivo    : Calcular o consumo de combustível em uma viagem.
Aprendizado : Uso de variáveis, entrada/saída e cálculos matemáticos.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int tempo, velocidade;
    double litros;

    scanf("%d", &tempo);
    scanf("%d", &velocidade);

    litros = (tempo * velocidade) / 12.0;

    printf("%.3lf\n", litros);

    return 0;
}
