#include <stdio.h>
#include <stdlib.h>
int main()
{
int num=0,flag=0;
char c;
while (scanf("%c",&c)!= EOF)
{
    if (c>='0' && c<='9'){
        if (flag==0){
            num=c-'0';
            flag=1;
            continue;}
        else {
            num=num*10+c-'0';
            continue;
        }}
   if (num%3!=0){
          if (c>='A'&&c<='Z'){
            c=c+29;
            if (c<97)
                c=c+26;
            }
        else if (c>='a'&&c<='z'){
            c=c-35;
            if(c<65)
                c=c+26;
            }
    }
    else if (c>='A' && c<='Z'){
            c=c+35;
            if (c>122)
                c=c-26;
         }
            else if (c>='a'&&c<='z'){
            c=c-29;
            if (c>90)
                c=c-26;
            }
    flag=0;
    printf("%c",c);
    }
  return 0;
}
