#include<stdio.h>
#include<stdlib.h>
typedef struct employeeRecord{
    char name[25];
    char gender[10];
    char designation[20];
    char department[10];
    float basic;
}employee;

employee* fillRecord(employee*,int);
void printRecords(employee*,int);
void printAmounts(float);

int main()
{
    int n;
    employee* emp;
    printf("Enter number of Employees: ");
    scanf("%d",&n);
    emp=(employee*)malloc(n*sizeof(employee));
    emp=fillRecord(emp,n);
    printRecords(emp,n);
    free((void*)emp);

}
employee* fillRecord(employee* emp, int n)
{
    printf("Enter %d records\n ",n);
    for(int i=0;i<n;i++){
        printf("Enter employee %d name: ",i+1);
        fflush(stdin);
        gets(emp[i].name);        

        printf("Enter employee %d gender: ",i+1);
        fflush(stdin);
        gets(emp[i].gender);        

        printf("Enter employee %d designation: ",i+1);
        fflush(stdin);
        gets(emp[i].designation);        

        printf("Enter employee department: ",i+1);
        fflush(stdin);
        gets(emp[i].department);        

        printf("Enter employee basic pay amount: ",i+1);
        fflush(stdin);
        scanf("%f",&emp[i].basic);
        

        printf("\n");
    }
    return emp;
}
void printRecords(employee* emp,int n)
{
    printf("\nPrinting all Employee records...\n");
    for(int i=0;i<n;i++){
        printf("\n%-20s %3s %-20s\n","Name",":",emp[i].name);
        printf("%-20s %3s %-20s\n","Gender",":",emp[i].gender);
        printf("%-20s %3s %-20s\n","Designation",":",emp[i].designation);
        printf("%-20s %3s %-20s\n","Department",":",emp[i].department);
        printf("%-20s %3s %-20.2f\n","Basic Pay",":",emp[i].basic);
        printAmounts(emp[i].basic);
    }
}
void printAmounts(float basic)
{
    float gross,hr,da;
    hr=0.25*basic;
    da=0.75*basic;
    gross=basic+hr+da;
    printf("%-20s %3s %-20.2f\n","HR",":",hr);
    printf("%-20s %3s %-20.2f\n","DA",":",da);
    printf("%-20s %3s %-20.2f\n","Gross Pay",":",gross);
}