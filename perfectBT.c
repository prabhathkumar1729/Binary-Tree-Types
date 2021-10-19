#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 
struct node* newNode(int data); 
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
struct node* arraytotree(int arr[],int start,int end) 
{ 
	if(start>end) 
	return NULL; 
	int mid=(start+end)/2; 
	struct node *root=newNode(arr[mid]); 
	root->left=arraytotree(arr,start,mid-1); 
	root->right=arraytotree(arr,mid+1,end); 
	return root; 
} 
struct node* newNode(int data) 
{ 
	struct node* node=(struct node*)malloc(sizeof(struct node)); 
	node->data=data; 
	node->left=NULL; 
	node->right=NULL; 
	return node; 
} 
int main() 
{ 
    int i,j,a,n,h,arr[50];
        printf("Enter the height to create for Perfect binary tree: ");
        scanf("%d", &h);
        n=pow(2,h+1)-1;
        printf("You need to enter data for %d nodes\n",n);
        for(i=0;i<n;i++)
        {
            printf("Enter the data for %d node: ",i+1);
            scanf("%d", &arr[i]);
        }
        for(i=0;i<n;i++) 
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j]) 
                {
                    a=arr[i];
                    arr[i]=arr[j];
                    arr[j]=a;
                }
            }
        }
	struct node *root=arraytotree(arr,0,n-1); 
	printf("Tree created with %d nodes in it with root %d",n,root->data);
	printf("\nInorder traversal: ");
  inorder_traversal(root);
	printf("\nPreorder traversal: ");
  pre_order_traversal(root);
  printf("\nPost order traversal: ");
  post_order_traversal(root);
} 
