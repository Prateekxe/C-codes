#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *top = NULL;

void push()
{
	struct node *temp;
	temp= (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
    {
        printf("Stack Overflow.");
        exit(1);
    }
	
	printf("Enter the data you want at BEGINNING: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    
    if(top==NULL){
    	top = temp;
	}
	else
	{
		temp->link = top;
		top = temp;
	}
}

void pop()
{
    if(top==0)
    {
		printf("Stack Underflow");
		exit(1);
	}
	struct node *ptr=top;
	int value=ptr->data;
	top=ptr->link;
	free(ptr);
	ptr=NULL;
	printf("Popped data is: %d",value);
}

void isEmpty()
{
   if(top==NULL)
   {
       printf("Stack is Empty.");
   }
   else
   {
       printf("No, stack is not empty.");
   }
}

void peak()
{
    if(top== NULL)
    {
        printf("The stack is empty.");
    }
    else
    {
        printf("Peak value or top value is,%d",top->data);
    }
}

void display()
{
	struct node *ptr;
	if(top==NULL)
	{
		printf("Stack Underflow");
	}
	else
	{
		ptr=top;
		while(ptr !=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->link;
			printf("\n");
		}
	}
}

int main()
{
    int n;
    while(1)
    {
        printf("\n1.Push\n");
        printf("\n2.Pop\n");
        printf("\n3.is stack Empty ??\n");
        printf("\n4.Display the top element\n");
        printf("\n5.Display\n");
        printf("\n6.Exit\n");
        printf("\nChoose Option: \t");
        scanf("%d",&n);
        
        switch(n)
        {
            case 1: push();
            break;
            
            case 2: pop();
            break;
            
            case 3: isEmpty();
            break;
            
            case 4: peak();
            break;
            
            case 5: display();
            break;
            
            case 6: exit(1);
            
            default: printf("Wrong Option Choosen.");
        }
        
    }
}

