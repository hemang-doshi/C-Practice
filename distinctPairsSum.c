#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, l, r, min, max, count=0;
    printf("Enter l,r: ");
    scanf("%d %d", &l, &r);
    min = 2 * l;
    max = 2 * r;
    for (int i = min; i <= max; i++) {
        count++;
    }
    printf("%d",count);
    return 0;
}
