//WAP to search in an array

#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
int main()
{
    int n,key,flag=false;
    int*arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the integer to search for: ");
    scanf("%d",&key);
    //searching
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            flag=true;
            printf("Element %d found at index %d",key,i);
        }
    }
    if(!flag)
        printf("Key not found");
    free((void*)arr);
}