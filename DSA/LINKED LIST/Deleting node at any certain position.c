#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;

void add_beg()
{
	struct node *temp;
	temp= (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the data you want at BEGINNING: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    
    if(head==NULL){
    	head = temp;
	}
	else
	{
		temp->link = head;
		head = temp;
	}
}

void del_pos()
{
    int pos;
    struct node *previous = head;
    struct node *current = head;
    
    printf("Enter the position: ");
    scanf("%d", &pos);
    
    if(head == NULL)
    {
        printf("linked list is already empty.");
    }
    else if(pos == 1)
    {
        head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos != 1)
        {
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
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
		ptr = ptr->link;
	    }
		
	}
}

int main()
{
int ch;
   while(1)
   {
   	
   	  printf("\n1. Insert Beginning\n");
   	  printf("\n2. Delete at any position\n");
   	  printf("\n3. Display \n");
   	  printf("\n4. Exit \n");
   	  printf("\nchoose option: ");
   	  scanf("%d",&ch);
   	  switch(ch)
   	{
   	 	case 1: add_beg();
   	 	break;
   	 	case 2: del_pos();
   	 	break;
   	 	case 3: display();
   	 	break;
   	 	case 4: exit(1);
   	 	default:
   	 	printf("wrong option taken");
	}
     
    }
   return 0;
}
