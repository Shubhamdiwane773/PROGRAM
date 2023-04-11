#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *insert(struct node*root,int data)
{
	if(root==NULL)
	{
		struct node *temp=malloc(sizeof(struct node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	if(data == root->data)
		return root;
	if(data < root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
void preorder(struct node*root)
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
	struct node *root=NULL;
	int choice,data;
	while(1)
	{
		printf("\n1.insert 2.preorder 3.inorder 4.postorder 5.search 6.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data\n");
				scanf("%d",&data);
			       	root=insert(root,data);
				break;
			case 2: printf("\n PREORDER\n");
			       	preorder(root);
				break;
			case 3: printf("\nINORDER\n");
				inorder(root);
				break;
			case 4: printf("\nPOSTORDER\n");
				postorder(root);
				break;
			case 5: printf("enter the data which u want to search\n");
				scanf("%d",&data);
				search(root,data);
				break;
			case 6: exit(0);
			default: printf("wrong choice.enter correct choice\n");
		}
	}
}
