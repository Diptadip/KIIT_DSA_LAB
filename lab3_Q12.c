#include<stdio.h>
#include<stdlib.h>



typedef struct Matrix{
    int rows;
    int cols;
    int**arr;
}matrix;

void printMatrix(matrix);
matrix matrixMultiply(matrix,matrix);
matrix fillMatrix();

int main()
{
    matrix a,b;
    printf("Enter for 1st matrix: \n");
    a=fillMatrix();
    printf("Enter for 2nd matrix: \n");
    b=fillMatrix();

    printf("The entered matrices are: \n");
    printMatrix(a);
    printMatrix(b);

    printf("Multiplying...\n");
    matrix c=matrixMultiply(a,b);
    printMatrix(c);

}
matrix fillMatrix()
{
    matrix m;
    printf("Enter rows and cols: ");
    scanf("%d %d",&m.rows,&m.cols);
    m.arr=(int**)malloc(m.rows*sizeof(int*));
    for(int i=0;i<m.rows;i++){
        m.arr[i]=(int*)malloc(m.cols*sizeof(int));
    }
    printf("Enter %d integers: ",m.rows*m.cols);
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++){
            scanf("%d",&m.arr[i][j]);
        }
    }
    return m;
}
matrix matrixMultiply(matrix a,matrix b)
{
    matrix c;
    if(a.cols != b.rows){
        printf("Incompatible...\n");
        exit(0);
    }
    c.rows=a.rows;
    c.cols=b.cols;
    c.arr=(int**)malloc(c.rows*sizeof(int*));
    for(int i=0;i<c.rows;i++){
        c.arr[i]=(int*)malloc(c.cols*sizeof(int));
    }
    for(int i=0;i<c.rows;i++){
        for(int j=0;j<c.cols;j++){
            c.arr[i][j]=0;
            for(int k=0;k<a.cols;k++){
                c.arr[i][j]+=a.arr[i][k]*b.arr[k][j];
            }
        }
    }
    return c;
}
void printMatrix(matrix m)
{
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++){
            printf("%3d",m.arr[i][j]);
        }
        printf("\n");
    }
}
