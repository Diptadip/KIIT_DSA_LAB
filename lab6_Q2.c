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
struct Node* add(struct Node* A,struct Node*B)
{
    struct Node* C=NULL;    
    if(A->expo>B->expo){
        while(A){
            int expo=A->expo;
            int coeff=A->coeff;
            if(A->expo==B->expo){
                coeff+=B->coeff;
                B=B->next;
            }
            addAtHead(&C,expo,coeff);
            A=A->next;
        }
    }
    else{
        while(B){
            int expo=B->expo;
            int coeff=B->coeff;
            if(B->expo==A->expo){
                coeff+=A->coeff;
                A=A->next;
            }
            addAtHead(&C,expo,coeff);
            B=B->next;
        }
    }
    return C;    
}
int main()
{
    struct Node* A=NULL,*B=NULL,*C;
    int a,b;
    printf("Enter max exponent of 1st polynomial: ");
    scanf("%d",&a);
    buildPoly(a,&A);
    //displayPoly(A);
    printf("\n");

    printf("Enter max exponent of 2nd polynomial: ");
    scanf("%d",&b);
    buildPoly(b,&B);
    //displayPoly(B);
    printf("\n");

    printf("Addition is: ");
    C=add(A,B);
    reverseList(&C);
    displayPoly(C);
    printf("\n");    
}