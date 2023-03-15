#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void add_to_empty()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    
    temp->prev = NULL;
    
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    
    temp->next = NULL;
    
    head = temp;
}



int main()
{
    add_to_empty();
    printf("%d", head->data);
    return 0;
}


