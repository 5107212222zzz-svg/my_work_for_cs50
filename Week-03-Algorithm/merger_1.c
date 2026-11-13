#include<stdio.h>
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

    int *tem=malloc((L+R)*4);

    int i=0;int j=0;int k=0;
    while (i<L||j<R)
    {
        if (i>=L)
        {
            tem[k]=right[j];
            k++;
            j++;
        }
        else if(j>=R)
        {
            tem[k]=left[i];
            k++;
            i++;
        }
     else   if (left[i]<right[j])//一边可能会迅速完，i，j可能会超
        {
            tem[k]=left[i];
            i++;
            k++;
        }
        else if(left[i]>right[j])
        {
            tem[k]=right[j];
            j++;
            k++;
        }
        else if(left[i]==right[j])
        {
            printf("Don't enter repeated number");
        
        }
            
    }

    return tem;
}

