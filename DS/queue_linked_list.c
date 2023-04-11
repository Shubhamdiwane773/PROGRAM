#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*link;
}P;
P*rear=NULL,*front=NULL;
int enqueue() // add_end logic
{
	P *temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(front==NULL)
		front=temp;
	else
		rear->link=temp;
	rear=temp;
}
int dequeue()//delete first logic
{
	P *temp=NULL;
	if(front==NULL)
	{
		printf("queue underflow\n");
		return 0;
	}
	printf("%d element is delete\n",front->data);
	temp=front;
	front=front ->link;
	free(temp);
}
int peek()
{
	if(front==NULL)
	{
		printf("queue underflow\n");
		return 0;
	}
	printf("The at the front is =%d\n",front->data);
}
int print()
{
	P*temp=front;
	if(front==NULL)
	{
		printf("queue is empty\n");
		return 0;
	}
	printf("queue element is\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.push 2.pop 3.peek 4.print 5.exit\n");
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: peek();
				break;
			case 4: print();
				break;
			case 5: exit(0);
			default: printf("wrong choice. enter correct choice\n");
		}
	}
}
