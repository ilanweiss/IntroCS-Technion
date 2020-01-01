#include <stdio.h>
#include <stdlib.h>

int solvesudoku(int n,int board[][n],int row,int column);

void fillbord(int n,int su[][n])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf(" %d",&su[i][j]);
}}}
int check(int i,int n, int board[][n],int num,int row,int column)
{
    if (i+1>n)
        return 1;
    if((board[row][i]==num)||(board[i][column]==num))
        return 0 ;
return check(i+1,n,board,num,row,column);
}
int duble_check(int i,int n, int board[][n],int row,int column)
{
    if(i<n)
    {
        if((board[row][i]==board[row][column])&&(i!=column))
            return 1;
        if((board[i][column]==board[row][column])&&(i!=row))
            return 1 ;
        return duble_check(i+1,n,board,row,column);
    }
return 0;}
void display(int n,int board[][n])
{
int row,column;
    for(row=0;row<n;row++)
    {
        for(column=0;column<n;column++)
            printf("%d ",board[row][column]);
    printf("\n");
}}
int solvesudoku(int n,int board[][n],int row,int column)
{
    int i;
    if (row<n&&column<n)
    {
        if(board[row][column]!=0)
        {
            if (duble_check(0,n,board,row,column))
                return 0;
            if(column+1<n)
                return solvesudoku(n,board,row,column+1);
            else if(row+1<n)
                return solvesudoku(n,board,row+1,0);
            else
                return 1;
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                if(check(0,n,board,i,row,column))
                {
                    board[row][column]=i;
                    if((column+1)<n)
                    {
                        if (solvesudoku(n,board,row,column+1))
                            return 1;
                    else
                        board[row][column]=0;
                    }
                else if((row+1)<n)
                {
                    if (solvesudoku(n,board,row+1,0))
                        return 1;
                    else
                        board[row][column]=0;}
                else
                    return 1;
                }}}
        return 0;}
return 1;
}
int main()
{
    int size;
    scanf(" %d",&size);
    int board[size][size];
    fillbord(size,board);
    if (!solvesudoku(size,board,0,0))
        printf("No Solution!");
    else
        display(size,board);
return 0;
}
