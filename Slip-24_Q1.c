#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        int data;
        struct node *left,*right;
}NODE;
NODE * create(NODE *root)
{
        NODE *newnode,*temp,*parent;
        int i,n;
        printf("Enter the Limit:");
        scanf("%d",&n);
      
        for(i=0;i<n;i++)
    {
            newnode=(NODE *)malloc(sizeof(NODE));
            printf("\nEnter the Element :");
            scanf("%d",&newnode->data);
            newnode->left=NULL;
            newnode->right=NULL;
            if(root==NULL)
            {
                    root=newnode;
                    continue;
                }
                temp=root;
                while(temp!=NULL)
                {
                        parent=temp;
                        if(newnode->data < temp->data)
                        temp=temp->left;
                        else
                         temp=temp->right;
                }
                if(newnode->data < parent->data)
                 parent->left=newnode;
                else
                  parent->right=newnode;
        }
        return root;
}
NODE *insert(NODE *root,int num)
{
	NODE *newnode,*temp,*parent;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=num;
	newnode->left=NULL;
	newnode->right=NULL;
	{
	if(root==NULL)
	{
		root=newnode;
	}
	temp=root;
	while(temp!=NULL)
	{
		parent=temp;
		if(newnode->data < temp->data)
		 temp=temp->left;
		else
		 temp=temp->right;
	}
	 if(newnode->data < parent->data)
	   parent->left=newnode;
	 else 
	   parent->right=newnode;
    }
	return root;
}
void postorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
int main()
{
		int ch,num;
        NODE *root=NULL;
    do{
    	printf("\n1-Create \n2-Insert \n3-Postorder Display \n:Enter the Choice :");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:root=create(root);
    		       break;
    		case 2:printf("\n Enter the Element to INsert:");
    				scanf("%d",&num);
    				insert(root,num);
    				break;
    		case 3:printf("\nDisplay Using Postorder :");
    				postorder(root);
    				break;
    		default :printf("\n Invalid Choice.......");
		}
	}while(ch<4);
       

}
