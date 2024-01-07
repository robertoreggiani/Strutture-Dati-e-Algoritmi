//
//  main.c
//  Gemelli
//
//  Created by Roberto Reggiani on 06/01/24.
//

#include <stdio.h>
#include "tree.h"
#include "elemtype.h"


bool TreesAreTwins(const Node *t1, const Node *t2) {
    
    if(t1 == NULL && t2 == NULL) {
        return true;
    }
    
    if(t1 == NULL || t2 == NULL) {
        return false;
    }
    
    return TreesAreTwins(t1->left, t2->left) && TreesAreTwins(t1->right, t2->right);
}
