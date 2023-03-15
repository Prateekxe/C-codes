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

void add_pos()
{
    int pos;
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    
    printf("Enter the position: ");
    scanf("%d", &pos);
    
    if(pos == 1)
    {
        add_beg();
    }
    else
    {
   	printf("Enter the data you want at any POSITION: ");
    scanf("%d",&temp->data);
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
}

void add_end()
{
    struct node *ptr, *temp;
     
    temp= (struct node *)malloc(sizeof(struct node));
    
    printf("Enter the data you want at the END: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    
    ptr = head;
    if(head == NULL)
	{
    	head = temp;
	}
   
    else
    {
        while(ptr->link != NULL)
        {
          ptr = ptr->link;  
        }
        ptr->link= temp;
        
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
   	
   	  printf("\n1. Insert at BEGINNING\n");
   	  printf("\n2. Insert at any POSITION\n");
   	  printf("\n3. Insert at END\n");
   	  printf("\n4. Delete at BEGINNING\n");
   	  printf("\n5. Delete at any POSITION\n");
   	  printf("\n6. Delete at END\n");
   	  printf("\n7. Display \n");
   	  printf("\n8. Exit \n");
   	  printf("\nchoose option: ");
   	  scanf("%d",&ch);
   	  switch(ch)
   	{
   	 	case 1: add_beg();
   	 	break;
   	 	case 2: add_pos();
   	 	break;
   	 	case 3: add_end();
   	 	break;
   	 	case 4: del_beg();
   	 	break;
   	 	case 5: del_pos();
   	 	break;
   	 	case 6: del_end();
   	 	break;
   	 	case 7: display();
   	 	break;
   	 	case 8: exit(1);
   	 	default:
   	 	printf("wrong option taken");
	}
     
    }
   return 0;
}
