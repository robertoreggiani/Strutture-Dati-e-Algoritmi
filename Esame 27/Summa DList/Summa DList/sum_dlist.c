//
//  sum_dlist.c
//  Summa DList
//
//  Created by Roberto Reggiani on 08/01/24.



#include "sum_dlist.h"

void prepend(Item **head, ElemType value) {
    Item *newNode = malloc(sizeof(Item));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = *head;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

Item* getLast(const Item *head) {
    const Item* current = head;
    
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    
    return (Item*)current;
}

Item* DListSum(const Item *i1, const Item *i2) {
    Item* res = NULL;
    Item* last1 = getLast(i1);
    Item* last2 = getLast(i2);
    
    int carry = 0;
    
    while (last1 != NULL || last2 != NULL || carry != 0) {
        int digit1 = last1 != NULL ? last1->value : 0;
        int digit2 = last2 != NULL ? last2->value : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        
        prepend(&res, sum);
        
        
        if (last1 != NULL) {
            last1 = last1->prev;
        }
        
        if (last2 != NULL) {
            last2 = last2->prev;
        }
    }
    
    return res;
}

