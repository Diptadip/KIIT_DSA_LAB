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

    int sparse[count+1][3];

    sparse[0][0]=row;
    sparse[0][1]=col;
    sparse[0][2]=count;
    int k=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(m[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k++][2]=m[i][j];
            }
        }
    }

    printf("\nThe sparse matrix is:-\n");
    for(int i=0;i<count+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%3d ",sparse[i][j]);
        }
        printf("\n");
    }
    
}