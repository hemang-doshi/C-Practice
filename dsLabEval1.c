#include <stdio.h>
#include <stdlib.h>

// Substructures
struct DOB {
    int day;
    int *month;
    int year;
};

struct STU_INFO {
    int reg_no;
    char *name;
    char *address;
};

struct COLLEGE {
    char *college_name;
    char *university_name;
};

// Main structure
struct STUDENT {
    struct DOB dob;
    struct STU_INFO stu_info;
    struct COLLEGE college;
};

int main() {
    // Allocate memory for substructures' pointers
    int month;
    char name[50], address[100], college_name[100], university_name[100];

    // Initialize substructures
    struct DOB dob;
    dob.month = &month;
    
    struct STU_INFO stu_info;
    stu_info.name = name;
    stu_info.address = address;

    struct COLLEGE college;
    college.college_name = college_name;
    college.university_name = university_name;

    // Initialize main structure
    struct STUDENT student;
    student.dob = dob;
    student.stu_info = stu_info;
    student.college = college;

    // Read input from user
    printf("Enter student's date of birth (day month year): ");
    scanf("%d %d %d", &student.dob.day, student.dob.month, &student.dob.year);
    printf("Enter student's registration number: ");
    scanf("%d", &student.stu_info.reg_no);
    printf("Enter student's name: ");
    scanf("%s", student.stu_info.name);
    printf("Enter student's address: ");
    scanf("%s", student.stu_info.address);
    printf("Enter college name: ");
    scanf("%s", student.college.college_name);
    printf("Enter university name: ");
    scanf("%s", student.college.university_name);

    // Display the input
    printf("\nStudent Information:\n");
    printf("Date of Birth: %d %d %d\n", student.dob.day, *student.dob.month, student.dob.year);
    printf("Registration Number: %d\n", student.stu_info.reg_no);
    printf("Name: %s\n", student.stu_info.name);
    printf("Address: %s\n", student.stu_info.address);
    printf("College Name: %s\n", student.college.college_name);
    printf("University Name: %s\n", student.college.university_name);

    return 0;
}
