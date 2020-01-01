#include <stdio.h>
#include <stdbool.h>
#define Max_num 10

int bulls=0,cows=0;

int create_secret_number()
{
    char c1,c2,c3,c4;
    scanf(" %c %c %c %c",&c1,&c2,&c3,&c4);
    int n1,n2,n3,n4;
    n1=c1%10;
    n2=((c1+c2)%10)*10;
    n3=((c1+c2+c3)%10)*100;
    n4=((c1+c2+c3+c4)%10)*1000;
return n1+n2+n3+n4;
}

bool check_legal_number(int num)
   {
    int i=0,a[4]={0};
    if (num<9876)
    {
    for (i=0;i<4;i++)
        {
        a[i]=num%10;
        num=num/10;
        }
    if ((a[3]==0) || (a[0]==a[1]) || (a[0]==a[2]) || (a[0]==a[3]) || (a[1]==a[2]) || (a[1]==a[3]) || (a[2]==a[3]))
        return false;
    else
        return true;
   }
   else
    return false;
    }
int get_num_of_bulls(int num,int guess)
{
    int n[4]={0},g[4]={0},bulls=0,i=0;
     for (i=0;i<4;i++)
        {
        n[i]=num%10;
        num=num/10;
        g[i]=guess%10;
        guess=guess/10;
        }
    for (i=0;i<4;i++)
    {
        if (n[i]==g[i])
            bulls++;
    }
return bulls;
}

int get_num_of_cows(int num,int guess)
{
    int n[4]={0},g[4]={0},cows=0,i=0,j=0;
     for (i=0;i<4;i++)
        {
        n[i]=num%10;
        num=num/10;
        g[i]=guess%10;
        guess=guess/10;
        }
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
       {
           if ((n[i]==g[j]) && (i!=j))
            cows++;
       }
    }
return cows;
}

int handle_guess(int num,int guess,int* bulls,int*cows)
{
    *bulls=get_num_of_bulls(num,guess);
    *cows=get_num_of_cows(num,guess);
    if (*bulls==4)
        return 0;
    else
        return 1;
}
int main()
{
    int secretnum;
    printf("Enter a 4 characters sequence:\n");
    secretnum=create_secret_number();
    bool check=check_legal_number(secretnum);
        while (check==false)
        {
            printf("This sequence creates an illegal secret number. Please try again:\n");
            secretnum=create_secret_number();
            check=check_legal_number(secretnum);
        }

    int guess;
    printf("You have %d attempts. Enter your first guess:\n",Max_num);
    int whatsup,i;
    for (i=Max_num;i>0;i--)
    {
        scanf("%d",&guess);
        check=check_legal_number(guess);
        while (check==0)
            {
            printf("Illegal guess. Please try again:\n");
            scanf("%d",&guess);
            check=check_legal_number(guess);
        }
    whatsup=handle_guess(secretnum,guess,&bulls,&cows);
    if (whatsup==1)
    {
        printf("Number of bulls: %d\n",bulls);
        printf("Number of cows: %d\n",cows);
        if (i>1)
            printf("You have %d attempts left. Enter another guess:\n",i-1);
    }
    else
    {
        printf("Well done! You are correct!");
        return 0;
    }
}
printf("You ran out of guesses!\nThe secret number was: %d",secretnum);
return 0;
}
