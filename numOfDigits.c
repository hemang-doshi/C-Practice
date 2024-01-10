#include <stdio.h>
#include <stdlib.h>

int numOfDigits(int num){
    int count=0, remainingNum;
    if(num == 0)
        return 0;
    remainingNum = num/10;
    count = 1 + numOfDigits(remainingNum);
    
    return count;
}

int main(){
    int num, result;
    printf("Enter your number: ");
    scanf("%d",&num);
    result = numOfDigits(num);
    printf("Your result is: %d",result);

    return 0;
}