
#include <limits.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int getMinDist(int*,int,int,int);

int main()
{
    int n,*arr,x,y;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements :\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the two elements between which distance has to be calculated :\n");
    scanf("%d %d",&x,&y);
    printf("Minimum distance between %d and %d is %d\n",x,y, getMinDist(arr, n, x, y));
    return 0;
}
int getMinDist(int arr[], int n, int x, int y)
{
    int i, j;
    int min_dist = INT_MAX;
    for (i = 0; i < n; i++) 
    {      
        for (j = i + 1; j < n; j++) 
        {
            if (( x == arr[i]&&y == arr[j] || x == arr[j]&&y == arr[i]) && min_dist > abs(i - j)){
                min_dist = abs(i - j);
            }
        }
        
    }
    if (min_dist > n) {
        return -1;
    }
    return min_dist;
}
 