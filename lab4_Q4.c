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
int deleteNode(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);
        return 0;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return -1;
    prev->next = temp->next; 
    free(temp);
    return 0;
}
int main()
{
    struct Node* head=NULL;
    int n,input,key;
    printf("how many nodes u want to enter? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data: ");
        scanf("%d",&input);
        push(&head,input);
    }
    printf("\nThe entered linked list is: ");
    printList(head);    
    printf("\nEnter the value of node u want to delete: ");
    scanf("%d",&key);
    if(deleteNode(&head,key)>=0){
        printf("\nSuccefully deleted\nThe list after deletion is: ");
        printList(head);
    }
    else{
        printf("\nList may be NULL or element not present\n");
    }
}