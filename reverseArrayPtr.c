#include <stdio.h>
#include <stdlib.h>

void reverse(int *a, int n){
    int i,temp;
    for(i=0;i<n/2;i++){
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-i-1] = temp;
    }
}

int main(){
    int i,n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    int *a;
    a = (int *)calloc(n, sizeof(int));
    printf("Enter the elements of the array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array is: \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    reverse(a,n);
    printf("The reversed array is: \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}