#include <stdio.h>
#include <stdlib.h>
int main()
{
int num,base10,base2,i=0,A[10]={0},B[2]={0};
scanf("%d",&num);
base10=num;
if (num!=0){
    while(base10>0){
        for (i=0;i<10;i++){
            if (base10%10==i){
                A[i]++;
                break;}
        }
        base10=base10/10;}
    base2=num;
    while(base2>0){
        for (i=0;i<2;i++){
            if (base2%2==i){
                B[i]++;
                break;}
        }
        base2=base2/2;}}
else{
    A[0]=1;
    B[0]=1;}
printf("Base 10 digit statistics:\n");
for (i=0;i<10;i++)
    printf("%d:%d\n",i,A[i]);
printf("Base 2 digit statistics:\n");
for (i=0;i<2;i++)
    printf("%d:%d\n",i,B[i]);
return 0;
}
