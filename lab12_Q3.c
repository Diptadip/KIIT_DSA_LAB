#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int*arr,int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void print(int*arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
}
int main()
{
    int n,*arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter %d integers: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The entered array is: ");
    print(arr,n);
    printf("The sorted array is: ");
    bubbleSort(arr,n);
    print(arr,n);
}