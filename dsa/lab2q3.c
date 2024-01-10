#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    char name[30];
    char dob; //    dd/mm/yyyy    //
    char address[100];
};

int main(){
    int n,i,j;
    struct employee *p;
    struct employee *e;
    printf("Enter the number of employees: \n");
    scanf("%d",&n);
    e = (struct employee *)calloc(n,sizeof(struct employee));
    p=e;
    for(i=0;i<n;i++){
        printf("Enter name, dob(ddmmyyyy), address of %d employee: \n",i+1);
        gets(p -> name);
        gets(p -> dob);
        printf("Enter address(house number, zip code, state) of %d employee: \n",i+1);
        gets(p -> address);
    }
    printf("The details of your employees are: \n");
    for(i=0;i<n;i++){
        puts(p -> name);
        puts(p -> dob);
        printf("Enter address(house number, zip code, state) of %d employee: \n",i+1);
        puts(p -> address);
    }
    return 0;
}