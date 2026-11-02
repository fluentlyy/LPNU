#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 4
#define NAME_LENGTH 50

int main(){

    FILE *pFstudents;

    int studentNumbers[MAX_STUDENTS];
    char surnames[MAX_STUDENTS][NAME_LENGTH];
    char names[MAX_STUDENTS][NAME_LENGTH];
    int programmingGrades[MAX_STUDENTS];
    int linearAlgebraGrades[MAX_STUDENTS];
    int englishGrades[MAX_STUDENTS];
    int kdmGrades[MAX_STUDENTS];
    double averageGrades[MAX_STUDENTS];

    pFstudents = fopen("students.txt", "r");

    int count = 0;
    char buffer[256];

    while(count < MAX_STUDENTS && fgets(buffer, sizeof(buffer), pFstudents) != NULL){
        if(sscanf(buffer, "%d %s %s %d %d %d %d", studentNumbers + count, surnames[count], names[count], programmingGrades + count, linearAlgebraGrades + count,
        englishGrades + count, kdmGrades + count) == 7){
            count++;
        }
    }

    fclose(pFstudents);

    double averageGroup = 0;
    double averageGroupSum = 0;

    int bestGradStudent = 0;
    int worstGradStudent = 0;
    for(int i = 0; i < count; i++){
        averageGrades[i] = (programmingGrades[i] + linearAlgebraGrades[i] + englishGrades[i] + kdmGrades[i]) / 4.0;
        averageGroupSum += averageGrades[i];
        averageGroup = averageGroupSum / (double)count;

        if(averageGrades[bestGradStudent] < averageGrades[i]){
            bestGradStudent = i;
        }
        if(averageGrades[worstGradStudent] > averageGrades[i]){
            worstGradStudent = i;
        }
    }

    for(int i = 0; i < count; i++){
        printf("%d %s %s %d %d %d %d average grade: %lf\n", studentNumbers[i], surnames[i], names[i], programmingGrades[i], linearAlgebraGrades[i], englishGrades[i], kdmGrades[i], averageGrades[i]);
    }
    printf("Group average grade: %lf\n", averageGroup);
    printf("Best graduate result has %s %s with average %lf\n", surnames[bestGradStudent], names[bestGradStudent], averageGrades[bestGradStudent]);
    printf("Worst graduate student has %s %s with average %lf", surnames[worstGradStudent], names[worstGradStudent], averageGrades[worstGradStudent]);


    return 0;
}