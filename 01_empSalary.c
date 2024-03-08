#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Max 50

struct employee{
    char id[Max];
    double salary;
    char gender[Max];
    char firstName[Max];
    char lastName[Max];
};

struct employee emp[100];

//Function define:
void take_data(int employee_amount);
int menu();
void change_salary (int employee_amount);

int main()
{
    int employee_amount;
    printf("Input the amount of employee in company: ");
    scanf("%d",&employee_amount);
    

    int userChoice;
    do{
        userChoice = menu();
        switch (userChoice)
        {
        case 1:
            take_data(employee_amount);
            break;
    
        case 2:
            change_salary(employee_amount);
            break;
        
        case 11:
            printf ("Programm exited.");
        
        default:
            printf ("Invalid Choice. Choose again!\n");
            break;
        } 
    } while (userChoice != 11);
}

//Functions below://
//Menu:
int menu()
{
    printf ("\nMENU\n");
    printf ("1. Nhap thong tin nhan vien.\n");
    printf ("2. Sua thong tin luong nhan vien.\n");
    printf ("3. Sua thong tin ho va ten nhan vien.\n");
    printf ("11. Quit.\n");
    printf ("Your choice: ");
    int choice;
    scanf ("%d", &choice);
    return choice;
}

//Function1: Nhap thong tin nhan vien
void take_data(int employee_amount)    
{
    int i = 0;
    for (i; i<employee_amount;i++){
        printf ("Input the %d Employee ID: ", i+1);
        scanf ("%s", emp[i].id);
        
        printf ("Input the %d Employee's last name: ", i+1);
        scanf ("%s", emp[i].lastName);
        
        printf ("Input the %d Employee's first name: ", i+1);
        scanf ("%s", emp[i].firstName);
        
        printf ("Input the %d Employee's gender (Male or Female): ", i+1);
        scanf ("%s", emp[i].gender);
        
        printf ("Input the %d Employee's salary: ", i+1);
        scanf ("%lf", &emp[i].salary);
        printf ("\n");
    }
}

//Funtion2: Sua thong tin luong
void change_salary (int employee_amount){
    char id[Max];
    printf ("Input employee's ID: ");
    scanf ("%s", id);
    
    for (int i=0; i<employee_amount; i++){
        if (strcmp(emp[i].id, id)==0) {
            printf("Input new salary: ");
            scanf("%lf", &emp[i].salary);
            printf("Change employee's salary successfully!\n");
            // printf ("%.2lf", emp[i].salary); CheckingFunction
            return;
        }
        printf ("Can not find the employee"); 
    }   
}

