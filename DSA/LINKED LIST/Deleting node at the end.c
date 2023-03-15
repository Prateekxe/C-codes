#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head= NULL;

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
        printf("Linked list is already empty.\n");
    }
    else 
    {
        temp = head;
        head = head->link;
        free(temp);
    }
}

void del_end()
{
    
    if(head == NULL)
    {
        printf("The linked list is empty.\n");
    }
    
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    
    else
    {
        struct node *ptr = head;
        struct node *temp = head;
        
        while(ptr->link != NULL)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        free(ptr);
        ptr = NULL;
    }
}


void display()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("memory allocation failure ;_;\n");
    }
    else
    {
        ptr = head;
        printf("The data of the linked list are: ");
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n\n");
}


int main()
{
    int ch;
    while(1)
{
    printf("\n1.Insert Beginning. \n");
    printf("\n2.Delete Beginning.\n");
    printf("\n3.Delete End.\n");
    printf("\n4.Display all the data.\n");
    printf("\n5.Exit.\n");
    printf("\nChoose Option: \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: add_beg();
        break;
        case 2: del_beg();
        break;
        case 3: del_end();
        break;
        case 4: display();
        break;
        case 5: exit(0);
        default:
        printf("You've entered the wrong input.");
    }
} 
    return 0;
}
