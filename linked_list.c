#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void insert(struct node* head, int data){
    struct node *help=head;
    while(help->next != NULL){
        help = help->next;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next = NULL;

    help->next = new_node;
}

int delete(struct node* head, int data){
    struct node *help=head;
    char found=0;

    while(help->next != NULL){
        if (help->next->data==data){
            found=1;

            struct node *temp=help->next;
            help->next=help->next->next;
            free(temp);

            break;
        }
        help = help->next;
    }
    return found;
}

void print(struct node* head){
    struct node* help=head;
    while(help != NULL){
        printf("%d\n",help->data);
        help = help->next;
    }
}

void clean(struct node* head){
    struct node *help=head;
    while(help != NULL){
        struct node *temp=help->next;
        free(help);
        help=temp;
        printf("cleaned\n");
    }
}

void insert_beginning(struct node *head,int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=head->next;

    head->next=new_node;
}

void delete_last(struct node* head){
    struct node* help=head;
    while(help->next->next != NULL){
        help=help->next;
    }
    struct node* temp=help->next;
    help->next=NULL;
    free(temp);
}

    

int main(){
    struct node *head=create(0);
    for(int i=1;i<10;i++){
        insert(head,i);
    }
    print(head);
    delete_last(head);
    printf("after: \n");
    print(head);

    insert_beginning(head,111);
    printf("after: \n");
    print(head);
    clean(head);
    return 0;
}
