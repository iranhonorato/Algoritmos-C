#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>


typedef struct Tree {
    struct Tree *left, *right, *parent;
    int key;
} TreeNode;


int busca_em_arvore(TreeNode *root, int val) {
    if (root == NULL) {
        return 0;
    }

    if (root->key == val) {
        return 1;

    } else if (root->key < val) {
        return busca_em_arvore(root->right, val);

    } else {
        return busca_em_arvore(root->left, val);
    }

    return -1;
}


// Propaga os limites [min, max) pela árvore:
//   - subárvore esquerda: todas as chaves devem ser < root->key  → max = root->key
//   - subárvore direita:  todas as chaves devem ser >= root->key → min = root->key
static int arvore_valida_helper(TreeNode *root, int min, int max) {
    if (root == NULL) return 1;

    if (root->key < min || root->key >= max) return 0;

    return arvore_valida_helper(root->left,  min,       root->key) &&
           arvore_valida_helper(root->right, root->key, max);
}


int arvore_valida(TreeNode *root) {
    return arvore_valida_helper(root, INT_MIN, INT_MAX);
}



TreeNode *insercao_node(TreeNode *root, int key) {
    if (root == NULL) {
        TreeNode *new_node = malloc(sizeof(TreeNode));
        new_node->key = key;
        new_node->left = new_node->right = new_node->parent = NULL;
        return new_node;
    }

    if (root->key > key) {
        root->left = insercao_node(root->left, key);
        root->left->parent = root;
    }

    if (root->key <= key) {
        root->right = insercao_node(root->right, key);
        root->right->parent = root;
    }

    return root;

}


int count_nodes(TreeNode *root) {
    if(root == NULL) return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}


// int *idx precisa ser ponteiro, pois 
// se você passasse apenas int idx (valor), 
// cada vez que a função chamasse a si mesma, ela criaria uma cópia do número atual.
void array_keys(TreeNode *root, int *idx, int *array) {
    if (root == NULL) return;

    // Quando o "trabalhador" da esquerda terminasse de preencher o array e somasse idx++, 
    // essa alteração morreria com ele. Quando a execução voltasse para o "trabalhador" pai, 
    // o idx dele ainda estaria no valor antigo.
    array_keys(root->left, idx, array);
    array[*idx] = root->key;
    (*idx)++;
    array_keys(root->right, idx, array);
}


TreeNode *build(int *array, int left, int right) {
    if (left > right) return NULL;
    
    int mid = (right + left)/2;
    TreeNode *node = malloc(sizeof(TreeNode));
    node->key = array[mid];

    node->left = build(array, left, mid-1);
    node->right = build(array, mid+1, right);

    return node;
}


void free_tree(TreeNode *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

TreeNode *abb_rebalance(TreeNode *root) {
    if (root == NULL) return NULL;
    int right = count_nodes(root);
    int *array = malloc(right * sizeof(int));
    int left = 0;

    array_keys(root, &left, array);
    
    TreeNode *new_root = build(array, 0, right-1);
    free(array);
    free_tree(root);
    return new_root;
}

