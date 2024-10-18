#include <stdio.h>

#define MAX_SUBJECTS 5
#define MAX_QUIZZES 5
#define MAX_ASSIGNMENTS 5
#define MAX_ID_LENGTH 20 // Adjusted length for alphanumeric ID

typedef struct {
    char name[50];
    char id[MAX_ID_LENGTH]; // Alphanumeric ID
    char branch[50];
    int semester;
    float scores[MAX_QUIZZES + MAX_ASSIGNMENTS + 1]; // Last index for midterm
} Student;

void inputStudentDetails(Student *student) {
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student->name);
    
    printf("Enter Student ID (alphanumeric): ");
    scanf(" %[^\n]", student->id); // Read alphanumeric ID

    printf("Enter Branch: ");
    scanf(" %[^\n]", student->branch);
    
    printf("Enter Semester (1-8): ");
    scanf("%d", &student->semester);
}

void calculateGrade(Student *student) {
    float total = 0;
    int quizzes, assignments;

    printf("Enter number of quizzes (up to %d): ", MAX_QUIZZES);
    scanf("%d", &quizzes);
    if (quizzes > MAX_QUIZZES) {
        printf("Number of quizzes cannot exceed %d.\n", MAX_QUIZZES);
        return;
    }

    for (int i = 0; i < quizzes; i++) {
        printf("Enter scores for Quiz %d (up to 5.00): ", i + 1);
        scanf("%f", &student->scores[i]);
        total += student->scores[i];
    }

    printf("Enter number of assignments (up to %d): ", MAX_ASSIGNMENTS);
    scanf("%d", &assignments);
    if (assignments > MAX_ASSIGNMENTS) {
        printf("Number of assignments cannot exceed %d.\n", MAX_ASSIGNMENTS);
        return;
    }

    for (int i = 0; i < assignments; i++) {
        printf("Enter scores for Assignment %d (up to 5.00): ", i + 1);
        scanf("%f", &student->scores[quizzes + i]);
        total += student->scores[quizzes + i];
    }

    float midTermMarks;
    printf("Enter Mid-term Marks (out of 30): ");
    scanf("%f", &midTermMarks);
    
    // Validate mid-term marks
    if (midTermMarks < 0 || midTermMarks > 30) {
        printf("Error: Mid-term marks must be between 0 and 30.\n");
        return;
    }

    student->scores[quizzes + assignments] = midTermMarks;
    total += midTermMarks;

    float percentage = (total / 70) * 100; // Total of quizzes, assignments, and mid-term

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
    printf("ID: %s\n", student.id); // Displaying alphanumeric ID
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
