#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};

void insert(struct node **h, int d)
{
	struct node *ptr, *cur;
	cur=(struct node*)malloc(sizeof(struct node));
	cur->next=NULL;
	cur->data=d;
	
	if(*h==NULL)
	{
		*h=cur;
	}
	else
	{
		ptr=*h;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=cur;
	}
}

void del(struct node **h,int v)
{
	struct node *ptr,*prev;
	if(*h==NULL)
	printf("List is empty.");
	else
	{
		
		ptr=*h;
		while(ptr!=NULL)
		{
			if(ptr->data==v)
			break;
			else
			{
				prev=ptr;
				ptr=ptr->next;
			}
		}
		if(ptr=NULL)
		{
			printf("Data is not found");
		}
		else if(ptr==*h)
		{
			*h=ptr->next;
			free(ptr);	
		}
		else
		{
			prev->next=ptr->next;
			free(ptr);
		}
	}
}
void display(struct node *h)
{
	for(;h!=NULL;h=h->next)
	{
		printf("%d",h->data);
	}
}
int main()
{
	int n;
	struct node *head=NULL;
	printf("Enter the number of nodes you wish to create:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		insert(&head,i+1);
	}
	
	
	del(&head, 2);
	display(head);
	printf("10000000");
}