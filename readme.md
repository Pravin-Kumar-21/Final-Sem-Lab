void iterative_inorder(bst *root)
{
    int top=-1;
    bst** stack;
    stack=(bst**)malloc(sizeof(bst**)*MAX);
    while(1)
    {
        while(root)
        {
            if(top=-1)
            {
                printf("Overflown");
            }
            stack[++top]=root;
            root=root->left;
        }
        if(top!=-1)
        {
            root=stack[top--];
            printf("%d\t",root->data);
            root=root->right;
        }
        else
        break;
        
    }

}
void iterative_preorder(bst *root)
{
    int top=-1;
   bst **stack;
   stack=(bst**)malloc(sizeof(bst**));
   while(1)
   {
        while(root)
        {
            printf("%d",root->data);
            if(top==MAX-1)
            {
                printf("Overflown");
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