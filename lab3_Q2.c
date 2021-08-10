#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int*,int);
int main()
{
    int n,*arr;
    printf("Enter the size of array :");    
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements :\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }  
    arr=bubbleSort(arr,n);
    printf("\nSecond smallest = %d\nSecond largest = %d\n",arr[1],arr[n-2]);
    return 0;
}
int* bubbleSort(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}