#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node* create(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->data=data;
    return new_node;
}

void insert(struct node* head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=head->next;
    head->next=new_node;
}
int call(struct node* head){
    struct node *help=head;
    int data=-1;
    if (help->next == NULL){
        return data;
    }
    while(help->next->next != NULL){
        help = help->next;
    }
    data = help->next->data;
    free(help->next);
    help->next=NULL;
    return data;
}

int main(){
    struct node *head=create(0);
    for(int i=1;i<6;i++){
        insert(head,i);
    }

    for(int i=0;i<6;i++){
        printf("%d\n",call(head));
    }
    free(head);
    return 0;
}
