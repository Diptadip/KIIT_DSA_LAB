//WAP to sort an array

#include<stdio.h>
#include<stdlib.h>

void printArray(int*,int);
int* bubbleSort(int*,int);
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
    //printing unsorted array
    printf("The unsorted array is:\n");
    printArray(arr,n);
    printf("The sorted array is:\n");
    bubbleSort(arr,n);
    printArray(arr,n);
}
void printArray(int*arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
}

int* bubbleSort(int*arr,int n)
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