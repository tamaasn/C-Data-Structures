#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

// Inorder Travesal

void print(struct node *root){
    if (!root) return;

    print(root->left);
    printf("%d \n",root->data);
    print(root->right);
}

int main(){
    struct node* root = create(0);
    root->left=create(1);
    root->right=create(2);
    root->left->left=create(3);
    root->left->right=create(4);
    
    print(root);
    return 0;
}
