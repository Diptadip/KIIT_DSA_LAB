#include<stdio.h>
#include<stdlib.h>

void printArray(int*,int);
int* multiply(int*,int);

int main()
{
    int*arr,n;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The entered array is: ");
    printArray(arr,n);

    printf("The array after multiplication is : ");
    arr=multiply(arr,n);
    printArray(arr,n);

}
int* multiply(int*arr,int n)
{
    int prod=1;
    for(int i=0;i<n;i++){
        prod*=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=prod/arr[i];
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