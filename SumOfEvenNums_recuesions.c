#include <stdio.h>
#include <stdlib.h>

int sumOfEvenNums(){
    int userInput;
    printf("Enter your sequence of numbers: \n");
    scanf("%d",&userInput);
    if(userInput == -1)
        return 0;
    if((userInput % 2) == 0)
        return userInput + sumOfEvenNums();
    return sumOfEvenNums();
}

int main(){
    int result;
    
    result = sumOfEvenNums();
    printf("Your result is: %d\n",result);
    return 0;
}