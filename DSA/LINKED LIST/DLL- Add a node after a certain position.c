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

void add_after_pos()
{
    int pos;
    printf("Enter the position after that you want to add a node: ");
    scanf("%d", &pos);
    struct node *temp,*temp2,*newp;
    newp = (struct node *)malloc(sizeof(struct node));
    newp->prev = NULL;
    printf("Enter the data: ");
    scanf("%d", &newp->data);
    newp->next = NULL;
    
    if(head == NULL)
    {
       head = temp;
       temp2 = temp->next;
    }
    
    else
    {
    while(pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = newp;
    temp2->prev = newp;
    newp->next = temp2;
    newp->prev = temp;
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
   	
   	  printf("\n1. Insert at beginning\n");
   	  printf("\n2. Insert at end\n");
   	  printf("\n3. Add after a position \n");
   	  printf("\n4. Display \n");
   	  printf("\n5. Exit \n");
   	  printf("\nchoose option: ");
   	  scanf("%d",&ch);
   	  switch(ch)
   	{
   	 	case 1: add_at_beg();
   	 	break;
   	 	case 2: add_at_end();
   	 	break;
   	 	case 3: add_after_pos();
   	 	break;
   	 	case 4: display();
   	 	break;
   	 	case 5: exit(1);
   	 	default:
   	 	printf("wrong option taken");
	}
     
    }
}

