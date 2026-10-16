#include <stdio.h>
//a)Find Factorial Of A Number.
int factorial(int n)
{
if(n == 0 || n == 1)
return 1;
return n * factorial(n - 1);
}
int main()
{
int n;
printf("Enter number: ");
scanf("%d", &n);
printf("Factorial = %d\n", factorial(n));
return 0;
}