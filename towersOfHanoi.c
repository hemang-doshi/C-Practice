#include <stdio.h>
#include <stdlib.h>

void towersOfHanoi(int n, char beg, char aux, char end){
    if(n == 1)
        printf("Move disc from %c to %c\n", beg, end);
    else{
        towersOfHanoi(n-1,beg, end, aux);
        towersOfHanoi(1, beg, aux, end);
        towersOfHanoi(n-1, aux, beg, end);
    }
}

int main(){
    int n;
    char beg='A', aux='B', end='C';
    printf("Enter number of discs: \n");
    scanf("%d",&n);
    towersOfHanoi(n, beg, aux, end);

    return 0;
}