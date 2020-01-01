#include <stdio.h>
#include <stdlib.h>
#define Qsize 4

char A[Qsize][Qsize][Qsize];

void func_start()      //fills the board with all the stars
{
    int i,j,k;
    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            for (k=0;k<Qsize;k++)
            {
                A[i][j][k]='*';
            }
        }
    }
return;
}

typedef struct    //just cos its easy to use
    {
        int row;
        int colem;
        int depth;
    } kordinatot;

void FillBordXfunc(int n1,int n2,int n3) //fills up board with X's where needed
{
    A[n1][n2][n3]='X';
    return;
}

void FillBordOfunc(int n1,int n2,int n3) // the same thing just with O's in sted
{
    A[n1][n2][n3]='O';
    return;
}

int hw2_row_func(int n) //some silly function i wrote a month ago modifide for this program
{
int i,j,winner1=0,winner2=0,win=0;
while (1)
{
    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            if (A[n][i][j]=='X')//checks rows
                winner1++;
            if (A[n][i][j]=='O')
                winner2++;
        }
        if (winner1==Qsize){
            win=1;
            break;}
        if (winner2==Qsize)
        {
            win=2;
            break;
        }
    winner1=0;
    winner2=0;
    }
    if (win!=0)
        break;
    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            if (A[n][j][i]=='X'){//check culoms
                winner1++;}
            if (A[n][j][i]=='O'){
                winner2++;}
        }
        if (winner1==Qsize){
            win=1;
            break;}
        if (winner2==Qsize){
            win=2;
            break;
            }
    winner1=0;
    winner2=0;
    }
    if (win!=0)
        break;
    for(i=0;i<Qsize;i++)
    {
        if (A[n][i][i]=='X')//check somthing really importent
            winner1++;
        if (A[n][i][i]=='O')
            winner2++;
    }
    if (winner1==Qsize){
        win=1;
        break;}
    if (winner2==Qsize){
        win=2;
        break;
        }
    winner1=0;
    winner2=0;
    for(i=0;i<Qsize;i++)
    {
            if (A[n][i][(Qsize-1-i)]=='X')//checks something secondery
                winner1++;
            else if (A[n][i][(Qsize-1-i)]=='O')
                winner2++;
    }
    if (winner1==Qsize){
        win=1;
        break;}
    if (winner2==Qsize){
        win=2;
        break;
        }
    winner1=0;
    winner2=0;
    break;
}
return win;
}

int hw2_culom_func(int n) // agian this silly function i wrote a month ago modifide for this program this time chacking the culoms for a winner
{
int i,j,winner1=0,winner2=0,win=0;
while(1)
{
    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            if (A[i][n][j]=='X')//do you really want me to say it again
                winner1++;
            if (A[i][n][j]=='O')
                winner2++;
        }
        if (winner1==Qsize){
            win=1;
            break;}
        if (winner2==Qsize)
        {
            win=2;
            break;
        }

    winner1=0;
    winner2=0;
    }
    if (win!=0)
        break;

    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            if (A[j][n][i]=='X'){// seriously just did copy paset
                winner1++;}
            if (A[j][n][i]=='O'){
                winner2++;}
        }
        if (winner1==Qsize){
            win=1;
            break;}
        if (winner2==Qsize){
            win=2;
            break;
            }
    winner1=0;
    winner2=0;
    }
    if (win!=0)
        break;

    for(i=0;i<Qsize;i++)
    {
        if (A[i][n][i]=='X')//that was what they asked for
            winner1++;
        if (A[i][n][i]=='O')
            winner2++;
    }
    if (winner1==Qsize){
        win=1;
        break;}
    if (winner2==Qsize){
        win=2;
        break;
        }
    winner1=0;
    winner2=0;
    for(i=0;i<Qsize;i++)
    {
            if (A[i][n][(Qsize-1-i)]=='X')//don't drink and drive
                winner1++;
            else if (A[i][n][(Qsize-1-i)]=='O')
                winner2++;
    }
    if (winner1==Qsize){
        win=1;
        break;}
    if (winner2==Qsize){
        win=2;
        break;
        }
    winner1=0;
    winner2=0;
    break;
}
return win;
}


int hw2_depth_func(int n) // for the last time this silly function i wrote a month ago modifide for this program this time chacking the the lines in depth for a winner
{
int i,j,winner1=0,winner2=0,win=0;
while(1)
{
    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            if (A[i][j][n]=='X')//defnettly
                winner1++;
            if (A[i][j][n]=='O')
                winner2++;
        }
        if (winner1==Qsize){
            win=1;
            break;}
        if (winner2==Qsize)
        {
            win=2;
            break;
        }
    winner1=0;
    winner2=0;
    }
    if (win!=0)
        break;

    for(i=0;i<Qsize;i++)
    {
        for(j=0;j<Qsize;j++)
        {
            if (A[j][i][n]=='X'){//dont drink and program
                winner1++;}
            if (A[j][i][n]=='O'){
                winner2++;}
        }
        if (winner1==Qsize){
            win=1;
            break;}
        if (winner2==Qsize){
            win=2;
            break;
            }
    winner1=0;
    winner2=0;
    }
    if (win!=0)
        break;
    for(i=0;i<Qsize;i++)
    {
        if (A[i][i][n]=='X')//but never, never.......
            winner1++;
        if (A[i][i][n]=='O')
            winner2++;
    }
    if (winner1==Qsize){
        win=1;
        break;}
    if (winner2==Qsize){
        win=2;
        break;
        }
    winner1=0;
    winner2=0;
    for(i=0;i<Qsize;i++)
    {
            if (A[i][(Qsize-1-i)][n]=='X')//duplicat the genni of the lamp duh do doo doo doo
                winner1++;
            else if (A[i][(Qsize-1-i)][n]=='O')
                winner2++;
    }
    if (winner1==Qsize){
        win=1;
        break;}
    if (winner2==Qsize){
        win=2;
        break;}
    winner1=0;
    winner2=0;
    break;
    }
return win;
}

int checker(int X,int O) // a whole new function just to check if there was a winner, didnt know i could do this a month ago :(
{
    int win=0;
    if (X==Qsize)
        {
            win=1;
        }

    if (O==Qsize)
        {
            win=2;
        }
return win;
}

int diagnlecheck()  // this new and exsating new program that checks if some one was smart enoghe to win by going throw the qube without the other player noticing
{
    int i,win=0,X=0,O=0;
    while(1){
        for(i=0;i<Qsize;i++){
            switch (A[i][i][i])
                {
                    case 'X': X++;break;
                    case 'O': O++;break;
                }}
        win=checker(X,O);
        if (win!=0) break;
        for (i=0;i<Qsize;i++){
            switch (A[Qsize-i-1][i][i])
            {
                case 'X': X++;break;
                case 'O': O++;break;
            }}
        win=checker(X,O);
        if (win!=0) break;
        for (i=0;i<Qsize;i++){
            switch (A[i][i][Qsize-i-1])
            {
                case 'X': X++;break;
                case 'O': O++;break;
            }}
        win=checker(X,O);
        if (win!=0) break;
        for (i=0;i<Qsize;i++){
            switch (A[Qsize-i-1][i][Qsize-i-1])
            {
                case 'X': X++;break;
                case 'O': O++;break;
            }}
        win=checker(X,O);
        if (win!=0) break;
    break;
    }
return win;
}

int main() // well here the fun ends just another boaring old program called main that returns 0 at the end of it
{
    kordinatot keptplace[64];
    int flag=0,i=0,win=0;
    printf("Please enter your game sequence.\n");
    func_start();
    while ((flag!=1) && (win==0))
    {
        if (i==64)
            break;
        scanf(" %1d%1d%1d",&keptplace[i].row,&keptplace[i].colem,&keptplace[i].depth);  //this struct thing is so cool!!!
        if ( (keptplace[i].row>3)          // can't do that in pascal :)
            || (keptplace[i].colem>3)
            || (keptplace[i].depth>3)
            || (keptplace[i].row<0)
            || (keptplace[i].colem<0)
            || (keptplace[i].depth<0))
        {
            flag=1; // I like flags.
            break;
        }
        int j=0;
        for (j=0;j<i;j++)
            {
                if ((keptplace[j].row==keptplace[i].row) &&
                    (keptplace[j].colem==keptplace[i].colem) &&
                    (keptplace[j].depth==keptplace[i].depth))
                {
                    flag=1; // I really do
                    break;
                }
            }
            if (flag==1) // A lot!
            {
                break;
            }
        int XorO=i%2;
        switch (XorO)
        {
            case 0 : FillBordXfunc(keptplace[i].row,keptplace[i].colem,keptplace[i].depth); break;
            case 1 : FillBordOfunc(keptplace[i].row,keptplace[i].colem,keptplace[i].depth); break;
        }
                for (j=0;j<Qsize;j++)
        {
            win=hw2_row_func(j);
            if (win!=0)
                break;
            win=hw2_culom_func(j);
            if (win!=0)
                break;
            win=hw2_depth_func(j);
            if (win!=0)
                break;
            win=diagnlecheck();
            if (win!=0)
                break;
        }
    i++;
    }
    if (flag==1)   // well if you havn't broken a smile till now  thers nothing more i can do but say:"flag flag flag", god it so late!
    {
        printf("Input incorrect.");
    }
    else
    {
        switch (win)
        {
            case 0: printf("Tie.\n");break;
            case 1: printf("X is the winner.\n");break;
            case 2: printf("O is the winner.\n");break;
        }
        int e,j,k;
        for(e=0;e<Qsize;e++)
        {
            for(j=0;j<Qsize;j++)
            {
                for (k=0;k<Qsize;k++)
                {
                    printf("%c ",A[e][j][k]);// this looks like an arrow head.... just saying.
                    if (k==Qsize-1)
                        printf("\n");
                }
            if (j==Qsize-1)
                printf("\n");
            }
        }
    }

return 0; //I did say it does that, by the way i hope you aren't really reading this cos their
}           //is no spell check here and i dont really use coments anyway.    P.S im not the only crazy person here!
