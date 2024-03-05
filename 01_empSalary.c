#include <stdio.h>
#include <stdbool.h>
#define bool _Bool
#define Max 50

struct employee{
    long id,hours;
    long salary;
    bool gender;
    char firstName[Max];
    char secondName[Max];
};

void take_data();
void salary_cal();
int main()
{
    int employee_amount;
    printf("Input the amount of employee in company: ");
    scanf("%d",&employee_amount);
    take_data(employee_amount);
    return 0;
}
void salary_cal(int id, int hours, long salary)
{    
    float total_salary = (float)salary*hours;
    printf("Emplyees ID: %d\n",id);
    printf("Salary = U$ %.2f\n",total_salary);
}
void take_data(int employee_amount)    
{
    struct employee employees[employee_amount];
    int i = 0;
    for (i; i<employee_amount;i++){
        printf("Input the %d Employees ID: ",i+1);
        scanf("%d",&employees[i].id);
        printf("Input worked hours of the %d employee: ",i+1);
        scanf("%d",&employees[i].hours);
        printf("Input slary per hour of %d employee: ",i+1);
        scanf("%ld",&employees[i].salary);
        printf("Employee number: %d\n",i+1);
        salary_cal(employees[i].id,employees[i].hours,employees[i].salary);
    }
}

//day_la_branch

