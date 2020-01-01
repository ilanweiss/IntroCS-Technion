#include <stdio.h>
#include <stdlib.h>
int main()
{
    int head_size,eye_c;

    printf("Enter the size of the head: ");
    scanf("%d",&head_size);

    while (head_size<6){
        printf("Invalid size. Try again: ");
        scanf("%d",&head_size);}

    printf("Enter the left eye's column: ");
    scanf("%d",&eye_c);
double limit=(head_size/2)-1;
    while (eye_c>limit || eye_c<=0){
        printf("Invalid column. Try again: ");
        scanf("%d",&eye_c);}
char char1,char2,char3;
    printf("Enter three chars: ");
    scanf("  %c %c %c",&char1,&char2,&char3);
int i;
for (i=0;i<head_size;i++){
    printf("%c",char1);}
printf("\n%c",char1);
for (i=1;i<head_size-1;i++){
    printf(" ");}
printf("%c\n%c",char1,char1);
for (i=1;i<head_size-1;i++){
    if (i==eye_c||i==head_size-eye_c-1)
        printf("%c",char2);
    else printf(" ");}
printf("%c\n",char1);
int j=4;
while (j<head_size-2){
   printf("%c",char1);
   for (i=1;i<head_size-1;i++){
        printf(" ");}
    printf("%c\n",char1);
    j++;}
printf("%c",char1);
for (i=1;i<head_size-1;i++){
    if (i>eye_c&&i<head_size-eye_c-1)
        printf("%c",char3);
    else printf(" ");}
printf("%c\n",char1);
printf("%c",char1);
for (i=1;i<head_size-1;i++){
        printf(" ");}
printf("%c\n",char1);
for (i=0;i<head_size;i++){
    printf("%c",char1);}
return 0;
}
