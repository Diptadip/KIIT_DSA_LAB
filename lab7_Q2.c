#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
void insert(struct Node** head_ref, int value)
{
    struct Node* node= (struct Node*)malloc(sizeof(struct Node)); 
    node->data = value;
 
    node->next = (*head_ref);
    node->prev = NULL;
 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = node;
 
    (*head_ref) = node;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;  

    if (*head_ref == del)
        *head_ref = del->next;
 
    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
}
 

void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
  
    if (*head_ref == NULL || n <= 0)
        return;
 
    struct Node* current = *head_ref;
    int i;
 
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
 
    if (current == NULL)
        return;
 
    deleteNode(head_ref, current);
}
 


int main()
{
    struct Node *head = NULL;
    int ch,n;
    do{
        printf("\n1.Insert Node \n");
        printf("2.Print List \n");
        printf("3.Delete a node\n");
        printf("4.Exit code\n");
        printf("Enter choice ... \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&n);
                insert(&head,n);
                break;

            case 2:
                printf("\nThe list is: ");
                printList(head);
                break;

            case 3:
                printf("\nThe list is: ");
                printList(head);
                printf("\nWhich node is to be deleted? ");
                scanf("%d",&n);
                deleteNodeAtGivenPos(&head,n);
                break;

            case 4:
                printf("\nExitting code");
                exit(0);

            default:
                printf("Wrong input...\n");
        }

    }while(1);
    return 0;
}