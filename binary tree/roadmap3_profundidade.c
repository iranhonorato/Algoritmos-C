#include <time.h>
#include "trees.c"
#include <stdio.h>



int dfs(Tree *root, int deep) {
    if (root == NULL) return deep-1;

    deep++;
    int left = dfs(root->left, deep);
    int right = dfs(root->right, deep);
    
    if (left > right) return left;

    return right;
}

int profundidade(Tree *root) {
    return dfs(root, 0);
}