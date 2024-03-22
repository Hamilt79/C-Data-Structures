#include <stdio.h>
#include <stdlib.h>
#include "bintree/tree.h"

void printTree(struct Node *node) {
    if (node == NULL) {
        return;
    }
    if (node->data != NULL) {
        printf("%d\n", *(int*)(node->data));
    }
    printTree(node->left); 
    printTree(node->right);
}

void addIntToNode(struct Node *node, int x) {
    int *data = (int*) malloc(sizeof(int));
    if (data == NULL) {
        exit(1);
    }
    *data = x;
    node->data = data;
}

struct Node* createIntNode(int x) {
    struct Node *node = (struct Node*) calloc(1, sizeof(struct Node));
    if (node == NULL) {
        exit(1);
    }
    addIntToNode(node, x);
    return node;
}

void freeTree(struct Node *node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node->data);
    free(node); 
}

struct Tree createIntTree() {
    struct Tree t;
    struct Node *root = createIntNode(5); 
    t.root = root;
    struct Node *left = createIntNode(6);
    t.root->left = left;
    struct Node *right = createIntNode(99);
    t.root->right = right;
    right->left = createIntNode(100);
    return t;  
}

int main() {
    struct Tree t = createIntTree();
    printTree(t.root);
    freeTree(t.root);
}
