#include <stdio.h>
int main()
{
    int arr[100],n,flag=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter elements of the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n/2;i++){
        if(arr[i] == arr[n-1-i]){
            flag = 1;
            break;
        }
        else{
            flag = 0;
        }
    }
    if(flag == 1){
        printf("The array is a palindrome");
    }
    else if (flag ==0){
        printf("The array is not a palindrome");
    }
    else{
        printf("ERROR");
    }
    return 0;
}