#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int front, rear, size;
	int capacity;
	int* array;
};

struct Queue* createQueue(int capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue)){
        printf("Queue overflow !!\n");
    }
    else{
        queue->rear = (queue->rear + 1)	% queue->capacity;
	    queue->array[queue->rear] = item;
	    queue->size = queue->size + 1;
	    printf("%d enqueued to queue\n", item);
    }	
}
void dequeue(struct Queue* queue)
{
	if (isEmpty(queue)){
        printf("Queue underflow !!\n");
    }
    else{
        int item = queue->array[queue->front];
	    queue->front = (queue->front + 1)% queue->capacity;
	    queue->size = queue->size - 1;
        printf("%d dequeued from queue.\n",item);
    }
}
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}
void display(struct Queue* queue)
{
    printf("The queue is: ");
    for(int i=queue->front;i<=queue->rear;i++){
        printf("%3d",queue->array[i]);
    }
    printf("\n");
}
int main()
{
    int n,ch,value;
    printf("Enter queue capacity: ");
    scanf("%d",&n);
    struct Queue* queue = createQueue(n);
    do{
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Is Full\n");
        printf("6.Is empty\n");
        printf("7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(queue,value);
                break;
            
            case 2:
                dequeue(queue);
                break;
            case 3:
                if(!isEmpty(queue)){
                    printf("Front item =%d\nRear item =%d\n",front(queue),rear(queue));
                }
                else
                    printf("Queue underflow!!\n");
                break;
            case 4:
                display(queue);
                break;
            case 5:
                if(isFull(queue)) printf("Queue is full .\n");
                else printf("Queue is not full\n");
                break;
            case 6:
                if(isEmpty(queue))printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong input\n");
        }
    }while(1);
}
