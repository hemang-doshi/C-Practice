#include<stdio.h> 

#define N 5 

int check(int a[N][N], int row, int col) 

{ 

    int i, j; 

  

    // Check this row on left side 

    for (i = 0; i < col; i++) 

        if (a[row][i]) 

            return 0; 

  

    // Check upper diagonal on left side 

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 

        if (a[i][j]) 

            return 0; 

  

    // Check lower diagonal on left side 

    for (i = row, j = col; j >= 0 && i < N; i++, j--) 

        if (a[i][j]) 

            return 0; 

  

    return 1; 

} 

  

int nqueen(int a[N][N], int col) 

{ 

    // Base case: If all queens are placed 

    // then return true 

    if (col >= N) 

        return 1; 

  

   

    for (int i = 0; i < N; i++) { 

          

        

        if (check(a, i, col)) { 

              

          

            a[i][col] = 1; 

  

           

            if (nqueen(a, col + 1)) 

                return 1; 

  

            

            a[i][col] = 0; // BACKTRACK 

        } 

    } 

  

     

    return 0; 

} 

 

int main() 

{ 

     

    int n,i,j; 

    printf("enter the n\n"); 

    scanf("%d",&n); 

    int a[n][n]; 

    for(i=0;i<n;i++) 

    { 

        for(j=0;j<n;j++) 

        a[i][j]=0; 

    } 

    if(nqueen(a,0)==0) 

    printf("there is no solution\n"); 

    else 

    for(i=0;i<n;i++) 

    { 

        for(j=0;j<n;j++) 

        printf("%d ",a[i][j]); 

        printf("\n"); 

    } 

} 