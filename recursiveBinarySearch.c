#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *a, int key, int high, int low){
    int mid;
    if(low>high)
        return -1;
    mid = (low + high)/2;
    if(key == a[mid])
        return mid;
    else if(key > a[mid]){
        low = mid+1;
        return binarySearch(a,key,high,low);
    }
    else{
        high = mid-1;
        return binarySearch(a,key,high,low);
    }
}

int main (){
    int n,key,i,high,low;
    printf("Enter the number of elements int the array: \n");
    scanf("%d",&n);
    int *a  = (int *)calloc(n,sizeof(int));
    printf("Enter the elements of the SORTED array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be found: \n");
    scanf("%d",&key);
    high = n-1;
    low = 0;
    int result = binarySearch(a, key, high, low);
    printf("Your element is found at index %d\n",result);
    free(a);
    
    return 0;
}