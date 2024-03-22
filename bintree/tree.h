#ifndef _TREE_H
#define _TREE_H

struct Tree {
    struct Node *root;
};

struct Node {  
    struct Node *left;
    void *data;
    struct Node *right;
};

#endif
