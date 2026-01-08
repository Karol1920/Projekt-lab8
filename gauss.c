#include "gauss.h"

int select_pivot(MatrixSystem *sys, int col) {

    return col;
}

int gauss(MatrixSystem *sys) {
    int n = sys->n;

    for (int k = 0; k < n - 1; k++) {
        int pivot_row = select_pivot(sys, k);

        if (pivot_row != k) {
            double *tempPtr = sys->A[k];
            sys->A[k] = sys->A[pivot_row];
            sys->A[pivot_row] = tempPtr;

            double tempVal = sys->b[k];
            sys->b[k] = sys->b[pivot_row];
            sys->b[pivot_row] = tempVal;
        }

        if (fabs(sys->A[k][k]) < 1e-12) {
            return -1; 
        }

        for (int i = k + 1; i < n; i++) {
            

            double factor = sys->A[i][k] / sys->A[k][k];

            sys->A[i][k] = 0.0; 

            for (int j = k + 1; j < n; j++) {
                sys->A[i][j] -= factor * sys->A[k][j];
            }

            sys->b[i] -= factor * sys->b[k];
        }
    }
    
    if (fabs(sys->A[n-1][n-1]) < 1e-12) return -1;

    return 0; 
}



void back_substitution(MatrixSystem *sys) {
    int n = sys->n;

    for (int i = n - 1; i >= 0; i--) {
        
        double s = 0.0;

        for (int j = i + 1; j < n; j++) {
            s += sys->A[i][j] * sys->x[j];
        }

        if (sys->A[i][i] == 0) {
            printf("Błąd: Dzielenie przez zero w podstawieniu wstecznym!\n");
            return;
        }

        sys->x[i] = (sys->b[i] - s) / sys->A[i][i];
    }
}


void initialize_system(MatrixSystem *sys, int n) {
    sys->n = n;
    sys->A = (double**)malloc(n * sizeof(double*));
    sys->b = (double*)malloc(n * sizeof(double));
    sys->x = (double*)malloc(n * sizeof(double));
    for(int i=0; i<n; i++) {
        sys->A[i] = (double*)malloc(n * sizeof(double));
        sys->x[i] = 0.0;
    }
}

void free_system(MatrixSystem *sys) {
    for(int i=0; i<sys->n; i++) free(sys->A[i]);
    free(sys->A);
    free(sys->b);
    free(sys->x);
}

void print_system(MatrixSystem *sys) {
    for (int i = 0; i < sys->n; i++) {
        for (int j = 0; j < sys->n; j++) {
            printf("%6.2f ", sys->A[i][j]);
        }
        printf("| %6.2f\n", sys->b[i]);
    }
    printf("\n");
}