#include<stdio.h>
#include<stdlib.h>

#define size 11

struct Node
{
    int data;
    struct Node *next;
};

struct Node *hash[size];

void setDefault()
{
    for(int i = 0; i < size; i++)
        hash[i] = NULL;
}

void insert(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    int key = value % size;

    if(hash[key] == NULL)
        hash[key] = newNode;
    
    else
    {
        struct Node *temp = hash[key];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void search(int value)
{
    int key=value%size;
    if(hash[key]==NULL){
        printf("Element %d not present\n",value);
    }
    else{
        struct Node* temp=hash[key];
        while(temp){
            if(temp->data==value){
                printf("Element %d found at key = %d\n",value,key);
                break;
            }
            temp=temp->next;
        }
        if(!temp){
            printf("Element %d not present\n",value);
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
void delete(int value)
{
    int key=value%size;
    if(hash[key]==NULL){
        printf("Element %d not present\n",value);
    }
    else{
        deleteNodeKey(&hash[key],value);
    }
}
void print()
{
    for(int i = 0; i < size; i++)
    {
        struct Node *temp = hash[i];
        printf("hash[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int n,value,ch;
    setDefault();
    printf("How many element to be entered: ");
    scanf("%d",&n);
    printf("Enter %d integers one by one...\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insert(value);
    }
    do{
        printf("1.Insert\n2.Search\n3.Delete\n4.Print\n5.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                printf("Enter value to search for: ");
                scanf("%d",&value);
                search(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                delete(value);
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong input !! try again\n");
        }
    }while (1);    
}