#include<stdio.h>
#include<stdlib.h>

void printMatrix(int**,int);
void swapElements(int*,int*);
void swap(int**,int);

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

    printf("Matrix after swapping: \n");
    swap(arr,n);

    //freeing space
    for(int i=0;i<n;i++){
        free((void*)arr[i]);
    }
    free((void*)arr);
}
void swapElements(int*x , int* y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void swap(int**arr,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<=n/2;j++){
            swapElements(&arr[i][j],&arr[i][n-1-j]);
        }
    }
    printMatrix(arr,n);
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
