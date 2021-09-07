#include<stdio.h>
#include<stdlib.h>
struct Node{
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
void printList(struct Node *node)
{
    while(node!=NULL){
        printf("%3d",node->data);
        node=node->next;
    }
}
void reverseList(struct Node** head)
{
    struct Node *rear, *cur, *front;
    rear = 0;
    cur = *head;
    front = cur ? cur->next : 0;
    while (cur) {
        cur->next = rear;
        rear = cur;
        cur = front;
        front = cur ? cur->next : 0;
    }
    *head = rear;
}

int main()
{
    struct Node* head=NULL;
    int m,n,input,key;
    printf("how many nodes u want to enter? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&input);
        addAtEnd(&head,input);
    }
    printf("\nThe entered linked list is: ");
    printList(head);    
    printf("\nReversing and printing List: ");
    reverseList(&head);
    printList(head);
}