#include <stdio.h>

#include <string.h>

 

int main(void) {

 

struct employees { // create a structure

char name[100]; // structure variable declaration

char dob[20]; // structure variable declaration

char add[200]; // structure variable declaration

};

int N; // variable declaration

 

printf("Enter number of employees you want to insert: ");

scanf("%d",&N); // Accept number of employees

 

struct employees emp[N]; // create structure array

struct employees *ptr = NULL; // create a pointer variable

 

ptr = emp; // Assign ptr with structure array

for (int i = 0; i < N; i++) { // Loop to accept employees

printf("\nEnter detail of employee %d:\n", (i + 1));

printf("Enter Name: ");

gets(ptr->name); // Accept name

 

printf("Enter Date Of Birth: ");

gets(ptr->dob); // Accept date of Birth of employee

 

printf("Enter add: ");

gets(ptr->add); // Accept adress of employee

 

ptr++; // Increment pointer

}

ptr = emp; // Restore the original position of the pointer

for (int i = 0; i < N; i++) { // Loop to print employee details

printf("\nDetails of employee %d:\n", (i + 1));

printf("Name: %s\n", ptr->name); // print name of employee

printf("Date Of Birth: %s\n", ptr->dob); // print date of birth of employee

printf("Adress: %s\n", ptr->add); // print address of employee

ptr++; // Increment pointer

}

return 0;

}