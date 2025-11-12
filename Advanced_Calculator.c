#include<stdio.h>
#include<math.h>
#include<stdlib.h>

     // Functions of Simple opertions 
double add(double x,double y) {return x+y;}
double sub(double x,double y) {return x-y;}
double mul(double x,double y) {return x*y;}
double divide(double x,double y) {return x/y;}
int mod(int x,int y) {return x%y;}

     // Factorial function upto 65
    unsigned long long factorial(int n)
    {
     long long fact=1; 
     for(int i=1;i<=n;i++){fact *= i;}
     return fact;
    }

          // Matrix function
void matrix_input(int m, int n, int matrix[m][n]);
void matrix_output(int m,int n,int matrix[m][n]);
void transpose(int m,int n,int matrix[m][n]);
void add_matrix(int m, int n,int matrix1[m][n],int matrix2[m][n]);
void sub_matrix(int m, int n,int matrix1[m][n],int matrix2[m][n]);
void multiply_matrix(int m,int n,int p,int A[m][n],int B[n][p],int C[m][p]);
void getCofactor(int n, int mat[n][n], int temp[n-1][n-1], int p, int q);
int determinant(int n, int mat[n][n]);
    

int main(){

     printf("==========================================================\n");
     printf("WELCOME TO HAMDAN's && ABDUL REHMAN's Calculator \n");
     printf("==========================================================\n");
     printf("I know you are genious but some time you need calculator for big calculation \nHow may I help you in your Calculation\n");
     printf("1.Simple calculation\n2.Factorial\n3.Matrices operation\n");
     int operation;
     scanf("%d", &operation);

     switch (operation)
     {   
          case 1: {
     float a,b;
     char operator;
     printf("Choose Airthmetic operation(+-*/%%): ");
     scanf(" %c", &operator);
     switch(operator)
     {
        case '+':
        printf("Enter 1st digit: ");scanf("%f", &a);
        printf("Enter 2nd digit: ");scanf("%f", &b);
        printf("%.2f", add(a,b)); break;
        case '-':
        printf("Enter 1st digit: ");scanf("%f", &a);
        printf("Enter 2nd digit: ");scanf("%f", &b);
        printf("%.2f", sub(a,b)); break;
        case '*':
        printf("Enter 1st digit: ");scanf("%f", &a);
        printf("Enter 2nd digit: ");scanf("%f", &b);
        printf("%.2f", mul(a,b)); break;
        case '/':
        printf("Enter 1st digit: ");scanf("%f", &a);
        printf("Enter 2nd digit: ");scanf("%f", &b);
        printf("%.2f", divide(a,b)); break; 
        case '%':
        printf("Enter 1st digit: ");scanf("%f", &a);
        printf("Enter 2nd digit: ");scanf("%f", &b);
        printf("%.0f", mod(a,b)); break;   
        default: printf("Invalid character!"); break;    
     }
     break;
}
          case 2: {
          int n1;
          printf("\nEnter a number(<66) for factorial: ");
          scanf("%d", &n1);
          printf("The factorial of %d is %llu \n", n1, factorial(n1));
     break;
}
          case 3: {
     int m,n,p;
     int selection;
     printf("Which operation do you want with matrix\n");
     printf("1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.DETERMINENT\n5.TRANSPOSE\n");
     scanf("%d", &selection);
     switch(selection)
     {
     case 1:
          {
               printf("Enter order of matrix: ");
               scanf("%d%d", &m, &n);
               int E[m][n],F[m][n]; 
               printf("Enter elements for 1st Matrix: ");
               matrix_input(m, n, E);
               printf("Enter elements for 2nd Matrix: ");
               matrix_input(m, n, F);
               add_matrix(m, n, E, F);
            break;
          }
        break;
     case 2:
          {
               printf("Enter order of matrix: ");
               scanf("%d%d", &m, &n);
               int G[m][n],D[m][n];
               printf("Enter elements for 1st Matrix: ");
               matrix_input(m, n, G);
               printf("Enter elements for 2nd Matrix: ");
               matrix_input(m, n, D);
               sub_matrix(m, n, G, D);
            break;
          }
     case 3:
          {
               printf("Enter order of first matrix(mxn): ");
               scanf("%d%d", &m, &n);     
               printf("Enter order of second matrix(mxn): ");
               scanf("%d%d", &n, &p);   
               int E[m][n],F[n][p],G[m][p];
               printf("Enter elements for 1st Matrix: ");
               matrix_input(m, n, E);
               printf("Enter elements for 2nd Matrix: ");
               matrix_input(n, p, F);
               multiply_matrix(m, n, p, E, F, G);
               matrix_output(m, p, G);
            break;
          }
     case 4:
          {
               printf("Enter order of square matrix: ");
               scanf("%d", &n);
               int I[n][n];
               matrix_input(n, n, I);
               printf("Determinant of the matrix is: %d\n", determinant(n, I));
          break;
          }
     case 5:
          {
               printf("Enter order of matrix (mxn): ");
               scanf("%d%d", &m, &n);
               int I[m][n];
               matrix_input(m, n, I);
               transpose(m, n, I);    
          break;
          }
     }

     break;
}
     return 0;

}
// main closing
}
     void matrix_input(int m, int n, int matrix[m][n]) {
          for(int i=0; i<m; i++) {
               for(int j=0; j<n; j++) {
                    scanf("%d", &matrix[i][j]);
               }
          }
     }

    void matrix_output(int m,int n,int matrix[m][n]) {
     for(int i=0; i<m; i++) {
          for(int j=0; j<n; j++) {
               printf("%d ", matrix[i][j]);
          }
          printf("\n");
     }
}

     void transpose(int m,int n,int matrix[m][n]) {
          for(int i=0; i<n; i++) {
               for(int j=0; j<m; j++) {
                    printf("%d ", matrix[j][i]);
               }
               printf("\n");
          }
     }
     
        void add_matrix(int m, int n,int matrix1[m][n],int matrix2[m][n]) {
          for(int i=0; i<m; i++) {
               for(int j=0; j<n; j++) {
                    printf("%d ", matrix1[i][j] + matrix2[i][j]);
               }
               printf("\n");
          }
     }        
     
     void sub_matrix(int m, int n,int matrix1[m][n],int matrix2[m][n]) {
          for(int i=0; i<m; i++) {
               for(int j=0; j<n; j++) {
                    printf("%d ", matrix1[i][j] - matrix2[i][j]);
               }
               printf("\n");
          }
     }
     
     void multiply_matrix(int m,int n,int p,int A[m][n],int B[n][p],int C[m][p]) {
          for(int i=0;i<m;i++) {
               for(int j=0;j<p;j++) {
                    C[i][j]=0;
                    for(int k=0;k<n;k++) {
                        C[i][j] += A[i][k]*B[k][j];
                    }
               }
          }
     }       
        
     void getCofactor(int n, int mat[n][n], int temp[n-1][n-1], int p, int q) {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != p && col != q) {
                    temp[i][j++] = mat[row][col];
    
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
               }
          }
     } 
}
    
     int determinant(int n, int mat[n][n]) {
          int det = 0; 
          if (n == 1)
          return mat[0][0];
          int temp[n-1][n-1];
          int sign = 1;     
     for (int f = 0; f < n; f++) {
          getCofactor(n, mat, temp, 0, f);
          det += sign * mat[0][f] * determinant(n-1, temp);
          sign = -sign;
     }
       return det;
}