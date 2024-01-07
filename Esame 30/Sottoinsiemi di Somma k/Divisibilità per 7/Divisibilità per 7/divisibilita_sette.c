#include <stdio.h>
#include <stdlib.h>

int Divisibile(int n) {
    
    if (n < 10 && n > -10) {
        return n == 0 || n == 7 || n == -7;
    }
    
    int lastDigit = n % 10;
    n /= 10;
    return Divisibile(abs(n - 2 * lastDigit));
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (n < 0) {
        return 1;
    }
    
    if (Divisibile(n)) {
        printf("Multiplo di 7.");
    } else {
        printf("Non multiplo di 7.");
    }
    
    return 0;
}
