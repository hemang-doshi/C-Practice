#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int num){
    int lastDigit,remainingNum,sum=0;
    if(num == 0)
        return 0;
    lastDigit = num % 10;
    remainingNum = num/10;

    sum = lastDigit + sumOfDigits(remainingNum);
    return sum;
}

int main(){
    int num,result;
    printf("Enter your number: ");
    scanf("%d",&num);
    result = sumOfDigits(num);
    printf("Your result is: %d\n",result);

    return 0;
}