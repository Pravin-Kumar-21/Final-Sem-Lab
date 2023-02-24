#include<stdio.h>
#include<stdlib.h>
typedef struct Link
{
    int data;
    struct Link *next;
}link;
void initilisation(link ** head)
{
    *head=NULL;
}
void serial_order_insertion(link ** head, int n)
{
    link *prv, *cur,*newnode;
    newnode=(link*)malloc(sizeof(link));
    newnode->data=n;
    newnode->next=NULL;
    for(cur=*head,prv=NULL;cur!=NULL;cur=cur->next)
        prv=cur;
    if(prv!=NULL)
    {
        prv->next=newnode;
    }
    else
        *head=newnode;
}
void insertion_sorted_order(link ** head, int n)
{
    link *cur,*prv,*newnode;
    newnode=(link*)malloc(sizeof(link));
    newnode->data=n;
    newnode->next=NULL;
    for(cur=*head,prv=NULL;cur!=NULL && n>cur->data;cur=cur->next)
    {
        prv=cur;
    }
    newnode->next=cur;
    if(prv!=NULL)
    {
        prv->next=newnode;
    }
    else{
        *head=newnode;
    }
}
void recursive_insertion_sorted_order(link **head, int n)
{
    link *newnode;
    newnode=(link*)malloc(sizeof(link));
    newnode->data=n;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else if(n>(*head)->data && *head!=NULL)
        {
            newnode->next = (*head);
            *head=newnode;
        }
    else
        recursive_insertion_sorted_order(&(*head)->next,n); 
}
void display(link *head)
{
    for(;head!=NULL;head=head->next)
    {
        printf("%d",head->data);
        printf("-[%d]-",head);
        printf("[%d]\t",head->next);
    }
    printf("\n");
}
void reverse(link **head)
{
    link *cur,*prv,*nextnode;
    nextnode=NULL;
    for(cur=*head,prv=NULL;cur!=NULL;cur=nextnode)
    {
        nextnode=cur->next;
        cur->next=prv;
        prv=cur;
    }
    *head=prv;
}
void delete (link **head,int n)
{
    int flag=0;
    link *cur , *prv;
    for(cur=*head,prv=NULL;cur!=NULL;cur=cur->next)
    {
        if(prv!=NULL && n==cur->data)
        {
            flag=1;
            prv->next=cur->next;
            free(cur);
            return;
        }
        else if(prv==NULL && n==cur->data)
        {
            *head=cur->next;
            free(cur);
            return;
        }
        else
        {
            prv=cur;
        }
    }
    if (!flag)
    {
        printf("\n Data not found\n");
    }
}
int searching_list(link **head,int n)
{
    link *cur;int count=0;
    for(cur=*head;cur!=NULL;cur=cur->next)
        {
            if(n==cur->data)
            {  
                count=1;
                break;
            }
        }
    if(count!=0)
        return 1;
    else
        return 0;

}
void recursive_insertion(link **head,int n)
{
    if (*head == NULL)
    {
        *head = (link *)malloc(sizeof(link));
        (*head)->data=n;
        (*head)->next=NULL;
    }
    else
    {
        recursive_insertion(&(*head)->next,n);
    }
}
int count(link **head)
{
    link *cur; int flag;
    for(cur=*head;cur!=NULL;cur=cur->next)
        flag++;
    return flag;
}
void split_and_display(link **head ,link **head_odd,link **head_even)
{
    link *cur;
    for(cur=*head;cur!=NULL;cur=cur->next)
    {
        if(cur->data%2==0)
        {
            serial_order_insertion(head_even,cur->data);
        }
        else
        {
            serial_order_insertion(head_odd,cur->data);
        }
    }
}
void merge_and_display(link **odd ,link **even)
{
     link *cur,*temp;
     cur=*odd;
     while(cur!=NULL)
     { 
        if(cur->next==NULL)
            temp=cur;
        cur=cur->next;
     }
     temp->next=*even;
}
void main()
{
    link *s = NULL;
    link *odd,*even;
    odd=NULL;even=NULL;
    initilisation(&s);
    int choice, n;
    while(1)
    {
        printf("\n Operations on Linked List\n Press 1 to Insert in Serial Order \n Press 2 to insert in Sorted order \n");
        printf(" Press 3 to Display\n Press 4 to Reverse the List\n Press 5 to Delete items \n Press 6 to Count no of items in the List\n Press 7 to Search an element\n");
        printf(" Press 8 to Split and Display data in Odd Even Form \n Press 9 to Merge and Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {   
                printf("\nEnter Data\n");
                scanf("%dd", &n);
                serial_order_insertion(&s, n);
                break;
            }
            case 2:
            {
                printf("\nEnter Data\n");
                scanf("%d", &n);
                insertion_sorted_order(&s,n);
                break;
            }
            case 3: 
            {
                display(s);
                break;
            }
            case 4:
            {
                reverse(&s);
                break;
            }
            case 5:
            {
                
                printf("\nEnter Data\n");
                scanf("%dd", &n);
                delete (&s, n);
                break;
            }
            case 6:
            {
                printf("%d",count(&s));
                break;
            }
            case 7:
            {
                scanf("%d",n);
                if (searching_list(&s, n))
                {
                    printf("\nItem Found!!!\n");
                }
                else
                {
                    printf("\n Not Found\n");
                }
                break;
            }
            case 8:
            {
                split_and_display(&s,&odd,&even);
                display(odd);
                display(even);
                break;
            }
            case 9:
            {
                merge_and_display(&odd,&even);
                display(odd);
                
            }
            default :
            {
                printf("\n Invalid Choice \n");
            }
        }
    }

}