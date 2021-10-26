#include<stdio.h>
#include<stdlib.h>

struct cQueue {
	int front, rear, size;
	int capacity;
	int* arr;
};

struct cQueue* createQueue(int capacity)
{
	struct cQueue* queue = (struct cQueue*)malloc(sizeof(struct cQueue));
	queue->capacity = capacity;
	queue->front = queue->rear = -1;

	queue->size = capacity - 1;
	queue->arr = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}
int isEmpty(struct cQueue* cq)
{
    return (cq->front == -1);
}

int isFull(struct cQueue* cq)
{
    return ((cq->front == 0 && cq->rear == cq->size-1) || (cq->rear == (cq->front-1)%(cq->size-1)));
}

void enqueue(struct cQueue* cq,int value)
{
    if (cq->front == -1)
    {
        //cq->arr=(int*)malloc(cq->size * sizeof(int));
        cq->front = cq->rear = 0;
        cq->arr[cq->rear] = value;
    }
 
    else if (cq->rear == cq->size-1 && cq->front != 0)
    {
        cq->rear = 0;
        cq->arr[cq->rear] = value;
    }
 
    else
    {
        cq->rear++;
        cq->arr[cq->rear] = value;
    }
}
int dequeue(struct cQueue* cq)
{
    int data = cq->arr[cq->front];
    cq->arr[cq->front] = -1;
    if (cq->front == cq->rear)
    {
        cq->front = -1;
        cq->rear = -1;
    }
    else if (cq->front == cq->size-1)
        cq->front = 0;
    else
        cq->front++;
 
    return data;
}
void displayQueue(struct cQueue* cq)
{
    if (cq->front == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (cq->rear >= cq->front)
    {
        for (int i = cq->front; i <= cq->rear; i++)
            printf("%d ",cq->arr[i]);
    }
    else
    {
        for (int i = cq->front; i < cq->size; i++)
            printf("%d ", cq->arr[i]);
 
        for (int i = 0; i <= cq->rear; i++)
            printf("%d ", cq->arr[i]);
    }
    printf("\n");
}
int main()
{
    int ch,value;
    struct cQueue *cq=createQueue(10);
    do{
    printf("1. Enqueue\n2. Dequeue\n3. Is full\n4. Is empty\n5. print queue\n6. exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            if(!isFull(cq)){
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(cq,value);
            }
            else{
                printf("Queue is full !!\n");
            }
            break;
        
        case 2:
            if(!isEmpty(cq)){
                printf("Element Dequeued = %d\n",dequeue(cq));
            }
            else{
                printf("Queue is Empty !!\n");
            }
            break;
        case 3:
            if(isFull(cq)){
                printf("Queue is full !!\n");
            }
            else{
                printf("Queue is not full !!\n");
            }
            break;
        case 4:
            if(isEmpty(cq)){
                printf("Queue is empty !!\n");
            }
            else{
                printf("Queue is not empty !!\n");
            }
            break;
        case 5:
            displayQueue(cq);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong input !! try again \n");
    }
    }while(1);
}