#include <stdio.h>
#include <stdlib.h>

int main() {
	int a,b,c,d,k;
	int t,flag = 0;
    scanf("%d", &t);
	while(t--)
	{
	    scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
	    int xdiff,ydiff;
	    xdiff = abs(a-c);
	    ydiff = abs(b-d);
	    int totalSteps= xdiff + ydiff;
	    if(totalSteps >= k && (k - totalSteps)%2 == 0){
	        flag = 1;
	    }
	    else{
	        flag = 0;
	    }
        if(flag == 1)
		printf("YES\n");
	else if(flag == 0)
		printf("NO\n");
	else
		printf("ERROR");
	}
	return 0;
}