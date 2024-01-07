//
//  isheap.c
//  Is Heap
//
//  Created by Roberto Reggiani on 05/01/24.
//

#include "minheap.h"


bool IsHeap(const Heap *h) {
    if (h == NULL || h->data == NULL || h->size == 0) {
        return false;
    }
    
    
    for (size_t i = 0; i < h->size / 2; i++ ) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        
        if (left < h->size && h->data[i] > h->data[left]) {
            return false;
        }
        if (right < h->size && h->data[i] > h->data[right]) {
            return false;
        }
    }
    return true;
}
