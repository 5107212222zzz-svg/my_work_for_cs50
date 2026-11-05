/*刚开始直接写归并是真的写不来，还是先熟悉一下递归的
di和gui的写完再说
注意到是只用一次再应用函数，接下来就是洋葱了
一般判断条件是放在函数内部的最前面，这检验的不仅是
刚开始也是每一次使用函数都要的，知道最后一次
函数开始回归return值
函数括号的n有点迷惑性，其实是是上一次的n-1
是阶乘的例子*/


#include <stdio.h>
int sum(int n);
int main (){
    printf("N?\n");

    int n;
    scanf("%d",&n);
    int ans=sum(n);

    printf("%d",ans);
}

int sum(int n)
{
    //检验，随时停止
    if(n==0)
    {
        return 0;
    }

    int x=n%10;
     n=n/10;//其实可以把n/10放到括号里去，这里还卡了一下

    int ans=x+sum(n);

    return ans;//真不知道取什么名字了
    
}
