#include <stdio.h>

int main(){
    int arr[100],n,flag=0,largestSum;
    printf("Enter the number of elements in the array: \n");
    scanf("%d",&n);
    printf("Enter elements of the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        largestSum = arr[i]+arr[i+1];
        if(arr[i]+arr[i+1]>=largestSum){
            largestSum = arr[i]+arr[i+1];
        }
    }

    printf("The largest sum of the 2 adjacent elements of the array is: %d\n",largestSum);

    return 0;
}