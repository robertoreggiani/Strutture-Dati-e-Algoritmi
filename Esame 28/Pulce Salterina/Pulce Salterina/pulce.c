#include "pulce.h"


const Item* CalcolaPercorso(const Item *start, size_t n) {

    if(start == NULL) {
        return NULL;
    }

    const Item *curr = start;
    int remainingJumps = n;

    while (remainingJumps > 0 && curr != NULL) {
        int jumpLenght = curr->value;

        if (jumpLenght == 0) {
            break;
        }

        while (jumpLenght != 0 && remainingJumps > 0) {
            if (jumpLenght > 0) {
                if (curr->next != NULL) {
                    curr = curr->next;
                } else {
                    jumpLenght =- jumpLenght;
                }
                jumpLenght--;
            } else {
                if (curr->prev != NULL) {
                    curr = curr->prev;
                } else {
                    jumpLenght =- jumpLenght;
                }
                jumpLenght++;
            }
            remainingJumps--;
        }
    }

    return curr;
}
