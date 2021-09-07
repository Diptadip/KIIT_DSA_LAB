#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void printMiddle(struct Node *head)
{
	struct Node *q = head;
	struct Node *p = head;

	if (head!=NULL)
	{
		while (p != NULL && p->next != NULL)
		{
			p = p->next->next;
			q = q->next;
		}
		printf("%d\n", q->data);
        return;
	}
    else{
        printf("\nList is empty !!\n");
    }
}

void addAtEnd(struct Node** head, int newData)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=newData;
    struct Node* p;
    struct Node* q;
    for(q=0,p=*head;p;p=p->next)
        q=p;
    if(q==0){
        node->next=*head;
        *head=node;
    }
    else{
        node->next=q->next;
        q->next=node;
    }
}

void printList(struct Node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

int main()
{
	struct Node* head = NULL;
	int n,value;
    printf("How many node you want to enter ?? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value of node %d : ",i+1);
        scanf("%d",&value);
        addAtEnd(&head,value);
    }
    printf("The list is: ");
    printList(head);
    printf("Middle Element is: ");
    printMiddle(head);
}
