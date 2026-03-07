#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>


typedef struct Tree {
    struct Tree *left, *right, *parent;
    int key;
} Node;


int main() {
    Node *no_52;
    no_52 = malloc(sizeof(Node));
    no_52->key = 52;
    no_52->left = no_52->right = no_52->parent = NULL;


    Node *no_81;
    no_81 = malloc(sizeof(Node));
    no_81->key = 81;
    no_81->left = no_81->right = NULL;
    no_81->parent = no_52;

    no_52->right = no_81; // Ligando os nós 

}