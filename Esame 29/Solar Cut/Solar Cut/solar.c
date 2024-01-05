#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* SolarCut(int A, size_t *sol_size) {
    
    int *sol = NULL;
    *sol_size = 0;
    int remainingArea = A;
    
    while (remainingArea > 0) {
        int side = (int)sqrt(remainingArea);
        int squareArea = side * side;
        remainingArea -= squareArea;
        
        sol = realloc(sol, (*sol_size + 1) * sizeof(int));
        sol[*sol_size] = squareArea;
        (*sol_size)++;
    }
    
    return sol;
}
