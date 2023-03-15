#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_beg();   // function declaration having type struct node bcz it will return head which is of type struct node

struct node* add_beg(struct node* head)// parameter d is local to this funnction
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 99; // made the node which has to be inserted in te beginning
    ptr->link = NULL;
    
    ptr->link = head; // this line will give access to ptr to point to the first node along with head
    head = ptr; // this line will give access to the head to point to the newly made node
    return head;   
}

// these two lines [17 & 18] are solely responsible to add new node in the beginning

int main()
{
    struct node *head= NULL;
    head = (struct node *)malloc(sizeof(struct node)); // first node 
    head->data = 45;
    head->link = NULL;
    
    struct node *ptr= NULL;
    ptr = (struct node *)malloc(sizeof(struct node)); // second node
    ptr->data = 66;
    ptr->link = NULL;
    head->link = ptr;
    
    // int data = 34; --> this will also work just you have to add another argument data in the add_beg function 
    // like this --> head = add_beg(head, data); and also add another parameter int d in the function parameter
    // like this --> struct node* add_beg(struct node* head, int d)
    // then in addition to this do this : ptr->data = d;
    
    head = add_beg(head); // this function will return head 
    
    ptr = head;           
    while(ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->link;
    }
    
    return 0;
}

