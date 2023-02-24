#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list *next;
}list;
void initialisation(list **head)
{
    *head=NULL;
}
void insertion_in_sorted_order(list **head, int n)
{
    list *cur,*prv,*newnode;
    newnode=(list*)malloc(sizeof(list));
    newnode->next=NULL;
    newnode->data=n;
    for(cur=*head,prv=NULL;cur!=NULL &&n>cur->data;cur=cur->next)
    {
        prv=cur;
    }
    newnode->next=cur;
    if(prv)
    {
        prv->next=newnode;
    }
    else
    {
        *head=newnode;
    }
}
void display(list *head)
{
    for(;head!=NULL;head=head->next)
    printf("%d\t",head->data);
}
void recursive_display(list *head)
{
        return;
    if(head==NULL)
    printf("%d\t",head->data);
    recursive_display(head->next);
}
int find_max(list *head)
{
    int max=0;
    list *cur;
    max=head->data;
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        if(max<cur->data)
        {
            max=cur->data;
        }
    }
    return max;
}
void main()
{
    list *p;
    initialisation(&p);
    int ch;
    while(1)
    {
        printf("\nPress 1. to Insert Data in Sorted Order\nPress 2. to Display\nPress 3. Recursive Display\nPress 4. to find Max Element in the list\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int n;
                printf("\nEnter Data to insert in list\n");
                scanf("%d", &n);
                insertion_in_sorted_order(&p, n);
                break;
            }
            case 2:
            {
                display(p);
                break;
            }
            case 3:
            {
                recursive_display(p);
                break;
            }
            case 4:
            {
               printf("The Maximun Element is %d\n",find_max(p));
               break;
            }
        }
    }
}