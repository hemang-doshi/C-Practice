#include <stdio.h>
#include <stdlib.h>



int main(){
    int total,val;
    printf("Enter the integer value 'total': ");
    scanf("%d",&total);
    printf("Enter the character value 'val': ");
    scanf(" %c",val);

    for(int i=0;i<total;i++){
        printf("%c",val);
    }
    for(int i=0;i<total;i++){
        printf("%c",val-32);
    }

    return 0;
}