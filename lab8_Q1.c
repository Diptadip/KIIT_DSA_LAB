#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int*arr;
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
    for(int i=0;i<s->tos;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct Stack* s;
    int n;
    printf("Enter the numer of Stack elements: ");
    scanf("%d",&n);
    s->arr=(int*)malloc(n*sizeof(int));
    s->tos=-1;
    s=(struct Stack*)malloc(sizeof(struct Stack));
    push(s,5);
    printStack(s);
    pop(s);
}