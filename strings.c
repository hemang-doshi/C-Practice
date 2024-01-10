#include <stdio.h>

int main(){
    int i=0;
    char str[100];
    printf("Enter your string: \n");
    gets(str);
    int length=0;
    while( str[i] != '\0'){
        length++;
        i++;
    }
    int flag=0;
    for(int i=0;i<length/2;i++){
        if(str[i] == str[length-i-1]){
            flag =1;
            break;
        }
    }
    if(flag == 1){
        printf("The word is a palindrome\n");
    }
    else if(flag == 0){
        printf("The word is not a palindrome\n");
    }
    else{
        printf("Error\n");
    }

    return 0;
}