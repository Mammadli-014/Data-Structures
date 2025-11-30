#include <stdio.h>
#include <stdlib.h>


typedef struct Tree {
    struct Tree *left;
    struct Tree *right;
    int value;
} Tree;


void deleteTree(Tree* root){
    if(root !=NULL){
        deleteTree(root->right);
        deleteTree(root->left);
        free(root);
    }
}

int numOfNodes(Tree* root){
    if(root == NULL)return 0;
    else return numOfNodes(root->left)+ numOfNodes(root->right)+1;
}

Tree *createNode(int value) {
    Tree *new = (Tree *) malloc(sizeof(Tree));
    new->left = NULL;
    new->right = NULL;
    new->value = value;
    return new;
}

Tree *insertNode(Tree *head, int value) {
    if (head == NULL)
        return createNode(value);
    if (value < head->value) {
        head->left = insertNode(head->left, value);
    } else {
        head->right = insertNode(head->right, value);
    }

    return head;
}

Tree *findLargestNode(Tree *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Tree *deleteNode(Tree *root, int value) {
    if (root == NULL) return NULL;
    if (value < root->value) root->left  = deleteNode(root->left, value);
    if (value > root->value) root->right = deleteNode(root->right, value);
    else {
        if (root->left != NULL && root->right != NULL) {//2 children
            Tree *temp = findLargestNode(root->left);
            root->value = temp->value;
            root->left = deleteNode(root->left, temp->value);
        }else{
            Tree* temp=root;
            if(root->left == NULL && root->right == NULL) root=NULL;
            else if(root->left !=NULL) root=root->right;
            else root=root->left;
            free(temp);
        }
    }
    return root;
}

Tree *searchNode(Tree *root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value > value) {
        return searchNode(root->left, value);
    } else if (root->value < value) {
        return searchNode(root->right, value);
    } else return root;

}

void displayInOrder(Tree *root) {//left root right
    if (root == NULL)return;
    displayInOrder(root->left);
    printf("%d ", root->value);
    displayInOrder(root->right);
}

void displayPreOrder(Tree *root) {//root left right
    if (root == NULL) return;
    printf("%d ", root->value);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayPostOrder(Tree *root) {//right left root
    if (root == NULL) return;
    displayPreOrder(root->left);
    displayPostOrder(root->right);
    printf("%d ", root->value);
}
