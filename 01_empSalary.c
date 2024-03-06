#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Max 50

struct employee{
    long id;
    long salary;
    char gender[Max];
    char firstName[Max];
    char lastName[Max];
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
        printf ("Input the %d Employee ID: ", i+1);
        scanf ("%d",&employees[i].id);
        
        printf ("Input the %d Employee's last name: ", i+1);
        scanf ("%s", employees[i].lastName);
        
        printf ("Input the %d Employee's first name: ", i+1);
        scanf ("%s", employees[i].firstName);
        
        printf ("Input the %d Employee's gender: ", i+1);
        scanf ("%s", employees[i].gender);
        
        printf ("Input the %d Employee's salary: ", i+1);
        scanf ("%lf", &employees[i].salary);
    }
}



