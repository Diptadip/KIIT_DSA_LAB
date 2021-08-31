#include<stdio.h>
#include<stdlib.h>

struct Node{
    int r;
    int c;
    int v;
    struct Node* next;
};

void addAtHead(struct Node** head, int row,int col,int value)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node ->r = row;
    node->c = col;
    node->v = value;
    node ->next =(*head);
    (*head)=node;
}
void display(struct Node* ptr)
{
    if(ptr==NULL)
        printf("\nList is empty\n");
    while(ptr){
        printf("%3d%3d%3d\n",ptr->r,ptr->c,ptr->v);
        ptr=ptr->next;
    }
}
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
    struct Node* sparse=NULL;
    for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=0;j--)
        {
            if(m[i][j]!=0)
            {
                addAtHead(&sparse,i,j,m[i][j]);
            }
        }
    }
    addAtHead(&sparse,row,col,count);
    display(sparse);
}