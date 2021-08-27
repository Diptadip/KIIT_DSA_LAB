#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void addAtHead(struct Node** head, int newData)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node ->data = newData;
    node ->next =(*head);
    (*head)=node;
}
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
void insertAfter(struct Node** head,int newData,int n)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=newData;
    struct Node* p;
    for(p=*head; p && p->data != n;p=p->next);
    if(p){
        node->next=p->next;
        p->next=node;
    }
    else{
        addAtHead(head,newData);
    }
}
/*void deleteNode(struct Node **head, int n){

}*/
void printList(struct Node* ptr)
{
    if(ptr==NULL)
        printf("\nList is empty\n");
    while(ptr){
        printf("%3d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct Node* head=NULL;
    int choice,n,t;
    do{
        printf("\n1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert after\n");
        printf("4. print List\n");
        printf("5. exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&n);
                addAtHead(&head,n);
                break;
            
            case 2:
                printf("Enter value: ");
                scanf("%d",&n);
                addAtEnd(&head,n);
                break;
            
            case 3:
                printf("Enter value: ");
                scanf("%d",&n);
                printf("Enter after: ");
                scanf("%d",&t);
                insertAfter(&head,n,t);
                break;

            case 4:
                printf("\n prinitng List : ");
                printList(head);
                printf("\n");
                break;
            
            case 5:
                printf("Exitting code\n");
                exit(0);

            default:
                printf("Wrong input..\n");
        }
        choice=-1;
    }while(choice<0);
}