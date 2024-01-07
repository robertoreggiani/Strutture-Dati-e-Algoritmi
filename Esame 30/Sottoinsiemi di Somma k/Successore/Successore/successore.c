#include "tree.h"
#include <limits.h>


void findSuccessorValue(const Node* root, int val, int* minGreater) {
    if (root == NULL) return;

    
    if (root->value > val && root->value < *minGreater) {
        *minGreater = root->value;
    }

    findSuccessorValue(root->left, val, minGreater);
    findSuccessorValue(root->right, val, minGreater);
}


const Node* findNodeWithValue(const Node* root, int val) {
    if (root == NULL) return NULL;
    if (root->value == val) return root;

    const Node* leftResult = findNodeWithValue(root->left, val);
    if (leftResult != NULL) return leftResult;

    return findNodeWithValue(root->right, val);
}

extern const Node* Successore(const Node *t, const Node *n) {
    if (t == NULL || n == NULL) return NULL;

    int minGreater = INT_MAX;
    findSuccessorValue(t, n->value, &minGreater);

    if (minGreater == INT_MAX) return NULL; 

    return findNodeWithValue(t, minGreater);
}
