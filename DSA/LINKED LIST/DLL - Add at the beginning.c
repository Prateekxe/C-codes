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

void display()
{
	if(head == NULL)
	{
		printf("Memory allocation failure");
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
   	
   	  printf("\n1. Insert in empty\n");
   	  printf("\n2. Insert at beginning\n");
   	  printf("\n3. Display \n");
   	  printf("\n4. Exit \n");
   	  printf("\nchoose option: ");
   	  scanf("%d",&ch);
   	  switch(ch)
   	{
   	 	case 1: add_to_empty();
   	 	break;
   	 	case 2: add_at_beg();
   	 	break;
   	 	case 3: display();
   	 	break;
   	 	case 4: exit(1);
   	 	default:
   	 	printf("wrong option taken");
	}
     
    }
}
