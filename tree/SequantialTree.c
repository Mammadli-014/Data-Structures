#include <stdio.h>

#define Max_Size 20

int tree[Max_Size];

void initializeTree(){
    tree[0]=0;
    for (int i = 1; i < Max_Size; ++i) {
        tree[i]=-1;
    }
}

void insert(int value){
    if(tree[1] == -1){
        tree[1]=value;
        return;
    }

    int i=1;
    while(1){

        if(i>=Max_Size){
            return;
        }

        if(tree[i] == -1){
            tree[i]=value;
            return;
        }

        if(value < tree[i]){
            i=2*i;
        } else i=2*i + 1;

    }
}

int findInOrder(int index){
    index =2*index +1;
    while (index *2 < Max_Size && tree[2*index] !=-1)
        index=2*index;
    return index;
}

void deleteByIndex(int index){
    if(tree[1] == -1) printf("Tree is empty");
    if(index >= Max_Size || tree[index] == -1) return;

    int i=index;
    while(1){

        if(i*2 >= Max_Size || (tree[i*2] == -1 && tree[i*2 +1] ==-1)){ // doesnt have child
            tree[i]=-1;
            return;
        }

        if(tree[i*2] !=-1 && tree[i*2+1] ==-1){ //left child
            tree[i]=tree[i*2];
            deleteByIndex(i*2);
            return;
        }

        if (tree[2*i] == -1 && tree[2*i+1] != -1) {//right child
            tree[i] = tree[2*i+1];
            deleteByIndex(2*i+1);
            return;
        }

        if(tree[i*2] !=-1 && tree[i*2 +1] !=-1){ // two child, selected with IN\n Order method
            int inOrderIndex= findInOrder(i);
            tree[i]=tree[inOrderIndex];
            deleteByIndex(inOrderIndex);
            return;
        }

    }
}

void display(){
    for (int i = 1; i < Max_Size; ++i) {
        if(tree[i]!=0)
            printf("%d ",tree[i]);
    }
}

int main(){
    initializeTree();
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(30);
    insert(40);
    insert(25);
    insert(12);
    insert(5);
    insert(1);
    display();
    printf("\n");


    deleteByIndex(6);
    display();

}