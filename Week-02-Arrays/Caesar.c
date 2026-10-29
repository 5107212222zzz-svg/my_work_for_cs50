/*这道题的逐个击破的障碍是：
1.26字母，循环z之后回到a，通过取余26解决
2.依旧将第几个字母问题转化为与‘a'码值的差，昨天刚学就用上了
不过这里还是分了大小写，毕竟是差32的
3.这里的限定了100个字符，明文长度
收获：
熟悉了命令行输入参数，这里要注意运行的./加实际参数
这里回车并不输入,因此这里取的是argv[1],第二个参数；
新的函数atoi，属于stdlib.h将字符转化为整数
刚刚测试了这个函数，只能接受字符串的输入，即要定义指针数组，括号里要填
一个字符串的指针，而且只能接受数字，'z'不行是错误输入，比如“1xxx“只会
读取1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc,char *argv[])
{
    //输入三个参数
    if (argc !=2)
    {
        printf("Input error !");

        return 1;
    }

    int a=strlen(argv[1]);

    for (int i=0;i<a;i++)
    {
        if(argv[1][i]<'0'||argv[1][i]>'9')
        {
            printf("Key must contain only digits\n");

            return 1;
        }
        
    }

    

    

    //一个新函数，atoi将字符转换为整数
    int key =atoi(argv[1]); 

    //实在难搞，就暂且搞个100
    char text [103];

    printf("Please enter the painttext\n");

    int n=strlen(text);

    //输入明文
    fgets(text,sizeof(text),stdin);

    

    if(n>102)
    {
        printf("Please enter at most 100 characters");

        return 1;
    }

    else {
        n--;
    }

    //逐个进行加密
    for (int i=0;i<n;i++)

    {
        //取余
        if (text[i]<='Z'&&text[i]>='A')
        {
            text[i]='A'+(text[i]-'A'+key)%26;
        }

        else if (text[i]<='z'&&text[i]>='a')
        {
            text[i]='a'+(text[i]-'a'+key)%26;
        }
    }

    //输出密文
    printf("The ciphertext is \n%s",text);

    return 0;

}

