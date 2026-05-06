

#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char A[1001], B[1001];

    while (N--) {
        scanf("%s %s", A, B);

        int tamA = strlen(A);
        int tamB = strlen(B);

        if (tamB > tamA) {
            printf("nao encaixa\n");
        } else {
            if (strcmp(A + (tamA - tamB), B) == 0) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        }
    }

    return 0;
}
