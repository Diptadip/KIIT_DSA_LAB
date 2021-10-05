#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int data;
    struct Node* next;
};
struct HeadNode{
    int count;
    int max;
    int min;
    struct Node *next;
};
void push(struct HeadNode **hr,int value)
{
    struct Node* head=(*hr)->next;   
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = head;
    new_node->data  = value;
    new_node->next = NULL;
    if (head == NULL)
    {
       head= new_node;
       return;
       printf("1");
    }       
    
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;   
}
void printList(struct HeadNode *hr)
{
    struct Node* head=hr->next;
    while(head){
        printf("%3d",head->data);
        head=head->next;
    }
    printf("\ncount = %d\nmax = %d\nmin = %d",hr->count,hr->max,hr->min);
}
int setMax(struct HeadNode *hr)
{
    struct Node* head=hr -> next;
    int max=INT_MIN;
    if(head) max=head->data;
    while(head){
        if(max<head->data)
            max=head->data;
        head=head->next;
    }
    return max;
}
int setMin(struct HeadNode *hr)
{
    struct Node* head=hr -> next;
    int min=INT_MAX;
    if(head) min=head->data;
    while(head){
        if(min>head->data)
            min=head->data;
        head=head->next;
    }
    return min;
}
void deleteFromEnd(struct HeadNode **hr)
{
    if((*hr)->count==0){
        printf("No node except head node\n");
        return;
    }
    struct Node* head=(*hr)->next;
    struct Node* p=head;
    while(head->next){
        p=head;
        head=head->next;
    }
    int del=head->data;
    p->next=NULL;
    (*hr)->count--;
    (*hr)->max=setMax(*hr);
    (*hr)->min=setMin(*hr);
    printf("%d deleted\n",del);
    free((void*)head);
}
int main()
{
    int n,val;
    struct HeadNode* hr=(struct HeadNode*)malloc(sizeof(struct HeadNode));
    hr->next=NULL;
    hr->count=0;
    hr->max=INT_MIN;
    hr->min=INT_MAX;
    printf("How many nodes to be enetered : ");
    scanf("%d",&n);
    printf("Enter %d integers: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        push(&hr,val);
        hr->count++;
        hr->max=setMax(hr);
        hr->min=setMin(hr);
    }
    printList(hr);
}