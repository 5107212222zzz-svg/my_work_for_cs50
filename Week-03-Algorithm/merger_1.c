//终于写出一个能跑的merge了，（手动大哭）
//虽然比较垃圾
//全是hardcode
/*先让我整理一下思路
从直观的偶数个开始，随后在推广
其实可以只输入一个数组作为参数，一些声明放到函数内
伪代码：
输出数组，检验元素个数是否为2//即检验回归的条件
为2则进行swap返回数组；
不为2则进行下一个函数（目前还没有回归）
在这里要提前把数组参数转化为左右两边
再次调用函数是对左右两边进行的，接下来进入了循环
直到刚刚调用的函数在元素数量为2时返回出一个数组
在这里直接利用返回值进行回归取值，这里我们再返回一个数组
这里其实我已经到达最深处了，开始和并*/

#include<stdio.h>
#include<stdlib.h>
int* merge(int *num,int n);
int main(){
    //先hardcode
    int num[]={3,8,1,7};

    int n=4;//hardcode
    int *ans=merge(num,n);

    
    for (int i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    free(ans);

    return 0;
}

int* merge(int *num,int n)//原来数组传入函数就会退化成指针
{
    if(n==2)
    {
        if (num[0]>num[1])
        {
            int tem;
            tem=num[0];
            num[0]=num[1];
            num[1]=tem;
        }
        return num;
    }

   
     n=n/2;
     int left[n];
    int right[n];
    //int mid=n/2-1;//右闭
    for (int i=0;i<n;i++)
    {
       int j=i+n;
        left[i]=num[i];
        right[i]=num[j];
        int a=left[i];int b=right[i];
        printf("%d %d",a,b);
       
    }

    int *releft=merge(left,n);
    int *reright=merge(right,n);

     int i=0;int j=0;int k=0;
     int *tems=malloc(2*n*sizeof(int));
    //接下来是对于左右两组来分的，好像可以数量不相等
    while (k<2*n)
    {
        if (i>=n)
        {
            tems[k]=reright[j];
            k++;
            j++;
        }
        else if(j>=n)
        {
            tems[k]=releft[i];
            k++;
            i++;
        }
     else   if (releft[i]<reright[j])//一边可能会迅速完，i，j可能会超
        {
            tems[k]=releft[i];
            i++;
            k++;
        }
        else if(releft[i]>reright[j])
        {
            tems[k]=reright[j];
            j++;
            k++;
        }
        else if(releft[i]==reright[j])
        {
            printf("Don't enter repeated number");
        
        }
            
    }

    return tems;

}
//懒得删了，就留着吧
/*#include<stdio.h>
#include<stdlib.h>
int * merge (int *left ,int *right);
int main(){
   // int num[4]={4,3,2,1};
    //int number=sizeof(num)/4;

    int l[]={2,9};
    int r[]={1,10};

    int *p=merge(l,r);

    for (int i=0;i<4;i++)
    {
        printf("%d",p[i]);
    }

}


int* merge (int *left ,int *right)
{


    int L=sizeof(left)/4;
    int R=sizeof(right)/4;

    //这是等到最后只剩下1个数的时候返回
    if(L=1)
    {
        if (left[0]<right[0])
        {
         int  ans[2]={left[0],right[0]};
            return ans;
        }
        else {
          int  ans[2]={right[0],left[0]};

            return ans;
        }
    }

    int *left1[L];
    int *right1[R];
    for (int i=0;i<L;i++)
    {
        left1[i]=left[i];
        right1[i]=left[i+L];
    }

    int *left2[L];
    int *right2[R];
    for (int i=0;i<L;i++)
    {
        left2[i]=right[i];
        right2[i]=right[i+L];
    }

   int *leftx=merge(left1,right1);
   int  *rightx=merge(left2,right2);

    int *tem=malloc((L+R)*4);

    int i=0;int j=0;int k=0;
    //接下来是对于左右两组来分的，好像可以数量不相等
    while (i<L||j<R)
    {
        if (i>=L)
        {
            tem[k]=rightx[j];
            k++;
            j++;
        }
        else if(j>=R)
        {
            tem[k]=leftx[i];
            k++;
            i++;
        }
     else   if (leftx[i]<rightx[j])//一边可能会迅速完，i，j可能会超
        {
            tem[k]=leftx[i];
            i++;
            k++;
        }
        else if(leftx[i]>rightx[j])
        {
            tem[k]=rightx[j];
            j++;
            k++;
        }
        else if(leftx[i]==rightx[j])
        {
            printf("Don't enter repeated number");
        
        }
            
    }

    return tem;
}*/

