#include <stdio.h>
int main()
{
    int mid,key,found=0;
    int a[10]={25,32,57,69,79,84,99,105,117,120};
    printf("Enter element to be found: ");
    scanf("%d",&key);
    int low=0;
    int high=9;
    while(low <= high)
    {
        mid=(high+low)/2;
        if(key<a[mid])
        {
            high=mid-1;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
        else if(key == a[mid])
        {
            printf("The element is found at location %d\n",mid);
            found=1;
            break;
        }
    }
    if(found == 0)
    {
        printf("Element not found");
    }
    return 0;
}