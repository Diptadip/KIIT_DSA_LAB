#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	int priority;
	struct Node* next;
};

void push(struct Node** head,char d,int p)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=(int)d;
	node->priority=p;
	node->next=NULL;
	if(*head==NULL){
		*head=node;
	}
	else{
		struct Node* start=*head;
		if((*head)->priority>p){
			node->next=(*head);
			(*head)=node;
		}
		else{
			while(start->next!=NULL && start->next->priority < p){
				start=start->next;
			}
			node->next=start->next;
			start->next=node;
		}
	}
}
int peek(struct Node** head)
{
	return (*head)->data;
}

void pop(struct Node** head)
{
	struct Node* temp = *head;
	(*head) = (*head)->next;
	//print temp.data
	free(temp);
}


int isEmpty(struct Node** head)
{
	return (*head) == NULL;
}
int main()
{
    int n,p;
    char d;
    struct Node* head=NULL;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter %d nodes in order - <data><space><priority>\n",n);
    for(int i=0;i<n;i++){
        printf("node %d: ",i+1);
		fflush(stdin);
        scanf("%c %d",&d,&p);
        push(&head,d,p);
    }
    printf("\n");
	while (!isEmpty(&head)) {
		printf("%c >> ", peek(&head));
		pop(&head);
	}
	printf("NULL \n");

	return 0;
}
