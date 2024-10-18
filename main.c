#include <stdio.h>

#define MAX_SUBJECTS 5
#define QUIZZES 5
#define ASSIGNMENTS 5

typedef struct {
    char name[50];
    int id;
    char branch[50];
    int semester;
    float scores[QUIZZES + ASSIGNMENTS + 1]; // Last index for midterm
} Student;

void inputStudentDetails(Student *student) {
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student->name);
    printf("Enter Student ID: ");
    scanf("%d", &student->id);
    printf("Enter Branch: ");
    scanf(" %[^\n]", student->branch);
    printf("Enter Semester: ");
    scanf("%d", &student->semester);
}

void calculateGrade(Student *student) {
    float total = 0;
    int quizzes, assignments;

    printf("Enter number of subjects: ");
    scanf("%d", &quizzes);
    
    for (int i = 0; i < quizzes; i++) {
        printf("Enter scores for Quiz %d: ", i + 1);
        scanf("%f", &student->scores[i]);
        total += student->scores[i];
    }

    printf("Enter number of assignments: ");
    scanf("%d", &assignments);
    
    for (int i = 0; i < assignments; i++) {
        printf("Enter scores for Assignment %d: ", i + 1);
        scanf("%f", &student->scores[quizzes + i]);
        total += student->scores[quizzes + i];
    }

    printf("Enter Mid-term Marks: ");
    scanf("%f", &student->scores[quizzes + assignments]);
    total += student->scores[quizzes + assignments];

    float percentage = (total / 70) * 100;

    char grade;
    if (percentage >= 70) grade = 'A';
    else if (percentage >= 60) grade = 'B';
    else if (percentage >= 50) grade = 'C';
    else if (percentage >= 40) grade = 'S';
    else if (percentage >= 30) grade = 'U';
    else grade = 'F';

    printf("Total Marks: %.2f\n", total);
    printf("Grade: %c\n", grade);
}

void displayResult(Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Branch: %s\n", student.branch);
    printf("Semester: %d\n", student.semester);
}

int main() {
    Student student;
    inputStudentDetails(&student);
    calculateGrade(&student);
    displayResult(student);
    
    return 0;
}
