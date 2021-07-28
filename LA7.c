//Wap to do following operations on nXn square matrix
//find the no of nonzero elements
//sum of elements above leading diagonal
//display the elements below minor diagonal
//find the product of diagonal elements

#include<stdio.h>
#include<stdlib.h>

void printMatrix(int**,int);
void nonZero(int**,int);
void aboveLeadingDiagSum(int**,int);
void belowMinorDiag(int**,int);
void diagElementsProd(int**,int);
int main()
{
    int n,**arr;
    printf("Enter order of matrix: ");
    scanf("%d",&n);
    arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        arr[i]=(int*)malloc(n*sizeof(int));
    }
    printf("Enter %d integers: ",n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The entered Matrix is:\n");
    printMatrix(arr,n);
    nonZero(arr,n);
    aboveLeadingDiagSum(arr,n);
    belowMinorDiag(arr,n);
    diagElementsProd(arr,n);

    //freeing space
    for(int i=0;i<n;i++){
        free((void*)arr[i]);
    }
    free((void*)arr);
}
void printMatrix(int**arr,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
}
void nonZero(int** arr,int n)
{
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]){
                count++;
            }
        }
    }
    printf("Number of non-zero elements = %d\n",count);
}
void aboveLeadingDiagSum(int**arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum+=arr[i][j];
        }
    }
    printf("Sum of elements above leading elements = %d\n",sum);
}
void belowMinorDiag(int**arr, int n)
{
    printf("Elements below minor diagonal : ");
    for(int i=0;i<n;i++){
        for(int j=n-1;j>n-1-i;j--){
            printf("%3d",arr[i][j]);
        }
    }
    printf("\n");
}
void diagElementsProd(int**arr,int n)
{
    int prodP=1;
    int prodS=1;
    for(int i=0;i<n;i++){
        prodP*=arr[i][i];
        prodS*=arr[i][n-1-i];
    }
    printf("Product of primary diagonal = %3d\nProduct of secondary diagonal = %3d\n",prodP,prodS);
}