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
int binarySearch(int*arr,int lb,int ub,int key)
{
    while(lb<=ub){
        int mid=(lb+ub)/2;
        if(key==arr[mid]){
            return mid;
        }
        if(key<arr[mid]){
            ub=mid-1;
        }
        if(key>arr[mid]){
            lb=mid+1;
        }
    }
    return -1;
}
int main()
{
    int *arr,n,key,idx;
    printf("Enter the array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key to search for: ");
    scanf("%d",&key);
    bubbleSort(arr,n);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
    idx=binarySearch(arr,0,n,key);
    if(idx!=-1) printf("Element %d present at index %d\n",key,idx);
    else printf("Element %d not present in array\n",key);
}