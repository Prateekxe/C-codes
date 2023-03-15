#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

void push()
{
    if(top == MAX-1)
    {
        printf("Stack Overflow.");
        return ;
    }
    top = top + 1;
    printf("Enter the element to be pushed: ");
    scanf("%d",&stack_arr[top]);
}

void pop()
{
    int value;
    if(top == -1)
    {
        printf("Stack Underflow.");
        //exit(1);
    }
    else
    {
    value = stack_arr[top];
    top = top-1;
    }
    printf("Popped value is: %d", value);
    
}

void isFull()
{
    if(top == MAX-1)
    {
        printf("Stack is full.");
    }
    else
    {
        printf("NO , Remaining Items: %d",(MAX-1-top));
    }
}

void isEmpty(){
	if(top == -1){
		printf("Stack is empty.");
	}
	else{
		printf("NO,There are %d items in the stack.",(top+1));
	}
}

void print(){
	int i;
	if(top==-1)
	{
		printf("Stack is empty");
	}
	for(i=top;i>=0;i--)
	{
		printf("%d ",stack_arr[i]);
		printf("\n");
	}
}

int main()
{
    int n;
    while(1)
    {
        printf("\n1.Push\n");
        printf("\n2.Pop\n");
        printf("\n3.Print\n");
        printf("\n4.Check whether stack is Full or not. \n");
        printf("\n5.Check whether stack is Empty or not.\n");
        printf("\n6.Exit\n");
        printf("\nChoose Option: \t");
        scanf("%d",&n);

    switch(n)
    {
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: print();
        break;
        case 4: isFull();
        break;
        case 5: isEmpty();
        break;
        case 6: exit(1);
        default: printf("Wrong option choosen.");
    }
  }
}
