#include <stdio.h>

int IntGer(float num){
    int op;
    op = (int)num;
    return op;
}

int main(){
    float numberToPass;
    int result;
    do{
        printf("Enter a number: \n");
        scanf("%f",&numberToPass);
        if(numberToPass == -1)
            break;
        result = IntGer(numberToPass);
        printf("%d\n",result);

    }while(numberToPass != -1);

    return 0;
}