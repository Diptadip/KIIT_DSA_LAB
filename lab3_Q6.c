#include<stdio.h>
#include<stdlib.h>

void printMatrix(int**,int,int);
int** transpose(int**,int,int);
int** matrixCopy(int**,int,int);
int* ascendingSort(int*,int);
int* descendingSort(int*,int);
void colSort(int**,int,int);
void rowSort(int**,int,int);
int main()
{
    int n,m,**arr,**arrCpy;
    printf("Enter row and col of mxn matrix: ");
    scanf("%d %d",&m,&n);
    arr=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        arr[i]=(int*)malloc(n*sizeof(int));
    }
    printf("Enter %d integers: ",m*n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    arrCpy=matrixCopy(arr,m,n);
    printf("The entered Matrix is:\n");
    printMatrix(arr,m,n);

    printf("After sorting rows in ascending order: \n");
    rowSort(arr,m,n);

    printf("After sorting columns in descending order: \n");
    colSort(arrCpy,m,n);    

    //freeing space
    for(int i=0;i<n;i++){
        free((void*)arr[i]);
    }
    free((void*)arr);
}
int* ascendingSort(int*arr,int n)
{    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    return arr;
}
int** transpose(int**arr,int row,int col)
{
    int rowT=col;
    int colT=row;
    int k=0;
    int**arrT=(int**)malloc(rowT*sizeof(int*));
    for(int i=0;i<rowT;i++){
        arrT[i]=(int*)malloc(colT*sizeof(int));
    }
    for(int i=0;i<rowT;i++){
        for(int j=0;j<colT;j++){
            arrT[i][j]=arr[j][i];
        }
    }
    //printMatrix(arrT,rowT,colT);
    return arrT;
}
void rowSort(int** arr,int m,int n)
{
    for(int i=0;i<m;i++){
        arr[i]=ascendingSort(arr[i],n);
    }
    printMatrix(arr,m,n);
}
void colSort(int** arr,int m,int n)
{
    //transposing matrix
    arr=transpose(arr,m,n);
    for(int i=0;i<n;i++){
        arr[i]=descendingSort(arr[i],m);
    }
    arr=transpose(arr,n,m);
    printMatrix(arr,m,n);
}
int* descendingSort(int*arr,int n)
{
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    return arr;
}
int** matrixCopy(int**arr,int m,int n)
{
    int**arrCpy=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        arrCpy[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arrCpy[i][j]=arr[i][j];
        }
    }
    return arrCpy;
}
void printMatrix(int**arr,int m,int n)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
}
