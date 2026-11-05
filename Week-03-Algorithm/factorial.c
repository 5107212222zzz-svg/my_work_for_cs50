#include <stdio.h>

int mul(int n);
int main (){

    int n=0;

    printf("N?\n");
   
    scanf("%d",&n);

    int ans=mul(n);

    printf("%d",ans);


    return 0;
}


int mul(int n)
{
   

    while (n==1)
    {
        return 1;
    }

   int  anw=n*mul(n-1);

    return anw;

   
}