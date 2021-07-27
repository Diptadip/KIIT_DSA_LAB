//WAP to reverse array

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int*arr,*rev;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    rev=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //reversing
    for(int i=0;i<n;i++){
        rev[i]=arr[n-1-i];
    }
    //printing
    printf("reversed array is:\n");
    for(int i=0;i<n;i++){
        printf("%3d",rev[i]);
    }
    free((void*)arr);
    free((void*)rev);
}