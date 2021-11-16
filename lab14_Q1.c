#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

struct Node{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Tree{
   struct  Node* root;
};

struct Node* getNode(int info){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=info;
    ptr->leftChild=ptr->rightChild=NULL;
    return ptr;
}

void insert(struct Tree* t,int info){
    struct Node* ptr=getNode(info);
    struct Node* p=t->root;
    struct Node* q=NULL;

    while(p!=NULL){
        q=p;
        if(info<p->data) p=p->leftChild;
        else p=p->rightChild;
    }
    if(q==NULL){
        t->root=ptr;
    }
    else{
        if(info<q->data) q->leftChild=ptr;
        else q->rightChild=ptr;
    }
}

void inorder(struct Node* p){
    if(p != NULL){
        inorder(p->leftChild);
        printf("%6d",p->data);
        inorder(p->rightChild);
    }
}

void preorder(struct Node* p){
    if(p!=NULL){
        printf("%6d",p->data);
        preorder(p->leftChild);
        preorder(p->rightChild);
    }
}

void postorder(struct Node* p){
    if(p!=NULL){
        postorder(p->leftChild);
        postorder(p->rightChild);
        printf("%6d",p->data);
    }
}

int search(struct Node* p,int key){
    if(p==NULL){
        return 0;
    }
    else{
    if(p->data==key){
        printf("Element %d present\n",key);
        return 1;
    }
    if(key<p->data){
        search(p->leftChild,key);
    }
    if(key>p->data){
        search(p->rightChild,key);
    }
    }
}

int smallest(struct Node* p,int key){
    if(p==NULL){
        return key;
    }
    else return smallest(p->leftChild,p->data);
}

int largest(struct Node* p,int key){
    if(p==NULL){
        return key;
    }
    else return largest(p->rightChild,p->data);
}

int main()
{
    struct Tree t;
    t.root=NULL;
    int n,ch,value,key;
    do{
        printf("\n\n0.Quit\n1.Create\n2.In-Order\n3.Pre-Order\n4.Post-Order\n5.Search\n6.Find smallest Element\n7.Find Largest Element\n\n");
        printf("%s\nEnter Your Choice: ","--------------------------------------");
        scanf("%d",&ch);

        switch(ch){
            case 0:
                printf("Exitting code\n");
                exit(0);
                break;

            case 1:
                t.root=NULL;
                printf("How many nodes you want to enter : ");
                scanf("%d",&n);
                printf("Enter %d integers: ",n);
                for(int i=0;i<n;i++){
                    scanf("%d",&value);
                    insert(&t,value);
                }
                break;
            
            case 2:
                printf("Traversing Inorder\n");
                inorder(t.root);
                printf("\n");
                break;

            case 3:
                printf("Traversing Preorder\n");
                preorder(t.root);
                printf("\n");
                break;

            case 4:
                printf("Traversing Postorder\n");
                postorder(t.root);
                printf("\n");
                break;

            case 5:
                printf("Enter an integer to search: ");
                scanf("%d",&value);
                if(t.root==NULL){
                    printf("Tree empty\n");
                }
                else{
                    if(search(t.root,value)==0){
                        printf("Not found\n");
                    }
                }
                break;

            case 6:
                if(t.root==NULL){
                    printf("Tree empty\n");
                }
                else{
                    printf("Smallest element = %d\n",smallest(t.root,t.root->data));
                }
                break;

            case 7:
                if(t.root==NULL){
                    printf("Tree empty\n");
                }
                else{
                    printf("Largest element = %d\n",largest(t.root,t.root->data));
                }
                break;
        }

    }while(1);
}