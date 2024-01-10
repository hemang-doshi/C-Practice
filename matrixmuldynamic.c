#include <stdio.h>
#include <stdlib.h>

int** multiply(int **a, int **b, int m, int n, int p, int q){
    int i, j;
    int **resultMatrix;
    resultMatrix = (int **)calloc(m, sizeof(int *));

    for(i=0;i<m;i++){
        resultMatrix[i] = (int *)calloc(q, sizeof(int));  
        for(j=0;j<q;j++){
            resultMatrix[i][j] = 0;
            for(int k=0;k<n;k++){
                resultMatrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return resultMatrix;
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m, n, p, q, i, j;

    printf("Enter dimensions of the first matrix (rows cols): ");
    scanf("%d %d", &m, &n);

    printf("Enter dimensions of the second matrix (rows cols): ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication is not possible.");
        exit(0);
    }

    int **a, **b;
    a = (int **)calloc(m, sizeof(int *));
    b = (int **)calloc(p, sizeof(int *));

    printf("Enter elements of matrix a: \n");
    for(i=0;i<m;i++){
        a[i] = (int*)malloc(n * sizeof(int));
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter elements of matrix b: \n");
    for(i=0;i<p;i++){
        b[i] = (int*)malloc(q * sizeof(int));
        for(j=0;j<q;j++){
            scanf("%d",&b[i][j]);
        }
    }

    printf("Matrix a: \n");
    displayMatrix(a,m,n);

    printf("Matrix b: \n");
    displayMatrix(b,p,q);

    int **resultantMatrix = multiply(a,b,m,n,p,q);

    printf("The resultant matrix is: \n");
    displayMatrix(resultantMatrix,m,q);

    for(i=0;i<m;i++){
        free(a[i]);
    }
    free(a);

    for(i=0;i<p;i++){
        free(b[i]);
    }
    free(b);

    for(i=0;i<m;i++){
        free(resultantMatrix[i]);
    }
    free(resultantMatrix);

    return 0;
}