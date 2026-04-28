/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : <Nikollas Beneveni de Souza>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1078
Data        : 28/04/2026
Objetivo    : Mostrar a tabuada de um valor".
Aprendizado : <uso do for em como fazer a taboada>
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
    int n1;
    int i;
    
    scanf("%d", &n1);

    for(i=1;i<=10;i++){
        printf("%d x %d = %d\n", i, n1, n1 * i);
    }
 
    return 0;
}
