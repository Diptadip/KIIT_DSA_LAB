#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next; 
    struct Node* prev; 
};

void append(struct Node** head, int new_data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 
    struct Node* end = *head; 
    node->data = new_data;
    node->next = NULL;
    if (*head == NULL) {
        node->prev = NULL;
        *head = node;
        return;
    }
    while (end->next != NULL)
        end = end->next;

    end->next = node;
    node->prev = end; 
}
void printForward(struct Node* node)
{
    while(node!=NULL){
        printf("%3d",node->data);
        node=node->next;
    }
}
void printBackward(struct Node* head)
{
    struct Node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    while(ptr!=NULL){
        printf("%3d",ptr->data);
        ptr=ptr->prev;
    }
}
int main()
{
    struct Node* head=NULL;
    int n,input;
    printf("how many nodes u want to enter? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&input);
        append(&head,input);
    }
    printf("\nThe entered linked list is: ");
    printForward(head);    
    printf("\nPrinting backwards: ");
    printBackward(head); 
}