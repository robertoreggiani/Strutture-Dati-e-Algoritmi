//
//  main.c
//  Connect Ropes
//
//  Created by Roberto Reggiani on 08/01/24.
//


/*Si hanno a disposizione N segmenti di corda e li si vogliono unire per formarne uno unico. L'unione di due segmenti ha un costo pari alla somma delle loro lunghezze.
 
 extern size_t ConnectRopes(Heap *ropes);
 
 La funzione prende in input un min-heap contenente le lunghezze di segmenti di corda che deve unire per formare una corda unica.
 I segmenti devono essere uniti minimizzando il costo complessivo della procedura, ovvero sommando iterativamente i due segmenti di corda più corti fino a quando non ne rimane uno solo. La funzione ritora quindi il costo di creazione della corda.
 L'implementazione deve sfruttare le proprietà heap e avere una complessità computazionale in tempo non superiore a O(n * logn)
 
 La funzione può modificare l'heap di input. Se l'heap è vuota la funzione ritorna 0.

 Per la risoluzione di questo esercizio avete a disposizione le seguenti definizioni:

 typedef int ElemType;
 struct Heap{
     ElemType *data;
     size_t size;
 };
 typedef struct Heap Heap;
 
 
 */


#include <stdio.h>
#include "minheap.h"

void heapify(Heap* h, size_t index) {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    size_t smallest = index;
    
    if (left < h->size && h->data[left] < h->data[smallest]) {
        smallest = left;
    }
    if(right < h->size && h->data[right] < h->data[smallest]) {
        smallest = right;
    }
    
    if (smallest != index) {
        ElemType tmp = h->data[index];
        h->data[index] = h->data[smallest];
        h->data[smallest] = tmp;
        heapify(h, smallest);
    }
}

ElemType Min(Heap *h) {
    if (h->size == 0) {
        return 0;
    }
    
    ElemType root = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapify(h, 0);
    
    return root;
}

void insertHeap(Heap *h, ElemType value) {
    h->size++;
    size_t i = h->size - 1;
    h->data[i] = value;
    
    while (i != 0 && h->data[(i - 1) / 2] > h->data[i]) {
        ElemType tmp = h->data[i];
        h->data[i] = h->data[(i - 1) / 2];
        h->data[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

size_t ConnectRopes(Heap *ropes) {
    
    size_t total = 0;
    
    while (ropes->size > 1) {
        ElemType first = Min(ropes);
        ElemType second = Min(ropes);
        
        ElemType sum = first + second;
        
        total += sum;
        insertHeap(ropes, sum);
    }
    return total;
}
