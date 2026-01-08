#include "gauss.h"

int main() {
    MatrixSystem sys;
    int n = 3;

    initialize_system(&sys, n);
    
    sys.A[0][0] = 2;  sys.A[0][1] = 1;  sys.A[0][2] = -1; sys.b[0] = 8;
    sys.A[1][0] = -3; sys.A[1][1] = -1; sys.A[1][2] = 2;  sys.b[1] = -11;
    sys.A[2][0] = -2; sys.A[2][1] = 1;  sys.A[2][2] = 2;  sys.b[2] = -3;

    printf("Macierz przed eliminacja:\n");
    print_system(&sys);

    if (gauss(&sys) == 0) {
        printf("Macierz po eliminacji:\n");
        print_system(&sys);
 
        back_substitution(&sys);
        
        printf("Rozwiazanie:\n");
        for(int i=0; i<n; i++) {
            printf("x[%d] = %6.2f\n", i, sys.x[i]);
        }
    } else {
        printf("Blad: Macierz osobliwa (dzielenie przez 0).\n");
    }

    free_system(&sys);
    return 0;
}