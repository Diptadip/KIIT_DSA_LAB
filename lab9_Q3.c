#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(front == NULL && rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct Node *temp;
    if(front == NULL)
        printf("Queue underflow!! \n");
    else
    {
        temp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        printf("Element %d dequeued\n",temp->data);
        free(temp);
    }
}
int isEmpty()
{
    return (front==NULL);
}
void peek()
{
    if(!isEmpty()){
        printf("Front = %d\nRear = %d\n",front->data,rear->data);
    }
    else{
        printf("Queue empty!");
    }
}

void printList()
{
    struct Node *temp = front;
    while(temp)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int n,ch,value;
    do{
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Is empty\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                printList();
                break;
            case 5:
                if(isEmpty())printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong input\n");
        }
    }while(1);
}