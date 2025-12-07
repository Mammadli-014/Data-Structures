#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Tree {
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
    Color color;
    int value;
} Tree;

Tree* root=NULL;

void case1(Tree* node);
void case2(Tree* node);
void case3(Tree* node);
void case4(Tree* node);
void case5(Tree* node);

Tree* grandParent(Tree* node){
    if(node!=NULL && node->parent!=NULL){
        return node->parent->parent;
    }
    else return NULL;
}

Tree* uncle(Tree* node){
    Tree *gr= grandParent(node);
    if(gr==NULL) return NULL;
    if(node->parent == gr->left)
        return gr->right;
    else return gr->left;
}

Tree* createNode(int value){
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->left = node->right = node->parent = NULL;
    node->value = value;
    node->color = RED;
    return node;
}

void rotate_Left(Tree *parent) {
    Tree *pivot = parent->right;
    if (pivot == NULL) return; // dönülecek bir şey yok


    parent->right = pivot->left;
    if (pivot->left != NULL)
        pivot->left->parent = parent;


    pivot->parent = parent->parent;
    if (parent->parent == NULL) {
        root = pivot;
    } else if (parent == parent->parent->left) {
        parent->parent->left = pivot;
    } else {
        parent->parent->right = pivot;
    }

    pivot->left = parent;
    parent->parent = pivot;
}

void rotate_Right(Tree *parent){
    Tree* pivot =parent->left;
    if(pivot == NULL) return;

    parent->left=pivot->right;
    if(pivot->right != NULL)
        pivot->right->parent=parent;

    pivot->parent=parent->parent;
    if(parent->parent== NULL){
        root=pivot;
    }else if (parent==parent->parent->left){
        parent->parent->left=pivot;
    }else parent->parent->right=pivot;

    pivot->right=parent;
    parent->parent=pivot;

}

void case5(Tree* node){
    Tree* g = grandParent(node);
    if(g==NULL) return;
    node->parent->color=BLACK;
    g->color=RED;

    if(node==node->parent->left && node->parent==g->left){
        rotate_Right(g);
    }else if (node==node->parent->right && node->parent==g->right){
        rotate_Left(g);
    }
}

void case4(Tree* node){
    Tree* g= grandParent(node);
    if(g== NULL) return;

    if(node==node->parent->right && node->parent == g->left){
        rotate_Left(node->parent);
        node=node->left;

    }else if(node==node->parent->left && node->parent == g->right){
        rotate_Right(node->parent);
        node=node->right;
    }
    case5(node);
}

void case3(Tree* node){
    void case1(Tree *node);

    Tree *u= uncle(node);
    Tree *g= grandParent(node);
    if(u !=NULL && u->color == RED){
        node->parent->color=BLACK;
        u->color=BLACK;
        g->color=RED;
        case1(g);
    }else case4(node);
}

void case2(Tree* node){
    if(node->parent->color == BLACK)return;
    else case3(node);
}

void case1(Tree* node){
    if(node->parent == NULL){
        node->color=BLACK;
    }else case2(node);
}

Tree* insert(Tree* subroot, Tree* node){
    if(subroot == NULL){
        return node;
    }

    if(subroot->value < node->value){
        subroot->right = insert(subroot->right, node);
        if(subroot->right != NULL) subroot->right->parent = subroot;
    }else{
        subroot->left = insert(subroot->left, node);
        if(subroot->left != NULL) subroot->left->parent = subroot;
    }
    return subroot;
}

void print_inorder(Tree* r){
    if(r==NULL) return;
    print_inorder(r->left);
    printf("%d(%s) ", r->value, r->color == RED ? "R" : "B");
    print_inorder(r->right);
}

int main(){
    int arr[] = {10, 20, 30, 15, 25, 5, 1, 50, 40, 60};
    int n = 10;

    for(int i=0; i<n; ++i){
        Tree* node = createNode(arr[i]);
        root = insert(root, node);
        case1(node);
        if(root != NULL) root->parent = NULL;
    }
    print_inorder(root);
}