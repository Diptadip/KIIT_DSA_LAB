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

int* multiply(int*A,int*B,int a,int b)
{
    int c=a+b;
    int*C=(int*)calloc(c+1,sizeof(int));
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            C[i+j] += A[i]*B[j];
        }
    }
    return C;
}
int main()
{
    int*A,*B,*D,a,b,d;
    printf("Enter max exponent of 1st polynomial: ");
    scanf("%d",&a);
    A=buildPoly(a);
    //displayPoly(A,a);

    printf("Enter max exponent of 2nd polynomial: ");
    scanf("%d",&b);
    B=buildPoly(b);
    //displayPoly(B,b);
    
    printf("A: ");
    displayPoly(A,a);
    printf("\nB: ");
    displayPoly(B,b);

    printf("\nMultiplication: ");
    //multiply
    d=a+b;
    D=multiply(A,B,a,b);
    displayPoly(D,d);
}