#include<stdio.h>
#include<stdlib.h>
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
int getSum(int**,int,int,int,int);
int sumFound(int**,int,int,int);
void printSubs(int**,int,int);
void printMatrix(int**,int,int,int,int);
int main()
{
    int n,k,s,**arr;
    printf("Enter order of square matrix: ");
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
    printf("The entered matrix is: \n");
    printMatrix(arr,0,0,n,n);
    //rintf("\nEnter value of k: ");
    //scanf("%d",&k);
    printf("Enter required sum: ");
    scanf("%d",&s);
    //sumFound(arr,4,136,4);
    printSubs(arr,s,n);

}
int getSum(int**arr,int r1,int c1,int r2,int c2)
{
    return arr[r2][c2] - arr[r2][c1] - arr[r1][c2]+ arr[r1][c1];
}
int sumFound(int**arr,int k,int s,int n)
{
    int**sumMat;
    int flag=0;
    sumMat=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0;i<=n;i++){
        sumMat[i]=(int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            sumMat[i][j]=0;
        }
    }    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sumMat[i + 1][j + 1] = sumMat[i + 1][j] + sumMat[i][j + 1] - sumMat[i][j] + arr[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            int sum = getSum(sumMat, i, j, i + k, j + k); 
            printf("%d\n",sum);
            if (sum ==s){
                flag=1;
                printMatrix(arr,i,j,i+k,j+k);
            }                
        }
    }
    //freeing space
    for(int i=0;i<n;i++){
        free((void*)sumMat[i]);
    }
    free((void*)sumMat);
    return flag;
}
void printSubs(int**arr,int s,int n)
{
    int flag=0;
    for(int k=1;k<=n;k++){
        printf("\nFor k= %d.....\n\n",k);
        flag=sumFound(arr,k,s,n);
    }
}
void printMatrix(int**arr,int r1,int c1,int r2,int c2)
{
    for(int i=r1;i<r2;i++){
        for(int j=c1;j<c2;j++){
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}