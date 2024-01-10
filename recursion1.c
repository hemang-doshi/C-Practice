#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num){
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    return fibonacci(num-1) + fibonacci(num-2);
}

int main(){
    int num,result;
    printf("Enter your index number: ");
    scanf("%d",&num);
    result = fibonacci(num);
    printf("Your result is: %d\n",result);
    return 0;
}

