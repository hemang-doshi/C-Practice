#include <stdio.h>
#include <stdlib.h>

struct rational{    
    int numerator;
    int denominator;
};
struct rational addition(struct rational num1, struct rational num2){
    
    /*In your code, struct rational is a user-defined data type representing a rational number.
    By specifying struct rational before the function name addition,
    you are explicitly indicating that the function addition returns
    a value of type struct rational.*/

    struct rational result;
    result.numerator = num1.numerator*num2.denominator + num2.numerator*num1.denominator;
    result.denominator = num1.denominator*num2.denominator;

    return result;
}

int main(){
    struct rational num1,num2,result;

    printf("Enter the numerator and denominator of the rational num1: ");
    scanf("%d%d",&num1.numerator,&num1.denominator);

    printf("Enter the numerator and denominator of the rational num2: ");
    scanf("%d%d",&num2.numerator,&num2.denominator);

    result = addition(num1,num2);

    printf("The sum of num1 and num2 is: %d/%d\n",result.numerator,result.denominator);

    //code ends here
    return 0;
}