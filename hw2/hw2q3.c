#include <stdio.h>
#include <stdlib.h>
int main()
{
int size,i,j;
int winner1=0,winner2=0,flag=0,notie=0;
char A[10][10];
printf("Enter board size (1 to 10): ");
scanf("%d",&size);
if (size>=1 && size<=10){
for(i=0;i<size;i++){//הדפסת הלוח
    for(j=0;j<size;j++){
        A[i][j]='_';
        printf("%c",A[i][j]);}
    printf("\n");}
int rounds=0,row=0,colum=0;
while (rounds<size*size){
    if (rounds % 2 == 0){
        printf("Player 1, enter next move: ");
        scanf("%d,%d",&row,&colum);
        if (row<=size && colum<=size && A[row-1][colum-1]=='_'){
            A[row-1][colum-1]='X';
        }
        else{
             printf("Bad move, retry.\n");
             for(i=0;i<size;i++){//עדכון הלוח
                for(j=0;j<size;j++){
                    printf("%c",A[i][j]);}
                printf("\n");}
            continue;}
    }
    else
    {
        printf("Player 2, enter next move: ");
        scanf("%d,%d",&row,&colum);
           if (row<=size && colum<=size && A[row-1][colum-1]=='_')
        {
            A[row-1][colum-1]='O';
        }
        else
        {
             printf("Bad move, retry.\n");
             for(i=0;i<size;i++){//עדכון הלוח
                for(j=0;j<size;j++){
                    printf("%c",A[i][j]);}
                printf("\n");}
            continue;}
            }

    rounds++;

    for(i=0;i<size;i++){//עדכון הלוח
        for(j=0;j<size;j++){
            printf("%c",A[i][j]);}
        printf("\n");}

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if (A[i][j]=='X')//בדיקת שורות
                winner1++;
            if (A[i][j]=='O')
                winner2++;}
        if (winner1==size){
            printf("Player 1 Wins!");
            notie=1;
            flag=1;
            break;}
        if (winner2==size){
            printf("Player 2 Wins!");
            notie=1;
            flag=1;
            break;
        }
        winner1=0;
        winner2=0;
    }
    if (flag!=0)
        break;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if (A[j][i]=='X'){//בדיקת עמודות
                winner1++;}
            if (A[j][i]=='O'){
                winner2++;}
        }
        if (winner1==size){
            printf("Player 1 Wins!");
            notie=1;
            flag=1;
            break;}
        if (winner2==size){
            printf("Player 2 Wins!");
            notie=1;
            flag=1;
            break;
            }
        winner1=0;
        winner2=0;
    }
    if (flag!=0)
        break;

    for(i=0;i<size;i++){
        if (A[i][i]=='X')//בדיקת אלכסון ראשי
            winner1++;
        if (A[i][i]=='O')
            winner2++;
        }
    if (winner1==size){
        printf("Player 1 Wins!");
        notie=1;
        break;}
    if (winner2==size){
        printf("Player 2 Wins!");
        notie=1;
        break;
        }
    winner1=0;
    winner2=0;
    for(i=0;i<size;i++){
            if (A[i][(size-1-i)]=='X')//אלכסון מישני
                winner1++;
            else if (A[i][(size-1-i)]=='O')
                winner2++;
        }
    if (winner1==size){
        printf("Player 1 Wins!");
        notie=1;
        break;}
    if (winner2==size){
        printf("Player 2 Wins!");
        notie=1;
        break;
        }
    winner1=0;
    winner2=0;
}
if (rounds==size*size && notie==0)
    printf("It's a tie!");}
return 0;
}
