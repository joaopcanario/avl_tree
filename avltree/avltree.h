//
//  avltree.h
//  avltree

#ifndef avltree_avltree_h
#define avltree_avltree_h

#include <stdio.h>
#include <stdlib.h>

typedef enum {false = 0, true = 1} bool;

typedef struct avl_node {
    int data;
    
    struct avl_node *left;
    struct avl_node *right;
} avl_node;

int find_height(avl_node *node);
int get_diff(avl_node *node);

avl_node *right_right_rotation(avl_node *parent);
avl_node *right_left_rotation(avl_node *parent);
avl_node *left_left_rotation(avl_node *parent);
avl_node *left_right_rotation(avl_node *parent);
avl_node *balancing(avl_node *node);
avl_node *insert(avl_node *root, int data);

void inorder(avl_node *tree);

#endif
