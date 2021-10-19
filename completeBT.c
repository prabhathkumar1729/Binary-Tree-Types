#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;	
};
struct node *root;
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
int countNumNodes(struct node *root) {
  if (root == NULL)
    return (0);
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}
bool checkComplete(struct node *root, int index, int numberNodes) 
{
  if (root == NULL)
    return true;
  if (index >= numberNodes)
    return false;
  return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}
struct node *tree(int Data)
{
    struct node *temp , *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=Data;
    temp->left = NULL;
	temp->right = NULL;
	if(root==NULL)
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
					break;
					}
				else
					p = p->left;										
			}				
		}
	} 
	return root;
}
int main()
{
	tree(50);
	tree(30);
	tree(15);
	tree(75);
	tree(40);
	tree(60);
	printf("Complete Binary Tree created with 6 nodes in it\n");
	int node_count = countNumNodes(root);
    int index = 0;
    if (checkComplete(root, index, node_count))
    printf("The tree is a complete binary tree");
    else
    printf("The tree is not a complete binary tree");
    printf("\nInorder traversal: ");
    inorder_traversal(root);
	  printf("\nPreorder traversal: ");
    pre_order_traversal(root);
    printf("\nPost order traversal: ");
    post_order_traversal(root); 
}
