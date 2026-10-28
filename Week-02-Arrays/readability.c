/*收获：
从这道题中熟悉了输入文本的fgets和strlen函数，都在输入输出标准库里
以及数组在遇到回车的操作，scanf不读回车，经常中断，而fgets会读
另外NUL叫空字符，占位置，但不加入strlen的计数
值得一提的是又学到一个四舍五入的函数，自己造轮子
原理是int类型的返回值会舍去小数值
问题：
目前有个问题是还没掌握动态输出，或者说动态输入内存的melloc函数
使得我总是要考虑回车和NUL的占位问题，太伤了
*/


#include <stdio.h>
#include <string.h>
int rounds (double a);

int main (void)
{
    int letter=0;
    int word=0;
    int sent=0;


    printf("Please enter the text less than 100 words");

    char text[102];

    //fgets会把最后的回车记进sizeof里面，/0是预留位置
    fgets(text,sizeof(text),stdin);

    //strlen计算\n，如果他能挤进去的话
    //而scanf遇到空格，回车tab会停止输入
    //字符串，字符数组会有/0
    int n=strlen(text);
    /*\0，即码值为0的字符，在这里已经不能算是字符了，他就充当一个结束的工具标志
    在ASCII叫空字符，NUL
    理想情况下n=101，100个文本里的加一个回车
    但\0仍然占一个数组位置用来，也是必须的，VIP锁定座位*/

    for (int i=0;i<(n-1);i++)//逐个查看字符
    {
        if (text[i]==' ')
        {
            word++;

        }
        else if(text[i]=='.'||text[i]=='!'||text[i]=='?')
        {
            sent++;
        }
        else if (text[i]>'A'&&text[i]<'Z'||text[i]<'z'&&text[i]>'a')
        letter++;
    }

    //注意前面用的是int，要在这里转换运算
    double L=(double)letter/word*100;
    double S=(double)sent/word*100;
    double I=0.0588*L-0.296*S-15.8;

    //定义的四舍五入函数
    I=rounds(I);

    if (I<=0)
    {
        printf("Before Grade 1");
    }
    else if (I>16)
    {
        printf("Grade 16 +");
    }

    else {
        printf("Grade %d",I);
    }

    return 0;


}
  





//四舍五入
int rounds (double a)
{
    if (a>=0)
    {
        return (a+0.5);
    }
    else {
        return (a-0.5);
    }
}