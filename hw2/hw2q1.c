#include <stdio.h>
#include <stdlib.h>
int main()
{
int digets=0,letters=0,spaces=0;
char c,p=0;
while ((c=getchar())!= ';'){
printf("%c%10d%10d%10d%10d\n",c,c,(c*c),(c-p),((c-p)%10));
p=c;
while (c>='0' && c<='9'){
digets++;
break;}
while ((c>='a' && c<='z') || (c>='A' && c<='Z')){
letters++;
break;}
while (c==' '){
spaces++;
break;}}
printf("Number of digits received: %d\nNumber of letters received: %d\nNumber of spaces received: %d",digets,letters,spaces);
return 0;
}
