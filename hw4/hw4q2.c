#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dic_size 6
#define MaxWord 101
#define MaxTran 301

void print_string(char *s)
{
printf("%s", s);
}

void DicCheck (char TransformedWord[],char* dic[dic_size],char* trans[dic_size])
{
    int i;
    for (i=0;i<dic_size;i++)
    {
        if (strcmp(TransformedWord,dic[i])==0)
            {
                strcpy(TransformedWord,trans[i]);
                break;
            }
    }
}

void change(char *TransformedWord,int n)
{
     int i;
     for (i=MaxTran;i>n+2;i--)
     {
        TransformedWord[i]=TransformedWord[i-1];
        TransformedWord[i-1]=TransformedWord[i-2];
        TransformedWord[i-2]=TransformedWord[i-3];
     }

}

void transform(char* word, char letter, char *TransformedWord,char* dic[dic_size],char* trans[dic_size])
{
    int i;
    strcpy(TransformedWord,word);
    for (i=0;i<MaxTran+1;i++)
    {
        if ((TransformedWord[i]=='a')||(TransformedWord[i]=='A')
            ||(TransformedWord[i]=='e')||(TransformedWord[i]=='E')
            ||(TransformedWord[i]=='i')||(TransformedWord[i]=='I')
            ||(TransformedWord[i]=='o')||(TransformedWord[i]=='O')
            ||(TransformedWord[i]=='u')||(TransformedWord[i]=='U'))
        {
            change(TransformedWord,i);
            TransformedWord[i+1]=letter;
            TransformedWord[i+2]=TransformedWord[i];
            i++; i++;
        }
    }
    DicCheck(TransformedWord,dic,trans);
}

int main()
{
    char *dic[dic_size]={"abanibi","obohebev","obotabach","safabafa","bebet","bet"};
    char *trans[dic_size]={"I","love","you","language","bet","in"};
    int WordLength;
    printf("What is the length of your word?");
    scanf(" %d",&WordLength);
    char Word[MaxWord],TransformedWord[MaxTran],SecretLetter;
    printf("\nEnter your word:");
    scanf("%s", Word);
    printf("\nEnter your secret char:");
    scanf(" %c",&SecretLetter);
    transform(Word,SecretLetter,TransformedWord,dic,trans);
    printf("\nThe transformed word is: ");
    print_string(TransformedWord);
    return 0;
}
