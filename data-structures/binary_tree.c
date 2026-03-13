#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>


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


int arvore_valida(TreeNode *root) {
    if (root == NULL) {
        return 1;
    }
    
    if (root->left != NULL && root->left->key >= root->key) {
        return 0; 
    }

    if (root->right != NULL && root->right->key < root->key) {
        return 0;
    }
    

    return abb_valida(root->left) && abb_valida(root->right);
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


