//
//  mai.c
//  avltree


#include "avltree.h"

int main(int argc, const char * argv[]) {
    int vector[] = {1, 3, 5, 7, 8, 9, 10, 13, 14, 17};
    int size = sizeof(vector) / sizeof(*vector);
    
    avl_node *root = NULL;
    
    for (int i = 0; i < size; i++) {
        printf("\nInserting in tree value: %d\n", vector[i]);
        root = insert(root, vector[i]);
    }
    
    printf("\n------ Printing tree ------\n\n");
    inorder(root);
    
    printf("\n\n------ Height of tree ------\n");
    int height = find_height(root);
    printf("\nThe height of tree is: %d\n\n", height);
    
    return 1;
}

