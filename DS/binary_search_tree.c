#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *new_node(int data)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *insert(struct node *root,int data)
{
	if(root==NULL)
		return new_node(data);
	if(data==root->data)
		return root;
	if(data < root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
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
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
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
struct node *search(struct node *root,int data)
{
	if(root==NULL)
	{
		printf("%d element is not found\n",data);
		return 0;
	}
	if(data==root->data)
		printf("%d element is found\n",data);
	else if(data < root->data)
		return search(root->left,data);
	else
		return search(root->right,data);
}
int main()
{
	int item;
	struct node *root=NULL;
	root=new_node(10);
	insert(root,20);
	insert(root,30);
	insert(root,40);
	insert(root,20);
	printf("enter the data\n");
	scanf("%d",&item);
	insert(root,item);
	printf("\nPREORDER\n");
	preorder(root);
	printf("\nINORDER\n");
	inorder(root);
	printf("\nPOSTORDER\n");
	postorder(root);
	printf("\n");
	search(root,80);
	search(root,30);
}
