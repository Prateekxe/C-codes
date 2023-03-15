#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};


void add_end(struct node *head, int data) 
{
    struct node *ptr, *temp; 
    ptr = head; 
    
    if(head==NULL)
    printf("The linked list is empty.");
    else
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    while(ptr->link !=NULL) 
    {                       
        ptr = ptr->link;
    }
    ptr->link = temp; 
}

void add_pos(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    pos--;
    while(pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    add_end(head, 98);
    add_end(head, 66);
    add_end(head, 108);
    
    add_pos(head, 89, 2);
    add_pos(head, 77, 3);
    
    add_end(head, 5466);
    
    struct node *ptr;
    ptr = head;
    
    while(ptr != NULL)
    {
        printf("\n %d \n", ptr->data);
        ptr = ptr->link;
    }
    
    return 0;
}
