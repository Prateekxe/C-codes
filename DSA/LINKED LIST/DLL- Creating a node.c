#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head -> prev = NULL;
    head -> data = 45;
    head -> next = NULL;
    
    return 0;
}
