#include<stdio.h>
#include<stdlib.h>

void printArray(int*,int);
int getLargest(int*,int);
int getOccurrence(int*,int);

int main()
{
    int*arr,n,max,count;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The entered array is: ");
    printArray(arr,n);
    max=getLargest(arr,n);
    count=getOccurrence(arr,n);
    printf("Largest element = %3d\nFrequency = %3d\n",max,count);

}
int getLargest(int*arr,int n)
{
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int getOccurrence(int*arr,int n)
{
    int max=getLargest(arr,n);
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==max){
            count++;
        }
    }
    return count;
}
void printArray(int*arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
}