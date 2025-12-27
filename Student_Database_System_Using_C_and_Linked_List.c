/*
------------------------------------------------------------
Student Database System using Linked List (C)
Mini Project – Beginner Friendly (3–4 months C learner)
------------------------------------------------------------
Features:
1. Add student
2. Display all students
3. Search student by roll number
4. Update student details
5. Delete student
6. Count total students
7. Exit
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- STRUCTURE DEFINITION ---------- */
struct student {
    int roll;
    char name[50];
    float marks;
    struct student *next;
};

struct student *head = NULL;

/* ---------- FUNCTION DECLARATIONS ---------- */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
int countStudents();

/* ---------- MAIN FUNCTION ---------- */
int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf(" STUDENT DATABASE SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Count Students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Total Students: %d\n", countStudents()); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

/* ---------- ADD STUDENT ---------- */
void addStudent() {
    struct student *newNode, *temp;

    newNode = (struct student *)malloc(sizeof(struct student));

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Student added successfully.\n");
}

/* ---------- DISPLAY STUDENTS ---------- */
void displayStudents() {
    struct student *temp;

    if (head == NULL) {
        printf("No students found.\n");
        return;
    }

    temp = head;
    printf("\nROLL\tNAME\tMARKS\n");
    printf("--------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

/* ---------- SEARCH STUDENT ---------- */
void searchStudent() {
    int roll;
    struct student *temp = head;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Student Found:\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\n",
                   temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");
}

/* ---------- UPDATE STUDENT ---------- */
void updateStudent() {
    int roll;
    struct student *temp = head;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new marks: ");
            scanf("%f", &temp->marks);
            printf("Student updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");
}

/* ---------- DELETE STUDENT ---------- */
void deleteStudent() {
    int roll;
    struct student *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    if (head->roll == roll) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student deleted successfully.\n");
}

/* ---------- COUNT STUDENTS ---------- */
int countStudents() {
    int count = 0;
    struct student *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
