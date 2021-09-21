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
int dequeue(struct Queue* queue)
{
        int item = queue->array[queue->front];
	    queue->front = (queue->front + 1)% queue->capacity;
	    queue->size = queue->size - 1;
        //printf("%d dequeued from queue.\n",item);
        return item;
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
void reverseQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return; 
    // Dequeue current item (from front) 
    int data = dequeue(queue); 
    // Reverse remaining queue 
    reverseQueue(queue);
 
    // Enqueue current item (to rear) 
    enqueue(queue,data);
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
    int cap,n,ch,value;
    printf("Enter queue capacity: ");
    scanf("%d",&cap);
    struct Queue* queue = createQueue(cap);
    printf("How many elements you want to enter (<=%d) ?? ",cap);
    scanf("%d",&n);
    printf("Enter %d inetegers: ",n);
    for(int i=1;i<=n;i++){
        scanf("%d",&value);
        enqueue(queue,value);
    }
    display(queue);
    reverseQueue(queue);
    display(queue);
}
