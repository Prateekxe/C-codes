// Neso > Data Structures > Video 34 & 35.

#include<stdio.h>
#include<stdlib.h>

struct node{        // Creating first node i.e. [data, link]
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL; // creating a pointer to the first node, 
    head = (struct node *)malloc(sizeof(struct node)); // allocating/giving memory to the first node & passing the address of first node to head
    head->data = 45; // putting 45 to the data part of the first node with the help of pointer head; bcz head can access data part of first node
    head->link = NULL; //assining NULL to the address part of the first node
    
    struct node *current = (struct node *)malloc(sizeof(struct node)); // creating another pointer to struct node(means second node forms here)
    current->data = 36; // putting 36 to the data part of the second node
    current->link = NULL; // assining NULL to the address part of the second node
    head->link = current; //putting current(means address if the second node) to the link(address part)part of the first node with help of head
    
    current = (struct node *)malloc(sizeof(struct node)); // here i'm re-using the previous pointer current which will now point to the third
    current->data = 69;                                   //node of the linked list
    current->link = NULL;
    head->link->link = current; // giving address of the newly re-used pointer to the address part of the second node
    
    printf("%d %d %d", head->data, current->data, current ->data);
    
/* Another method for creating third node is :
----------------------------------------------------------------------------------------------
   struct node *current2 = (struct node *)malloc(sizeof(struct node));
    current2->data = 89;
    current2->link = NULL;
    head->link->link = current;
    
    printf("%d %d %d", head->data, current->data, current2 ->data);
    return 0;
-----------------------------------------------------------------------------------------------    
    In this method we're creating a third pointer with another name current2 which will point to the third node ,
    we're not using the name of the second pointer as we've used in this program
*/
    
    return 0;
}
