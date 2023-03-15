// neso -> Data Structure -> video number 37

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;

void print_data();

void print_data(struct node *head)
{
  if(head==NULL)
  {
      printf("The linked list empty.");
  }
  else
  {
      struct node *ptr = NULL;
      ptr=head;
      
      printf("The data parts of the created linked list are : ");
      while(ptr != NULL)
      {
          printf("%d ",ptr->data);
          ptr = ptr->link;
      }
  }
}

int main()
{
    struct node *ptr = NULL;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = 21;
    ptr->link = NULL;
    head = ptr;
    
    struct node *current = NULL;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 22;
    current->link = NULL;
    ptr->link = current;
    
    struct node *current2 = NULL;
    current2 = (struct node *)malloc(sizeof(struct node));
    current2->data = 23;
    current2->link = NULL;
    current->link = current2;
    
    struct node *current3 = NULL;
    current3 = (struct node *)malloc(sizeof(struct node));
    current3->data = 24;
    current3->link = NULL;
    current2->link = current3;
    
    
    print_data(head);
    
    return 0;
}
