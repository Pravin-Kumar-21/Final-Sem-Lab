#include<stdio.h>
#include<stdlib.h>
typedef struct cir_link
{
    int data;
    struct cir_link *next;
}list;
void initialilsation(list **head)
{
    *head=NULL;
}
void deletion(list **head,int n)
{
    if(*head=NULL)
    {
        printf("\nThe list is Empty\n");
        return;
    }
    list *cur,*tail,*prv;
    for(tail=*head;tail->next!=*head;tail=tail->next);
    for(cur=*head,prv=NULL;cur->next!=*head;cur=cur->next)
    {
        list *t;
        if((*head)->data==n)
        {
            t=*head;
            *head=(*head)->next;
            tail->next=*head;
            t->next==NULL;
        }
        else if(cur->data==n)
        {
            t=cur;
            prv=cur->next;
        }
        else if()
        {
            
        }
    }
}
void insertion(list **head,int n)
{
    list *cur,*prv,*newnode;
    newnode=(list*)malloc(sizeof(list));
    newnode->data=n;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        newnode->next=newnode;
        return;
    }
    for(cur=*head;cur->next!=*head;cur=cur->next);
    cur->next=newnode;
    newnode->next=*head;
}
void display(list *head)
{
    list *cur;
    cur=head;
    for(cur=head;cur->next->next!=head->next;cur=cur->next)
    {
        printf("%d", cur->data);
        printf("-[%d]-", cur);
        printf("[%d]\t", cur->next);
    }
    printf("%d", cur->data);
    printf("-[%d]-", cur);
    printf("[%d]\t", cur->next);

    printf("\n");
}
void main()
{
    list *s = NULL;
    initialilsation(&s);
    int choice, n;
    while (1)
    {
        printf("\n Operations on Linked List\n Press 1 to Insert in Serial Order\n");
        printf(" Press 2 to Display\n");
        printf("\nPress 3. to Delete items from the list\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\nEnter Data\n");
            scanf("%dd", &n);
            insertion(&s, n);
            break;
        }
        case 2:
        {
            display(s);
            break;
        }
        case 3:
        {
            printf("\nEnter data to delete from the list\n");
            int n;
            scanf("%d",&n);
            deletion(&s,n);
            break;
        }
        }
    }
}