#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int*,int);
int main()
{
    int n,*arr,k;
    printf("Enter the size of array :");    
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements :\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }  
    do{
        printf("Enter k..must be <= %d: ",n/2);
        scanf("%d",&k);
    }while( k>n/2 &&  printf("invalid!\n"));
    arr=bubbleSort(arr,n);
    printf("\n%d smallest = %d\n%d largest = %d\n",k,arr[k-1],k,arr[n-k]);
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