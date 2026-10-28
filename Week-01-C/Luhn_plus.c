/*相对于上一个把卡号当成大整数的方法是在太雷了
这里巧妙地运用了ASCII码值中数字连续排列，字符可以
转换成数值有关
数组长度限定再20位，对应最大的19位卡号加一个0/
这次再加一下检验输入数字字符实在有必要，不然输入个字母就惨了
这次对数组，指针的运用更加熟练了*/



#include <stdio.h>
int main ()
{
    int sum=0;
    int add=0;
    char num[20]={0};//初始化数组，防止在位数较少时，垃圾值影响结果

    //提示用户输入卡号
    printf("Please enter your card number\n");

   
   //检验输入
   if ( scanf("%19s",num)!=1)
   {
    printf("Input error");

    return 1;
   }


   //确定输入的都是数字字符
   for (int i=0;i<20;i++)

   {
    if(num[i]>'\0'&&num[i]<'0'||num[i]>'9')

    {
        printf("Input error");

    return 1;
    }
   }

   

    //确认结果
   printf("Your card number is %s\n",num);

   //计算奇数位的和
   for (int i=0;i<19;i+=2)

   {
    int digit=num[i]-'0';

    sum+=digit;
   }

   //计算偶数位的和
   for (int i=1;i<18;i+=2)

   {
    int digit =num[i]-'0';

    digit*=2;

    add+=digit/10+digit%10;

   }

   int x=sum+add;

   //检验是否合规
   if (x%10==0)
   {
    printf("The number is valid ");

    return 0;
   }

   printf("The number isn't valid");



   return 0;

   

}
