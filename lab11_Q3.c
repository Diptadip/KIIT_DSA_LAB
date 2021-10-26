#include<stdio.h>
#include<stdlib.h>

int linearSearch(int* arr,int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            count++;
        }
    }
    return count;
}
int main()
{
    int *arr,n,key,count;
    printf("Enter the array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key to search for: ");
    scanf("%d",&key);
    count=linearSearch(arr,n,key);
    if(count) printf("Elment %d occurred %d times in the array\n",key,count);
    else printf("Element %d not present in array\n",key);
}