//WAP to find next greater element an array

#include<stdio.h>
#include<stdlib.h>

void printArray(int*,int);
int* bubbleSort(int*,int);
int main()
{
    int n;
    int*arr,*nge;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    nge=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                nge[i]=arr[j];
                break;
            }
        }
        if(j==n){
            nge[i]=-1;
        }
    }
    nge[n-1]=-1;
    for(int i=0;i<n;i++){
        printf("%3d",nge[i]);
    }
    printf("\n");
    free((void*)arr);
    free((void*)nge);
}