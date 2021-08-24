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
void deleteList(struct Node** head)
{
    struct Node *temp;

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;

        free(temp);
    }

    printf("\nDeleted all nodes\n");
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
    printf("\nThe entered linked list is: ");
    printList(head);    
    deleteList(&head);
}