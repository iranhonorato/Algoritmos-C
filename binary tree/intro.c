#include <time.h>
#include <stdio.h>


typedef struct {
    double value;
    Tree *left, *right;
} Tree;




void pre_ordem(Tree *root) {
    if (root == NULL) return;

    printf("Nodo atual: %d\n", root->value);
    pre_ordem(root->left);
    pre_ordem(root->right);

    return;
}


void pos_ordem(Tree *root) {
    if (root == NULL) return;

    pos_ordem(root->left);
    pos_ordem(root->right);
    printf("Nodo atual: %d\n", root->value);

    return;
}



void ordem(Tree *root) {
    if (root == NULL) return;

    ordem(root->left);
    printf("Nodo atual: %d\n", root->value);
    ordem(root->right);

    return;
}