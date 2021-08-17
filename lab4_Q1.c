#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref,int new_data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node -> next=(*head_ref);
    (*head_ref)=new_node;

}
void printList(struct Node *node)
{
    while(node!=NULL){
        printf("%3d",node->data);
        node=node->next;
    }
}
int main()
{
    struct Node* head=NULL;
    int n,input;
    printf("how many nodes u want to enter? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data: ");
        scanf("%d",&input);
        push(&head,input);
    }
    printf("The entered linked list is: ");
    printList(head);    
}