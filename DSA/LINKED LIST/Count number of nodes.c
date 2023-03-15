#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head = NULL; // creating the head separately because we have to keep the head fixed.

int count();

int count(struct node *head)
{
    int count= 0;
    if(head== NULL)
        printf("The linked list is empty");
    else
    {
        struct node *ptr =  NULL;
        ptr = head;
        while(ptr != NULL)
        {
            count++;
            ptr=ptr->link;
        }
        printf("The number of nodes is: %d", count);
    }
    //return count; // return 0; will also work
}

int main()
{
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 45;
    ptr->link = NULL;
    head = ptr;
    
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 36;
    current->link = NULL;
    ptr->link = current;
    
    struct node *current2 = (struct node *)malloc(sizeof(struct node));
    current2->data = 69;
    current2->link = NULL;
    current->link = current2;

    int num;
    num = count(head); // simply, count(head); will also work.
    return 0;
}
