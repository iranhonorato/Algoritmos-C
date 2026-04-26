#include <time.h>
#include "trees.c"
#include <stdio.h>



int conta_nodos(Tree *root) {
    if (root == NULL) return 0;

    return conta_nodos(root->left) + conta_nodos(root->right) + 1;
}


void monta_array(Tree *root, double *array, int *idx) {
    if (root == NULL) return;

    monta_array(root->left, array, idx);
    array[*idx] = root->value;
    (*idx)++;
    monta_array(root->right, array, idx);

    return;
}


Tree *monta_arvore(double *array, int inicio, int fim) {
    Tree *new_tree;
    new_tree = malloc(sizeof(Tree));

    if (inicio > fim) {
        return NULL;
    }

    int mid = (inicio + fim)/2;
    int node_value = array[mid];

    new_tree->value = node_value;
    new_tree->left = monta_arvore(array, inicio, mid-1);
    new_tree->right = monta_arvore( array, mid+1, fim);

    return new_tree;

}


Tree *rebalancemaneto(Tree *root)  {
    int num = conta_nodos(root);

    double *array;
    array = malloc(num*sizeof(double));

    monta_array(root, array, 0);

    
    return monta_arvore(array, 0, num-1);
}