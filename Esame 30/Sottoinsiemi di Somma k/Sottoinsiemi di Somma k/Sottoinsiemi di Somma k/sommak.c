//
//  main.c
//  Sottoinsiemi di Somma k
//
//  Created by Roberto Reggiani on 07/01/24.
//

#include <stdio.h>
#include <stdlib.h>

void printSubset(const int* subset, size_t subsetSize) {
    
    printf("{");
    for (size_t i = 0; i < subsetSize; i++) {
        printf("%d, ", subset[i]);
    }
    
    printf("}, ");
}


void SommaKRec( int n, int k, int* subset, size_t subsetSize, int start, int sum, int *count) {
    if(sum == k) {
        printSubset(subset, subsetSize);
        (*count)++;
        return;
    }
    
    for (int i = start; i <= n; i++) {
        if (sum + i <= k) {
            subset[subsetSize] = i;
            SommaKRec( n, k, subset, subsetSize + 1, i + 1, sum + i, count);
        }
    }
}
int SommaK(int n, int k) {
    
    int count = 0;
    int *subset = calloc(n, sizeof(int));
    
    SommaKRec(n, k, subset, 0, 1, 0, &count);
    free(subset);
    return count;
}
