#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define Max 50

struct employee
{
    char id[Max];
    double salary;
    char gender[Max];
    char firstName[Max];
    char lastName[Max];
};

struct employee emp[100];

// Function define:
int menu();
void take_data();
void change_salary();
void change_name();
void delete_emp();
void salaryDecreaseSorting();
void nameIncreaseSorting();
void printAll_emp();
void idExport();
void salaryRangeExport();
void optionalExport();

// MAIN
int main()
{
    int employee_amount = 0;
    int *emp_amount = &employee_amount;

    int userChoice;
    do
    {
        if (employee_amount == 0)
        {
            printf("\nThere aren't any informations yet. Please choose '1' options to add more.");
        }
        userChoice = menu();
        switch (userChoice)
        {
        case 1:
            take_data(*emp_amount, &employee_amount);
            break;
        case 2:
            change_salary(employee_amount);
            break;
        case 3:
            change_name(employee_amount);
            break;
        case 4:
            delete_emp(*emp_amount, &employee_amount);
            break;
        case 5:
            salaryDecreaseSorting(employee_amount);
            printf("The data has done sorted!");
            break;
        case 6:
            nameIncreaseSorting(employee_amount);
            printf("The data has done sorted!");
            break;
        case 7:
            printAll_emp(employee_amount);
            break;
        case 8:
            idExport(employee_amount);
            break;
        case 9:
            salaryRangeExport(employee_amount);
            break;
        case 10:
            optionalExport(employee_amount);
            break;

        case 11:
            printf("Programm exited.");
            break;

        default:
            printf("Invalid Choice. Choose again!\n");
            break;
        }
        if(userChoice == 11){
            return 0;
        }
        char lastDecision;
        printf("Do you want to countinue: Y/N");
        scanf(" %c", &lastDecision);
        if (lastDecision == 'Y'||lastDecision=='y')
        {
            continue;
        }
        else if (lastDecision == 'N'||lastDecision=='n')
        {
            printf("Programm exited.");
            break;
        }
        else
        {
            printf("Invalid input. Program's forced to out!");
            return 0;
        }

    } while (userChoice != 11);
}

// Functions below://
// Menu:
int menu()
{
    printf("\nMENU\n");
    printf("1. Add employee data.\n");
    printf("2. Change employee salary.\n");
    printf("3. Change employee name.\n");
    printf("4. Delete employee data.\n");
    printf("5. Sorting the data by salary descend.\n");
    printf("6. Sorting the data by name increase.\n");
    printf("7. Export all employee data.\n");
    printf("8. Export employee's information with ID.\n");
    printf("9. Export employee's data in a salary range.\n");
    printf("10. Show the average salary,the highest salary and the lowest salary.\n");
    printf("11. Quit.\n");
    printf("Your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function1: Nhap thong tin nhan vien
void take_data(int emp_amount, int *employee_amount)
{
    int cur;
    do
    {
        printf("The amount of employee you want to add: ");
        scanf("%d", &cur);
    } while (cur < 0);
    int i = emp_amount;
    for (i; i < emp_amount + cur; i++)
    {
        printf("Input the No.%d Employee ID: ", i + 1);
        scanf("%s", emp[i].id);

        printf("Input the No.%d Employee's first name: ", i + 1);
        scanf("%s", emp[i].firstName);

        printf("Input the No.%d Employee's last name: ", i + 1);
        scanf("%s", emp[i].lastName);

        printf("Input the No.%d Employee's gender (Male or Female): ", i + 1);
        scanf("%s", emp[i].gender);

        printf("Input the No.%d Employee's salary: ", i + 1);
        scanf("%lf", &emp[i].salary);
        printf("\n");
    }
    *employee_amount = emp_amount + cur;
}

// Funtion2: Sua thong tin luong
void change_salary(int employee_amount)
{
    char id[Max];
    printf("Input employee's ID: ");
    scanf("%s", id);
    int count = 0;
    for (int i = 0; i < employee_amount; i++)
    {
        if (strcmp(emp[i].id, id) == 0)
        {
            printf("Input new salary: ");
            scanf("%lf", &emp[i].salary);
            printf("Change employee's salary successfully!\n");
            // printf ("%.2lf", emp[i].salary); CheckingFunction
            count++;
            return;
        }
    }
    if (count == 0)
        printf("Can not find the employee");
}

// Function 3: Sua ho ten nhan vien
void change_name(int employee_amount)
{
    char id[Max];
    printf("Input employee's ID: ");
    scanf("%s", id);
    int count = 0;
    for (int i = 0; i < employee_amount; i++)
    {
        if (strcmp(emp[i].id, id) == 0)
        {
            // Doi ten
            printf("Input new first name: ");
            scanf("%s", emp[i].firstName);
            printf("Change fisrt name successfully!\n");
            // Doi ho
            printf("Input new last name: ");
            scanf("%s", emp[i].lastName);
            printf("Change last name successfully!\n");
            // printf ("%s %s", emp[i].firstName, emp[i].lastName); Checking
            count++;
            return;
        }
    }
    if (count == 0)
        printf("Can not find the employee");
}

// Function 4: Xoa nhan vien
void delete_emp(int emp_amount, int *employee_amount)
{
    char id[Max];
    printf("Input employee's ID: ");
    scanf("%s", id);

    int count = 0; // neu khac ko -> tim duoc ma nhan vien
    for (int i = 0; i < emp_amount; i++)
    {
        if (strcmp(emp[i].id, id) == 0)
        {
            for (int j = i; j < emp_amount; j++)
            {
                emp[j] = emp[j + 1];
            }
            *employee_amount -= 1;
            count++;
            return;
        }
    }
    if (count == 0)
        printf("Can not find the employee.");
}

// Function 5: Sắp xếp danh sách giảm dần theo Lương
void salaryDecreaseSorting(int employee_amount)
{
    int i, count = 0;
    int temp = Max + 1;
    for (i = 0; i < employee_amount; i++)
    {
        if (emp[i].salary < emp[i + 1].salary)
        {
            emp[temp] = emp[i];
            emp[i] = emp[i + 1];
            emp[i + 1] = emp[temp];
            count++;
        }
    }
    if (count != 0)
    {
        salaryDecreaseSorting(employee_amount);
    }
}

// Function 6: Sắp xếp danh sách tăng dần theo Tên nhân viên
void nameIncreaseSorting(int employee_amount)
{
    char temp = Max + 1;
    int i, j;
    for (i = 0; i < employee_amount; i++)
    {
        for (j = i + 1; j < employee_amount; j++)
        {
            if (strcmp(emp[i].firstName, emp[j].firstName) > 0)
            {
                emp[temp] = emp[i];
                emp[i] = emp[j];
                emp[j] = emp[temp];
            }
        }
    }
}

// Function7: xuat tat ca Nhan Vien
void printAll_emp(int employee_amount)
{
    for (int i = 0; i < employee_amount; i++)
    {
        printf("The No.%d Employee ID: ", i + 1);
        printf("%s\n", emp[i].id);

        printf("The No.%d Employee's first name: ", i + 1);
        printf("%s\n", emp[i].firstName);

        printf("The No.%d Employee's last name: ", i + 1);
        printf("%s\n", emp[i].lastName);

        printf("The No.%d Employee's gender (Male or Female): ", i + 1);
        printf("%s\n", emp[i].gender);

        printf("The No.%d Employee's salary: ", i + 1);
        printf("%.2lf\n", emp[i].salary);
        printf("\n");
    }
}

// Function 8: Xuất danh sách theo Mã nhân viên
void idExport(int employee_amount)
{
    char userInput[Max];
    printf("Input the employee's ID you want to find: ");
    scanf("%s", &userInput);
    int i;
    for (i = 0; i < employee_amount; i++)
    {
        if (strcmp(emp[i].id, userInput) == 0)
        {
            printf("The No.%d Employee ID: ", i + 1);
            printf("%s\n", emp[i].id);

            printf("The No.%d Employee's last name: ", i + 1);
            printf("%s\n", emp[i].lastName);

            printf("The No.%d Employee's first name: ", i + 1);
            printf("%s\n", emp[i].firstName);

            printf("The No.%d Employee's gender (Male or Female): ", i + 1);
            printf("%s\n", emp[i].gender);

            printf("The No.%d Employee's salary: ", i + 1);
            printf("%.2lf\n", emp[i].salary);
            printf("\n");
        }
    }
}

// Function 9: Xuất danh sách theo Lương trong khoảng nào đó
void salaryRangeExport(int employee_amount)
{
    int i;
    double userInputStart, userInputEnd;

    printf("Input the begin: ");
    scanf("%lf", &userInputStart);
    printf("Input the end: ");
    scanf("%lf", &userInputEnd);
    printf("\n");

    for (i = 0; i < employee_amount; i++)
    {
        if (emp[i].salary >= userInputStart && emp[i].salary <= userInputEnd)
        {
            printf("The No.%d Employee ID: ", i + 1);
            printf("%s\n", emp[i].id);

            printf("The No.%d Employee's last name: ", i + 1);
            printf("%s\n", emp[i].lastName);

            printf("The No.%d Employee's first name: ", i + 1);
            printf("%s\n", emp[i].firstName);

            printf("The No.%d Employee's gender (Male or Female): ", i + 1);
            printf("%s\n", emp[i].gender);

            printf("The No.%d Employee's salary: ", i + 1);
            printf("%.2lf\n", emp[i].salary);
            printf("\n");
        }
    }
}

// Function 10: Xuất Lương trung bình, Lương cao nhất, Lương thấp nhất
void optionalExport(int employee_amount)
{
    int i, userInput;
    double avg, lws, hgs;
    printf("\nCHOOSE THE OPTION YOU WANT:\n");
    printf("1. Export average salary\n");
    printf("2. Export lowese salary.\n");
    printf("3. Export highest salary.\n");

    scanf("%d", &userInput);
    switch (userInput)
    {
    case 1:
        for (i = 0; i < employee_amount; i++)
        {
            avg += emp[i].salary;
        }
        printf("The average salary: %lf", avg / employee_amount);
        break;
    case 2:
        lws = emp[0].salary;
        for (i = 0; i < employee_amount; i++)
        {
            if (lws > emp[i].salary)
            {
                lws = emp[i].salary;
            }
        }
        printf("The lowest salary: %lf", lws);
    case 3:
        hgs = emp[0].salary;
        for (i = 0; i < employee_amount; i++)
        {
            if (lws < emp[i].salary)
            {
                lws = emp[i].salary;
            }
        }
        printf("The highest salary: %lf", hgs);
    default:
        printf("Invalid Choice. Choose again!\n");
        break;
    }
};
