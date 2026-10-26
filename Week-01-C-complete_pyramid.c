/*遇到的困难是怎么输出前面的空格，我觉得我有不知道一行一共有几个格子，但是我们用
们用户都是从左边开始看的，我总想要把他打印在中间
一个循环套两个独立的循环*/


#include <stdio.h>
int main (void)
{
     int n;

     //输入金字塔高度
    printf("Please enter the hight of your pyramid\n ");

    scanf("%d",&n);

    //i循环，规定第几行，为了方便int i=1
    for (int i=1;i<=n;i++)
    {
        //输出前面的空格
        for (int j=0;j<(n-i);j++)
        {
            printf(" ");
        }
        //输出一定数量的#
        for (int k=0;k<(2*i-1);k++)
        {
            printf("#");
        }
        //在i循环的末尾换行
        printf("\n");
    }

    return 0;

}
