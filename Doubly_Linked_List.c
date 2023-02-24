#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list *next,*prev;
}list;
void initialisatiion(list **head)
{
    *head=NULL;
}
void insertion(list **head,int n)
{
    list *cur,*prv,*newnode;
    newnode=(list*)malloc(sizeof(list));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    for(cur=*head,prv=NULL;cur!=NULL;cur=cur->next)
    {
        prv=cur;
    }
    if(prv)
    {
        newnode->prev=prv;
        prv->next=newnode;
    }
    else
    {
        *head=newnode;
    }
}
void insertion_in_sorted_order(list **head,int n)
{
    list *cur,*prv,*newnode;
    newnode=(list*)malloc(sizeof(list));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    for(cur=*head,prv=NULL;cur!=NULL && n>cur->data;cur=cur->next)
    {
        prv=cur;
    }
    newnode->next=cur;
    if(cur!=NULL)
    {
        cur->prev=newnode;
    }
    if(prv)
    {
        prv->next=newnode;
        newnode->prev=prv;
    }
    else
    {
        *head=newnode;
    }

}
void deletion(list **head,int n)
{
    int flag=0;
     if(*head==NULL)
     {
        printf("\nList is  Empty\n");
     }
     list *cur,*prv,*t;
     for(cur=*head,prv=NULL;cur!=NULL;cur=cur->next)
     {
        if(cur->data==n)
        {
            flag=1;
            t=cur;
            if(prv)
            {
                if(cur->next==NULL){
                    prv->next = NULL;
                }
                else
                {
                    cur->next->prev = prv;
                    prv->next = cur->next;
                }
            }
            else
            {
                cur->next->prev=NULL;
                *head=cur->next;
            }
            free(t);
            printf("\nItem Deleted Successfully\n");
            return;
        }
        else
        {
            prv=cur;
        }
     }
     
}
void Display(list *head)
{
    for(;head;head=head->next)
    {
        printf("%d\t",head->data);
    }
}
int search_element(list *head,int n)
{
    int flag=0;
    list *cur=head;
    if(cur==NULL)
    {
        printf("\nList is Empty\n");
    }
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        if(cur->data==n)
        {
            flag=1;
        }
    }
    return flag;

}
void insert_at_beginning(list **head,int n)
{
    list *cur,*newnode;
    newnode=(list*)malloc(sizeof(list));
    newnode->data=n;
    cur=*head;
    newnode->prev=NULL;
    newnode->next=cur;
    *head=newnode;
}
void reverse_doubly_linked_list(list **head)
{
    list *cur;
    cur=*head;
    if(cur==NULL || cur->next==NULL)
    {
        return;
    }
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    *head=cur;
    cur->next=cur->prev;
    cur->prev=NULL;
    cur=cur->next;
    while(cur->prev!=NULL)
    {
        list *temp=cur->next;
        cur->next=cur->prev;
        cur->prev=temp;
        cur=cur->next;
    }
    cur->prev=cur->next;
    cur->next=NULL;
}
void insert_at_end(list **head,int n)
{
    list *cur,*newnode;
    newnode=(list*)malloc(sizeof(list));
    newnode->data=n;
    cur=*head;
    while(cur->next!=NULL)
    {
        cur=cur->next;

    }
    cur->next=newnode;
    newnode->prev=cur;
    newnode->next=NULL;
}
void reverse_Display(list *head)
{
    list *cur;
    cur=head;
    for(cur=head;cur->next!=NULL;cur=cur->next);
    for(;cur!=NULL;cur=cur->prev)
    {
        printf("%d\t",cur->data);
    }
}
int main()
{
    list *p;
    initialisatiion(&p);
    while(1)
    {
        int ch;
        printf("\n Press 1. to Insert Data\n Press 2. to Display\n Press 3 . Delete Data\n Press 4. to Reverse the list\n Press 5. to Search an Element\n Press 6. to Insert at element at the beginning \n Press 7. to Insert at the end\n Press 8. to Display the list in Reverse Order\n Press 9. to Insert List in Sorted Order\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int n;
                scanf("%d",&n);
                insertion(&p,n);
                break;
            }
            case 2:
            {
                Display(p);
                break;
            }
            case 3:
            {
                int n;
                printf("\nEnter the Data to Delete\n");
                scanf("%d",&n);
                deletion(&p,n);
                break;
            }
            case 4:
            {
                reverse_doubly_linked_list(&p);
                break;
            }
            case 5:
            {
                int n;
                scanf("%d",&n);
                if(search_element(p,n))
                {
                    printf("\n element is Present\n");
                }
                else
                {
                    printf("\nElement is not Present\n");
                }
                break;
            }
            case 6:
            {
                int n;
                scanf("%d",&n);
                insert_at_beginning(&p,n);
                break;
            }
            case 7:
            {
                int n;
                scanf("%d",&n);
                insert_at_end(&p,n);
                break;
            }
            case 8: 
            {
                reverse_Display(p);
                break;
            }
            case 9:
            {
                int n;
                scanf("%d",&n);
                insertion_in_sorted_order(&p,n);
                break;
            }
            default :
            {
                printf("\n Invalid Choice\n");
                break;
            }
        }
    }
}