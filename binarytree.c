#include <stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
void insert(void);
void delete(void);
void main ()
{
  int ch; 
  while (1)
    {
       printf ("Binary Search Tree Operations : \n");
       printf ("1.Insert\n"); 
       printf ("2.Delete\n");
       printf("3.Display\n"); 
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:
           insert();
           break;
           case 2:
           delete();
           break;
           
       }
    }
}
void insert()
{
    struct node* temp,*parent;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    parent=root;
    if(root==NULL)
    root=temp;
    else
    {
        struct node* current;
        current=root;
        while(current)
        {
            parent=current;
            if(temp->data>current->data)
            {
                current=current->right;
            }
            else current=current->left;
        }
        if(temp->data>parent->data)
        parent->right=temp;
        else parent->left=temp;
    }
}
void delete()
{
    printf("enter the data:");
    scanf("%d",&d);
    if(root==NULL)
    printf("Tree is empty");
    struct node* parent;
    parent=root;
    else
    {
        struct node* current;
        current=root;
        while(d!=current->data)
        {
            parent=current;
            if(d>current->data)
            {
                current=current->right;
            }
            else current=current->left;
        }
        if(d>parent->data)
        parent->right=temp;
        else parent->left=temp;
    }
}
