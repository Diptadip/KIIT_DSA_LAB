#include<stdio.h>
#include<stdlib.h>
typedef struct consumerRecord{
    int id;
    char name[25];
    char gender[10];
    float years;
    float discount;
}consumer;

consumer* fillRecord(consumer*,int);
void printRecords(consumer*,int);
float calculateDiscount(float);
void putDiscount(consumer*,int);

int main()
{
    int n;
    consumer* c;
    printf("Enter number of consumers: ");
    scanf("%d",&n);
    c=(consumer*)malloc(n*sizeof(consumer));
    c=fillRecord(c,n);
    putDiscount(c,n);
    printRecords(c,n);
    free((void*)c);

}
consumer* fillRecord(consumer* c, int n)
{
    printf("Enter %d records\n ",n);
    for(int i=0;i<n;i++){
        printf("Enter consumer %d id: ",i+1);
        fflush(stdin);
        scanf("%d",&c[i].id);        

        printf("Enter consumer %d name: ",i+1);
        fflush(stdin);
        gets(c[i].name);        

        printf("Enter consumer %d gender: ",i+1);
        fflush(stdin);
        gets(c[i].gender);        

        printf("Enter consumer %d years of usage: ",i+1);
        fflush(stdin);
        scanf("%f",&c[i].years);        

        printf("\n");
    }
    return c;
}
void printRecords(consumer* c,int n)
{
    printf("\nPrinting all consumer records...\n");
    for(int i=0;i<n;i++){
        printf("\n%-20s %3s %-20d\n","ID",":",c[i].id);
        printf("%-20s %3s %-20s\n","Name",":",c[i].name);
        printf("%-20s %3s %-20s\n","Gender",":",c[i].gender);
        printf("%-20s %3s %-20.2f\n","Years of usage",":",c[i].years);
        printf("%-20s %3s %-20.2f\n","Discount",":",c[i].discount);
    }
}
float calculateDiscount(float years)
{
    return years*0.1;
}
void putDiscount(consumer* c,int n)
{
    for(int i=0;i<n;i++){
        c[i].discount=calculateDiscount(c[i].years);
    }
}