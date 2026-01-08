#ifndef GAUSS_H
#define GAUSS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int n;
    double **A;
    double *b;
    double *x;
} MatrixSystem;

void initialize_system(MatrixSystem *sys, int n);
void free_system(MatrixSystem *sys);
void print_system(MatrixSystem *sys);

int select_pivot(MatrixSystem *sys, int col);

int gauss(MatrixSystem *sys);

void back_substitution(MatrixSystem *sys);

#endif