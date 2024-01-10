#include <stdio.h>
#include <stdlib.h>

int SumOfDigits(int num){
    int lastDigit, remainingNum, sum = 0;
    if(num == 0)
        return 0;
    lastDigit = num % 10;
    remainingNum = num / 10;
    sum = lastDigit + SumOfDigits(remainingNum);
    return sum;
}

int main(){
    int num, result, flag=0;
    printf("Enter you number: ");
    scanf("%d",&num);
    result = SumOfDigits(num);
    if(result%2 == 0)
        flag = 1;
    else if(result%2 != 0)
        flag = 0;
    printf("%d",flag);

    return 0;
}