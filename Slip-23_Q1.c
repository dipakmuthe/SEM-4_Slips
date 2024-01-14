/* Q.1) Implement a Binary search tree (BST) library (btree.h) with operations – create, search, preorder.
Write a menu driven program that performs the above operations. */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
   int data;
   struct node *left,*right;
}NODE;

struct stack
{
	struct node *data[MAX];
	int top;
}s;

void init()
{
   s.top=-1;
}

int isempty()
{
	if(s.top==-1)
	   return 1;
	else
	   return 0;
}
int isfull()
{
	if(s.top==MAX-1)
	   return 1;
	else
	  return 0;
}
void push(struct node *temp)
{
	if(isfull())
	   printf("stack is full");
	else
	{
		s.top++;
		s.data[s.top]=temp;
	}
}
struct node *pop()
{
	struct node *temp;
	if(isempty())
	   printf("stack is underflow");
	else
	{
		temp=s.data[s.top];
		s.top--;
	}
  return temp;
}
NODE * create(NODE *root)
{
   int i,n;
   NODE *temp,*parent,*newnode;
   printf("Enter limit:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      newnode=(NODE*)malloc(sizeof(NODE));
      printf("Enter value:");
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
        if(newnode->data<temp->data)
             temp=temp->left;
        else
             temp=temp->right;
     } 
     if(newnode->data<parent->data)
        parent->left=newnode;
     else
        parent->right=newnode;
   }
  return root;
}

void search(NODE *root,int num)
{
   NODE *temp=root;
   int flag=0;
   while(temp!=NULL)
   {
      push(temp);
	  temp=temp->left;	
   }   
   while(!isempty())
   {
   	 temp=pop();
   	 if(temp->data == num)
   	 {
   		flag=1;
		 break; 	
	}
   	 temp=temp->right;
   	 while(temp!=NULL)
   	 {
   	   push(temp);
   	   temp=temp->left;	
	    }
   }
   if(flag==1)
    {
    	  printf("\n Number is Found.....");
	}
    else
    {
    	  printf("\n Number not Found.....");
	}
}

void preorder(NODE *root)
{
   NODE *temp=root;
    if(temp!=NULL)
    {
    	printf("%d\t",temp->data);
    	preorder(temp->left);
    	preorder(temp->right);
    	
	}
}
int main()
{
   NODE *root=NULL;
   int num,ch;
   init();
   do{
   	  printf("\n1-Create \n2-Search \n3-Preorder \nEnter the Choice :");
   	  scanf("%d",&ch);
   	  switch(ch)
   	  {
   	  	case 1: root=create(root);
   	  	        break;
   	  	case 2: printf("\n Enter num to search :");
    			scanf("%d",&num);
  				 search(root,num);
  				 break;
  		case 3:  printf("\n Display using preorder :");
  				 preorder(root);
  				 break;
  	    default : printf("\n  Invalid Choice...");
		 }
   }while(ch<4);
}
