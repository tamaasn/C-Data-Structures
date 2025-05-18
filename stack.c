#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node* create(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(struct node* head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;

    struct node *help=head;
    while(help->next != NULL){
        help = help->next;
    }

    help->next=new_node;
}

int pop(struct node* head){
    int data=-1;
    struct node *help=head;

    if (help->next == NULL){
        return data;
    }

    while(help->next->next != NULL){
        help=help->next;
    }
    if (help->next != NULL){
        data=help->next->data;
        free(help->next);
        help->next=NULL;
    }
    return data;
}

int main(){
    struct node *head = create(0);
    for(int i=1;i<6;i++){
        push(head,i);
    }

    for(int i=0;i<6;i++){
        printf("pop: %d\n",pop(head));
    }
    free(head);
    return 0;
}
