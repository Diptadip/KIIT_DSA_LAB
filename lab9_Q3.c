#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}
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