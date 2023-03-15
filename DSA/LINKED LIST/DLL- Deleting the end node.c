#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void add_at_end()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    ptr = head;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    }
    
}

void add_at_beg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    
    if(head == NULL)
    {
       head = temp;
    }
    else
    {
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}

void del_first()
{
    head = head->next; // moving head to the second node
    free(head->prev);
    head->prev = NULL; // so that the previous part of the first node contains NULL
}

void del_end()
{
    struct node *temp = head;
    struct node *temp2;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp = NULL;
}

void display()
{
	if(head == NULL)
	{
		printf("Doubly Linked List is empty.");
	}
	else
	{
		struct node *ptr;
		ptr = head;
		while(ptr != NULL)
		{
		printf("%d \n", ptr->data);
		ptr = ptr->next;
	    }
		
	}
}

int main()
{
   int ch;
   while(1)
   {
   	
   	  printf("\n1. Insert at beginning\n");
   	  printf("\n2. Insert at end\n");
   	  printf("\n3. Display \n");
   	  printf("\n4. Exit \n");
   	  printf("\n5. Delete the first node \n");
   	  printf("\n6. Delete the End node \n");
   	  printf("\nchoose option: ");
   	  scanf("%d",&ch);
   	  switch(ch)
   	{
   	 	case 1: add_at_beg();
   	 	break;
   	 	case 2: add_at_end();
   	 	break;
   	 	case 3: display();
   	 	break;
   	 	
   	 	case 4: exit(1);
   	 	
   	 	case 5: del_first();
   	 	break;
   	 	case 6: del_end();
   	 	break;
   	 	default:
   	 	printf("wrong option taken");
	}
     
    }
}
