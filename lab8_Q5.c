#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void push(struct Node**head,int value)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next=*head;
    *head=ptr;
}
int isEmpty(struct Node*head)
{
    return (head==NULL);
}

void pop(struct Node** head)
{
    struct Node* p=*head;
    if(isEmpty(*head)){
        printf("Stack underflow\n");
        return;
    }
    *head=(*head)->next;
    p->next=NULL;
    printf("Element popped: %d",p->data);
    free((void*)p);
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
void printList(struct Node* head)
{
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head=NULL;
    int ch,value,n;
    printf("Enter number of stack elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&value);
        push(&head,value);
    }
    printf("The stack is: ");
    printList(head);
    printf("The reversed stack is: ");
    reverseList(&head);
    printList(head);
}