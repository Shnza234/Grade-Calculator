#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 12
#define MAX_LENGTH 100

// Structure for entry of data
struct Module_Percentage 
{
    char module[MAX_LENGTH];
    float percent;
    int credits;
};

// Function to enter all module names and percentages
void enterFunc(struct Module_Percentage modules[], int count) 
{
    for (int i = 0; i < count; i++) {
        printf("Please enter the module name: ");
        fgets(modules[i].module, MAX_LENGTH, stdin);
        modules[i].module[strcspn(modules[i].module, "\n")] = '\0';

        printf("Please enter what percent you got in the module: ");
        scanf("%f", &modules[i].percent);
        getchar(); // Clear newline

        printf("Please enter what credits this module has: ");
        scanf("%d", &modules[i].credits);
        getchar(); // Clear newline
    }
}

void gpaCalculations(struct Module_Percentage modules[], int count) 
{
    float totalPercent = 0, min = 100, max = 0;
    int totalCredits = 0;
    float weightedSum = 0;

    for (int i = 0; i < count; i++) 
    {
        totalPercent += modules[i].percent;

        if (modules[i].percent < min) min = modules[i].percent;
        if (modules[i].percent > max) max = modules[i].percent;

        weightedSum += modules[i].percent * modules[i].credits;
        totalCredits += modules[i].credits;
    }

    float avg = totalPercent / count;
    float gpa = weightedSum / totalCredits;

    printf("\nSummary:\n");
    printf("Average Percentage: %.2f%%\n", avg);
    printf("Highest Percentage: %.2f%%\n", max);
    printf("Lowest Percentage: %.2f%%\n", min);
    printf("Weighted GPA: %.2f%%\n", gpa);
}

// Function to find out how many modules they did
void ModuleNo() 
{
    int moduleNo;
    struct Module_Percentage modules[MAX_ENTRIES];

    printf("Please enter how many modules you did: ");
    scanf("%d", &moduleNo);
    getchar(); // Clear newline

    if (moduleNo > 0 && moduleNo <= MAX_ENTRIES) 
    {
        enterFunc(modules, moduleNo);
        gpaCalculations(modules, moduleNo);
    }
 
}

int main() 
{
    ModuleNo();
    return 0;
}
