#include<stdio.h>
int main (void)
{

    int ch;
    printf("Please enter your change");

    scanf("%d",&ch);

    int a,b,c,d;

    a=ch/20;

    b=(ch%20)/10;

    c=(ch%10)/5;

    d=ch%5;

    printf("The least number of coins is %d",a+b+c+d);

    return 0;




}