#include <stdio.h>
#include <stdlib.h>

void push(char op,char *stack)
{
    for (int i=9;i>0;i--)
        stack[i]=stack[i-1];
    stack[0]=op;
}

void calculator(char op,int *numbers,int *oddVSeven)
{
    switch (op)
    {
    case '+': *numbers=*numbers+1; break;
    case '-': *numbers=*numbers-1; break;
    case '*': *numbers=*numbers*2; break;
    case '/': *numbers=*numbers/2; break;
    case '!': {
                if (*oddVSeven==1 && *numbers>0)
                    *numbers=*numbers*2+1;
                else if (*oddVSeven==1 && *numbers<0)
                    *numbers=*numbers*2-1;
                else
                    *numbers=*numbers*2;
                break;
              }
    }
    printf("Current number is: %d\n",*numbers);
}

void pop(char *stack,int *numbers,int *oddVSeven)
{
    char op=stack[0];
    switch (op)
    {
        case '+': op='-'; break;
        case '-': op='+'; break;
        case '*': op='/'; break;
        case '/': op='!'; break;
    }
    for (int i=0;i<9;i++)
        stack[i]=stack[i+1];
    stack[9]='0';
    calculator(op,numbers,oddVSeven);
}
void undo(char *stack,int *numbers,int *oddVSeven)
{
    if (stack[0]=='+' || stack[0]=='-' || stack[0]=='*' || stack[0]=='/')
        pop(stack,numbers,oddVSeven);
    else
        printf("Can't undo! Please enter another operation:\n");
}

void clear(char *stack)
{
    for (int i=0;i<10;i++) stack[i]='0';
}

int EOFchecker(char *EOFop)
{
    char a;
    if (scanf(" %c",&a)!=EOF)
    {
        *EOFop=a;
        return 1;
    }
    else
        return 0;
}

int main()
{
    printf("Enter your number:\n");
    int *numbers,start,x,z,*oddVSeven;
    oddVSeven=&z;
    char stack[10]={'0'};
    clear(stack);
    scanf("%d",&start);
    x=start;
    numbers=&x;
    printf("Current number is: %d\n",start);
    char *EOFop,opo;
    EOFop=&opo;
    if ((EOFchecker(EOFop))==0)
        opo='e';
    else
        opo=*EOFop;
    while (opo!='e')
    {
        if (opo=='/')
        {
            if(*numbers%2==0)
                *oddVSeven=0;
            else *oddVSeven=1;
        }
        if (opo=='+' || opo=='-' || opo=='*' || opo=='/')
            {
                calculator(opo,numbers,oddVSeven);
                push(opo,stack);
            }
        if (opo=='u')
            undo(stack,numbers,oddVSeven);
        if (opo=='r')
        {
            if (stack[0]=='0')
                printf("No operation to print. Please enter another operation:\n");
            else
                printf("Last operation was: %c\n",stack[0]);
        }
        if (opo=='c')
        {
            *numbers=start;
            clear(stack);
            printf("Current number is: %d\n",*numbers);
        }
        if (!(EOFchecker(EOFop)))
            opo='e';
        else
            opo=*EOFop;
}
  return 0;
}
