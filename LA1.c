//WAP to find largest and smallest

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,max,min;
    int*arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    max=min=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i])
            max=arr[i];
        if(min>arr[i])
            min=arr[i];
    }
    printf("largest=%d , smallest=%d ",max,min);
    free((void*)arr);
    return 0;    
}