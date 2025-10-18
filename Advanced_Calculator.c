#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

     // Functions of Simple opertions 
float add(float x,float y) {return x+y;}
float sub(float x,float y) {return x-y;}
float mul(float x,float y) {return x*y;}
float divide(float x,float y) {return x/y;}
float mod(int x,int y) {return x%y;}

     // Factorial function upto 65
    unsigned long long factorial(int n)
    {
         for(int i=1;i<=n;i++){n *= i;}
         return n;
    }
int main()
{
         // Airthmetic / simple operation +-*/ 
    int a,b;
    char operator;
    printf("Choose Airthmetic operation(+-*/%%): ");
    scanf(" %c", &operator);
    switch(operator)
    {
        case '+':
        printf("Enter 1st digit: ");scanf("%d", &a);
        printf("Enter 1st digit: ");scanf("%d", &b);
        printf("%.2f", add(a,b)); break;
        case '-':
        printf("Enter 1st digit: ");scanf("%d", &a);
        printf("Enter 1st digit: ");scanf("%d", &b);
        printf("%.2f", sub(a,b)); break;
        case '*':
        printf("Enter 1st digit: ");scanf("%d", &a);
        printf("Enter 1st digit: ");scanf("%d", &b);
        printf("%.2f", mul(a,b)); break;
        case '/':
        printf("Enter 1st digit: ");scanf("%d", &a);
        printf("Enter 1st digit: ");scanf("%d", &b);
        printf("%.2f", divide(a,b)); break; 
        case '%':
        printf("Enter 1st digit: ");scanf("%d", &a);
        printf("Enter 1st digit: ");scanf("%d", &b);
        printf("%.0f", mod(a,b)); break;   
        default: printf("Invalid character!"); break;    
    }

               // Factorial 
     int n;
     printf("\nEnter a number(<66) for factorial: ");
     scanf("%d", &n);
     printf("The factorial of %d is %llu", n, factorial(n));

    return 0;
    
}