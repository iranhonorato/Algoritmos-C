#include <time.h>
#include "trees.c"
#include <stdio.h>



Tree *inserir(Tree *root, Tree *new_node) {
    if (root == NULL) return new_node;
    
    if (new_node->value > root->value) {
        root->right = inserir(root->right, new_node);
    }

    else if (new_node->value < root->value) {
        root->left = inserir(root->left, new_node);
    }

    return root;
}