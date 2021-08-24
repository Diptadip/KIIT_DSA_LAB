#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traverseList(struct Node* ptr)
{
    if(ptr==NULL)
        printf("\nList is empty\n");
    while(ptr){
        printf("%3d",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct Node*head)
{
    if(head==NULL)
        return 1;
    return 0;
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

void addAtAnyPos(struct Node**head, int newData,int pos)
{
    int size=countNodes(*head);
    struct Node* p=*head;
    if (pos < 1 || pos > size + 1)
        printf("Position out of bound \n");
    else { 
        while (pos--) { 
            if (pos == 0) { 
                struct Node* node=(struct Node*)malloc(sizeof(struct Node));
                node->next = p;
                p = node;
            }
            else
                p = p->next;
        }
    }
}

void deleteHead(struct Node **head)
{
    struct Node *ptr=NULL;
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    ptr=(*head)->next;
    printf("deleting node %d\n",(*head)->data);
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

void deleteNodeKey(struct Node** head,int n)
{
    struct Node *p = *head, *q = 0;
    int count = 0;
    while (p) {
        while (p && p->data != n) {
            q = p;
            p = p->next;
        }
        if (p) { // Node found
            if( q == 0) { // head Node to be deleted
                *head = p->next;
                free((void*)p);
                p = *head;
            }
            else {
                q->next = p->next;
                free((void*)p);
                p = q->next;
            }       
            count++;
        }
    }
    printf("Number of nodes deleted = %d\n",count);
}

void search(struct Node *node,int key)
{
    if(node==NULL){
        printf("The list is empty\n");
        //return -1;
    }
    while(node!=NULL){
        if(node->data==key){
            printf("Element present\n");
            //return 0;
        }
        node=node->next;
    }
}

int main()
{
    struct Node* head=NULL;
    int choice,n,t;
    do{
        printf("\n1. Traverse the List\n");
        printf("2. Check if List is Empty\n");
        printf("3. Insert at head\n");
        printf("4. Insert at end\n");
        printf("5. Insert at any position\n");
        printf("6. Delete head\n");
        printf("7. Delete end\n");
        printf("8. Delete any position\n");
        printf("9. Delete for given key\n");
        printf("10. Count number of nodes\n");
        printf("11. Search for an element\n");
        printf("12. exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("\n prinitng List : ");
                traverseList(head);
                printf("\n");
                break;

            case 2:
                if(isEmpty(head))
                    printf("List is empty\n");
                else
                    printf("List is not empty\n");
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d",&n);
                addAtHead(&head,n);
                break;
            
            case 4:
                printf("Enter value: ");
                scanf("%d",&n);
                addAtEnd(&head,n);
                break;
            
            case 5:
                printf("Enter value: ");
                scanf("%d",&n);
                printf("Enter position(starting from 1): ");
                scanf("%d",&t);
                addAtAnyPos(&head,n,t);
                break;

            case 6:
                deleteHead(&head);
                break;
            
            case 7:
                deleteTail(&head);
                break;

            case 8:
                printf("Enter Node number you want to delete (starting from 0): ");
                scanf("%d",&n);
                deletePos(&head,n);
                break;

            case 9:
                printf("Enter key: ");
                scanf("%d",&n);
                deleteNodeKey(&head,n);
                break;

            case 10:
                printf("Number of nodes = %d\n",countNodes(head));
                break;

            case 11:
                printf("\nEnter element to search for: ");
                scanf("%d",&n);
                search(head,n);
                break;
            
            case 12:
                printf("Exitting code\n");
                exit(0);

            default:
                printf("Wrong input..\n");
        }
        choice=-1;
    }while(choice<0);
}