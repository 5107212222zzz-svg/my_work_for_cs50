//目前只能九位数有效
//发现inde后面没加long
//现在能用16位了
//比较难绷的是把卡号当成大数字了

#include<stdio.h>
long long int inde (int a,int b);    

int main (void)
{
    //输入卡号
    printf("Please enter your credit card number\n");


long long int  num=0;

    scanf("%lld",&num);

    int sum=0;
//计算奇数位的和
    for (int i=0;i<16;i+=2)//固定循环20次，不限定位数
    {
        sum+=(num/inde(10,i))%10;//通过除法和取余找到各个计数位的数
    }

    int SUM=0;
    for(int i=1;i<17;i+=2)//同理找偶数位

    {
        

        //多一步
        int p=((num/inde(10,i))%10)*2;

        SUM+=p/10+p%10;
    }

    //计算结果mod10
    if ((sum+SUM)%10==0)

    {
        printf("The number is valid");
    }

    else {
        printf("The number isn't valid");
    }
    }
//定义指数函数
long long int inde (int a,int b)
{long long int x=1;
    for (int i=0;i<b;i++)
    {
       

        x*=a;
    }
    return x;
}