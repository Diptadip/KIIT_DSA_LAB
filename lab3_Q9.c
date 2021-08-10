#include<stdio.h>
#include<stdlib.h>

void printArray(int*,int);
int* arrangeZeroOne(int*,int);

int main()
{
    int*arr,n;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter total of %d 0's and 1's\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array before rearrangement is: ");
    printArray(arr,n);

    printf("The array after rearrangement is: ");
    arr=arrangeZeroOne(arr,n);
    printArray(arr,n);

}
int* arrangeZeroOne(int*arr,int n)
{
    int k=-1;
    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            k++;
            int t=arr[i];
            arr[i]=arr[k];
            arr[k]=t;
        }
    }
    return arr;
}
void printArray(int*arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
}