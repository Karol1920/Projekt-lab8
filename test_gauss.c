#include "gauss.h"
#include <stdio.h>
#include <math.h>

int double_compare(double a, double b) {
    return fabs(a - b) < 1e-6;
}

void test_simple() {
    MatrixSystem sys;
    initialize_system(&sys, 2);

    sys.A[0][0] = 2; sys.A[0][1] = 1; sys.b[0] = 3;
    sys.A[1][0] = 1; sys.A[1][1] = -1; sys.b[1] = 0;

    int res = gauss(&sys);
    if(res == 0) {
        back_substitution(&sys);
        if(double_compare(sys.x[0], 1.0) && double_compare(sys.x[1], 1.0)) {
            printf("Wynik poprawny x=1, y=1\n");
        } else {
            printf("Wynik bledny x=%.2f y=%.2f\n", sys.x[0], sys.x[1]);
        }
    } else {
        printf("Funkcja gauss zwrocila blad\n");
    }
    free_system(&sys);
}

void test_pivot() {
    MatrixSystem sys;
    initialize_system(&sys, 2);

    sys.A[0][0] = 0; sys.A[0][1] = 1; sys.b[0] = 2;
    sys.A[1][0] = 1; sys.A[1][1] = 1; sys.b[1] = 3;

    int res = gauss(&sys);
    if(res == 0) {
        back_substitution(&sys);
        if(double_compare(sys.x[0], 1.0) && double_compare(sys.x[1], 2.0)) {
            printf("Pivot zadzialal poprawnie x=1 y=2\n");
        } else {
            printf("Wynik bledny x=%.2f y=%.2f\n", sys.x[0], sys.x[1]);
        }
    } else {
        printf("Funkcja gauss zwrocila blad pivot nie zadzialal\n");
    }
    free_system(&sys);
}

void test_singular() {
    MatrixSystem sys;
    initialize_system(&sys, 2);

    sys.A[0][0] = 1; sys.A[0][1] = 1; sys.b[0] = 2;
    sys.A[1][0] = 1; sys.A[1][1] = 1; sys.b[1] = 2;

    int res = gauss(&sys);
    if(res != 0) {
        printf("Prawidlowo wykryto macierz osobliwa\n");
    } else {
        printf("Nie wykryto macierzy osobliwej\n");
    }
    free_system(&sys);
}

int main() {
    test_simple();
    test_pivot();
    test_singular();
    return 0;
}