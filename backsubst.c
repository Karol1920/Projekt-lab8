#include "gauss.h"

void back_substitution(MatrixSystem *sys) {
    int n = sys->n;

    for (int i = n - 1; i >= 0; i--) {
        
        double s = 0.0;

        for (int j = i + 1; j < n; j++) {
            s += sys->A[i][j] * sys->x[j];
        }

        if (sys->A[i][i] == 0) {
            printf("Blad - Dzielenie przez zero w podstawieniu wstecznym\n");
            return;
        }
        sys->x[i] = (sys->b[i] - s) / sys->A[i][i];
    }
}