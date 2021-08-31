#include<stdio.h>

int main()
{
    int row,col,count=0;

    printf("Enter the number of rows: ");
    scanf("%d",&row);

    printf("Enter the number of columns: ");
    scanf("%d",&col);

    int m[row][col];

    printf("Enter %d integers: \n",row*col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    printf("\nThe entered matrix is:\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%3d ",m[i][j]);
            if(m[i][j]!=0)
            count++;
        }
        printf("\n");
    }

    printf("\nNumber of non-zero integers = %d\n",count);

    int sparse[3][count+1];

    sparse[0][0]=row;
    sparse[1][0]=col;
    sparse[2][0]=count;
    int k=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(m[i][j]!=0)
            {
                sparse[0][k]=i;
                sparse[1][k]=j;
                sparse[2][k++]=m[i][j];
            }
        }
    }

    printf("\nThe sparse matrix is:-\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<count+1;j++)
        {
            printf("%3d ",sparse[i][j]);
        }
        printf("\n");
    }
    
}