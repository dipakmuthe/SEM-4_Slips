#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *left,*right;
}node;

node *create(node *root)
{
	node *newnode,*temp,*parent;
	int i,n;
	printf("Enter the limit :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(node *)malloc(sizeof(node));
		printf("Enter the element :");
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
void *preorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
int main()
{
	int ch;
	node *root=NULL;
	do{
        printf("\n1-Create \n2-Preorder \nEnter the Choice =");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: root=create(root);
			        break;
			case 2: printf("Display Pretorder is :");
					preorder(root);
			        break;
			default :printf("Invalid Choice..");
		}
	}while(ch<3);
}





