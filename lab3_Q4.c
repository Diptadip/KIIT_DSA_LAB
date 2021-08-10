#include<stdio.h>
#include<stdlib.h>
int* calculateNge(int*,int);
int main()
{
    int n;
    int*arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("After changing elements to next greatest element:\n");
    arr=calculateNge(arr,n);
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
    free((void*)arr);
}
int* calculateNge(int*arr,int n)
{
    for(int i=0;i<n-1;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                arr[i]=arr[j];
                break;
            }
        }
        if(j==n){
            arr[i]=-1;
        }
    }
    arr[n-1]=-1;
    return arr;
}