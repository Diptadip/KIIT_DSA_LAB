#include<stdio.h>
#include<stdlib.h>

int* selectionSort(int*,int);
int getSmallest(int*,int);
int getSecondSmallest(int*,int);

int main()
{
    int*arr,n,min,s_min;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers...\n",n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("The unsorted array is: ");
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");

    arr=selectionSort(arr,n);

    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
    
    min=getSmallest(arr,n);
    s_min=getSecondSmallest(arr,n);
    printf("Smallest element = %d\nSecond smallest = %d\n",min,s_min);
}
int* selectionSort(int*arr,int n)
{
    for(int i=n-1;i>0;i--){
        int largest=arr[0];
        int index=0;
        for (int j = 1; j <= i; j++){ 
            if (arr[j] > largest){
                largest = arr[j];
                index = j;
            }
        }
        arr[index]=arr[i];
        arr[i]=largest;
    }
    return arr;
}
int getSmallest(int*arr,int n)
{
    return arr[0];
}
int getSecondSmallest(int*arr,int n)
{
    int smallest=getSmallest(arr,n);
    for(int i=1;i<n;i++){
        if(arr[i]!=smallest){
            return arr[i];
        }
    }
    return smallest;
}