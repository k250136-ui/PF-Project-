#include<stdio.h>
#include<math.h>

     // Functions of Simple opertions 
float add(float x,float y) {return x+y;}
float sub(float x,float y) {return x-y;}
float mul(float x,float y) {return x*y;}
float div(float x,float y) {return x/y;}
float mod(int x,int y) {return x%y;}
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
        printf("%.2f", div(a,b)); break; 
        case '%':
        printf("Enter 1st digit: ");scanf("%d", &a);
        printf("Enter 1st digit: ");scanf("%d", &b);
        printf("%.0f", mod(a,b)); break;   
        default: printf("Invalid character!"); break;    
    }

  
    
    return 0;
    
}