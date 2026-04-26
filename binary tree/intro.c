#include <time.h>
#include <stdio.h>


typedef struct {
    double value;
    Tree *left, *right;
} Tree;


// Uma árvore binária é uma estrutura de dados hierárquica onde cada nó
// tem no máximo dois filhos, chamados de filho esquerdo e filho direito.
// Ela é composta por:

// - Raiz: o nó do topo, sem pai
// - Nós internos: têm pelo menos um filho
// - Folhas: nós sem filhos (left e right são None)

// É importante não confundir com árvore binária de busca (BST), que é um caso especial com uma regra a mais: 
// todo nó da subárvore esquerda é menor que o pai, e todo nó da subárvore direita é maior. 

// Uma árvore binária genérica não tem essa restrição — os valores podem estar em qualquer ordem.



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