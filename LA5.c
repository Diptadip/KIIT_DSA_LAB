//WAP to display the count and the elements where a=<element<=b in an array

#include<stdio.h>
#include<stdlib.h>

void printArray(int*,int);
int* bubbleSort(int*,int);
int main()
{
    int n,a,b,count=0;
    int*arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter lower bound: ");
    scanf("%d",&a);
    printf("Enter upper bound: ");
    scanf("%d",&b);
    //starting search
    for(int i=0;i<n;i++){
        if(arr[i]>=a && arr[i]<=b){
            printf("%3d",arr[i]);
            count++;
        }
    }
    printf("\ncount = %d\n",count);
}