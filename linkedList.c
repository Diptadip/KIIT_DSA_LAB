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
int countNodes(struct Node* ptr)
{
    int count=0;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    return count;
}
void deleteHead(struct Node **head)
{
    struct Node *ptr=NULL;
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    ptr=(*head)->next;
    printf("deleted %d ",(*head)->data);
    free((void*)(*head));
    *head=ptr;
}
void deleteTail(struct Node **head)
{
    struct Node* p=NULL;
    struct Node* q=NULL;
    if((*head)==NULL || (*head)->next==NULL){
        deleteHead(head);
    }
    else{
        for(p=*head;p->next;p=p->next){
            q=p;
        }
        printf("Deleting Node %d ",p->data);
        free((void*)p);
        q->next=NULL;    
    }
}
void deleteAllNodes(struct Node**head)
{
    struct Node *ptr=NULL;
    while(*head){
        ptr=*head;
        *head=(*head)->next;
        printf("Deleting node %d\n",ptr->data);
        free((void*)ptr);
    }
}
void deletePos(struct Node**head , int pos)
{
    struct Node* p=*head;
    struct Node* q=NULL;
    if(!*head){
        printf("List is empty ");
    }
    else if(pos==0){
        deleteHead(head);
    }
    else{
        for(int i=0;p && i<pos-1;i++){
            p=p->next;
        }
        if(!p || !p->next){
            printf("position out of bound\n");
        }
        else{            
            q=p->next->next;
            printf("Deleteing node %d\n",p->next->data);
            free((void*)p->next);
            p->next=q;
        }
    }
}

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
        printf("5. delete head\n");
        printf("6. delete tail\n");
        printf("7. Delete All nodes\n");
        printf("8. Delete specific pos\n");
        printf("9. exit\n");
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
                deleteHead(&head);
                break;
            
            case 6:
                deleteTail(&head);
                break;

            case 7:
                deleteAllNodes(&head);
                break;

            case 8:
                printf("Enter Node number you want to delete (starting from 0): ");
                scanf("%d",&n);
                deletePos(&head,n);
                break;
            
            case 9:
                printf("Exitting code\n");
                exit(0);

            default:
                printf("Wrong input..\n");
        }
        choice=-1;
    }while(choice<0);
}