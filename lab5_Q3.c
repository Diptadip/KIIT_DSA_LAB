#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

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
void printList(struct Node *node)
{
    while(node!=NULL){
        printf("%3d",node->data);
        node=node->next;
    }
}
void printM(struct Node* ptr,int m,int n)
{
    for(int i=1;i<n-m+1;i++){
        ptr=ptr->next;
    }
    printf("The value is: %d\n",ptr->data);
}

int main()
{
    struct Node* head=NULL;
    int m,n,input,key;
    printf("how many nodes u want to enter? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&input);
        addAtEnd(&head,input);
    }
    printf("\nThe entered linked list is: ");
    printList(head);    
    printf("\nEnter value of m: ");
    scanf("%d",&m);
    printM(head,m,n);
}