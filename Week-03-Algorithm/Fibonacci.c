/*发现之前写的反复赋值打印数值，还是和这个指定第n个还是有区别的
写了几个就发现了递归的奥秘了，自认为的奥秘hh
接下来开始写简单的归并排序，先hardcode把*/
#include <stdio.h>
int fib(int n);
int main(){
    printf("What's the ranking?\n");

    int n;
    scanf("%d",&n);
    int x=fib(n);

    printf("%d",x);
}

int fib(int n)
{

    if (n==1||n==2)
    {
        return 1;
    }

    int ans=fib(n-1)+fib(n-2);

    return ans;
}