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
int menu ();
void take_data (int employee_amount);
void change_salary (int employee_amount);
void change_name (int employee_amount);
void delete_emp(int employee_amount);
void printAll_emp (int employee_amount);


//MAIN
int main ()
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
        
        case 3:
            change_name(employee_amount);
            break;

        case 4:
            delete_emp(employee_amount);
            break;

        case 7:
            printAll_emp(employee_amount);
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
int menu ()
{
    printf ("\nMENU\n");
    printf ("1. Input employee data.\n");
    printf ("2. Change employee salary.\n");
    printf ("3. Change employee name.\n");
    printf ("4. Delete employee data.\n");
    printf ("7. Export all employee data.\n");
    printf ("11. Quit.\n");
    printf ("Your choice: ");
    int choice;
    scanf ("%d", &choice);
    return choice;
}

//Function1: Nhap thong tin nhan vien
void take_data (int employee_amount)
{
    int i = 0;
    for (i; i<employee_amount;i++){
        printf ("Input the No.%d Employee ID: ", i+1);
        scanf ("%s", emp[i].id);
        
        printf ("Input the No.%d Employee's last name: ", i+1);
        scanf ("%s", emp[i].lastName);
        
        printf ("Input the No.%d Employee's first name: ", i+1);
        scanf ("%s", emp[i].firstName);
        
        printf ("Input the No.%d Employee's gender (Male or Female): ", i+1);
        scanf ("%s", emp[i].gender);
        
        printf ("Input the No.%d Employee's salary: ", i+1);
        scanf ("%lf", &emp[i].salary);
        printf ("\n");
    }
}

//Funtion2: Sua thong tin luong
void change_salary (int employee_amount)
{
    char id[Max];
    printf ("Input employee's ID: ");
    scanf ("%s", id);
    int count = 0;
    for (int i=0; i<employee_amount; i++){
        if (strcmp(emp[i].id, id)==0) {
            printf("Input new salary: ");
            scanf("%lf", &emp[i].salary);
            printf("Change employee's salary successfully!\n");
            // printf ("%.2lf", emp[i].salary); CheckingFunction
            count++;
            return;
        } 
    } 
    if (count == 0) printf ("Can not find the employee"); 
}

//Function 3: Sua ho ten nhan vien
void change_name (int employee_amount)
{
    char id[Max];
    printf ("Input employee's ID: ");
    scanf ("%s", id);
    int count = 0;
    for (int i=0; i<employee_amount; i++){
        if (strcmp(emp[i].id, id)==0) {
            //Doi ten
            printf ("Input new first name: ");
            scanf ("%s", emp[i].firstName);
            printf ("Change fisrt name successfully!\n");
            //Doi ho
            printf ("Input new last name: ");
            scanf ("%s", emp[i].lastName);
            printf ("Change last name successfully!\n");
            //printf ("%s %s", emp[i].firstName, emp[i].lastName); Checking
            count++;
            return;
        }  
    } 
    if (count == 0) printf ("Can not find the employee");
}

//Function 4: Xoa nhan vien
void delete_emp (int employee_amount)
{
    char id[Max];
    printf ("Input employee's ID: ");
    scanf ("%s", id);
    
    int count=0;//neu khac ko -> tim duoc ma nhan vien
    for (int i=0; i<employee_amount; i++){
        if (strcmp(emp[i].id, id)==0) {
            for (int j=i; j<employee_amount; j++){
                emp[j] = emp[j+1];
            }
            employee_amount-=1;
            count++;
            return;
        } 
    }
	if (count == 0) printf ("Can not find the employee");  
}

//Function7: xuat tat ca NhanVien
void printAll_emp (int employee_amount)
{
    for (int i=0; i<employee_amount; i++){
        printf ("The No.%d Employee ID: ", i+1);
        printf ("%s\n", emp[i].id);
        
        printf ("The No.%d Employee's last name: ", i+1);
        printf ("%s\n", emp[i].lastName);
        
        printf ("The No.%d Employee's first name: ", i+1);
        printf ("%s\n", emp[i].firstName);
        
        printf ("The No.%d Employee's gender (Male or Female): ", i+1);
        printf ("%s\n", emp[i].gender);
        
        printf ("The No.%d Employee's salary: ", i+1);
        printf ("%.2lf\n", emp[i].salary);
        printf ("\n");
    }
}