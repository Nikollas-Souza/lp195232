/*
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Nikollas Beneveni de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1015
Data        : 20/05/2026
Objetivo    : Calcular a distância entre dois pontos no plano cartesiano.
Aprendizado : Uso das funções sqrt() e pow() da biblioteca math.
*/

#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("%.4f\n", distancia);

    return 0;
}
