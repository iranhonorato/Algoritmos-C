
#include <time.h>
#include "trees.c"
#include <stdio.h>


int conta_nodos(Tree *root) {
    if (root == NULL) return 0;

    return conta_nodos(root->left) + conta_nodos(root->right) + 1;
}