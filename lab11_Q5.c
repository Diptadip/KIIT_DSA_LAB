#include<stdio.h>
#include<stdlib.h>

struct Dequeue{
    int *arr,front,rear,size;
};

struct Dequeue* createQueue(int capacity)
{
    struct Dequeue* dq=(struct Dequeue*)malloc(sizeof(struct Dequeue));
    dq->front=-1;
    dq->rear=0;
    dq->size=capacity;
    dq->arr=(int*)malloc(capacity*sizeof(int));
    return dq;
}
int isFull(struct Dequeue* dq)
{
    return((dq->front==0 && dq->rear==dq->size-1)|| dq->front==dq->rear+1);
}
int isEmpty(struct Dequeue* dq)
{
    return(dq->front==-1);
}
void insertFront(struct Dequeue* dq,int value)
{
    if(isFull(dq)){
        printf("Overflow\n");
    }
    else{
        if(dq->front==-1){
            dq->front=0;
            dq->rear=0;
        }
        else if(dq->front==0){
            dq->front=dq->size-1;
        }
        else{
            dq->front=dq->front-1;
        }
        dq->arr[dq->front]=value;
    }
}
void insertRear(struct Dequeue* dq,int value)
{
    if(isFull(dq)){
        printf("Overflow\n");
    }
    else{
        if(dq->front==-1){
            dq->front=0;
            dq->rear=0;
        }
        else if(dq->rear==dq->size-1){
            dq->rear=0;
        }
        else{
            dq->rear=dq->rear+1;
        }
        dq->arr[dq->rear]=value;
    }
}
void deleteFront(struct Dequeue* dq)
{
    if(isEmpty(dq)){
        printf("Underflow\n");
    }
    else{
        printf("Element dqueued = %d\n",dq->arr[dq->front]);
        if(dq->front==dq->rear){
            dq->front=-1;
            dq->rear=-1;
        }
        else{
            if(dq->front==dq->size-1){
                dq->front=0;
            }
            else{
                dq->front=dq->front+1;
            }
        }
    }
}
void deleteRear(struct Dequeue* dq)
{
    if(isEmpty(dq)){
        printf("Underflow\n");
    }
    else{
        printf("Element dqueued = %d\n",dq->arr[dq->rear]);
        if(dq->front==dq->rear){
            dq->front=-1;
            dq->rear=-1;
        }
        else if(dq->rear==0){
            dq->rear=dq->size-1;
        }
        else{
            dq->rear=dq->rear-1;
        }
    }
}
void peek(struct Dequeue* dq)
{
    if(isEmpty(dq)|| dq->rear<0){
        printf("underflow\n");
    }
    else{
        printf("front element = %d\nrear element = %d\n",dq->arr[dq->front],dq->arr[dq->rear]);
    }
}
void display(struct Dequeue* dq)
{
    if(isEmpty(dq)){
        printf("Underflow\n");
    }
    else{
        for(int i=dq->front;;){
            printf("%d ",dq->arr[i]);
            if(i==dq->rear) break;
            i=(++i)%dq->size;
        }
        printf("\n");
    }
}
int main()
{
    int n,c,ch,value;
    printf("1. Input-restricted Dequeue\n2. Ouput-restricted Dequeue\nEnter your choice: ");
    scanf("%d",&c);
    struct Dequeue* dq;
    switch(c){
        case 1:
            printf("Input restricted from rear end\n");
            printf("Enter capacity of Dequeue: ");
            scanf("%d",&n);
            dq=createQueue(n);
            do{
                printf("1. Enqueue(front)\n");
                printf("2. Dequeue(front)\n");
                printf("3. Dequeue(rear)\n");
                printf("4. peek\n");
                printf("5. display\n");
                printf("6. exit\n");
                printf("Enter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d",&value);
                        insertFront(dq,value);
                        break;
                    case 2:
                        deleteFront(dq);
                        break;
                    case 3:
                        deleteRear(dq);
                        break;
                    case 4:
                        peek(dq);
                        break;
                    case 5:
                        display(dq);
                        break;
                    case 6:
                        exit(0);
                    default:
                        printf("Wrong input!! Try again\n");
                }
            }while(1);
            break;
        
        case 2:
            printf("Output restricted from rear end\n");
            printf("Enter capacity of Dequeue: ");
            scanf("%d",&n);
            dq=createQueue(n);
            do{
                printf("1. Enqueue(front)\n");
                printf("2. Enqueue(rear)\n");
                printf("3. Dequeue(front)\n");
                printf("4. peek\n");
                printf("5. display\n");
                printf("6. exit\n");
                printf("Enter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d",&value);
                        insertFront(dq,value);
                        break;
                    case 2:
                        printf("Enter value: ");
                        scanf("%d",&value);
                        insertRear(dq,value);
                        break;
                    case 3:
                        deleteFront(dq);
                        break;
                    case 4:
                        peek(dq);
                        break;
                    case 5:
                        display(dq);
                        break;
                    case 6:
                        exit(0);
                        break;
                    default:
                        printf("Wrong input !! try again\n");
                }
            }while(1);
            break;

        default:
            printf("Wrong input!!");
    }
}