#include <stdio.h>
#include <stdlib.h>

//void func(){
//    int a = 10;
 //   for(int i=0;i<3;i++){
 //       printf("%d",++a);
//    }
//}

void func(){
   int a = 10;
   ++a;
   printf("%d",a);
}

int main(){
    func();
    return 0;
}