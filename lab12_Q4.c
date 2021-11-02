#include<stdio.h>
#include<stdlib.h>

void selectionSort(int*arr,int n)
{
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                    minIdx=j;
            }
        }
        int temp=arr[minIdx];
        arr[minIdx]=arr[i];
        arr[i]=temp;
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
    selectionSort(arr,n);
    print(arr,n);
}