#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;	
};
void pre_order_traversal(struct node* root) 
{
   if(root!=NULL) 
   {
      printf("%d ",root->data);
      pre_order_traversal(root->left);
      pre_order_traversal(root->right);
   }
}
void inorder_traversal(struct node* root) 
{
   if(root!=NULL) 
   {
      inorder_traversal(root->left);
      printf("%d ",root->data);          
      inorder_traversal(root->right);
   }
}
void post_order_traversal(struct node* root) 
{
    if(root!=NULL)
    {
      post_order_traversal(root->left);
      post_order_traversal(root->right);
      printf("%d ",root->data);
    }
}
int main()
{
	int n=0,i,r;
	struct node *temp,*p,*root;
	printf("**Please follow the instructions to successfully create the Full Binary Tree**\n");
	while(n%2==0)
	{
	    printf("Enter the odd number of nodes to create a full binary tree: ");
	    scanf("%d",&n);	
	}
	for(i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(i==0)
		printf("Enter the data to store in root node: ");
		else
		printf("Enter data to add in %d node: ",i+1);
		scanf("%d",&temp->data);
		temp->left=NULL;
		temp->right=NULL;
		if(i==0)
		root=temp; 
		else
		{	
			p=root;   
			while(1)
			{				
				if(temp->data > p->data)
				{
					if(p->right==NULL)
						{					
						p->right=temp;
						if(root->right==temp && p->left==NULL)
						printf("**Please enter the data for left node less than %d**\n",root->data);
						else
						{
						    if(p->left==NULL && temp->data>root->data)
						    printf("**Please enter the data for left node between %d and %d**\n",r,p->data);
						    if(p->left==NULL && temp->data<root->data)
						    printf("**Please enter the data less than %d**\n",p->data);
						}
						break;
						}
					else
					{
					    r=p->data;
						p = p->right;
					}
				}
				else
				{
					if(p->left==NULL)
						{						
						p->left = temp;
						if(root->left==temp && p->right==NULL)
						printf("**Please enter the data for right node more than %d**\n",root->data);
						else
						{
						    if(p->right==NULL && temp->data<root->data)
						    printf("**Please enter the data for right node between %d and %d**\n",p->data,r);
						    if(p->right==NULL && temp->data>root->data)
						    printf("**Please enter the data for right node more than %d**\n",p->data);
						}
						break;
						}
					else
					{
					    r=p->data;
						p=p->left;					
					}
				}				
			}
		}
	}
	printf("Tree created with %d nodes in it",n);
	printf("\nInorder traversal: ");
  inorder_traversal(root);
	printf("\nPreorder traversal: ");
  pre_order_traversal(root);
  printf("\nPost order traversal: ");
  post_order_traversal(root);   
}
