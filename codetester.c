#include <stdio.h>
void swap(int *a, int *b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main() {
    int num1,num2;
    printf("Enter number 1: ");
    scanf("%d",&num1);
    printf("Enter number 2: ");
    scanf("%d",&num2);
    
    swap(&num1,&num2);

    printf("After swapping value of num1=%d and value of num2 =%d\n",num1,num2);
    return 0;
}