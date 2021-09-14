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
    int ch,value;
    do{
        printf("\n1. Push\n");
        printf("2. Check if Stack is empty\n");
        printf("3. pop\n");
        printf("4. print stack\n");
        printf("5. Exit code\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&value);
                push(&head,value);
                break;

            case 2:
                if(isEmpty(head))
                    printf("Stack is empty\n");
                else  
                    printf("Stack is not empty.\n");
                break;

            case 3:
                pop(&head);
                break;
            case 4:
                printf("Printing Stack: ");
                printList(head);
                break;
            case 5:
                printf("Exitting code\n");
                break;
            default:
                printf("Wrong input\n");
        }
    }while(1);    
}