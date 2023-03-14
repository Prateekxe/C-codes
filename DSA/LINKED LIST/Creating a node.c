#include<stdio.h>
#include<stdlib.h>

struct node{           // In this line we're creating a node with the help of structure but here memory is not allocated
                        // it will allocated after the use of malloc function
    int data;   // --> data part of the structure
    struct node *link;  // --> link part of the structure
};

int main()
{
 //struct node *head = NULL;     --> you can use this also and then in the next line start with -> head = (struct node *)malloc.....
 struct node *head = (struct node *)malloc(sizeof(struct node));  /*Giving the size of that node to a pointer named head, now head contains the 
                                                    address of that node , that means head can access that node  */
 printf("Enter data: ");
 scanf("%d", &head->data);    //user input to fill data of node through head 
 //head->data = 45;          -->or youc directly input; {head ke data me 45 insert karna}
 head->link = NULL;         // head ke link(address) me NULL insert karna
    
 printf("The data part of that node is:%d \n", head->data);
 printf("Hurray, You've done this.");
 return 0;
    
}
