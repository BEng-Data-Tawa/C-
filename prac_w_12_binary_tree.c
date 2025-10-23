#include <stdio.h>
#include <stdlib.h>

// structure for binary tree node.
struct treeNode
{
    char data;
    struct treeNode *leftPtr, *rightPtr;
};
typedef struct treeNode TreeNode;

// struct that points to the rootq node
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, char data);
void deleteTree(TreeNodePtr *treePtr);

// traversals 

void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);



int main(void)
{
    TreeNodePtr rootPtr = NULL; // start with an empty tree

    // insert some nodes (random example)
    insertNode(&rootPtr, 'F');
    insertNode(&rootPtr, 'B');
    insertNode(&rootPtr, 'G');
    insertNode(&rootPtr, 'A');
    insertNode(&rootPtr, 'D');
    insertNode(&rootPtr, 'I');
    insertNode(&rootPtr, 'C');
    insertNode(&rootPtr, 'E');
    insertNode(&rootPtr, 'H');

    printf("\nIn-order traversal:   ");
    inOrder(rootPtr);

    printf("\nPre-order traversal:  ");
    preOrder(rootPtr);

    printf("\nPost-order traversal: ");
    postOrder(rootPtr);

    printf("\n\nDeleting tree...\n");
    deleteTree(&rootPtr);

    return 0;
}

void insertNode(TreeNodePtr *treePtr, char data)
{
    
    if (*treePtr == NULL)
    {
        // Insert node:
        printf("Inserting node containing %c\n", data);
        *treePtr = malloc(sizeof(TreeNode));
        (*treePtr)->data = data;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;
    }
    else
    { // Recursively find a place to insert node:
        if (data < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->leftPtr), data);
        }
        else
        {
            insertNode(&((*treePtr)->rightPtr), data);
        }
    }
}

void deleteTree(TreeNodePtr *treePtr)
{
    if (*treePtr != NULL)
    {
        deleteTree(&((*treePtr)->leftPtr));
        deleteTree(&((*treePtr)->rightPtr));
        printf("Deleting node containing %c\n", (*treePtr)->data);
        free(*treePtr);
        *treePtr = NULL;
    }
}

void inOrder(TreeNodePtr treePtr){
    // enter at root node and visit as many left as possible, then right as possible 

    // visit the root node(print root node )
    // case for only one node 
   if(treePtr != NULL){
    inOrder(treePtr->leftPtr);
    // print the left node struff 
    printf("%c", treePtr->data);

    inOrder(treePtr->rightPtr);
   } else {
    printf("Empty tree");
   }
}

void preOrder(TreeNodePtr treePtr){
    // visit root, then left, then right 
    if(treePtr !=NULL){
        // visit == print the node 
        printf("%c", treePtr->data);
        // traverse left 
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);

    }

}

void postOrder(TreeNodePtr treePtr){
    // left, right, root
    // visit the left most, then visit right most then 
    if(treePtr !=NULL){

        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%c", treePtr->data);

    }
}