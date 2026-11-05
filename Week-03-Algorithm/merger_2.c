/*作为第二版，我觉得应该达到最终效果了
1.它应该是从用户那接受一串数字，并检验
算了，等我在学习一下
2.解决奇数不对称分组的问题
3.应该尽量优美
4.排序的话应该允许有相同的数
可能的解决方法
统一规定每次划分的规则，比如左边总是偶数
右边总是奇数，但是这样再回归的时候排序要修改
*/
/**/



#include<stdio.h>
#include<stdlib.h>
int *merge(int *num,int n);

int main()
{
    printf("Please enter the number of numbers\n");

    int n=0;
   
    scanf("%d",&n);

    int *num=malloc(n*sizeof(int));

    printf("Please enter the numbers\n");
    for(int i=0;i<n;i++)
    {
        //这里没有检验是否为整数
        scanf("%d",&num[i]);
    }

    printf("Disorder:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }

    int *p=merge( num,n);

    printf("Order:");

    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }

    free(p);

        return 0;


}

int *merge(int *num,int n)
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


    else if(n==3)
    {
        for(int i=0;i<2;i++)
        {
            for (int j=0;j<(2-i);j++)
            {
                 if (num[j]>num[j+1])
                 {
                    int tem;
                    tem=num[j];
                    num[j]=num[j+1];
                    num[j+1]=tem;
                 }
            }
        }

        return num;
    }

    int mid=n/2;
    int L=mid;
    int R=n-mid;
    int left[L];
    int right[R];


    for(int i=0;i<L;i++)
    {
        left[i]=num[i];
    }
    for (int i=0;i<R;i++)
    {
        right[i]=num[L+i];
    }

    int *releft=merge(left,L);
    int *reright=merge(right,R);

    int *tems=malloc((L+R)*sizeof(int));

    int i=0,j=0,k=0;

    while(k<(R+L))
    {
        if(i>=L)
        {
            tems[k++]=reright[j++];
        }
        else if(j>=R)
        {
            tems[k++]=releft[i++];
        }

         else   if (releft[i]<reright[j])
        {
            tems[k++]=releft[i++];//优化一波
        }
        else if(releft[i]>reright[j])
        
            tems[k++]=reright[j++];
        
        else if(releft[i]==reright[j])
        {
            printf("Don't enter repeated number");
        
        }

    
            
    }

    return tems;

    }












