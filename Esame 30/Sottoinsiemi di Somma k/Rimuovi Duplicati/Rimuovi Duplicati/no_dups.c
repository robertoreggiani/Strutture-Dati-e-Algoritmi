
#include "no_dups.h"

bool isPresent(const Item* list, ElemType value) {
    const Item* current = list;
    while( current != NULL ) {
        if(current->value  == value) {
            return true;
        }
        
        current = current->next;
    }
    
    return false;
}

void append(Item** list, ElemType value) {
    Item* newNode = malloc(sizeof(Item));
    newNode->value = value;
    newNode->next = NULL;
    
    if(*list == NULL) {
        *list = newNode;
    } else {
        Item* current = *list;
        while(current->next != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
    }
    
}

Item *RemoveDuplicates(const Item* i) {

    
    if (i == NULL) {
        return NULL;
    }
    
    Item* res = NULL;
    const Item* current = i;
    
    while (current != NULL) {
        if(!isPresent(res, current->value)) {
            append(&res, current->value);
        }
        current = current->next;
    }
    
    return res;
}
