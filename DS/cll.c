#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}P;
P *head=NULL;
int create()
{
	P *temp=malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		temp->link=head;
	}
	else
	{
		P*ptr=head;
		while(ptr->link!=head)
			ptr=ptr->link;
		ptr->link=temp;
		temp->link=head;
	}
}
int add_beg()
{
	P*temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=head;
	if(head==NULL)
	{
		head=temp;
		temp->link=head;
	}
	else
	{
	while(ptr->link!=head)
		ptr=ptr->link;
	ptr->link=temp;
	}
}
int add_end()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=head;
	while(ptr->link!=head)
		ptr=ptr->link;
//	temp->link=head;
	ptr->link=temp;
}
int print()
{
	P *ptr=head;
	while(ptr->link!=head)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d ",ptr->data);
	printf("\n");
}
int main()
{
	int i;
	//for(i=0;i<2;i++)
	//	create();
	//print();
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	print();
}
