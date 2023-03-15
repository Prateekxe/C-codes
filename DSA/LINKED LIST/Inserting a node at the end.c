#include<stdio.h>
#include<stdlib.h>

struct node{          // creating a structure for making nodes
    int data;
    struct node *link;
};

struct node *head = NULL; // making a head pointer which will always points to the first node

void add_end(); // declaring function to insert node at end
void print_data();  // Declaring function to print the data part of linked list

void add_end(struct node *head, int data) // function definition
{
    struct node *ptr, *temp; // making ptr pointer to traverse the list & temp pointer to store the data of the node to be inserted
    ptr = head;  // this line gives access to ptr to access the first node and then traverse the list
    
    if(head==NULL)
    printf("The linked list is empty.");
    else
    temp = (struct node *)malloc(sizeof(struct node));//making a node and giving the address to temp
    temp->data = data;
    temp->link = NULL;
    
    while(ptr->link !=NULL) //ptr->link != NULL; means we'll not execute the while part for the last node so that we can 
    {                       // access that node and add another node at the end
        ptr = ptr->link;
    }
    ptr->link = temp; // connecting the node to be inserted with the last node
}

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
      while(ptr!= NULL) // if we write ptr->link != NULL; then it will stop printing after printing the second last node
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
    add_end(head,67);
    printf("\n");
    print_data(head);
    return 0;
    
}

