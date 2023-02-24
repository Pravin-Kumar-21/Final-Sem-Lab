#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct binary_tree
{
    int data;
    struct binary_tree * left, *right;
}bst;
void initialisation(bst **root)
{
    *root==NULL;
}
void insertion_iterative(bst **root, int n)
{
    bst *newnode,*par,*cur;
    newnode=(bst*)malloc(sizeof(bst));
    newnode->data=n;
    newnode->left=newnode->right=NULL;
    if(*root==NULL)
    {
        *root=newnode;
    }
    else
    {
        par=NULL;
        cur=*root;
        while(cur!=NULL)
        {
            par=cur;
            if(n<cur->data)
                cur=cur->left;
            else
                cur=cur->right;
        }
        if(n<par->data)
            par->left=newnode;
        else
            par->right=newnode;
    }
}
void recursive_insertion(bst **root,int n)
{
    if(*root==NULL)
    {
        *root=(bst*)malloc(sizeof(bst));
        (*root)->data=n;
        (*root)->left=(*root)->right=NULL;
    }
    else if(n < (*root)->data)
    {
        recursive_insertion(&(*root)->left,n);
    }
    else
    {
        recursive_insertion(&(*root)->right,n);
    }
}
void inorder_display(bst *root)
{
    if(root!=NULL)
    {
        inorder_display(root->left);
        printf("%d\t",root->data);
        inorder_display(root->right);
    }
}
void preorder_display(bst *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder_display(root->left);
        preorder_display(root->right);
    }
}
void postorder_display(bst *root)
{
    if(root!=NULL)
    {
        preorder_display(root->left);
        preorder_display(root->right);
         printf("%d\t",root->data);
    }
}
int find_min(bst *root)
{
    bst *cur=NULL;
    cur=root;
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur->data;
}
int find_max(bst* root)
{
    bst *cur=NULL;
    cur=root;
    while(cur->right!=NULL)
    {
        cur=cur->right;
    }
    return cur->data;

}
void search_element(bst *root, int val)
{
    bst *cur=NULL;
    cur=root;
    if(cur->data==val)
    {   
        printf("\nThe Element Present %d",val);
    }
    else if(val<cur->data)
    {
        search_element(cur=cur->left,val);
    }
    else if(val>cur->data)
    {
        search_element(cur=cur->right,val);
    }
    else
    {
        printf("\nElement does not exist\n");
    }
}
int find_height(bst *root)
{
    int leftheight, rightheight;
    if(root==NULL)
        return 0;
    else
    {
        leftheight=find_height(root->left);
        rightheight=find_height(root->right);
        return (leftheight>rightheight) ? leftheight+1 : rightheight +1;
    }
}
int count_all_nodes(bst *root)
{
    if(root==NULL)
        return 0;
    else
    {
        return count_all_nodes(root->left) + count_all_nodes(root->right) + 1;
    }
}
int count_leaf_node( bst *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        return count_leaf_node(root->left) + count_leaf_node(root->right);
    }
}
int count_non_leaf_node(bst *root)
{
    if(root==NULL)
        return 0;
    else
    {
        return count_all_nodes(root)-count_leaf_node(root);
    }
}
void iterative_inorder(bst *root)
{
    int top=-1;
    bst **stk;
    stk=(bst**)malloc(sizeof(bst**)*MAX);
    while(1)
    {
        while(root)
        {
            stk[++top]=root;
            root=root->left;
        }
        if(top!=-1)
        {
            root=stk[top--];
            printf("%d\t",root->data);
            root=root->right;
        }
        else
        break;
    }
}
/*void iterative_preorder(bst*root)
{
    int top=-1;
    bst **stk;
    stk=(bst**)malloc(sizeof(bst**)*MAX);
    while(1)
    {
        while(root)
        {
            printf("%d\t",root->data);
            if(top==MAX-1)
            {
                printf("\nOverflown\n");
                exit(1);
            }
            stk[++top]=root;
            root=root->left;
        }
        if(top!=-1)
        {
            root=stk[top--];
            root=root->right;
        }
        else
        {
            break;
        }

    }
}*/
void iterative_preorder(bst *root)
{
    int top=-1;
   bst **stack;
   stack=(bst**)malloc(sizeof(bst**)*100);
   while(1)
   {
        while(root)
        {
            printf("%d\t",root->data);
            if(top==MAX-1)
            {
                printf("\nOverflown\n");
            }
            stack[++top]=root;
            root=root->left;
        }
        if(top!=-1)
        {
            root=stack[top--];
            root=root->right;
        }
        else
        {
            break;
        }
   }     
}
void main()
{
    bst *t=NULL;
    int ch;
    initialisation(&t);
    while(1)
    {
        printf("\nPress 1. to Insert data via Iterative Method\nPress 2. to insert Data Recursively\nPress 3. for Inorder Display\nPress 4. for Postorder Display\nPress 5. for Preorder Display\nPress 6. to Find Minimun element in the Tree\nPress 7. to Find Maximum element in the Tree\nPress 8. to Search an element\nPress 9. to find height of the Binary Tree\nPress 10. to Count all Nodes\nPress 11. to Count all Leaf-Nodes\nPress 12. to Count Non-Leaf-Node\nPress 13. for Non-Recursive Inorder Traversal\nPress 14. To insert Non-Recursive Preorder traversal\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int n;
                printf("\nEnter the Data\n");
                scanf("%d",&n);
                insertion_iterative(&t,n);
                break;
            }
            case 2:
            {
                int n;
                printf("\nEnter the Data\n");
                scanf("%d",&n);
                recursive_insertion(&t,n);
                break;
            }
            case 3:
            {
                inorder_display(t);
                break;
            }
            case 4 :
            {
                postorder_display(t);
                break;
            }
            case 5:
            {
                preorder_display(t);
                break;
            }
            case 6:
            {
                printf("The Smallest Element is %d",find_min(t));
                break;
            }
            case 7:
            {
                printf("The Largest Element is %d",find_max(t));
            }
            case 8:
            {
                int val;
                printf("\nEnter the data to search\n");
                scanf("%d",&val);
                search_element(t,val);
                break;
            }
            case 9:
            {
                printf("\nThe height of the Binary Tree is %d\n",find_height(t));
                break;               
            }
            case 10:
            {
                printf("\nThe Total no of Nodes Present is%d\n",count_all_nodes(t));
                break;
            }
            case 11:
            {
                printf("\nThe Total No of Leaf Node %d\n",count_leaf_node(t));
                break;
            }
            case 12:
            {
                count_non_leaf_node(t);
                break;
            }
            case 13:
            {
                iterative_inorder(t);
                break;
            }
            case 14:
            {
                iterative_preorder(t);
                break;
            }
        }
    }
}