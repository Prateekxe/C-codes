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
    struct node *temp =(struct node *) malloc(sizeof(struct node));
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
        //pos--; //why decrement//
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
   	
   	  printf("\n1. Insert at Beginning\n");
   	  printf("\n2. Insert at end\n");
   	  printf("\n3. Insert at position\n");
   	  printf("\n4. Display \n");
   	  printf("\n5. Exit \n");
   	  printf("\nchoose option: ");
   	  scanf("%d",&ch);
   	  switch(ch)
   	{
   	 	case 1: add_beg();
   	 	break;
   	 	case 2: add_end();
   	 	break;
   	 	case 3: add_pos();
   	 	break;
   	 	case 4: display();
   	 	break;
   	 	case 5: exit(1);
   	 	default:
   	 	printf("wrong option taken");
	}
     
    }
   return 0;
}





