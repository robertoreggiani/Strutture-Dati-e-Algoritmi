//
//  main.c
//  Sottoalbero Colorato
//
//  Created by Roberto Reggiani on 06/01/24.
//

#include <stdio.h>
#include "tree.h"

bool isEqual(const Node* root, int* size, ElemType color) {
    
    if (root == NULL) {
        *size = 0;
        return true;
    }
    
    int leftSize, rightSize;
    
    bool leftEq = isEqual(root->left, &leftSize, root->value);
    bool rightEq = isEqual(root->right, &rightSize, root->value);
    
    //aggiorno spazio
    *size = leftSize + rightSize + 1;
    
    return leftEq && rightEq && root->value == color;
}


int treeHeight(const Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

const Node* BiggestColoredTree(const Node *t) {
    if (t == NULL) {
        return NULL;
    }

    int size;
    if (isEqual(t, &size, t->value)) {
        return t;
    }

    const Node *leftSubtree = BiggestColoredTree(t->left);
    const Node *rightSubtree = BiggestColoredTree(t->right);

    // Confronta dimensione e altezza dei sottoalberi
    int leftSize = 0, rightSize = 0, leftHeight = 0, rightHeight = 0;
    if (leftSubtree) {
        leftSize = treeHeight(leftSubtree);
        leftHeight = treeHeight(leftSubtree);
    }
    if (rightSubtree) {
        rightSize = treeHeight(rightSubtree);
        rightHeight = treeHeight(rightSubtree);
    }

    if (leftSize == rightSize) {
        return leftHeight >= rightHeight ? leftSubtree : rightSubtree;
    }

    return leftSize > rightSize ? leftSubtree : rightSubtree;
}
