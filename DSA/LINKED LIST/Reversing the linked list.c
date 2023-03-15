#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head;

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

void rev_list()
{
    struct node *prev = NULL;
    struct node *next = NULL;
    
    if(head == NULL)
    {
        printf("Linked list is already empty.");
    }
    
    else
    {
        while(head != NULL)
        {
            next = head->link;
            head->link = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }

}

void del_list()
{
  struct node *temp = head;
  
  while(temp != NULL)
  {
    temp = temp->link;
    free(head);
    head = temp;
  }
}

void display()
{
	if(head == NULL)
	{
		printf("Linked List is Empty");
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
    printf("\n1. Insert at the beginning\n");
    printf("\n2. Delete whole list\n");
    printf("\n3. Reverse the linked list\n");
    printf("\n4. Display\n");
    printf("\n5. Exit\n");
    
    printf("\nChoose Options\n");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:add_beg();
    break;
    case 2:del_list();
    case 3: rev_list();
    break;
    break;
    case 4:display();
    break;
    case 5: exit(1);
    break;
    default:
    printf("Wrong input given");
    }
    }
    return 0;
}
