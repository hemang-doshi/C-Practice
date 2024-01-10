#include <stdio.h>
#include <stdlib.h>
int lucasSequence(int num){
    if(num == 0)
        return 2;
    if(num == 1)
        return 1;

    return lucasSequence(num-1)+lucasSequence(num-2);
}

int main(){
    int result;
    int num;
    printf("Enter the index: ");
    scanf("%d",&num);

    for(int i=0;i<=num;i++){
        result = lucasSequence(i);
        printf("%d ", result);
    }
    return 0;
}