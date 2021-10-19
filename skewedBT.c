#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;	
};
void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->left);
      pre_order_traversal(root->right);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->left);
      printf("%d ",root->data);          
      inorder_traversal(root->right);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->left);
      post_order_traversal(root->right);
      printf("%d ", root->data);
   }
}
int main()
{
    int n,i;
	struct node *temp,*p,*root;
	printf("**Please follow the instructions to create a Skewed Binary Tree**\n");
	printf("Enter the number of nodes to create for skewed binary tree: ");
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
	    temp = (struct node*)malloc(sizeof(struct node));
		if(i==0)
		printf("Enter the data to store in root node: ");
		else
		printf("\nEnter data to add in %d node: ",i+1);
		scanf("%d",&temp->data);
		temp->left = NULL;
		temp->right = NULL;
		if(i == 0)
		root = temp; 
		else
		{	
			p = root;
			while(1)
			{		
				if(temp->data > p->data)
				{
					if(p->right == NULL)
						{					
						p->right = temp;
						if(i>=1)
						printf("**Please enter data more than %d**",temp->data);
						break;
						}
					else
				    p = p->right;
				}
				else
				{
					if(p->left == NULL)
						{						
						p->left = temp;
						if(i>=1)
						printf("**Please enter data less than %d**",temp->data);
						break;
						}
					else
					p = p->left;
				}				
			}
		}
	}
printf("\nTree created with %d nodes in it",n);
	printf("\nInorder traversal: ");
    inorder_traversal(root);
	printf("\nPreorder traversal: ");
    pre_order_traversal(root);
    printf("\nPost order traversal: ");
    post_order_traversal(root);   
}
