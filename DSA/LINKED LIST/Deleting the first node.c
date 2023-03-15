#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;

void add_beg()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at BEGINNING: \n");
    scanf("%d",&temp->data);
    temp->link = NULL;
    
    if(head == NULL)
    {
        head = temp;
    }
    else 
    {
        temp->link = head;
        head = temp;
    }
    
}

void del_beg()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("Linked list is already empty.");
    }
    else 
    {
        temp = head;
        head = head->link;
        free(temp);
    }
}

void display()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("memory allocation failure ;_;");
    }
    else
    {
        ptr = head;
        while(ptr != NULL)
        {
            printf("The data of the linked list are: \n %d \n", ptr->data);
            ptr = ptr->link;
        }
    }
}


int main()
{
    int ch;
    while(1)
{
    printf("\n1.Insert Beginning. \n");
    printf("\n2.Delete Beginning.\n");
    printf("\n3.Display all the data.\n");
    printf("\n4.Exit.\n");
    printf("\nChoose Option: \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: add_beg();
        break;
        case 2: del_beg();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        default:
        printf("You've entered the wrong input.");
    }
} 
    return 0;
}
