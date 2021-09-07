#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

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
void printKthFromLast(struct Node* ptr, int k)//recursive
{
    static int counter = 0;
    if (ptr == NULL)//base case
        return;
    printKthFromLast(ptr->next, k);
    if (++counter == k)
        printf("%d", ptr->data);
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
	int n,value,k;
    printf("How many node you want to enter ?? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value of node %d : ",i+1);
        scanf("%d",&value);
        addAtEnd(&head,value);
    }
    printf("\nEnter value of k: ");
    scanf("%d",&k);
    printf("The list is: ");
    printList(head);
    printf("%d element from last is: ",k);
    printKthFromLast(head,k);
}
