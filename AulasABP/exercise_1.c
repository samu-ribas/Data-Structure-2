// This is code that exercises implementations of the binary tree structure.
// and aarm-up/review exercises on pointer, abstract types, and recursion.

// This exercise was made available by data structure teacher, *Saulo Queiroz*

#include<stdio.h>
#include<stdlib.h>

typedef struct tNode{
    int key;
    struct tNode *left, *right;
}TreeNode;


int main()
{
    //full code at the end


    /*
    a-  Issue the command to print the memory address of root node 7
        and the address of the "root" variable. In both cases, use 
        the "root" variable to print the requested values.

    printf("Root node address: %p\n", raiz); //<-----
	printf("Root variable address: %p\n", &raiz); //<-------

    free(node); 
    */

   /*
    b-  Enter the command to print the memory address of root node 7
        and the address of the "root" variable. In both cases, use the "r"
        variable to print the requested values.

        The variable r in main is of type pointer to pointer (i.e., TreeNode **r),
        and holds the address of the root variable.

    printf("Root node address: %p\n", *r);//<-----
    printf("Root variable address: %p\n", r);//<-------
    */

   /*
    c-  Run the command to print the key value of root node 7 twice. On one 
        printout, use the "root" variable. On the other, use the "r" variable.

        ..root is a pointer to a node (TreeNode *root).
        r is a pointer to a pointer (TreeNode **r), storing the root address.
        The root node (key = 7) is either at *root or at **r.

    printf("%d\n", root->key);   // using root
    printf("%d\n", (*r)->key);   // using r
   */

   /*
    d-  Run the command to print the value of the left field of node 7 and 
        the address where the right field of the same node resides. In both cases,
        use the "root" variable to print the requested values.

        ..root is of type TreeNode* and points to the root node (in this case, the node with key 7).
        root->left → pointer to the left node (in the drawing, the node with key 5).
        root->right → pointer to the right node (in the drawing, the node with key 9).

    printf("%p", root->left);
	printf("%p", &(root->right));
   */
  /*
    e-   Enter the command to print the value of the left field of node 7 and the address
         where the right field of the same node resides. In both cases, use the variable "r" 
         to print the requested values.

    printf("%p", (*r)->left);
	printf("%p", &(*r)->right);
  */

  /*
    f - Present the command to correctly remove node 8 from the tree. Use the "root" variable to
        perform the removal.

    free(root->right->left); // frees node 8
    root->right->left = NULL; // adjusts the pointer of 9
  */

/*
    h)  Present the command to correctly remove node 8 from the tree. Use the variable "r" to
        perform the removal.

    free((*r)->right->left); // frees node 8
    (*r)->right->left = NULL; // adjusts the pointer of 9
*/
    // ------------------------------
    // Building the tree from the figure
    // Root = 7, Right = 9, Left of 9 = 8
    // ------------------------------

    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->key = 7;
    root->left = NULL;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));

    root->right->key = 9;
    root->right->right = NULL;
    root->right->left = (TreeNode*)malloc(sizeof(TreeNode));

    root->right->left->key = 8;
    root->right->left->left = root->right->left->right = NULL;

    // Pointer to pointer to access the root
    TreeNode **r = &root;

    printf("Before removal:\n");
    printf("Root = %d\n", (*r)->key);
    printf("Right child of root = %d\n", (*r)->right->key);
    printf("Left child of 9 = %d\n", (*r)->right->left->key);


    // Removing node 8 using r
    free((*r)->right->left);   // free memory for node 8
    (*r)->right->left = NULL;  // adjust pointer in node 9

    printf("\nAfter removal:\n");
    printf("Root = %d\n", (*r)->key);
    printf("Right child of root = %d\n", (*r)->right->key);
    if((*r)->right->left == NULL)
        printf("Node 8 has been removed.\n");

    // Free memory
    free((*r)->right);
    free(*r);

    return 0;
}