# Grade Book Application

## Problem Statement
Managing student grades across various subjects can be cumbersome for both students and educators. An efficient system is needed to input, calculate, and display grades for quizzes, assignments, and mid-term exams.

## Proposed Solution
Create a console application that allows users to:
- Input student details (name, ID, branch, semester).
- Ask for the number of subjects, quizzes, and assignments (limited to 5 each).
- Collect scores for quizzes, assignments, and mid-term marks.
- Calculate total scores and assign grades based on predefined criteria.

## Code Structure
- `main.c`: Contains the main logic of the application.
- Functions:
  - `inputStudentDetails()`: To input student information.
  - `calculateGrade()`: To calculate the total score and determine the grade.
  - `displayResult()`: To display the final results.

## How to Run
1. Compile the code using a C compiler (e.g., `gcc main.c -o GradeBook`).
2. Run the application (`./GradeBook`).

## Test Case Screenshots

1. **Test Case 1: Valid Inputs**
   ![Test Case 1](Images/Test_1_Valid_Input.png)

2. **Test Case 2: Quiz Limit Exceeded**
   ![Test Case 2](Images/Test_2_Exceed_Quiz_Limit.png)

3. **Test Case 3: Assignment Limit Exceeded**
   ![Test Case 3](Images/Test_3_Exceed_Assignment_Limit.png)
   
4. **Test Case 4: All Zero Inputs**
   ![Test Case 1](Images/Test_4_All_Zero_Inputs.png)

5. **Test Case 5: Perfect Score Input**
   ![Test Case 2](Images/Test_5_Perfect_Scores.png)

6. **Test Case 6: Edge Grade Calculation**
   ![Test Case 3](Images/Test_6_Edge_Grade.png)

7. **Test Case 7: Mid Marks Limit Exceeded**
   ![Test Case 3](Images/Test_7_Mid_Marks_Exceed_Limit.png)


## Conclusion
This Grade Book application effectively simplifies the process of managing student grades by allowing easy input and calculation of scores across multiple assessments. It provides instant feedback on student performance, helping educators and students alike to monitor academic progress.
