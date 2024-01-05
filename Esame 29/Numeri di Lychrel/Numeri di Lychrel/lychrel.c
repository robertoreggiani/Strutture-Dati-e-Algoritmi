#include <stdio.h>
#include <stdlib.h>


long reverseNumber (long n) {
    long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return reversed;
}

int isPalindrome(long n) {
    return n == reverseNumber(n);
}

int isLychrel(long n, int i) {
    if ( i == 0) {
        return 1;
    }
    
    if (isPalindrome(n)) {
        return 0;
    }
    
    return isLychrel(n + reverseNumber(n), i - 1);
}
int main (int argc, char *argv[]) {
    
    if (argc != 3 || atoi(argv[1]) < 0) {
        return 1;
    }
    
    int n = atoi(argv[1]);
    int i = atoi(argv[2]);
    
    
    if (isLychrel(n + reverseNumber(n), i)) {
        printf("Lychrel");
    } else {
        printf("Non di Lychrel");
    }
    
       return 0;
}
