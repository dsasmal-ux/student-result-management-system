#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

struct Student s[MAX];
int count = 0;

/* Calculate result */
void calculateResult(struct Student *st) {
    int i;
    st->total = 0;

    for (i = 0; i < 5; i++)
        st->total += st->marks[i];

    st->percentage = st->total / 5.0;

    if (st->percentage >= 90)
        st->grade = 'A';
    else if (st->percentage >= 80)
        st->grade = 'B';
    else if (st->percentage >= 70)
        st->grade = 'C';
    else if (st->percentage >= 60)
        st->grade = 'D';
    else if (st->percentage >= 50)
        st->grade = 'E';
    else
        st->grade = 'F';
}

/* Add student */
void addStudent() {
    int i;

    if (count >= MAX) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].rollNo);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter marks for 5 subjects:\n");

    for (i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s[count].marks[i]);
    }

    calculateResult(&s[count]);

    count++;

    printf("\nStudent added successfully!\n");
}

/* Display all students */
void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n================ STUDENT RESULTS ================\n");

    printf("%-8s %-20s %-10s %-12s %-8s\n",
           "Roll", "Name", "Total", "Percentage", "Grade");

    printf("--------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-8d %-20s %-10.2f %-12.2f %-8c\n",
               s[i].rollNo,
               s[i].name,
               s[i].total,
               s[i].percentage,
               s[i].grade);
    }
}

/* Search student */
void searchStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", s[i].rollNo);
            printf("Name        : %s\n", s[i].name);
            printf("Total Marks : %.2f\n", s[i].total);
            printf("Percentage  : %.2f%%\n", s[i].percentage);
            printf("Grade       : %c\n", s[i].grade);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

/* Update student */
void updateStudent() {
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter New Marks:\n");

            for (j = 0; j < 5; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &s[i].marks[j]);
            }

            calculateResult(&s[i]);

            printf("\nStudent record updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

/* Delete student */
void deleteStudent() {
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {

            for (j = i; j < count - 1; j++)
                s[j] = s[j + 1];

            count--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

/* Find topper */
void findTopper() {
    int i, topper;

    if (count == 0) {
        printf("\nNo student records available!\n");
        return;
    }

    topper = 0;

    for (i = 1; i < count; i++) {
        if (s[i].percentage > s[topper].percentage)
            topper = i;
    }

    printf("\n================ TOPPER ================\n");
    printf("Roll Number : %d\n", s[topper].rollNo);
    printf("Name        : %s\n", s[topper].name);
    printf("Total Marks : %.2f\n", s[topper].total);
    printf("Percentage  : %.2f%%\n", s[topper].percentage);
    printf("Grade       : %c\n", s[topper].grade);
}

/* Main function */
int main() {
    int choice;

    do {
        printf("\n\n============================================");
        printf("\n     STUDENT RESULT MANAGEMENT SYSTEM");
        printf("\n============================================");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Find Topper");
        printf("\n7. Exit");

        printf("\n============================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                findTopper();
                break;

            case 7:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
