#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int expo;
    struct Node* next;
};
void addAtHead(struct Node** head, int e, int c)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node ->expo = e;
    node->coeff = c;
    node ->next =(*head);
    (*head)=node;
}
void reverseList(struct Node**ptr)
{
    struct Node *rear, *cur, *front;
    rear = 0;
    cur = *ptr;
    front = cur ? cur->next : 0;
    while (cur) {
        cur->next = rear;
        rear = cur;
        cur = front;
        front = cur ? cur->next : 0;
    }
    *ptr = rear;
}
void buildPoly(int a,struct Node** headA)
{
    int c;
    for(int i=0;i<=a;i++){
        printf("Enter coefficient for X^%d: ",i);
        scanf("%d",&c);
        addAtHead(headA,i,c);
    }
}
void displayPoly(struct Node* head)
{
    struct Node* ptr=head;
    if(ptr->coeff!=0){
        printf("%dx^%d",ptr->coeff,ptr->expo);
    }
    ptr=ptr->next;
    while(ptr){        
        if(ptr->coeff>0){
            printf(" +%dx^%d",ptr->coeff,ptr->expo);
        }
        if(ptr->coeff<0){
            printf(" %dx^%d",ptr->coeff,ptr->expo);
        }
        ptr=ptr->next;
    }
}
void removeDups(struct Node** ptr)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = *ptr;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1; 
        while (ptr2->next != NULL) {
            if (ptr1->expo == ptr2->next->expo) {
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free((void*)dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
struct Node* multiply(struct Node* A,struct Node* B)
{
    struct Node *ptr1, *ptr2, *C=NULL;
    ptr1 = A;
    ptr2 = B;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, expo;
            coeff = ptr1->coeff * ptr2->coeff;
            expo = ptr1->expo + ptr2->expo;
            addAtHead(&C, expo, coeff);
            ptr2 = ptr2->next;
        }
        ptr2 = B;
        ptr1 = ptr1->next;
    }
    removeDups(&C);
    return C;
}
int main()
{
    struct Node* A=NULL,*B=NULL,*D;
    int a,b;
    printf("Enter max exponent of 1st polynomial: ");
    scanf("%d",&a);
    buildPoly(a,&A);
    //displayPoly(A);
    //printf("\n");

    printf("Enter max exponent of 2nd polynomial: ");
    scanf("%d",&b);
    buildPoly(b,&B);
    //displayPoly(B);
    //printf("\n");

    printf("A: ");
    displayPoly(A);
    printf("\nB: ");
    displayPoly(B);

    printf("\nmultipliation is: ");
    D=multiply(A,B);
    reverseList(&D);
    displayPoly(D);
    
}