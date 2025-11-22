#include <stdio.h>
#include <math.h>

#define PI 3.142

//-------------------Functions of Simple opertions-----------------------------------------------------

double add(double x, double y) { return x + y; }
double sub(double x, double y) { return x - y; }
double mul(double x, double y) { return x * y; }
double divide(double x, double y) { return x / y; }
int mod(int x, int y) { return x % y; }

//--------------------Factorial function upto 65---------------------------------------------------------

unsigned long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

//------------------Convert Degree into Radin-------------------------------------------------------------

double degreeToRadian(double degree) { return degree * (PI / 180); }

//------------------SOME Prototypes of Long Functions------------------------------------------------------

void sineFunc(double degree);
void cosFunc(double degree);
void tanFunc(double degree);
void cosecFunc(double degree);
void secFunc(double degree);
void cotFunc(double degree);
void powerFunc(double base, double exp);
void rootFunc(double num);
void cubeRootFunc(double num);
void sinhFunc(double degree);
void coshFunc(double degree);
void tanhFunc(double degree);
void cosechFunc(double degree);
void sechFunc(double degree);
void cothFunc(double degree);
void matrix_input(int m, int n, int matrix[m][n]);
void matrix_output(int m, int n, int matrix[m][n]);
void transpose(int m, int n, int matrix[m][n]);
void add_matrix(int m, int n, int matrix1[m][n], int matrix2[m][n]);
void sub_matrix(int m, int n, int matrix1[m][n], int matrix2[m][n]);
void multiply_matrix(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]);
void getCofactor(int n, int mat[n][n], int temp[n - 1][n - 1], int p, int q);
int determinant(int n, int mat[n][n]);
void toBinary(int n);

//============================= MAIN Functon =============================================

int main()
{
    printf("1.Simple Airthmetic\n");
    printf("2.Trignometric\n");
    printf("3.Trignometric hyperbolic\n");
    printf("4.Matrices\n");
    printf("5.Power Function\n");
    printf("6.Factorial\n");
    printf("7.Decimal to Binary\n");

    int function;
    scanf("%d", &function);
    switch (function)
    {
    case 1:
    {
        double a, b;
        printf("Choose Airthmetic operation(+-*/%%): ");
        char airthmeticOperator;
        scanf(" %c", &airthmeticOperator);

        switch (airthmeticOperator)
        {
        case '+':
        {
            printf("Enter 1st digit: ");
            scanf("%lf", &a);
            printf("Enter 2nd digit: ");
            scanf("%lf", &b);
            printf("%.2lf", add(a, b));
            break;
        }

        case '-':
        {
            printf("Enter 1st digit: ");
            scanf("%lf", &a);
            printf("Enter 2nd digit: ");
            scanf("%lf", &b);
            printf("%.2lf", sub(a, b));
            break;
        }

        case '*':
        {
            printf("Enter 1st digit: ");
            scanf("%lf", &a);
            printf("Enter 2nd digit: ");
            scanf("%lf", &b);
            printf("%.2lf", mul(a, b));
            break;
        }

        case '/':
        {
            printf("Enter 1st digit: ");
            scanf("%lf", &a);
            printf("Enter 2nd digit: ");
            scanf("%lf", &b);
            printf("%.2lf", divide(a, b));
            break;
        }

        case '%':
        {
            printf("Enter 1st digit: ");
            scanf("%lf", &a);
            printf("Enter 2nd digit: ");
            scanf("%lf", &b);
            printf("%.0lf", mod(a, b));
            break;
        }

        default:
            printf("Invalid character!");
            break;
        }
        break;
    }

    case 2:
    {
        printf("1.Sine\n");
        printf("2.Cosine\n");
        printf("3.Tangent\n");
        printf("4.Cosecant\n");
        printf("5.Secant\n");
        printf("6.Cotangent\n");

        int trigFun;
        double degree;
        scanf("%d", &trigFun);
        switch (trigFun)
        {
        case 1:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            sineFunc(degree);
            break;
        }
        case 2:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            cosFunc(degree);
            break;
        }
        case 3:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            tanFunc(degree);
            break;
        }
        case 4:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            cosecFunc(degree);
            break;
        }
        case 5:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            secFunc(degree);
            break;
        }
        case 6:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            cotFunc(degree);
            break;
        }
        default:
            printf("Enter correct number!!\n");
            break;
        }
        break;
    }

    case 3:
    {
        printf("1.Sine hyperbolic\n");
        printf("2.Cosine hyperbolic\n");
        printf("3.Tangent hyperbolic\n");
        printf("4.Cosecant hyperbolic\n");
        printf("5.Secant hyperbolic\n");
        printf("6.Cotangent hyperbolic\n");

        double degree;
        int hyperbolic;
        scanf("%d", &hyperbolic);

        switch (hyperbolic)
        {

        case 1:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            sinhFunc(degree);
            break;
        }
        case 2:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            coshFunc(degree);
            break;
        }
        case 3:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            tanhFunc(degree);
            break;
        }
        case 4:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            cosechFunc(degree);
            break;
        }
        case 5:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            sechFunc(degree);
            break;
        }
        case 6:
        {
            printf("Enter angle in degrees: ");
            scanf("%lf", &degree);
            cothFunc(degree);
            break;
        }
        default:
            printf("Enter correct number!!\n");
            break;
        }
        break;
    }

    case 4:
    {
        int m, n, p, o;
        int selection;
        printf("Which operation do you want with matrix\n");
        printf("1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.DETERMINENT\n5.TRANSPOSE\n");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
        {
            printf("Enter order of matrix: ");
            scanf("%d%d", &m, &n);
            int E[m][n], F[m][n];
            printf("Enter elements for 1st Matrix\n");
            matrix_input(m, n, E);
            printf("Enter elements for 2nd Matrix\n");
            matrix_input(m, n, F);
            add_matrix(m, n, E, F);
            break;
        }
        break;
        case 2:
        {
            printf("Enter order of matrix: ");
            scanf("%d%d", &m, &n);
            int G[m][n], D[m][n];
            printf("Enter elements for 1st Matrix\n");
            matrix_input(m, n, G);
            printf("Enter elements for 2nd Matrix\n");
            matrix_input(m, n, D);
            sub_matrix(m, n, G, D);
            break;
        }
        case 3:
        {
            printf("Enter order of first matrix(mxn): ");
            scanf("%d%d", &m, &n);
            printf("Enter order of second matrix(mxn): ");
            scanf("%d%d", &o, &p);
            int E[m][n], F[o][p], G[m][p];
            if (n != o)
            {
                printf("Multiplication is not possible!!");
                break;
            }
            printf("Enter elements for 1st Matrix\n");
            matrix_input(m, n, E);
            printf("Enter elements for 2nd Matrix\n");
            matrix_input(o, p, F);
            multiply_matrix(m, n, p, E, F, G);
            matrix_output(m, p, G);
            break;
        }
        case 4:
        {
            printf("Enter order of square matrix (n): ");
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
        default:
            printf("Enter correct number!!\n");
            break;
        }
        break;
    }

    case 5:
    {
        printf("1.Power of nth\n");
        printf("2.Square root\n");
        printf("3.Cube root\n");

        int power;
        double a, b;
        scanf("%d", &power);
        switch (power)
        {
        case 1:
        {
            printf("Enter base number: ");
            scanf("%lf", &a);
            printf("Enter exponent: ");
            scanf("%lf", &b);
            powerFunc(a, b);
            break;
        }
        case 2:
        {
            printf("Enter number: ");
            scanf("%lf", &a);
            rootFunc(a);
            break;
        }
        case 3:
        {
            printf("Enter number: ");
            scanf("%lf", &a);
            cubeRootFunc(a);
            break;
        }
        default:
        {
            printf("Enter correct number!!\n");
            break;
        }
        }
        break;
    }
    case 6:
    {
        {
            int n1;
            printf("\nEnter a number(<66) for factorial: ");
            scanf("%d", &n1);
            printf("The factorial of %d is %llu \n", n1, factorial(n1));
            break;
        }
    default:
    {
        printf("Choose Right Function\n");
        break;
    }
    }
    break;
    case 7:
    {
        int binary;
        printf("Enter Deciamal number (0-9): ");
        scanf("%d", &binary);
        toBinary(binary);
        break;
    }
    }

    return 0;
}

//=================== Main Closed ===============================================

//------------------- Trignometric Function -----------------------------------------------

void sineFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("sin(%.2lf°) = %.2lf\n", degree, sin(rad));
}

void cosFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("cos(%.2lf°) = %.2lf\n", degree, cos(rad));
}

void tanFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("tan(%.2lf°) = %.2lf\n", degree, tan(rad));
}

void cosecFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("cosec(%.2lf°) = %.2lf\n", degree, 1 / sin(rad));
}

void secFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("sec(%.2lf°) = %.2lf\n", degree, 1 / cos(rad));
}

void cotFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("cot(%.2lf°) = %.2lf\n", degree, 1 / tan(rad));
}

//---------------------------------Trignimetric hyperbolic Function----------------------------------

void sinhFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("sinh(%.2lf°) = %.2lf\n", degree, sinh(rad));
}

void coshFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("cosh(%.2lf°) = %.2lf\n", degree, cosh(rad));
}

void tanhFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("tanh(%.2lf°) = %.2lf\n", degree, tanh(rad));
}

void cosechFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("cosech(%.2lf°) = %.2lf\n", degree, 1 / sinh(rad));
}

void sechFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("sech(%.2lf°) = %.2lf\n", degree, 1 / cosh(rad));
}

void cothFunc(double degree)
{
    double rad = degreeToRadian(degree);
    printf("coth(%.2lf°) = %.2lf\n", degree, 1 / tanh(rad));
}

//---------------------------------Power Functions--------------------------------------------------

void powerFunc(double base, double exp)
{
    printf("Result: %.2lf\n", pow(base, exp));
}

void rootFunc(double num)
{
    printf("Result: %.2lf\n", sqrt(num));
}

void cubeRootFunc(double num)
{
    printf("Result: %.2lf\n", cbrt(num));
}

//---------------------------------Matrices Functions------------------------------------------------

void matrix_input(int m, int n, int matrix[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// -----------------------------------------------------------------------------------------------------

void matrix_output(int m, int n, int matrix[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// -----------------------------------------------------------------------------------------------------

void transpose(int m, int n, int matrix[m][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

// -----------------------------------------------------------------------------------------------------

void add_matrix(int m, int n, int matrix1[m][n], int matrix2[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix1[i][j] + matrix2[i][j]);
        }
        printf("\n");
    }
}

// -----------------------------------------------------------------------------------------------------

void sub_matrix(int m, int n, int matrix1[m][n], int matrix2[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix1[i][j] - matrix2[i][j]);
        }
        printf("\n");
    }
}

// -----------------------------------------------------------------------------------------------------

void multiply_matrix(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// -----------------------------------------------------------------------------------------------------

void getCofactor(int n, int mat[n][n], int temp[n - 1][n - 1], int p, int q)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// -----------------------------------------------------------------------------------------------------

int determinant(int n, int mat[n][n])
{
    int det = 0;
    if (n == 1)
        return mat[0][0];
    int temp[n - 1][n - 1];
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        getCofactor(n, mat, temp, 0, i);
        det += sign * mat[0][i] * determinant(n - 1, temp);
        sign = -sign;
    }
    return det;
}

//------------------------------------------------------------------------------------------------------

void toBinary(int n)
{
    int binary[32];
    int i = 0;
    int temp = n;

    if (n == 0)
    {
        printf("Decimal 0 -> Binary = 0\n");
        return;
    }
    while (n > 0)
    {
        binary[i++] = n % 2;
        n /= 2;
    }
    printf("Decimal %d -> Binary = ", temp);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}
//============================== The END ==================================================================