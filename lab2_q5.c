#include<stdio.h>
#include<stdlib.h>
typedef struct studentRecord{
    int roll;
    char name[25];
    char gender[10];
    float cgpa;
}student;

student* fillRecord(student*,int);
void printRecords(student*,int);

int main()
{
    int n;
    student* s;
    printf("Enter number of students: ");
    scanf("%d",&n);
    s=(student*)malloc(n*sizeof(student));
    s=fillRecord(s,n);
    printRecords(s,n);
    free((void*)s);

}
student* fillRecord(student* s, int n)
{
    printf("Enter %d records\n ",n);
    for(int i=0;i<n;i++){
        printf("Enter student %d roll: ",i+1);
        fflush(stdin);
        scanf("%d",&s[i].roll);
        

        printf("Enter student %d name: ",i+1);
        fflush(stdin);
        gets(s[i].name);
        

        printf("Enter student %d gender: ",i+1);
        fflush(stdin);
        gets(s[i].gender);
        

        printf("Enter student %d cgpa: ",i+1);
        fflush(stdin);
        scanf("%f",&s[i].cgpa);
        

        printf("\n");
    }
    return s;
}
void printRecords(student* s,int n)
{
    printf("\nPrinting all student records...\n");
    for(int i=0;i<n;i++){
        printf("\n%-20s %3s %-20d\n","Roll number",":",s[i].roll);
        printf("%-20s %3s %-20s\n","Name",":",s[i].name);
        printf("%-20s %3s %-20s\n","Gender",":",s[i].gender);
        printf("%-20s %3s %-20.2f\n","CGPA",":",s[i].cgpa);
    }
}
