/*伪代码
1.先检验输入参数，数量，全字母，大小写都可以
2.实现数组的映射
3.依照2实现密文对明文的映射*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* lowercase (char []);

int main (int argc,char* argv[])//神了，这本身就是一个0-25的映射
{
    //检查只输入两个参数
    if (argc!=2)
    {
        printf("Input eerror");

        return 1;
    }

    //检查第二个字符串是26个字符
    if (strlen(argv[1])!=26)
    {
        printf("You need enter 26 letters");

        return 1;
    }

    


    //检查输入的都是字母
    for (int i=0;i<26;i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Please enter letter\n");

            return 1;
        }
    }

    char *key=lowercase(argv[1]);
    //检查没有重复的字母，这里我先变小写
    //采取计数的方式
    int index;

    char point[26]={0};
    for(int i=0;i<26;i++)
    {
        
        index=key[i]-'a';
        point[index]++;

        if (point[index]>1)
        {
            printf("Don't enter repeated letter");

            return 1;
        }
    }

    printf("Your key is %s\n",key);

    printf("Please enter painttext\n");


    char text[103];
    fgets(text,sizeof(text),stdin);

    int length=strlen(text);
    if (length==102)
    {
        printf("The length is at most 100");
        return 1;
    }

    int x;
    for (int i=0;i<(length-1);i++)//length-1不考虑最后的回车
    {
        if (text[i]<='z'&&text[i]>='a')
        {
            x=text[i]-'a';//定位字母在字母表中的相对位置

            text[i]=key[x];//进行替换
        }
        else if (text[i]<='Z'&&text[i]>='A')
        {
            //大写字母先变小，再换
            x=text[i]-'A';

            text[i]=key[x]-32;
        }
    }


    //输出密文
    printf("%s",text);

    return 0;

}

//定义的变小写函数
char* lowercase (char* key)
{
    for (int i=0;i<26;i++)
    {

        if (key[i]>='A'&&key[i]<='Z')
        {
            key[i]+=32;
        }

    }
    

    return key;
}