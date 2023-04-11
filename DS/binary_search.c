#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *new_node(int item)
{
	struct node*temp=malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *insert(struct node *root,int item)
{
	if(root==NULL)
		return new_node(item);
	if(item < root->data)
		root->left=insert(root->left,item);
	else
		root->right=insert(root->right,item);
	return root;
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{

	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
		

int main()
{
	struct node *root=NULL;
	root=new_node(10);
	insert(root,20);
	insert(root,30);
	insert(root,40);
	printf("\nPreorder\n");
	preorder(root);
	printf("\nInorder\n");
        inorder(root);
        printf("\npostorder\n");
        postorder(root);
}
