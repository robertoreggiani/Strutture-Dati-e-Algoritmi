//
//  diff_dlist.c
//  Differenza DList
//
//  Created by Roberto Reggiani on 05/01/24.
//

#include "diff_dlist.h"


Item* getLast(const Item* head) {
    const Item* current = head;
    
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    
    return (Item*)current;
}

void prepend(Item** head, ElemType value) {
    Item *newNode = malloc(sizeof(Item));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = *head;
    
    if(*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

Item* DListDiff(const Item *i1, const Item *i2) {
    Item* res = NULL;
    Item* last_1 = getLast(i1);
    Item* last_2 = getLast(i2);
    
    int borrow = 0;
    
    while (last_1 != NULL || last_2 != NULL || borrow != 0) {
        int digit_1 = (last_1 != NULL) ? last_1->value : 0;
        int digit_2 = (last_2 != NULL) ? last_2->value : 0;
        
        int diff = digit_1 - digit_2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        prepend(&res, diff);
        
        if (last_1 != NULL) {
            last_1 = last_1->prev;
        }
        if (last_2 != NULL) {
            last_2 = last_2->prev;
        }
    }
    
    while (res != NULL && res->value == 0) {
        Item* tmp = res;
        res = res->next;
        free(tmp);
        if (res != NULL) {
            res->prev = NULL;
        }
    }
    
    return res;
}


