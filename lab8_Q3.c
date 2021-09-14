#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int *arr;
    int tos;
};
void push(struct Stack* s,int n)
{
    s->arr[++(s->tos)]=n;
}
int isEmpty(struct Stack* s)
{
    return(s->tos==-1);
}
int pop(struct Stack* s)
{
    return(s->arr[s->tos--]);
}
void printStack(struct Stack* s)
{
    for(int i=s->tos;i>=0;i--){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct Stack* s;
    int n,ch,value;
    printf("Enter the numer of Stack elements: ");
    scanf("%d",&n);
    s->arr=(int*)malloc(n*sizeof(int));
    s->tos=-1;
    do{
        printf("\n1. Push\n");
        printf("2. Check if Stack is empty\n");
        printf("3. pop\n");
        printf("4. print stack\n");
        printf("5. Exit code\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(s->tos==n-1){
                    printf("Stack overflow\n");
                    break;
                }
                printf("Enter value to push: ");
                scanf("%d",&value);
                push(s,value);
                break;

            case 2:
                if(isEmpty(s))
                    printf("Stack is empty\n");
                else  
                    printf("Stack is not empty.\n");
                break;

            case 3:
                if(isEmpty(s)){
                    printf("Stack underflow\n");
                    break;
                }
                else{
                    printf("Element Popped : %d\n",pop(s));
                }
                break;
            case 4:
                printf("Printing Stack: ");
                printStack(s);
                break;
            case 5:
                printf("Exitting code\n");
                exit(0);
            default:
                printf("Wrong input\n");
        }
    }while(1);    
}