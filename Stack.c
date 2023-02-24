#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
}elements;
void initialisation(elements **top)
{
    *top=NULL;
}
void push(elements **top,int n)
{
    elements *newnode;
    newnode=(elements*)malloc(sizeof(elements));
    newnode->data=n;
    newnode->next=*top;
    *top=newnode;
}
int pop(elements **top)
{
    int n;
    elements *t;
    if(*top!=NULL)
    {
        t=*top;
        n=(*top)->data;
        *top=(*top)->next;
        free(t);
        return n;
    }
    else
    {
        printf("\nStack is Empty\n");
        return;
    }
}
void display(elements *top)
{
    while(top!=NULL)
    {
        printf("%d\t",top->data);
        top=top->next;
    }
}
void main()
{
    elements *s;
    initialisation(&s);
    int ch;
    while(1)
    {
        printf("\nPress 1. to Push Data\nPress 2. to Pop item\nPress 3. to Display Data\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int n;
                scanf("%d",&n);
                push(&s,n);
                printf("\nItem pushed successfully\n");
                break;
            }
            case 2:
            {
                printf("Item Popped Succesfully%d",pop(&s));
                break;
            }
            case 3:
            {
                display(s);
                break;
            }
        }
    }
}