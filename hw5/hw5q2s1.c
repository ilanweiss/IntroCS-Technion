#include <stdio.h>
#include <stdlib.h>

int factorial(int n,int sulo)
    {
        if (n>0)
        {
            sulo=sulo*n;
            n=n-1;
            factorial(n,sulo);
        }
        return sulo;
    }

int Pow(int a,int b)
    {
        if (b>0)
        {
            a=a*Pow(a,b-1);
        }
    return a;
    }

int super_factorial(int n)
{

}
int main()
{

  return 0;
}
