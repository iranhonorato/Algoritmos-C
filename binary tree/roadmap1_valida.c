#include <time.h>
#include "trees.c"
#include <stdio.h>



int valida_arvore_bst(Tree *root, double min_value, double max_value) {
    if (root == NULL) return 1;

    if (root->value >= max_value) return 0;

    if (root->value <= min_value) return 0;
    
    return valida_arvore_bst(root->left, min_value, root->value) && valida_arvore_bst(root->right, root->value, max_value);

}   

