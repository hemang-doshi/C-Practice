#include <stdio.h>
#include <stdlib.h>

void printUptoN(int num){
    if(num >= 1){
        printUptoN(num-1);
        printf("%d ",num);
    }
}

int main(){
    int num,result;
printf("Enter your number: ");
scanf("%d",&num);
printUptoN(num);

return 0;
}