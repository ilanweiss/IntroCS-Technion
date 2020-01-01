#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
    {
        if (n<=1)
            return 1;
        return n*factorial(n-1);
    }

int Pow(int a,int b)
    {
        if (b==0)
            return 1;
    return a*Pow(a,b-1);
    }

int super_factorial1(int n)
{
    if (n<=1)
        return 1;
    return factorial(n)*super_factorial1(n-1);
}

int super_factorial2(int a,int b)
{
    if(a==1)
        return 1;
    return super_factorial2(a-1,b+1)*Pow(a,b);

}

int main()
{
int a,b;
scanf(" %d %d",&a,&b);
if (b==1)
    a=super_factorial1(a);
if (b==2)
    a=super_factorial2(a,b-1);
printf("%d",a);
  return 0;
}

