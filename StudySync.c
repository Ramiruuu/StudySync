#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_NAME_LENGTH 50

// Structure to hold subject data
struct Subject {
    char name[MAX_NAME_LENGTH];
    float grade;
    int study_hours;
};

int main() {
    int num_subjects, i;
    struct Subject subjects[MAX_SUBJECTS];
    float total_grade = 0.0, average_grade;
    int total_study_hours = 0;

    // Input number of subjects
    printf("Welcome to the USTP Student Grade & Study Planner!\n");
    printf("How many subjects are you taking (max %d)? ", MAX_SUBJECTS);
    scanf("%d", &num_subjects);
    
    if (num_subjects <= 0 || num_subjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects. Please enter between 1 and %d.\n", MAX_SUBJECTS);
        return 1;
    }

    // Clear input buffer
    while (getchar() != '\n');

    // Input subject details
    for (i = 0; i < num_subjects; i++) {
        printf("\nSubject %d:\n", i + 1);
        printf("Enter subject name: ");
        fgets(subjects[i].name, MAX_NAME_LENGTH, stdin);
        subjects[i].name[strcspn(subjects[i].name, "\n")] = 0; // Remove newline

        printf("Enter your grade (0-100): ");
        scanf("%f", &subjects[i].grade);
        while (subjects[i].grade < 0 || subjects[i].grade > 100) {
            printf("Invalid grade! Enter a value between 0 and 100: ");
            scanf("%f", &subjects[i].grade);
        }

        printf("Enter planned study hours per week: ");
        scanf("%d", &subjects[i].study_hours);
        while (subjects[i].study_hours < 0) {
            printf("Invalid hours! Enter a positive number: ");
            scanf("%d", &subjects[i].study_hours);
        }

        total_grade += subjects[i].grade;
        total_study_hours += subjects[i].study_hours;
        while (getchar() != '\n'); // Clear buffer
    }

    // Calculate average grade
    average_grade = total_grade / num_subjects;

    // Display results
    printf("\n=== Your Summary ===\n");
    printf("Subject\t\tGrade\tStudy Hours\n");
    printf("------------------------------------\n");
    for (i = 0; i < num_subjects; i++) {
        printf("%-15s\t%.2f\t%d\n", subjects[i].name, subjects[i].grade, subjects[i].study_hours);
    }
    printf("------------------------------------\n");
    printf("Average Grade: %.2f\n", average_grade);
    printf("Total Study Hours per Week: %d\n", total_study_hours);

    // Basic advice based on average grade
    if (average_grade >= 85) {
        printf("Great job! Keep up the good work.\n");
    } else if (average_grade >= 75) {
        printf("You're doing okay! Consider adding %d more study hours weekly.\n", num_subjects * 2);
    } else {
        printf("You might need help! Try increasing study time by %d hours and seeking tutoring.\n", num_subjects * 3);
    }

    return 0;
}
