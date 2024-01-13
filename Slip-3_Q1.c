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
node *insert(node *root,int num)
{
	node *newnode,*temp,*parent;
	newnode=(node *)malloc(sizeof(node));
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
    printf("\n Insert Successfully....");
	return root;
}
void *postorder(node *root)
{
	node *temp=root;
	 if(temp!=NULL)
	 {
	 	postorder(temp->left);
	 	postorder(temp->right);
		printf("%d\t",temp->data);
	 }
}
int main()
{
	int num,ch;
	node *root=NULL;
	do{
        printf("\n1-Create \n2-Insert \n3-postorder \nEnter the Choice =");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: root=create(root);
			        break;
			case 2: printf("\nEnter the element to insert :");
					scanf("%d",&num);
					root=insert(root,num);
					break;
			case 3:printf("Display Postorder is :");
					postorder(root);
			        break;
			default :printf("Invalid Choice..");
		}
	}while(ch<4);
}





