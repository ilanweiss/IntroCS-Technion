#include <stdio.h>
#include <stdlib.h>
#define max 100
int main()
{
        float x=0;
        printf("Enter a positive number:");
        scanf("%f",&x);
        while (x<=0) {
                printf(" Invalid number. Please enter again:");
                scanf("%f",&x);
                }
        int i=0,activity=1,sum=0,a[max]={0};
        float count=-1.0,sum_avg=0.0;//0 makes the while end so it isn't part of the count.
        printf(" Enter the account activity: ");
        while (activity!=0) {
            scanf(" %d",&activity);
            sum=sum+activity;
            sum_avg+=abs(activity);
            a[i]=activity;
            count++;
            i++;
            }
        float avg;
        if (count!=0)
            avg=sum_avg/count;
        else avg=sum_avg;
        printf("Account balance: %d\n",sum);
        printf("Average amount: %.2f\n",avg);
        int susp=avg*x;
        int j,countnew=(int)count;
        for (j=0;j<=countnew;j++){
            if (abs(a[j])>susp){
                printf("Suspicious account!");
                j=-1;
                break;
                }
}
    if (j!=-1)
        printf("No suspicious activity detected.");
return 0;
}
