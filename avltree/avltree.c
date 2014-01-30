//
//  avltree.c
//  avltree

#include "avltree.h"

int find_height(avl_node *node) {
    int height = 0;
    
    if (node != NULL) {
        
        int left_height = find_height(node->left);
        int right_height = find_height(node->right);
        
        int max = (left_height > right_height) ? left_height : right_height;
        
        height = 1 + max;
    }
    
    return height;
}

int get_diff(avl_node *node) {
    int left_height = find_height(node->left);
    int right_height = find_height(node->right);
    
    int b_factor = left_height - right_height;
    
    return b_factor;
}

avl_node *right_right_rotation(avl_node *parent) {
    avl_node *temp;
    
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    
    return temp;
}

avl_node* right_left_rotation(avl_node *parent) {
    avl_node *temp;
    
    temp = parent -> right;
    parent->right = left_left_rotation(temp);
    
    return right_right_rotation(parent);
}

avl_node* left_left_rotation(avl_node *parent) {
    avl_node *temp;
    
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    
    return temp;
}

avl_node* left_right_rotation(avl_node *parent) {
    avl_node *temp;
    
    temp= parent -> left;
    parent-> left = right_right_rotation(temp);
    
    return left_left_rotation(parent);
}

avl_node* balancing(avl_node *node) {
    int b_factor = get_diff(node);
    
    if (b_factor > 1) {
        if (get_diff(node->left) > 0) {
            node = left_left_rotation(node);
        } else {
            node = left_right_rotation(node);
        }
    } else if (b_factor < -1) {
        if (get_diff(node->right) > 0) {
            node = right_left_rotation(node);
        } else {
            node = right_right_rotation(node);
        }
    }
    
    return node;
}


avl_node* insert(avl_node *root,int data) {
    if (root == NULL) {
        root = (avl_node*) malloc(sizeof(avl_node));
        
        root->data = data;
        
        root->left = NULL;
        root->right = NULL;
        
        return root;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
        root = balancing(root);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        root = balancing(root);
    }
    
    return root;
}

void inorder(avl_node *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d\t",tree->data);
        inorder(tree->right);
    }
}