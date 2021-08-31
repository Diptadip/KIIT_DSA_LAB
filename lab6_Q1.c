#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* buildPoly(int maxExp)
{
    int*coeff=(int*)calloc(maxExp+1,sizeof(int));
    printf("Enter the coeffcients...\n");
    for(int i=maxExp;i>=0;i--){
        printf("coeff of x^%d : ",i);
        scanf("%d",&coeff[i]);
    }
    printf("\n");
    return coeff;
}
void displayPoly(int*coeff,int maxExp)
{
    if(coeff[maxExp]!=0){
        printf("%dx^%d",coeff[maxExp],maxExp);
    }
    for(int i=maxExp-1;i>=0;i--){
        if(coeff[i]>0){
            printf(" +%dx^%d",coeff[i],i);
        }
        if(coeff[i]<0){
            printf(" %dx^%d",coeff[i],i);
        }
    }
}
int max(int a,int b)
{
    return (a>b) ? a : b;
}
int* add(int* A,int *B,int a,int b)
{
    int c=max(a,b);
    int *C=(int*)calloc(c+1,sizeof(int));
    if(a==c){
        for(int i=0;i<=a;i++){
            C[i]=A[i];
        }
        for(int i=0;i<=b;i++){
            C[i]+=B[i];
        }
    }
    else{
        for(int i=0;i<=b;i++){
            C[i]=B[i];
        }
        for(int i=0;i<=a;i++){
            C[i]+=A[i];
        }
    }
    return C;
}
int main()
{
    int*A,*B,*C,a,b,c;
    printf("Enter max exponent of 1st polynomial: ");
    scanf("%d",&a);
    A=buildPoly(a);
    //displayPoly(A,a);

    printf("Enter max exponent of 2nd polynomial: ");
    scanf("%d",&b);
    B=buildPoly(b);
    //displayPoly(B,b);

    //adding
    c=max(a,b);
    C=add(A,B,a,b);
    printf("\nAddition is : ");
    displayPoly(C,c);
}