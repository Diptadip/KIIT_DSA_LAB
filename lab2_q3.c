#include<stdio.h>
#include<stdlib.h>

int* selectionSort(int*,int);
void printArray(int*,int);

int main()
{
    int n,*arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The entered array is: ");
    printArray(arr,n);
    printf("The sorted array is: ");
    selectionSort(arr,n);
    printArray(arr,n);
    free((void*)arr);
}
void printArray(int* arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%3d",arr[i]);
    }
    printf("\n");
}
int* selectionSort(int*arr,int n)
{
    for (int i = n-1; i> 0; i--){ // number of passes
        int largest = arr[0];
        int index = 0;
        for (int j = 1; j <=i; j++){ // number of comparisons in each pass
            if (arr[j] > largest){
                largest = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = largest;
    }
}