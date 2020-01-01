#include <stdio.h>
#include <stdlib.h>

void fill_metrix(int n, int array[n][n])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf(" %d",&array[i][j]);
        }
    }
}


void print_metrix(int n, int array[n][n])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}
void swap(int* p,int *q)
{
    int tmp;
    tmp=*p;
    *p=*q;
    *q=tmp;
}

void sorting_func(int i,int n, int array[i][n],int start,int end )
{
     int pivot,j,k;

     if(end>start){
         pivot=start;
         k=start;
         j=end;

         while(k<j){
             while(array[i][k]<=array[i][pivot]&&k<end)
                 k++;
             while(array[i][j]>array[i][pivot])
                 j--;
             if(k<j)
                {
                 swap(&array[i][k],&array[i][j]);
                }
         }
         swap(&array[i][pivot],&array[i][j]);
         sorting_func(i,n,array,start,j-1);
         sorting_func(i,n,array,j+1,end);

    }
}
void reverse_func(int i,int n,int array[i][n])
{
    for (int j=0;j<(n+1)/2;j++)
    {
        swap(&array[i][n-j-1],&array[i][j]);
    }
}

int main()
{
int n;
scanf(" %d",&n);
int array[n][n];
fill_metrix(n,array);
for (int i=0;i<n;i++)
{
    sorting_func(i,n,array,0,n-1);
}
for(int i=1;i<n;i++)
{
    reverse_func(i,n,array);
    i++;
}
print_metrix(n,array);
  return 0;
}
