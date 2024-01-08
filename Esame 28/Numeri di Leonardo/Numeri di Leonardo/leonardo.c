//
//  main.c
//  Numeri di Leonardo
//
//  Created by Roberto Reggiani on 08/01/24.
//

/* I numeri di Leonardo sono una sequenza di numeri data dalla relazione:
 
    L(n) = 1, n = 0 oppure n = 1;
    L(n) = L(n - 1) + L(n - 2) + 1, n > 1
 
 Essi sono legati ai numeri di Fibonacci dalla relazione L(n)= 2*F(n + 1) - 1,  n>=0
 
 Scrivere un programma a linea di comando con la seguente sintassi:

 leonardo <n>
 Il programma prende in input un numero intero positivo n e stampa a video i valori della sequenza di Leonardo da
 L(0) a L(n)inclusi, calcolati ricorsivamente.

 Se n < 0 o se il numero di parametri passati al programma è sbagliato, questo termina con codice 1 senza stampare nulla, in tutti gli altri casi il programma termina con codice 0 dopo aver stampato su stdout.

 Il formato della stampa deve corrispondere aquello degli esempi riportati di seguito.
 */

#include <stdio.h>
#include <stdlib.h>

int Leonardo(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    
    return Leonardo(n - 1) + Leonardo(n - 2) + 1;
}

int main(int argc, char *argv[]) {
    
    if(argc != 2) {
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if(n < 0) {
        return 1;
    }
    
    for(int i = 0; i <= n; i++) {
        printf("%d, ", Leonardo(i));
    }
    
    return 0;
}
