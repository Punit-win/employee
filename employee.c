#include <stdio.h>

// Define the Employee structure
struct Employee {
    int Empno;
    char EmpName[100]; 
    struct Date {
        int dd, mm, yy;
    } hiredate;
    float BasicSalary;
    float NetSalary;
};

// Function to calculate net pay
void calculateNetPay(struct Employee *emp) {
    // Calculate DA, TA, and PF based on percentages
    float DA = 0.40 * emp->BasicSalary;
    float TA = 0.10 * emp->BasicSalary;
    float PF = 0.05 * emp->BasicSalary;

    // Calculate Net Salary
    emp->NetSalary = emp->BasicSalary + DA + TA - PF;
}

// Function to accept employee data
void acceptEmployeeData(struct Employee *emp) {
    printf("Enter Employee Number: ");
    scanf("%d", &emp->Empno);

    printf("Enter Employee Name: ");
    scanf("%s", emp->EmpName); // Assuming no spaces in the name

    printf("Enter Hire Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp->BasicSalary);
}

// Function to display employee data
void showEmployeeData(struct Employee *emp) {
    printf("\nEmployee Number: %d\n", emp->Empno);
    printf("Employee Name: %s\n", emp->EmpName);
    printf("Hire Date: %d/%d/%d\n", emp->hiredate.dd, emp->hiredate.mm, emp->hiredate.yy);
    printf("Basic Salary: %.2f\n", emp->BasicSalary);
    printf("Net Salary: %.2f\n", emp->NetSalary);
}

int main() {
    struct Employee emp;

    // Accept employee data
    acceptEmployeeData(&emp);

    // Calculate net pay
    calculateNetPay(&emp);

    // Display employee data
    showEmployeeData(&emp);

    return 0;
}