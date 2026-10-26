/*当硬币面值是倍数关系就变得有趣了
比如20，10，5，1，这样省去了减去已有数值的操作，只需要取余就像*/


#include<stdio.h>
int main (void)
{

    int ch;
    printf("Please enter your change");

    scanf("%d",&ch);

    int a,b,c,d;

    //a是20元
    a=ch/20;

    //b是10元
    b=(ch%20)/10;

    //c是5元
    c=(ch%10)/5;

    //d是1元
    d=ch%5;

    printf("The least number of coins is %d",a+b+c+d);

    return 0;




}